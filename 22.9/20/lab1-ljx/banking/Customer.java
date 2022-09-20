

package banking;

public class Customer extends Account{
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

    public Account getAccount()
    {
        return account;
    }
    public void setAccount(Account a)
    {
        account=a;
    }
    public static void main(String[] args){}




}
