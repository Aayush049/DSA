#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

struct node* findMin(struct node* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* findMax(struct node* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

int height(struct node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countLeafNodes(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct node* root = NULL;
    int n, val, ch;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Insert\n");
        printf("2. Largest\n");
        printf("3. Smallest\n");
        printf("4. Height\n");
        printf("5. Count leaf nodes\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert in BST: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Element %d inserted successfully.\n", val);
                break;

            case 2:
                if (root != NULL)
                    printf("Largest element in BST = %d\n", findMax(root)->data);
                else
                    printf("BST is empty.\n");
                break;

            case 3:
                if (root != NULL)
                    printf("Smallest element in BST = %d\n", findMin(root)->data);
                else
                    printf("BST is empty.\n");
                break;

            case 4:
                printf("Height of BST = %d\n", height(root));
                break;

            case 5:
                printf("Number of leaf nodes = %d\n", countLeafNodes(root));
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}