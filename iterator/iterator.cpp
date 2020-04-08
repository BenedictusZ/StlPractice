//
// Created by zhuzhengxing on 2020/4/8.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//TODO 算法 负责统计某个元素的个数
/*int mycount(int* start,int* end,int val){
	int num=0;
	while (start!=end){
		if (*start==val){
			num++;
		}
		start++;
	}
	return num;
}
int main(){

	//数组容器
	int arr[]={0,7,5,4,9,2,0};

	int* pBegin=arr;//指向容器的第一个位置
	int* pEnd=&(arr[sizeof(arr)/sizeof(int)]);

	int num=mycount(pBegin,pEnd,0);
	cout<<"num: "<<num<<endl;
}*/

//TODO STL基本语法

void PrintVector(int v) {
	cout << v << " ";
	cout << endl;
}

void test() {
	vector<int> v;//定义容器，并且指定元素存放类型
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过STL提供的算法for_each算法
	//容器提供的迭代器
	//vector<int>::iterator 迭代器类型
	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//容器中可能存放基础的数据类型，也可能放自定义数据类型
	for_each(pBegin, pEnd, PrintVector);
}

//容器可以存放自定义数据类型
class Person {
public:
	Person(int age, int id) : age(age), id(id) {}

public:
	int age;
	int id;
};

void test02() {
	//创建容器，并且指定容器的元素类型是Person
	vector<Person> v;
	Person p1(10, 20), p2(30, 40), p3(50, 60);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//遍历
	for ( vector<Person>::iterator it = v.begin(); it != v.end(); it++ ) {
		cout << (*it).age << " " << (*it).id << endl;
	}
}


int main() {
	test();
	test02();
	return 0;
}