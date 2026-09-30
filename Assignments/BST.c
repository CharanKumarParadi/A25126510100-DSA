#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void search(struct Node *root, int value)
{
    if(root == NULL)
    {
        printf("%d not found in BST\n", value);
        return;
    }

    if(root->data == value)
    {
        printf("%d found in BST\n", value);
        return;
    }

    if(value < root->data)
        search(root->left, value);
    else
        search(root->right, value);
}

int main()
{
    struct Node *root = NULL;
    int n, value, searchValue;

    printf("Enter number of values: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n\nEnter value to search: ");
    scanf("%d", &searchValue);

    search(root, searchValue);

    return 0;
}