#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char page[100];
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *current = NULL;

void insertPage(char page[])
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = tail = current = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    printf("Page inserted\n");
}

void moveForward()
{
    if(current == NULL)
    {
        printf("No page available\n");
    }
    else if(current->next == NULL)
    {
        printf("Already at the last page\n");
    }
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

void moveBackward()
{
    if(current == NULL)
    {
        printf("No page available\n");
    }
    else if(current->prev == NULL)
    {
        printf("Already at the first page\n");
    }
    else
    {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}

void deletePage(char page[])
{
    struct Node *temp = head;

    while(temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Page not found\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    if(current == temp)
    {
        if(temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Page deleted\n");
}

void displayForward()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("No pages available\n");
        return;
    }

    printf("Pages from first to last:\n");

    while(temp != NULL)
    {
        printf("%s\n", temp->page);
        temp = temp->next;
    }
}

void displayBackward()
{
    struct Node *temp = tail;

    if(tail == NULL)
    {
        printf("No pages available\n");
        return;
    }

    printf("Pages from last to first:\n");

    while(temp != NULL)
    {
        printf("%s\n", temp->page);
        temp = temp->prev;
    }
}

int main()
{
    int choice;
    char page[100];

    while(1)
    {
        printf("\n1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter page name: ");
                scanf("%99s", page);
                insertPage(page);
                break;

            case 2:
                moveForward();
                break;

            case 3:
                moveBackward();
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%99s", page);
                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}