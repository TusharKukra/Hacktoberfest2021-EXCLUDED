import java.util.Scanner;  
 class SpyNumber
{  
public static void main(String args[])  
{   
int num, product=1, sum=0, lastdigit;  
// create object of scanner  
Scanner sc = new Scanner(System.in);  
System.out.print("Enter the number to check: " );  
//reads an integer from the user and stores it in the variable num  
num=sc.nextInt();  
//executes untill the condition becomes false  
while(num>0)  
{  
//finds the last digit of the number      
lastdigit=num%10;  
sum=sum+lastdigit;  
product=product*lastdigit;  
num=num/10;  
}  
//compares the sum and product  
if(sum==product)  
 
System.out.println("The given number is a spy number.");  
else  
System.out.println("The given number is not a spy number.");  
}  
}  