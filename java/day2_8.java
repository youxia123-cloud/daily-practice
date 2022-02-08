package com.company;
//可以使用super关键字来调用超类中的构造器，当时用super()时，超类的吴灿构造器会被调用
//使用final关键字声明的方法不能被覆写
//使用final关键字声明的类不能被继承


//定义一个派生类
class AutoCar{
    //定义三个私有的字段，代表了对象的三个属性
    private String brand;
    private float exhaust;
    private int speed;
    //定义一个带参数的构造器，用来初始化字段
    public AutoCar(String brand,float exhaust,int speed){
        this.brand = brand;
        this.exhaust = exhaust;
        this.speed = speed;
    }
    //获取属性brand的值
    public String getBrand(){
        return brand;
    }
    //获取属性exhaust的值
    public float getExhaust(){
        return exhaust;
    }
    //获取属性speed的值
    public int getSpeed(){
        return speed;
    }
    //设置speed属性的值
    public void setSpeed(int newSpeed) {
        speed = newSpeed;
    }
    //测试覆写的代码
    public void printMethod(){
        System.out.println("hello");
    }
}
//定义子类
class Car extends AutoCar{
    //子类中新增加一个字段，代表载重量
    public int weight;
    public Car(int startWeight,String originalBrand,float originExhaust,int startSpeed){
        //调用超类中的构造器
        super(originalBrand,originExhaust,startSpeed);
        weight = startWeight;
    }
    //car子类中新增加一个方法
    public void setWeight(int newWeight){
        weight = newWeight;
    }
    //覆写超类中的方法
    public void printMethod(){
        super.printMethod();
        System.out.println("你好");
    }
    //Object类的获取对象类信息的方法getClass()
    public void printClassName(Object obj){
        System.out.println("对象所属的类是"+obj.getClass().getSimpleName());
    }
}
//定义一个接口
interface sayHello{
    //常量声明
    double PI = 3.1415;
    void doSomething();
}
class C implements sayHello{
    public int x;
    public int y;
    //构造器
    public C(int x,int y){
        //初始化实例
        this.x = x;
        this.y = y;
    }
    //覆写Object类中的clone方法，返回C对象的一个拷贝
    public C clone(){
        return new C(x,y);
    }
    public void doSomething(){
        System.out.println("通过接口调用！");
    }

}
//定义一个新的类，用来测试 “协变覆盖”
public class day2_8 {
    public static void main(String[] args) {
       C p1 = new C(23,35);
       C p2 = p1.clone();
       Car p3 = new Car(2,"A",3,6);
       p3.printMethod();
       p3.printClassName(p3);
       System.out.println(p3.toString());
    }
}
