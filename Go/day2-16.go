package main

import (
	"fmt"
)
//函数闭包的实例
func getValue() func() int{
	i := 0
	return func() int{
		i+=1
		return i
	}
}
//声明结构体
type Books struct {
	title string
	author string
	subject string
	book_id int
}

func main() {

	nextNumber := getValue()
	fmt.Println(nextNumber())
	fmt.Println(nextNumber())
	fmt.Println(nextNumber())
	nextNumber1 :=getValue()
	fmt.Println(nextNumber1())
	fmt.Println(nextNumber1())
	fmt.Println(nextNumber1())
	fmt.Println("----------------")
	var i,j int
	var arr1 [10]int
	//定义数组
	arr :=[...]int{1,2,3,4,5}
	//声明数组并初始化
	for i = 0;i < 10;i++{
		arr1[i] = i + 5
	}
	//输出数组的元素
	for j = 0;j < 10;j++{
		fmt.Println("数组元素",arr1[j])
	}
	fmt.Println(arr[1])

	//声明指针
	var a int = 15
	var ip *int
	//声明空指针
	var b *int = nil
	ip = &a
	fmt.Println(ip)
	fmt.Println(b)
	//创建一个新的结构体
	fmt.Println(Books{"Go语言教程","XXX","教育资料",123456})
	var Books1 Books
	Books1.title = "Go语言"
	fmt.Println(Books1)

}
