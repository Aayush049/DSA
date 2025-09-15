#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* head=NULL;

void insertbig(int data){
    struct node * new = malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    if (head==NULL){
        head=new;
        new->link=head;
    }
    else{
        struct node* ptr = head;
        while (ptr->link!=head){
            ptr=ptr->link;
        }
        new->link=head;
        head=new;
        ptr->link=new;
    }    
}

void insertlas(int data){
    struct node * new = malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    if (head==NULL){
        head=new;
        new->link=head;
    }
    else{
        struct node* temp=head;
        while (temp->link!=head){
            temp=temp->link;
        }
        temp->link=new;
        new->link=head;
    }
}

void insertpos(int data, int pos){
    struct node * new = malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;

    if (pos < 1){
        printf("Invalid position\n");
        return;
    }
    else if (pos == 1){
        if (head == NULL){
            head = new;
            new->link = head;
        }
        else{
            struct node* ptr = head;
            while (ptr->link != head){ 
                ptr = ptr->link;
            }
            new->link = head;
            head = new;
            ptr->link = head;
        }
    }
    else {
        struct node* ptr = head;
        int i = 1;
        while (i < pos-1 && ptr->link != head){
            ptr = ptr->link;
            i++;
        }
        new->link = ptr->link;
        ptr->link = new;
    }

    printf("Node inserted at position %d!\n", pos);
}

void delbig(){
    if (head==NULL){
        printf("List empty\n");
        return;
    }
    else if (head->link == head){
        free(head);
        head = NULL;
    }
    else{
        struct node *ptr=head,*temp=head;
        while (ptr->link!=head){
            ptr=ptr->link;
        }
        head=head->link;
        ptr->link=head;
        free(temp);
    }
}

void dellas(){
    if (head==NULL){
        printf("List empty\n");
        return;
    }
    else if (head->link == head){  
        free(head);
        head = NULL;
    }
    else{
        struct node *temp,*ptr=head;
        while (ptr->link->link!=head){
            ptr=ptr->link;
        }
        temp = ptr->link;
        ptr->link=head;
        free(temp);
    }
}

void delpos(int pos){
    if (head==NULL){
        printf("List empty\n");
        return;
    }

    struct node *temp=head, *ptr=head;

    // Case 1: delete first node
    if (pos==1){
        while (temp->link!=head){   // find last node
            temp=temp->link;
        }

        if (head->link == head){    // only one node
            free(head);
            head = NULL;
        }
        else{
            ptr = head;             // old head
            head = head->link;      // move head
            temp->link = head;      // last node points to new head
            free(ptr);              // free old head
        }
        printf("Node deleted from position 1\n");
    }

    // Case 2: delete at position > 1
    else{
        int i = 1;
        while (i < pos-1 && ptr->link != head){ 
            ptr = ptr->link;
            i++;
        }

        if (ptr->link == head){  
            printf("Invalid position\n");
        }
        else{
            temp = ptr->link;           
            ptr->link = temp->link;     
            free(temp);
            printf("Node deleted from position %d\n", pos);
        }
    }
}


void travcont(){
    int count = 0;
    if (head == NULL){
        printf("List empty\n");
        return;
    }
    struct node *temp = head;

    do {
        printf("%d -> ", temp->data);
        count++;
        temp = temp->link;
    } while (temp != head);

    printf("head\n");
    printf("Total no. of nodes: %d\n", count);
}


void main(){
    int n,data,pos,ch;
    printf("Enter the no. of node: ");
    scanf("%d",&n);
    printf("Enter the data\n");
    for (int i=0; i<n; i++){
        printf("For %d node: ",i+1);
        scanf("%d",&data);
        insertpos(data,i+1);
    }

    printf("MENU\n");
    printf("1. insert at begining.\n");
    printf("2. insert at end.\n");
    printf("3. insert at specific position.\n");
    printf("4. delete from begining.\n");
    printf("5. delete from end.\n");
    printf("6. delete from specific position.\n");
    printf("7. traverse.\n");
    printf("8. EXIT\n");

    while(1){
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data to inserts: ");
                scanf("%d",&data);
                insertbig(data);
                break;
            case 2:
                printf("Enter the data to inserts: ");
                scanf("%d",&data);
                insertlas(data);
                break;
            case 3:
                printf("Enter the data and position: ");
                scanf("%d %d",&data,&pos);
                insertpos(data,pos);
                printf("Node inserted\n");
                break;
            case 4:
                delbig();
                break;
            case 5:
                dellas();
                printf("Node deleted!\n");
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d",&pos);
                delpos(pos);
                break;
            case 7:
                travcont();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}