//Even numbers arranged in lower triangular matrix in given number of rows.

#include <stdio.h>

void main()
{
   int i,j,rows,t=0;
   printf("Input number of rows : ");
   scanf("%d",&rows);
   for(i=1;i<=rows;i++)
   {
        for(j=(rows-i);j>=1;j--)
            printf("\t");
	    for(j=1;j<=i;j++)
	        printf("%d\t",t=t+2);
	printf("\n");
   }
}
