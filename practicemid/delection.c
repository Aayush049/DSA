#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node * head = NULL;

void insert(int data, int pos){
    struct node* new = malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;

    if (head==NULL){
        printf("List empty\n");
        return;
    }
    else{
        struct node* temp = head;
        if (pos == 1){
            new->link=head;
            head=new;
        }
        else{
            for (int i=1; i<pos-1 && temp!=NULL; i++){
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
void delbig(){
    if (head==NULL){
        printf("List empty!\n");
        return;
    }
    else{
        struct node* temp = head;
        head=head->link;
        free(temp);
        printf("Node deleted!\n");
    }
}
void dellas(){
    struct node* temp=head,*temp1;
    if (head==NULL){
        printf("List empty!\n");
        return;
    }
    else if (head->link==NULL){
        free(head);
        head=NULL;
        return;
    }
    else{
    while (temp->link!=NULL){
        temp1=temp;
        temp=temp->link;
    }
    free(temp);
    temp1->link=NULL;
}
}
void delpos(int pos){
    if (head==NULL){
        printf("List empty!\n");
        return;
    }
    else{
        struct node* temp= head;
        if (pos==1){
            head=head->link;
            free(temp);
        }
        else{
            for (int i=1; i<pos-1 && temp!=NULL; i++){
                temp=temp->link;
            }
            if (temp == NULL || temp->link==NULL){
                printf("Position out if bound!\n");
                return;
            }
            else{
                struct node * del = temp->link;
                temp->link=del->link;
                free(del);
            }
        }
    }
}
void tracont(){
    int count=0;
    if (head==NULL){
        printf("List empty!\n");
        return;
    }
    else{
        struct node* temp=head;
        while (temp!=NULL){
            count++;
            printf("%d -> ",temp->data);
            temp=temp->link;
        }
        printf("NULL\n");
        printf("the no. of nodes are: %d\n",&count);
    }
}

void main(){
    int n,data,pos,ch;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    printf("Enter the data\n");
    for (int i = 0; i < n; i++){
        printf("Enter the %d node",i+1);
        scanf("%d",&data);
        insert(data,pos+1);
    }

    printf("MENU\n");
    printf("1. delete from begining.\n");
    printf("2. delete from end.\n");
    printf("3. delete from specific position.\n");
    printf("4. traverse & count.\n");
    printf("5. EXIT\n");

    while(1){
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                delbig();
                break;
            case 2:
                dellas();
                printf("Node deleted!\n");
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d",&pos);
                delpos(pos);
                printf("Node deleted\n");
                break;
            case 4:
                tracont();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
