/*5.2 Write a program to create a circular linked list and display the elements of the list.*/

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*head=NULL,*last=NULL;
void create(int n){
    int d;
    for(int i=1;i<=n;i++){
        printf("Enter info of node%d: ",i);
        scanf("%d",&d);
        struct Node*newNode=malloc(sizeof(struct Node));
        newNode->data=d;
        newNode->next=NULL;
        if(!head){
            head=last=newNode;
            last->next=head;
        }
        else{
            last->next=newNode;
            last=newNode;
            last->next=head;
        }
    }
}
void display(){
    if(!head){
        printf("List is empty!\n");
        return;
    }
    struct Node*t=head;
    printf("The circular list is: ");
    do{
        printf("%d ",t->data);
        t=t->next;
    }while(t!=head);
    printf("\n");
}
int main(){
    int n;
    printf("Enter no.of nodes: ");
    scanf("%d",&n);
    create(n);
    display();
    return 0;
}