package keypad2;
import java.util.Scanner;
public class keyp {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
        String num=scan.next();
        int count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='1'){
                count++;
            }
        }
        if(count==num.length()){
            System.out.println(".");
        }
        count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='2'){
                count++;
            }
        }
        if(count==num.length()){
            String str="abc";
            System.out.println(str.charAt(count-1));
        }
        count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='3'){
                count++;
            }
        }
        if(count==num.length()){
            String str="def";
            System.out.println(str.charAt(count-1));
        }
        count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='4'){
                count++;
            }
        }
        if(count==num.length()){
            String str="ghi";
            System.out.println(str.charAt(count-1));
        }
        count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='5'){
                count++;
            }
        }
        if(count==num.length()){
            String str="jkl";
            System.out.println(str.charAt(count-1));
        }
        count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='6'){
                count++;
            }
        }
        if(count==num.length()){
            String str="mno";
            System.out.println(str.charAt(count-1));
        }
        count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='7'){
                count++;
            }
        }
        if(count==num.length()){
            String str="pqrs";
            System.out.println(str.charAt(count-1));
        }
        count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='8'){
                count++;
            }
        }
        if(count==num.length()){
            String str="tuv";
            System.out.println(str.charAt(count-1));
        }
        count=0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)=='9'){
                count++;
            }
        }
        if(count==num.length()){
            String str="wxyz";
            System.out.println(str.charAt(count-1));
        }
	}

}
