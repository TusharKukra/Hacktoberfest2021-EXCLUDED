import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String b= "";
        int n = A.length();
        for(int i = n - 1; i >= 0; i--){

             b = b + A.charAt(i);
        }
        if(A.equalsIgnoreCase(b))
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
        
    
}}
