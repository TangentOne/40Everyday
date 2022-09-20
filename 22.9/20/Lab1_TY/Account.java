package banking;

public class Account {

    public static void main(String[] args) {}

    public  Account(double init_balance){banlance=init_balance;}
    public Account(){banlance=0;}

    public double getBalance(){return banlance;}
    public boolean deposit(double amt){banlance+=amt;return true;}
    public boolean withdraw(double amt){if(banlance>=amt){banlance-=amt;return true;}else return false;}
    private double banlance;

}
