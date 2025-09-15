#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev,*next;
};

struct node * head = NULL;

void insetbig(int data){
    struct node* new = malloc(sizeof(struct node));
    new->data=data;
    new->next=new->prev=NULL;
    if(head==NULL){
        head = new;
    }
    else{
        new->next=head;
        head->prev=new;
        head=new;
    }
    printf("Node inserted!\n");
}

void insertlas(int data){
    struct node* new = malloc(sizeof(struct node));
    new->data=data;
    new->next=new->prev=NULL;
    if (head==NULL){
        head=new;
    }
    else{
        struct node* temp = head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
}

void insertpos(int data,int pos){
    struct node* new = malloc(sizeof(struct node));
    new->data=data;
    new->next=new->prev=NULL;
    if (pos<1){
        printf("Invalid position!\n");
    }
    else if (pos==1){
        new->next=head;
        if (head!=NULL){
            head->prev=new;
        }
        head=new;
        printf("Node inserted\n");
    }
    else{
        struct node* temp = head;
        for (int i=1; i<pos-1 && temp!=NULL; i++){
            temp=temp->next;
        }
        if (temp==NULL){
            printf("Position out of bound\n");
            return;
        }
        new->next=temp->next;
        new->prev=temp;
        if(temp->next!=NULL){
            temp->next->prev=new;
        }
        temp->next=new;
        printf("Node inserted\n");
    }
}

void delbig(){
    if (head==NULL){
        printf("List empty\n");
        return;
    }
    else{
        struct node* temp = head;
        head=head->next;
        if (head!=NULL){ //recheck head condition 
            head->prev=NULL;
        }
        free(temp);
        printf("Node deleted\n");
    }
}

void dellas(){
    if (head==NULL){
        printf("List empty\n");
        return;
    }
    else if(head->next==NULL){ //for lenth 1
        free(head);
        head=NULL;
        printf("node deleted\n");
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
        printf("node deleted\n");
    }
}

void delpos(int pos){
    struct node* temp=head;
    if (head==NULL){
        printf("List empty\n");
        return;
    }
    else if(pos==1){
        head=head->next;
        if (head!=NULL){
            head->prev=NULL;
        }
        free(temp);
        printf("Node delelted\n");
    }
    else{
        for (int i=1; i<pos&&temp!=NULL; i++){
            temp=temp->next;
        }
        if (temp==NULL){
            printf("Position out of bound\n");
            return;
        }
        if (temp->prev!=NULL){
            temp->prev->next=temp->next;
        }
        if (temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        free(temp);
        printf("Node delelte\n");
    }
}

void traverse(){
    struct node* temp=head;
    int count=0;
    if(head==NULL){
        printf("List empty\n");
    }
    while (temp!=NULL){
        count++;
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    printf("total no. of nodes: %d\n",count);
}

void main(){
    int n,data,pos,ch;
    printf("Enter the no. of nodes: ");
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
                printf("Node deleted\n");
                break;
            case 7:
                traverse();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}