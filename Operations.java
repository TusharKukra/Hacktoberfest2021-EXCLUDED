import java.io.*;
import java.util.*;
public class Operations
{
    public static void print( ArrayList<ArrayList<String>> dbms)
    {
        System.out.println();
        System.out.println("Now Database is in this state");
        for(ArrayList<String> s :dbms)
        {
            for(String ss : s)
                System.out.print(ss+" ");
            System.out.println();
        }
        System.out.println();

    }
    public static void main(String args[])
    {
        try
        {
            File f = new File("dbms.txt");
            FileReader fin=new FileReader(f);
            Scanner inn = new Scanner(fin);
            Scanner in = new Scanner(System.in);

            System.out.println("Performing CRUD Opertaion on File");
            ArrayList<ArrayList<String>> dbms = new ArrayList<>();
            while(inn.hasNextLine())
            {
                String[] line = inn.nextLine().trim().split(" ");
                ArrayList<String> temp = new ArrayList<>();
                for (int j=0; j<line.length; j++) {
                    temp.add(line[j]);
                }
                dbms.add(temp);
            }
            print(dbms);

            int c;
            do {
                System.out.println("Enter 1 For Create Operation\n" +
                        "Enter 2 for Read Operation\n"+
                        "Enter 3 for Update Operation\n"+
                        "Enter 4 for Delete Operation\n"+
                        "Enter 0 for Exit");
                c = in.nextInt();
                switch (c)
                {
                    case 1 :
                        System.out.println("Creating a new entry in Database");
                        System.out.print("Enter Roll number : ");
                        String nrn = in.next();
                        System.out.print("Enter Name : ");
                        String nn = in.next();
                        System.out.print("Enter Branch : ");
                        String nb = in.next();
                        ArrayList<String> temp = new ArrayList<>();
                        temp.add(nrn);
                        temp.add(nn);
                        temp.add(nb);
                        dbms.add(temp);
                        print(dbms);
                        break;

                    case 2 :
                        System.out.println("Reading an entry from Database");
                        System.out.print("Enter Roll number : ");
                        String rrn = in.next();
                        boolean flag = false;
                        for(ArrayList<String> s : dbms)
                        {
                            if(s.get(0).equalsIgnoreCase(rrn))
                            {
                                flag = true;
                                for(String ss : s)
                                    System.out.print(ss+" ");
                                System.out.println("\n");
                            }
                        }
                        if(flag == false)
                            System.out.println("Record not found");
                        break;

                    case 3:
                        System.out.println("\nUpdating an entry from Database");
                        System.out.print("Enter Roll number : ");
                        rrn = in.next();
                        flag = false;
                        for(ArrayList<String> s : dbms)
                        {
                            if(s.get(0).equalsIgnoreCase(rrn))
                            {
                                flag = true;
                                System.out.print("Enter new Name : ");
                                String un = in.next();
                                s.set(1,un);
                                System.out.println("Updated Successfully");

                            }
                        }
                        if(flag == false)
                            System.out.println("Record not found");
                        print(dbms);
                        break;

                    case 4:
                        System.out.println("\nDeleting an entry from Database");
                        System.out.print("Enter Roll number : ");
                        rrn = in.next();
                        flag = false;
                        for(ArrayList<String> s : dbms)
                        {
                            if(s.get(0).equalsIgnoreCase(rrn))
                            {
                                flag = true;
                                dbms.remove(s);
                                System.out.println("Deleted Successfully");
                                break;

                            }
                        }
                        if(flag == false)
                            System.out.println("Record not found");
                        print(dbms);
                }
            }while(c!=0);

            File fout=new File("dbms.txt");
            if(!fout.exists())
                fout.createNewFile();
            FileWriter fw=new FileWriter(fout,false);
            PrintWriter out=new PrintWriter(fw);

            for(ArrayList<String> s :dbms)
            {
                for(String ss : s)
                    out.print(ss+" ");
                out.println();
            }

            out.close();
            inn.close();

        }
        catch (Exception e)
        {
            System.out.println(e.getStackTrace());
        }

    }
}