//自己通用的数组类
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
    //有参构造函数（参数是容量）
    MyArray(int capacity)
    {
//        cout << "MyArray的有参构造调用"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    //拷贝构造函数
    MyArray(const MyArray& arr)
    {
//        cout <<"MyArray的拷贝构造调用"<<endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress;
        //深拷贝
        this->pAddress = new T[arr.m_Capacity];
        //将arr中的数据都拷贝过来
        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    //operator=防止浅拷贝问题
    MyArray& operator=(const MyArray& arr)
    {
//        cout <<"MyArray的operator=调用"<<endl;
        //先判断原来堆区是否有数据，如果有数据先释放
        if (this->pAddress != NULL)
        {
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i=0; i<this->m_Size;i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    //尾插法
    void Push_Back(const T &val)
    {
        //判断容量是否已经等于大小
        if (this->m_Capacity == this->m_Size)
        {
            cout<<"数组应经满了"<<endl;
            return;
        }
        this->pAddress[this->m_Size] = val; //在数组的末尾插入数据
        //更新数组的大小
        this->m_Size ++;
    }
    //尾删法
    void Pop_Back()
    {
        //让用户访问不到最后一个元素，即为尾删除
        if (this->m_Size ==0)
        {
            cout <<"数组为空"<<endl;
            return;
        }
        this->m_Size--;
    }
    //通过下标的方式访问数组中的元素
    T& operator[](int index)
    {
        return this->pAddress[index];
    }
    //返回数组的容量
    int getCapacity()
    {
        return this->m_Capacity;
    }
    //返回数组的大小
    int getSize()
    {
        return this->m_Size;
    }


    //析构函数
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
//            cout <<"MyArray的析构函数调用"<<endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }


private:
    T * pAddress;   //指针指向堆区开辟的真实的数组

    int m_Capacity; //数组的容量
    int m_Size;  //数组的元素个数





};











