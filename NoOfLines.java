import java.io.*;
import java.util.*;
public class NoOfLines
{
    public static void main(String args[])
    {
        try
        {
            Scanner in = new Scanner(System.in);
            System.out.println("Enter the source code location whose number of lines you want to calculate");
            String location = in.nextLine();
            FileInputStream fi = new FileInputStream(location);
            Scanner file = new Scanner(fi);
            int ans = 0;
            while (file.hasNextLine())
            {
                String temp = file.nextLine();
                ans++;
            }
            System.out.println("The number of lines in the file is " + ans);
            fi.close();
            in.close();
            file.close();
        }
        catch(Exception e)
        {
            System.out.println("File is not found or File is not compatible for calculation of number of lines");
            System.out.print(e.getMessage());
        }
    }
}
