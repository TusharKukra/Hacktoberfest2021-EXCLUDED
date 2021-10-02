class Main
{
    public static String removeZero(String str)
    {
        int i = 0;
        while (i < str.length() && str.charAt(i) == '0')
            i++;
  
        StringBuffer sb = new StringBuffer(str);
  
        sb.replace(0, i, "");
  
        return sb.toString();  
    }
  
    public static void main (String[] args)
    {
        String str = "00000123569";
        str = removeZero(str);
        System.out.println(str);
        
        str = "000879669000";
        str = removeZero(str);
        System.out.println(str);
    }
}
