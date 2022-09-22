import javax.swing.plaf.synth.SynthOptionPaneUI;
import java.util.Scanner;

public class binary
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=0;
        System.out.print("Enter an integer:");

        if(sc.hasNextInt())//判断输入是否为整数
        {
            n=sc.nextInt();
        }
        else
        {
            System.out.println("输入的不是整数");
        }

        System.out.println("The binary value is "+decimalToBinary(n));//调用函数

    }

    public static String decimalToBinary(int value)
    {
        int temp=value;
        String binary="";//创建空字符串
        while(true)
        {
            binary=temp%2+binary;//将余数与字符串拼接
            if(temp/2==0)
            {
                break;//若整除到0，结束循环
            }
            temp/=2;//整除2
        }
        return binary;
    }
}
