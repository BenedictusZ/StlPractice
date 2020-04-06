#include <iostream>
using namespace std;

//模板技术
/*
template<class T>
void MySwap(T& a,T& b){
	T temp=a;
	a=b;
	b=temp;
}
void test01(){
	int a=10;
	int b=20;
	//1、自动类型推导
	MySwap(a,b);
	cout<<a<<b<<endl;
}
int main() {
	test01();
	return 0;
}*/

//对char类型和int类型数据进行排序
//打印函数
/*template<class T>
void PrintArray(T* arr,int len){
	for ( int i = 0; i < len; i++ ) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//排序
template<class T>
void MySort(T* arr,int len){
	for ( int i = 0; i < len; i++ ) {
		for ( int j = i+1; j < len; j++ ) {
			//从大到小排序
			if (arr[i]<arr[j]){
				T temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main(){
	//数组
	int arr[]={2,6,1,8,9,2};
	//数组长度
	int len=sizeof(arr)/sizeof(int );

	PrintArray(arr,len);
	MySort(arr,len);
	PrintArray(arr,len);

	char charr[]={'a','c','b','p','t'};
	len=sizeof(charr)/sizeof(char);
	PrintArray(charr,len);
	MySort(charr,len);
	PrintArray(charr,len);
	return 0;
}*/


template<class T>
class Animal{
public:
	void Jiao(){
		cout<<mAge<<"岁猫在叫！"<<endl;
	}
public:
	T mAge;
};

template<class T>
class Cat: public Animal<int>{

};

int main(){
	Cat<int> cat;
	return 0;
}
















