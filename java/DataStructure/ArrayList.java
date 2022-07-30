//package com;
//顺序表的实现

public class ArrayList<E> extends AbstractList<E> {
    //底层的数组
    private Object[] arr = new Object[20];
    //数组的长度
    private int size = 0;

    @Override
    public int size() {
        return size;
    }

    @Override
    public void add(E e, int index) {
        //判断插入的位置是否合法
        if(index > size)throw new IllegalArgumentException("超出数组的长度范围！");
        //判断数组长度是否超出最大范围
        if(size >= arr.length){
            //这里的arr是一个局部的变量，不是上面的arr
            Object[] arr = new Object[this.arr.length + 50];
            for(int i=0;i<this.arr.length;i++) arr[i] = this.arr[i];
            this.arr = arr;
        }
        //将要添加的元素后面的元素后移一位
        int i = size - 1;
        while(i >= index){
            arr[i+1] = arr[i];
            i--;
        }
        //插入数据
        arr[index] = e;
        size++;
    }

    @Override
    public E remove(int index) {
        //判断删除的位置是否合法
        if(index > size-1)throw new IllegalArgumentException("超出数组的长度范围！");
        int i = index;
        E e = (E)arr[i];
        while (i<size-1){
            arr[i] = arr[i+1];
            i++;
        }
        size--;
        return e;
    }

    @Override
    public E get(int index) {

        if(index >= size) throw new IndexOutOfBoundsException("无法访问该数据！");
        return (E)arr[index];
    }
}
