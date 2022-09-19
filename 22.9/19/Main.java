import java.awt.desktop.SystemEventListener;
import java.util.Random;
import java.util.Scanner;


public class Main {

    public static void main(String[] args)
    {
        HWDecimalToBinary();
    }



///////////////////////////////////////////////////////////////////////////////////////////////////

    public static void HWDecimalToBinary()
    {
        System.out.println("Enter an integer:");
        int num=scan.nextInt();
        System.out.println("The binary value is "+decimalToBinary(num));
    }

    public static String decimalToBinary(int value)
    {
        String str="";
        while(value!=0)
        {
            str+=(char)(value%2+'0');
            value/=2;
        }
        return reverse(str);
    }
    public static String reverse(String str)
    {
        return new StringBuffer(str).reverse().toString();
    }









    ///////////////////////////////////////////////////////////////////////////////////////////////////
    public static void HWMathTutor()
    {

        Random r= new Random();
        while(true)
        {
            System.out.println("Main menu\n1: Addition\n2: Subtraction\n3: Multiplication\n4: Division\n5: Exit\nEnter a choice:");
            int option=scan.nextInt();
            int a=r.nextInt(10);
            int b=r.nextInt(10);
            switch (option)
            {
                case 1:doAdd(a,b);break;
                case 2:doSub(a,b);break;
                case 3:doMul(a,b);break;
                case 4:doDiv(a,b);break;
                default:return;
            }
            System.out.println();
        }




    }
    public static void doAdd(int lhs,int rhs)
    {
        System.out.println("What is "+lhs+"+"+rhs+"?");
        int ans=scan.nextInt();
        if(ans==rhs+lhs) System.out.println("Correct");
        else System.out.println("Your answer is wrong. The correct answer is "+Math.addExact(lhs,rhs) );

    }
    public static void doSub(int lhs,int rhs)
    {
        System.out.println("What is "+lhs+"-"+rhs+"?");
        int ans=scan.nextInt();
        if(ans==lhs-rhs) System.out.println("Correct");
        else System.out.println("Your answer is wrong. The correct answer is "+Math.subtractExact(lhs,rhs) );
    }
    public static void doMul(int lhs,int rhs)
    {
        System.out.println("What is "+lhs+"*"+rhs+"?");
        int ans=scan.nextInt();
        if(ans==lhs*rhs) System.out.println("Correct");
        else System.out.println("Your answer is wrong. The correct answer is "+Math.multiplyExact(lhs,rhs) );
    }
    public static void doDiv(int lhs,int rhs)
    {
        while(rhs==0) {Random r=new Random();rhs=r.nextInt(10);}
        System.out.println("What is "+lhs+"/"+rhs+"?");
        int ans=scan.nextInt();
        if(ans==Math.floorDiv(lhs,rhs)) System.out.println("Correct");
        else System.out.println("Your answer is wrong. The correct answer is "+Math.floorDiv(lhs,rhs) );

    }






///////////////////////////////////////////////////////////////////////////////////////////////////
    public static void HWRandomPoint()
    {
        Random r = new Random();
        double d1 = r.nextDouble()*5; // 生成[0,1.0]区间的小数
        boolean b1 = r.nextBoolean(); // 生成一个随机布尔型值
        if(b1) d1=-d1;

        double d2 = r.nextDouble()*5; // 生成[0,1.0]区间的小数
        boolean b2 = r.nextBoolean(); // 生成一个随机布尔型值
        if(b2) d2=-d2;

        System.out.println("The point is (" + d1+","+d2+") and its distance to the center is "+Math.sqrt(d1*d1+d2*d2));
    }


    static Scanner scan = new Scanner(System.in);



}