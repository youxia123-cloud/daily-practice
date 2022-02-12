package com.company;
//创建一个简单的图形界面程序
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class day2_12 {
    //创建一个GUI界面并显示
    private static void createAndShowGUI(){
        //创建并设置程序运行窗体
        JFrame frame = new JFrame("hello World");  //创建带有标题的窗体
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  //设置关闭窗体时自动关闭窗口
        //创建一个菜单栏，将其背景甚至为绿色
        JMenuBar greenMenuBar = new JMenuBar();
        //将菜单栏背景设置为不透明
        greenMenuBar.setBackground(new Color(172,231,218));
        //设置菜单栏的首选大小
        greenMenuBar.setPreferredSize(new Dimension(200,50));

        //添加“ hello标签”
        JLabel label = new JLabel("hello"); //创建带有文字内容的标签对象
        //将标签背景设置为不透明
        label.setOpaque(true);
        //设置标签的背景颜色
        label.setBackground(new Color(113,128,250));
        //设置标签的首选大小
        label.setPreferredSize(new Dimension(200,180));
        //设置菜单栏并将标签添加到内容面板中
        frame.setJMenuBar(greenMenuBar);
        //向窗体的内容面板添加标签
        frame.getContentPane().add(label,BorderLayout.CENTER);
        //显示窗体
        //所有窗体以首件大小显示
        frame.pack();
        //显示窗体
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        //为事件分发线程预定一个工作
        //创建并显示本程序的GUI
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                //创建窗体并显示
                createAndShowGUI();
            }
        });
    }
}
