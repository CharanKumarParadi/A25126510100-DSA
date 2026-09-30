#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int roll;
    struct Node *next;
};
struct Node *head = NULL;
void insertBeginning(int roll)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = head;
    head = newNode;
    printf("Inserted at beginning\n");
}
void insertEnd(int roll)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
    printf("Inserted at end\n");
}
void search(int roll)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        if(temp->roll == roll)
        {
            printf("Roll number %d found\n", roll);
            return;
        }
        temp = temp->next;
    }
    printf("Roll number %d not found\n", roll);
}
void deleteNode(int roll)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->roll == roll)
    {
        head = head->next;
        free(temp);
        printf("Roll number %d deleted\n", roll);
        return;
    }
    while(temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Roll number %d not found\n", roll);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Roll number %d deleted\n", roll);
}
void display()
{
    struct Node *temp = head;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Roll numbers: ");
    while(temp != NULL)
    {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice, roll;

    while(1)
    {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                display();
                break;
            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                display();
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;
            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteNode(roll);
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}