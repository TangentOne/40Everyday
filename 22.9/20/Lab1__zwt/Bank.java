package banking;

public class Bank
{
   public int numOfCustomers=0;
    public Customer[] customers;
    public Bank()
    {
          customers=new Customer[10];
    }
public void addCustomer(String f,String l)
{
    Customer tem=new Customer(f,l);
    customers[numOfCustomers]=tem;
    numOfCustomers++;

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
