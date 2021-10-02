
/*
                HEY EVERYONE, I'm Om Duragkar
        The problem discussed int his is very famous and a good Question.
        Topics Required: Function and Arrays:


        Problem Stement: 
        In a country of novice government, the economic system is changed where only coins are used that too of various denominations. Whenever a foreigner visits this country, they visit a money exchanger to get the currency of the same country. As the foreigner is unaware of the denomination of the country, the money exchange prefers to tell them the denomination which is the nearest maximum and nearest minimum to the denomination mentioned by the foreigner. In case they get the correct guess of the denomination, they are told the same denomination. The denominations are always quoted in ascending order.

        Example 1: In a country, 8 given denominations are as follows
        [5, 10, 15, 22, 33, 40, 42, 55]

        The foreigner asks for denomination 25.
        The money exchange tells them that denominations of 33 and 22 are available.

        Example 2: 
        In a country, 5 given denominations are as follows
        [7, 14, 18, 25, 30]

        The foreigner asks for the denomination of 18.

        The money exchange tells them a denomination of 18 is available.  

        You are required to print the values told by the money exchange to the foreigner.

        1. You are given a number n, representing the size of array a.
        2. You are given n numbers, representing elements of the array a.
        3. You are given another number d.
        4. You are required to find the ceil and floor of d in array a.


        So let's Begin:
*/


import java.util.*;

public class brokeneconomy{
    
    public static void main(String[] args) {
        
        // Since we have to take input thus making a scanner:
        Scanner scn = new Scanner(System.in);
        // Now making array  of the total Denominations:
        int n =scn.nextInt();
        int []arr= new int [n];
        for(int i=0;i<n;i++)
        {
            //Scanned n denomination
            arr[i] = scn.nextInt();  
        }
        // The denomination person wants:
        int imp = scn.nextInt();

        // Now lets assign ceil floor some value:
        int ceil = -1;
        int floor = -1;
        int i=0;
        int j=arr.length -1;
        while(i<=j)
        {
            int sum = (i+j)/2;
            if(arr[sum] == imp)
            {
                System.out.println(imp);
                return;
            }
            else if(arr[sum]> imp)
            {
                
                ceil = arr[sum];
                j=sum-1;
            }
            else if(arr[sum]<imp)
            {
                floor=arr[sum];
                i=sum+1;
                
            }
        }
        System.out.println(ceil);
        System.out.println(floor);
    }
}