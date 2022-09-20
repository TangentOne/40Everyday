package banking;

public class Bank {
    public Bank(){}
    public void  addCustomer(String f,String l){customer[customerCnt]=new Customer(f,l);customerCnt++;}
    public int getNumOfCustomers(){return customerCnt;}
    public Customer getCustomer(int index){return customer[index];}
    private Customer customer[]=new Customer[1000];
    private int customerCnt=0;
}
