#include<stdio.h>
void fact(int n)
{
	int prod = 1;
	for (int i=1; i<=n; i++)
	{
		prod*=i;
	}
	printf("%d\n",prod);
}
void main()
{
	int n;
	printf("Enter the number to find factorial: ");
	scanf("%d",&n);
	fact(n);
}