public class EmployeeTest{

    public static void main(String[] args){
        /* 使用构造器创建两个对象 */
        Employee empOne = new Employee("RUNOOB1");
        Employee empTwo = new Employee("RUNOOB2");

        // 调用这两个对象的成员方法
        empOne.empAge(1);
        empOne.empDesignation("A");
        empOne.empSalary(1000);
        empOne.printEmployee();

        empTwo.empAge(2);
        empTwo.empDesignation("B");
        empTwo.empSalary(10000);
        empTwo.printEmployee();
    }
}
