package com.company;
//定义枚举类型
enum Day{
    星期日,星期一,星期二,星期三,星期四,星期五,星期六
}
class A{
    //声明一个静态变量
    public static int a;
    //声明一个私有的变量
    private int b = 3;
    A(){
        a++;
        System.out.println(this.b);
    }
}
public class day2_7 {
    //定义一个常量
    static final int x = 10;

    //定义枚举类型的变量
    Day day;
    //构造器
    public day2_7(Day day){
        this.day = day;
    }
    public void tellFelling(){
        //匹配每一天，并输出感受
        switch (day){
            case 星期一:System.out.println("星期一都不令人喜欢。");
            break;
            case 星期五:System.out.println("星期五比较好，有盼头。");
            break;
            case 星期六:
            case 星期日:System.out.println("周末令人愉快。");
            break;
            default:System.out.println("一周的中间一般般，不好也不坏。");
            break;
        }
    }

    public static void main(String[] args) {
        A a1 = new A();
        System.out.println(a1.a);
        A a2 = new A();
        System.out.println(a2.a);
        //创建一个新的实例对象
        day2_7 firstDay = new day2_7(Day.星期一);
        firstDay.tellFelling();
        //创建另一个新的实例对象
        day2_7 thirdDay = new day2_7(Day.星期二);
        thirdDay.tellFelling();
        //创建第三个实例对象
        day2_7 fifthDay = new day2_7(Day.星期五);
        fifthDay.tellFelling();
        //创建第四个实例对象
        day2_7 sixthDay = new day2_7(Day.星期六);
        sixthDay.tellFelling();
        //创建第五个实例对象
        day2_7 seventhDay = new day2_7(Day.星期日);
        seventhDay.tellFelling();
        System.out.println(x);
    }
}
