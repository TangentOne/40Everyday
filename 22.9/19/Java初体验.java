import java.util.Scanner;

public class Conversion {
    public static void main(String[] args) {
      int tem=1451;
      System.out.println(decimalToBinary(tem));
    }

    public static String reorder(String str){
        return new StringBuffer(str).reverse().toString();
    }
    public static String decimalToBinary(int value)
    {
        String stl="";
        int i=0;
        int current=0;
        double math=0;
        while(value!=0)
        {
            current=value%2;
            value=value/2;
            stl=stl+current;
        }

        return reorder(stl);
    }



}
