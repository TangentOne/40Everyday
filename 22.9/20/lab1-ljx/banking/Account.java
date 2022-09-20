package banking;

public class Account {
    private double balance;

    public Account(double balance)
    {
        this.balance=balance;
    }
    public Account(){balance=0;}
    public double getBalance()
    {
        return balance;
    }
    public boolean deposit(double x)
    {
        balance+=x;
        return true;
    }
    public boolean withdraw(double x)
    {
        if(balance>=x)
        {balance-=x; return true;}
        else {return false;}

    }

    public static void main(String[] args){}

}
