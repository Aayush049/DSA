#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};

struct node * head = NULL;

void insertbig(int data){
    struct node * new = malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    if (head==NULL){
        head=new;
    }
    else{
        new->link=head;
        head=new;
    }
    printf("Node Inserted!\n");
}
void insertlas(int data){
    struct node * new = malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    if (head==NULL){
        head=new;
    }
    else{
        struct node * temp = head;
        while (temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=new;
    }
}
void insertpos(int data, int pos){
    struct node * new = malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;

    if (pos<1){
        printf("invalid position\n");
        return;
    }
    else{
        if (pos==1){
            new->link=head;
            head=new;
        }
        else{
            struct node * temp = head;
            for (int i=1; i<pos-1&&temp!=NULL; i++){
                temp=temp->link;
            }
            if(temp==NULL){
                printf("Position out of bound!\n");
                free(new);
                return;
            }
            new->link=temp->link;
            temp->link=new;
        }
    }
}
void traverse(){
    int count=0;
    struct node * temp = head;
    if (head==NULL){
        printf("List empty!\n");
        return;
    }
    else{
        while (temp != NULL){
            count++;
            printf("%d -> ",temp->data);
            temp=temp->link;
        }
        printf("NULL\n");
        printf("total no. of nodes: %d\n",count);
    }
}

void main(){
    int n,ch,data,pos;
    printf("Enter the no. of node: ");
    scanf("%d",&n);
    printf("Enter the data: \n");
    for (int i=0;i<n;i++){
        printf("for %d node: ",i+1);
        scanf("%d",&data);
        insertpos(data,i+1);
    }

    printf("MENU\n");
    printf("1. insert at begining.\n");
    printf("2. insert at end.\n");
    printf("3. insert at specific position.\n");
    printf("4. traverse.\n");
    printf("5. EXIT\n");

    while(1){
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch (ch){
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
                traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("INvalid choice!\n");
        }
    }
}