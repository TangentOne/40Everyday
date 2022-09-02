import java.util.Scanner;

public class demo {

    public static void hanio(int m, char A, char b, char c) {
        if (m > 1) {
            hanio(m - 1, A, c, b);
            System.out.println(A + "->" + c);
            hanio(m - 1, b, A, c);
        }
        if (m == 1) {
            System.out.println(A + "->" + c);
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int m = scan.nextInt();
        System.out.println("盘子的个数为 " + m);
        hanio(m, 'A', 'b', 'c');
        scan.close();
    }
}
