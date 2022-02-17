package main

import (
	"fmt"

)
type Sayer interface {
	say()
}
type dog struct {
	name string
}
type cat struct {
	name string
}
//实现接口方法
func (d dog)say(){
	fmt.Println(d.name)
	fmt.Println("汪")
}
func (c cat)say(){
	fmt.Println("喵")
}
func main() {
	var x Sayer //声明一个Sayer类型的变量x
	a := dog{"旺柴"}
	x = a
	x.say()
	//使用new关键字来创建结构体实例
	y :=new(dog)
	y.name = "旺财"
	y.say()


}
