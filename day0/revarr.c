#include<stdio.h>
void main(){
	int n;
	printf("Enter the size of array");
	scanf("%d",&n);
	int *arr;
	arr=malloc(n*sizeof(int));
	for (int i=0; i<n; i++){
                scanf("%d",&arr[i]);
        }
	for (int i=0; i<(n/2); i++){
		int temp;
		temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;
	}
	for (int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
