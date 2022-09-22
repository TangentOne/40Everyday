import java.util.Random;
import java.text.DecimalFormat;
public class RadomPoint {
    public static void main(String[] args) {


        DecimalFormat df = new DecimalFormat("#.0000000000000000");
        Random random = new Random();
        double Pointx=random.nextDouble()*5;
        double Pointy=random.nextDouble()*5;
        System.out.println("The point is "+"("+df.format(Pointx)+","+df.format(Pointy)+")"+"and its distance to the center is");
        double distance=Math.sqrt(Pointx*Pointx+Pointy*Pointy);
        System.out.println(df.format(distance));

    }
}
