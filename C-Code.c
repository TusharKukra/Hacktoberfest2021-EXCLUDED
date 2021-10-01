#include <stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
   int i,j,spc,rows,k,t=0;
   printf("Input number of rows : ");
   scanf("%d",&rows);
   spc=rows+4-1;
   for(i=1;i<=rows;i++)
   {
         for(k=spc;k>=1;k--)
            {
              printf("   ");
            }
	   for(j=1;j<=i;j++)
	   printf("%d\t",t=t+2);
	printf("\n");
    spc--;
   }
}
