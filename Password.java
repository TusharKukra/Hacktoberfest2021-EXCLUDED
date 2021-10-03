package passwordsecurity;
import java.util.Scanner;

public class pass {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		   System.out.println("Username");
		   String un=scan.next();
		   String str=" ";
		   int flag=0,index=0,flag1=0,flag2=0,flag3=0,flag4=0,index1=0;

		   for(int i=0;i<un.length();i++){
		      if(un.charAt(i)=='@'){
		         flag=1;
		         index=i;
		         break;
		      }
		   }


		      for(int i=index;i<un.length();i++){
		         if(un.charAt(i)=='.'){
		            flag1=1;
		            index1=i;
		            break;
		         }
		      }

		      if(flag==1 && flag1==1){
		         for(int i=index+1;i<index1;i++){
		            str+=un.charAt(i);
		         }
		      }


		      if(flag==1 && flag1==1){
		         System.out.println("Hello"+str+" "+"user");
		      }

		      System.out.println("Password");
		      String pwd=scan.next();

		      if(pwd.length()>=8){
		         if(un!=pwd){
		            for(int i=0;i<pwd.length();i++){
		               int d=pwd.charAt(i);
		               if(d>=48 && d<=57){
		                  flag2=1;
		                  break;
		               }
		            }
		            for(int i=0;i<pwd.length();i++){
		               int d=pwd.charAt(i);
		               if(d<48 || d>57 && d<65 || d>91 && d<122){
		                  flag3=1;
		                  break;
		               }
		            }
		            int p=pwd.charAt(0);
		            if(p>=65 && p<=91){
		               flag4=1;
		            }
		         }

		   }


		   if (flag==1 && flag1==1 && flag2==1 && flag3==1 && flag4==1){

		      System.out.println("Welcome to our calculator");
		      System.out.println("Enter first number");
		      int fn=scan.nextInt();
		      System.out.println("Enter second number");
		      int sn=scan.nextInt();
		      System.out.println("Choose an operator");
		      String op=scan.next();
		      int ans=0;
		      switch(op.charAt(0)){
		         case '+':
		            ans=fn+sn;
		            break;
		         case '-':
		            ans=fn-sn;
		            break;
		         case '*':
		            ans=fn*sn;
		            break;
		         case '/':
		            ans=fn/sn;
		            break;
		      }
		      System.out.println("Answer = "+ans);
		   }
		   else{
		      System.out.println("This account does not exist");
		   }
		   }
		
		
		
		
		
		
		
	}
