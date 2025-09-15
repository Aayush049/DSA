#include<stdio.h>

void arra(int n)
{
        int arr[n];
        printf("Enter the values in the array ");
        for (int i=0; i<n; i++)
                scanf("%d",&arr[i]);
        for (int i=0; i<n; i++)
                printf("%d ",arr[i]);
	printf("\n");
}
void main(){
        int n;
        printf("Enter the size of the array: ");
        scanf("%d",&n);
	arra(n);
}
