public class longestPalindromicSubsequence {
    public static void main(String[] args) {
        String s = "bbbab";
        StringBuilder sb = new StringBuilder(s);
        System.out.println(lcs(sb.toString(), sb.reverse().toString()));

    }
    public static int lcs(String text1, String text2) {
        int[][] dp  = new int[text1.length() + 1][text2.length() + 1];
        for(int i = 1; i < text1.length() + 1; i++) {
            for(int j = 1; j < text2.length() + 1; j++) {
                char t1 = text1.charAt(i-1);
                char t2 = text2.charAt(j-1);

                if(t1 == t2)
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }


        return dp[text1.length()][text2.length()];
    }
}
