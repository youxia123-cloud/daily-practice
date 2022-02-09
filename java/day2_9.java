package com.company;

//定义一个抽象类
abstract class A1{
    //定义方法，不实现方法
    abstract public void sayHello();
}
//定义一个子类，继承于抽象类
class B1 extends A1{
    @Override
    public void sayHello() {
        System.out.println("hello");
    }
}

//定义嵌套类
class DataStructure{
    //创建一个数组
    private final static int SIZE = 14;
    //创建一个int类型的数组
    private int[] arrayOfInts = new int[SIZE];
    public DataStructure(){
        //使用升序的整数值填充数组
        for(int i=0;i<SIZE;i++){
            arrayOfInts[i] = i;
        }
    }
    public void printEven(){
        //输出数组偶数索引的值
        InnerEvenIterator iterator = this.new InnerEvenIterator();
        while(iterator.hasNext()){
            System.out.println(iterator.getNext() + "");
        }
    }
    //创建嵌套类的实例

    //实现Iterator模式的内部类
    private class InnerEvenIterator{
        //从头开始遍历数组
        private int next = 0;
        public boolean hasNext(){
            //检查当前元素是否是数组中的最后一个元素
            return (next<=SIZE-1);
        }
        public int getNext(){
            //记录数组的一个偶数索引的值
            int retValue = arrayOfInts[next];
            //获得下一个偶数元素
            next += 2;
            return retValue;
        }
    }
}


//定义一个泛型类
class Box<T>{
    private T t; //代表类型
    public void add(T t){
        this.t = t;
    }
    public T get(){
        return t;
    }

}



public class day2_9 {
    public static void main(String[] args) {
        DataStructure ds = new DataStructure();
        ds.printEven();
        //执行泛型类型调用，并实例化类
        Box<Integer> integerBox = new Box<Integer>();
        integerBox.add(new Integer(10));
        Integer someInteger = integerBox.get();
        System.out.println("-------------");
        System.out.println(someInteger);
    }
}
