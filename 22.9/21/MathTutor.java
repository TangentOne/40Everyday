import java.util.Random;
import java.util.Scanner;

public class MathTutor {
    public static void main(String[] args)
    {
     Scanner input=new Scanner(System.in);
     int choose=0;
     while(choose!=5)
     {
         menu();
         choose=input.nextInt();
         choice(choose);
     }
    }
    public static void menu()
    {
        System.out.println("1: Addition");
        System.out.println("2: Subtraction");
        System.out.println("3: Multiplication");
        System.out.println("4: Division");
        System.out.println("5: Exit");
    }

    public static void choice(int value)
    {

        Scanner putans=new Scanner(System.in);
        int number1=(int)(Math.random()*10);
        int number2=(int)(Math.random()*10);
        int tem=0;
        int answer=0;
        switch(value)
        {
            case 1:
                System.out.print("What is "+number1+"+"+number2+"?");
                answer=putans.nextInt();
                System.out.println();
                if(answer==number1+number2)
                    System.out.println("Correct");
                else
                {
                    answer=number1+number2;
                    System.out.println("Your answer is wrong. The correct answer is "+answer);
                }
                break;
            case 2:
                if(number1<number2) {
                    tem = number1;
                    number2 = number1;
                    number2 = tem;
                }
                System.out.print("What is "+number1+"-"+number2+"?");
                answer=putans.nextInt();
                System.out.println();
                if(answer==number1-number2)
                    System.out.println("Correct");
                else
                {
                    answer=number1-number2;
                    System.out.println("Your answer is wrong. The correct answer is "+answer);
                }
                break;
            case 3:
               while(number2==0)
               {
                   number2=(int)(Math.random()*10);
               }
                System.out.print("What is "+number1+"/"+number2+"?");
                answer=putans.nextInt();
                System.out.println();
                if(answer==number1/number2)
                    System.out.println("Correct");
                else
                {
                    answer=number1/number2;
                    System.out.println("Your answer is wrong. The correct answer is "+answer);
                }
                break;
            case 4:
                System.out.print("What is "+number1+"*"+number2+"?");
                answer=putans.nextInt();
                System.out.println();
                if(answer==number1*number2)
                    System.out.println("Correct");
                else
                {
                    answer=number1*number2;
                    System.out.println("Your answer is wrong. The correct answer is "+answer);
                }
                break;
            case 5:
                break;
            default:
                System.out.println("wrong");
        }
    }
}
