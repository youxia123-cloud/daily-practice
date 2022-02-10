package com.company;
import java.util.*;
public class day2_10 {
    public static void search(String[] args){
        //声明不能重复的hashSet对象
        Set<String> s = new HashSet<String>();
        //遍历命令行字符串
        for (String a : args) {
            if (!s.add(a)) {
                System.out.println("重复的元素：" + a);
            }
        }
        System.out.println(s.size() + "个单独的单词：" + s);
    }
    //使用HashSet进行单词统计
    public static void wordCounts(String[] args){
        //声明HashSet实例对象，使用泛型版本
        Set<String> uniques = new HashSet<String>();
        //声明HashSet实例对象，使用泛型版本
        Set<String> dups = new HashSet<String>();
        for(String a :args){
            //遍历参数字符串数组
            if(!uniques.add(a)){
                //如果a存在，将a添加到dups集合中
                dups.add(a);
            }
        }
        //破坏性的集合差
        uniques.removeAll(dups);//从uniques中移除所有具有重复的单词
        System.out.println("不重复的单词：" +uniques);
        System.out.println("重复的单词：" + dups);
    }
    public static void main(String[] args) {
        String[] a = {"i","left","new","i"};
        search(a);
        String[] b ={"i","came","i","saw","i","left"};
        wordCounts(b);
    }
}
