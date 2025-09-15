#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;  // header node pointer

// Function to create header node (call only once)
void initHeader() {
    head = malloc(sizeof(struct node));
    head->data = 0;   // store count of nodes
    head->link = NULL;
}

// Function to insert node at given position
void createLL(int data, int pos) {
    if (head == NULL) {
        printf("Header not initialized. Call initHeader() first.\n");
        return;
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;

    if (pos < 1) {
        printf("Invalid position\n");
        free(new);
        return;
    }

    if (pos == 1) {  // insert at beginning
        new->link = head->link;
        head->link = new;
        printf("Node iserted\n");
    } 
    else { // insert at given pos
        struct node *temp = head->link;
        for (int i = 1; i < pos-1 && temp != NULL; i++) {
            temp = temp->link;
        }

        if (temp == NULL) {
            printf("Position out of bound\n");
            free(new);
            return;
        }

        new->link = temp->link;
        temp->link = new;
        printf("Node iserted\n");
    }
    head->data++;  // increase count of nodes
}

void display(){
    struct node* temp=head->link;
    printf("Header count: %d",head->data);
    while (temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}

int main() {
    int n,data,pos,ch;
    initHeader();     // Initialize header node
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data:\n");
    for (int i = 0; i < n; i++) {
        printf("For node %d: ", i + 1);
        scanf("%d", &data);
        createLL(data, i + 1);   // insert sequentially at position (1, 2, 3, …)
    }
    printf("MENU\n");
    printf("1.Isert\n");
    printf("2.Display\n");
    printf("3.Exit");
    while (1){
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter the data & position: ");
                scanf("%d %d",data,pos);
                createLL(data,pos);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("INvalid choice!\n");
        }
    }

}