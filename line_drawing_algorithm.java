// Java code for Bresenham's line algorithm
// this code will give plot points between 2 cordinates.

import java.util.Scanner;

public class Main {
    static int dPara;
    static int x0;
    static int y0;
    static int x1;
    static int y1;
    static int dY;
    static int dX;
    static int x;
    static int y;


    public static void main(String[] args) {
        int xArr[] = new int[2];
        int yArr[] = new int[2];
        int x0;
        int x1;
        int y0;
        int y1;
        int dPara;
        int dy;
        int dx;
        int x;
        int y;

        Scanner read = new Scanner(System.in);
        String s[] = read.nextLine().split(" ");
        for (int i = 0; i < s.length; i++) {
            xArr[i] = Integer.parseInt(s[i]);
        }
        String s1[] = read.nextLine().split(" ");
        for (int i = 0; i < s1.length; i++) {
            yArr[i] = Integer.parseInt(s1[i]);
        }
        x0 = xArr[0];
        x1 = yArr[0];
        y0 = xArr[1];
        y1 = yArr[1];
        dx = Math.abs(x0 - x1);
        dy = Math.abs(y0 - y1);
        dPara = (2 * dy) - dx;

        if (x0 > x1) {
            x = x1;
            y = y1;
            for (int i = x1; i <= x0; i++) {
                if (dPara < 0) {
                    System.out.println(x++ + " " + y);
                    dPara = dPara + (2 * dy);
                } else {
                    System.out.println(x++ + " " + y++);
                    dPara = dPara + (2 * dy) - (2 * dx);
                }
            }
        } else {
            x = x0;
            y = y0;
            // System.out.println(x + " " + y);
            for (int i = x0; i <= x1; i++) {
                if (dPara < 0) {
                    System.out.println(x++ + " " + y);
                    dPara = dPara + (2 * dy);
                } else {
                    System.out.println(x++ + " " + y++);
                    dPara = dPara + (2 * dy) - (2 * dx);
                }
            }
        }
    }
}
