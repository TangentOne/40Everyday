public class Account
{
    private double balance;

    public Account(double init_balance)
    {
        this.balance = init_balance;
    }

    public double getBalance()
    {
        return balance;
    }

    public boolean deposit(double amount)
    {
        this.balance+=amount;
        return true;
    }

    public boolean withdraw(double amount)
    {
        if(amount<=balance)
        {
            this.balance-=amount;
            return true;
        }
        else 
        {
            return false;
        }
    }
}

public class Customer
{
    private String firstName;
    private String lastName;
    private Account account;

    public Customer(String f,String l)
    {
        firstName=f;
        lastName=l;
    }

    public String getFirstName()
    {
        return firstName;
    }
    public String getLastName()
    {
        return lastName;
    }

    public void setAccount(Account acc) {
        this.account = acc;
    }

    public Account getAccount() {
        return account;
    }
}

import banking.*;
public class Bank
{
    private Customer[] customers;
    private int numOfCustomers =0;
    public Bank()
    {
        customers=new Customer[6];
    }
     public void addCustomer(String f,String l)
     {
         Customer temp=new Customer(f,l);
         customers[numOfCustomers]=temp;
         ++numOfCustomers;
     }


    public int getNumOfCustomers()
     {
         return numOfCustomers;
     }

     public Customer getCustomer(int index)
     {
         return customers[index];
     }
}

