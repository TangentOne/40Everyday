package banking;

public class Bank {
    Customer arr[];
    int k=0;

    public Bank(){
        Customer arr[]=new Customer[10];
    }
    public void addCustomer(String f,String l){
        arr[k]=new Customer(f,l);
        k++;
    }
    public int getNumOfCustomers(){return k;}
    public Customer getCustomer(int index){return arr[index];}
    public static void main(String[] args){}

}
