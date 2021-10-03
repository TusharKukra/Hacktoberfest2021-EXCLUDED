#include<stdio.h>
void main()
{    
	int i;
	int j;
	int n;
    int a[80][80];
	printf("Enter size of square matrix \n");
	scanf("%d",&n);
	printf("\n Enter elements in array\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n lower half of matrix is \n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i>=j)
			printf(" %d ",a[i][j]);
		}
	printf("\n")	;
	}
	
}
