package Patterns;

import java.util.ArrayList;
import java.util.List;

public class KMP {

    private String text;

    public KMP(String text) {
        this.text = text;
    }

    public List<Integer> getMatches(String pattern) {
        return KMP.getMatches(text, pattern);
    }

    public static List<Integer> getMatches(String text, String pattern) {

        List<Integer> result = new ArrayList<>();

        int[] lps = lps(pattern);
        int j = 0;

        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) == pattern.charAt(j)) {
                if (j == pattern.length() - 1) {
                    result.add(i - j);
                    j = lps[j + 1];
                } else
                    j++;

            } else {
                if (j != 0) {
                    j = lps[j];
                    i--;
                }
            }

        }

        return result;
    }

    static int[] lps(String pattern) {

        int[] lps = new int[pattern.length() + 1];
        lps[0] = 0;

        int j = 1;

        for (int i = 1; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);
            if (ch == pattern.charAt(j - 1)) {
                lps[i + 1] = j;
                j++;
            } else {
                if (j == 1) {
                    lps[i + 1] = 0;
                } else {
                    j = 1;
                    i--;
                }
            }
        }

        return lps;
    }

    public static void main(String args[]) {

        String txt = "aabcaabccbbacaabbbcccaaaabcbcbcbaabababaccbababaabc";
        String pat = "abc";

        List<Integer> result = getMatches(txt, pat);
        System.out.println(result.toString());
    }
}
