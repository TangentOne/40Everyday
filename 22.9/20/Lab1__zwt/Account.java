package banking;
public class Account
{
   public Account(double value)
    {
        balance=value;
    }
    public double getBalance()
    {
        return balance;
    }

    public boolean deposit(double value)
    {
        balance+=value;
        return true;
    }

    public boolean withdraw(double value)
    {
        if(value>balance)
        {
            return false;
        }
        else
        {
            balance -= value;
        }
        return true;
    }

   private double balance=0.0;


}
