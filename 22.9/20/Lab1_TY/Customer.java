package banking;

public class Customer  {

    public Customer(String f ,String l) {firstName=f;lastName=l;}
    public Customer() {firstName="";lastName="";}
    public String getFirstName(){return firstName;}
    public String getLastName(){return lastName;}
    public Account getAccount(){return account;}
    public void setAccount(Account acct){account=acct;}

    private String firstName;
    private String lastName;
    private Account account;


}
