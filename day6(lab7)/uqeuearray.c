/*Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue,
Traverse, IsEmpty, IsFull operations.*/

#include<stdio.h>
#include<stdlib.h>

int front,rare;
int *queue;

void dequeue(){

}
void main(){
    int data,ch,n;
    printf("Enter no. of data to fill: ");
    scanf("%d",&n);
    printf("Enter the data: ");
    for(int i=0; i<n; i++){
        printf("For %d node: ",i+1);
        scanf("%d",&data);
    }

    printf("MENU\n");
    printf("Enqueue\n");
    printf("Dequeue\n");
    printf("Isempty\n");
    printf("Isfull\n");
    printf("Traverse\n");
    printf("Exit\n");
    while (1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
    }

    switch(ch){
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (isempty())
                printf("Queue empty: True\n");
            else
                printf("Queue empty: False\n");
            break;
        case 4:
            if (isfull())
                printf("Queue full: True\n");
            else
                printf("Queue full: False\n");
            break;
        case 5:
            traverse();
            break;
        case 6:
            free(queue); // free allocated memory
            exit(0);
        default:
            printf("Invalid option! Try again.\n");
    }
}