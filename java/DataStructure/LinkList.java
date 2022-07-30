//package com;
//链表的实现
public class LinkList<E> extends AbstractList<E> {

    private Node<E> head = new Node<E>(null);
    private int size;


    @Override
    public int size() {
        return size;
    }

    @Override
    public void add(E e, int index) {
        //判断插入的位置是否合法
        if(index > size)throw new IllegalArgumentException("超出数组的长度范围！");
        Node<E> node = head,temp;
        for(int i=0;i<index;i++){
            node = node.next;
        }
        temp = node.next;
        node.next = new Node<E>(e);
        node.next.next = temp;
        size++;
    }

    @Override
    public E remove(int index) {
        //判断删除的位置是否合法
        if(index > size-1)throw new IllegalArgumentException("超出数组的长度范围！");
        Node<E> node = head,temp;
        for(int i = 0; i < index; i++){
            node = node.next;
        }
        temp = node.next;
        node.next = node.next.next;
        size--;
        return temp.e;
    }

    @Override
    public E get(int index) {
        if(index >= size) throw new IndexOutOfBoundsException("无法访问该数据！");
        Node<E> node = head.next;
        for(int i=0;i<index;i++){
            node = node.next;
        }

        return node.e;
    }
    private static class Node<E>{
        private E e;
        Node<E> next;
        public Node(E e){
            this.e = e;
        }
    }
}
