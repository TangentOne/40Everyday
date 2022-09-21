import java.util.Scanner;

public class binary {
    public static void main(String[] args)
    {

        Scanner scanner=new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int a=scanner.nextInt();
        System.out.print("The binary value is ");
        deal(a);
    }
    public static void deal(int x)
    {
        if(x==0)
            return;
        int temp=x%2;
        deal(x/2);
        System.out.print(temp);
    }
}
