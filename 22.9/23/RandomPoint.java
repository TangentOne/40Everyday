import java.util.Random;


public class RadomPoint

{

    public static void main(String[] args)

    {

        double x,y,distance;//坐标

        Random r=new Random();

        x=r.nextDouble()*2*Math.sqrt(5)-Math.sqrt(5);//生成-√5~√5的随机数

        y=r.nextDouble()*2*Math.sqrt(5-x*x)-Math.sqrt(5-x*x);//生成-√(1-x^2)~√(1-x^2)的随机数

        distance=x*x+y*y;

        System.out.println("The point is ("+x+","+y+")"+

                " and its distance to the center is "+distance);

    }


}
