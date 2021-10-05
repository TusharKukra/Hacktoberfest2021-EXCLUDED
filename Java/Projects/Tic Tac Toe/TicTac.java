package game;

import java.util.Scanner;

public class TicTac {
    private char board[][];
    private int cur_player;
    TicTac()
    {
        board=new char[3][3];
        cur_player=0;
        char k='1';
       for(int i=0;i<3;i++)
       {
           for(int j=0;j<3;j++)
               board[i][j]=k++;
       }
    }
    void getWin(int i,int j)
    {
        System.out.print("Player ");
        if(board[i][j]=='X')
            System.out.print("1");
        else
            System.out.print("2");
        System.out.println( " Wins");
    }
    boolean checkStatus()
    {
            if(cur_player==9)
            {
                System.out.println("Game Drawn");
                return true;
            }
            for(int j=0;j<3;j++)
            {
                if(board[0][j]==board[1][j]&&board[0][j]==board[2][j])
                {
                    getWin(0,j);
                    return  true;
                }
            }
        for(int j=0;j<3;j++)
        {
            if(board[j][0]==board[j][1]&&board[j][0]==board[j][2])
            {
                getWin(j,0);
                return  true;
            }
        }
       if(board[0][0]==board[1][1]&&board[0][0]==board[2][2])
       {
           getWin(0,0);
           return true;
       }
       if(board[0][2]==board[1][1]&&board[0][2]==board[2][0])
       {
           {
               getWin(0,2);
               return true;
           }
       }
        return false;
    }
    void  diplay_board()
    {
        for(int i=0;i<3;i++)
        {
            System.out.print("| ");
            for(int j=0;j<3;j++)
                System.out.print(board[i][j]+" | ");
            System.out.println();
        }
    }
    void fill()
    {
        Scanner sc =new Scanner(System.in);
        diplay_board();
        System.out.println("Enter cell to make your move");
        int pos=sc.nextInt();
        int r=(pos-1)/3,c=(pos-1)%3;
        if(pos<1||pos>9||board[r][c]=='X'||board[r][c]=='O')
        {
            System.out.println("Invalid Move");
        }
        else
        {
            if(cur_player%2==0)
                board[r][c]='X';
            else
                board[r][c]='O';
            cur_player=cur_player+1;
        }
    }
    void run()
    {
        System.out.println("Player "+(cur_player%2+1)+" turn");
        while(checkStatus()==false)
        {
            fill();
        }
    }
}
