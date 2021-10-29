#include<string.h>
void reduceSequence(char *str, char ch)
{
  int i,count=0,k=0;
  int x = strlen(str);
  //printf("x=%d\n",x);
	if(x==1)
    {
      //printf("%s\n",str);
    }
	else
    {
      for(i=0;i<x-1;i++)
      {
     	  if(str[i] == ch && str[i+1] == ch)
          str[i+1] = '0';
        
        	else if(str[i] == '0' && str[i+1] == ch)
              str[i+1] = '0';
      }
      
      for(i=0;i<x;i++)
      {
        if(str[i] != '0')
          count++;
      }
     // printf("count=%d\n",count);
      char a[count];
      for(i=0;i<x;i++)
      {
        //printf("k=%d  i=%d\n",k,i);
        if(str[i] != '0')
        {
          a[k] = str[i];          
          //printf("k=%d  i=%d\n",k,i);
          k++;
          
        }
      }
      for(i=0;i<=count;i++)
      {
        if(i==count)
          str[i] = '\0';
        else
        str[i] = a[i];
      }
    }
}
