//package com;

public abstract class AbstractList<E> {

    /**
    * 获取表的长度
    * @return 顺序表的长度
    * */
    public  abstract int size();

    /**
    * 添加一个元素
    * @param e 元素
    * @param index 要添加的位置
    * */
    public abstract void add(E e,int index);
    /**
    * 移除指定位置的元素
    * @param index  要移除元素的位置
    * @return 移除的元素
    * */
    public abstract E remove(int index);

    /**
     * 获取指定位置的元素
     * @param index 元素的位置
     * @return  获取的元素
     *  */
    public abstract E get(int index);
}
