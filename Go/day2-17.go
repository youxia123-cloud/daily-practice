package main
import "fmt"
//切片是对数组的抽象
//go语言中数组的长度不可改变
//go语言中map是一种无序的键值对集合
func main() {
	//创建切片
	var numbers[] int =[]int{1,2,3,4,5,6}
	fmt.Println(numbers)
	//通过索引来创建切片
	numbers1 := numbers[1:2]
	fmt.Println(numbers1)
	fmt.Println(numbers[:3]) //默认从第一个元素开始，包含第一个元素
	fmt.Println(numbers[1:]) //默认从最后一个元素开始，包含最后一个元素
	//使用append方法向切片末尾追加元素
	numbers2 := append(numbers1,0)
	fmt.Println(numbers2)
	fmt.Println(numbers)
	numbers3 := numbers[:3]
	fmt.Println(numbers3)
	copy(numbers3,numbers2)
	fmt.Println(numbers3)

}
