import java.util.Random;
import java.util.Scanner;

public class Mathtutor
{
    public static void main(String[] args)
    {
        int flag;
        int x,y;
        int ans;
        Random r=new Random();
        Scanner input=new Scanner(System.in);
        while(true)
        {
            System.out.println("Main menu");
            System.out.println("1: Addition");
            System.out.println("2: Subtraction");
            System.out.println("3: Multiplication");
            System.out.println("4: Division");
            System.out.println("5: Exit");
            System.out.print("Enter a choice:");
            if(input.hasNextInt())
            {
                flag=input.nextInt();//读入标识符
                if(flag==1)//加法
                {
                    x=r.nextInt(10);//生成个位数x
                    y=r.nextInt(10);//生成个位数y
                    System.out.print("What is "+x+"+"+y+"?");
                    if(input.hasNextInt())//判断输入的合法性
                    {
                        ans=input.nextInt();
                        if(x+y==ans)
                        {
                            System.out.println("Correct\r\n");
                        }
                        else
                        {
                            System.out.println("Your answer is wrong. The correct answer is "+(x+y)+"\r\n");
                        }
                    }
                    else
                    {
                        System.out.println("请输入整数\r\n");
                        String s=input.next();//将读入的值清空，避免死循环
                    }
                }
                else if(flag==2)//减法
                {
                    x=r.nextInt(10);//生成个位数x
                    y=r.nextInt(x+1);//生成个位数y,y<=x
                    System.out.print("What is "+x+"-"+y+"?");
                    if(input.hasNextInt())
                    {
                        ans=input.nextInt();
                        if(x-y==ans)
                        {
                            System.out.println("Correct\r\n");
                        }
                        else
                        {
                            System.out.println("Your answer is wrong. The correct answer is "+(x-y)+"\r\n");
                        }
                    }
                    else
                    {
                        System.out.println("请输入整数\r\n");
                        String s=input.next();//将读入的值清空，避免死循环
                    }
                }
                else if(flag==3)//乘法
                {
                    x=r.nextInt(10);//生成个位数x
                    y=r.nextInt(10);//生成个位数y
                    System.out.print("What is "+x+"*"+y+"?");
                    if(input.hasNextInt())
                    {
                        ans=input.nextInt();
                        if(x*y==ans)
                        {
                            System.out.println("Correct\r\n");
                        }
                        else
                        {
                            System.out.println("Your answer is wrong. The correct answer is "+(x*y)+"\r\n");
                        }
                    }
                    else
                    {
                        System.out.println("请输入整数\r\n");
                        String s=input.next();//将读入的值清空，避免死循环
                    }
                }
                else if(flag==4)//除法
                {
                    x=r.nextInt(10);//生成个位数x
                    y=r.nextInt(9)+1;//生成非0个位数y
                    System.out.print("What is "+x+"/"+y+"?");
                    if(input.hasNextInt())
                    {
                        ans=input.nextInt();
                        if(x/y==ans)
                        {
                            System.out.println("Correct\r\n");
                        }
                        else
                        {
                            System.out.println("Your answer is wrong. The correct answer is "+(x/y)+"\r\n");
                        }
                    }
                    else
                    {
                        System.out.println("请输入整数\r\n");
                        String s=input.next();//将读入的值清空，避免死循环
                    }
                }
                else if(flag==5)//退出
                {
                    break;
                }
                else
                {
                    System.out.println("请输入菜单中的数字\r\n");
                    String s=input.next();//将读入的值清空，避免死循环
                }
            }
            else
            {
                System.out.println("请输入整数\r\n");
                String s=input.next();//将读入的值清空，避免死循环
            }
        }

    }
}
