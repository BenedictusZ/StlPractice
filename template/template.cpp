#include <iostream>
#include <string>

using namespace std;

//TODO 模板技术
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

//TODO 对char类型和int类型数据进行排序
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

//TODO 类内实现
/*template<class T1,class T2>
class Person{
public:
	Person(T1 name,T2 age) {
		this->mName=name;
		this->mAge=age;
	}
	void Show(){
		cout<<"Name:"<<this->mName<<" Age:"<<this->mAge<<endl;
	}
public:
	T1 mName;
	T2 mAge;
};

void test(){
	Person<string,int> p("aaaa",20);
	p.Show();
}

int main(){
	test();
	return 0;
}*/

//TODO 类模板中的友元

template<class T>
class Person;

template<class T>
void PrintPerson(Person<T> &p);

template<class T>
class Person {
public:
	friend void PrintPerson<T>(Person<T> &p);

	//重载左移运算符
	friend ostream &operator<<(ostream &os, Person<T> &p);

	void Show();

	Person(T age, T id);

private:
	T mAge;
	T mId;
};

template<class T>
Person<T>::Person(T age, T id) {
	this->mAge = age;
	this->mId = id;
}

template<class T>
void Person<T>::Show() {
	cout << "Age:" << mAge << " ID:" << mId << endl;
}

template<class T>
ostream &operator<<(ostream &os, Person<T> &p) {
	os << "Age:" << p.mAge << " ID:" << p.mId << endl;
}

template<class T>
void PrintPerson(Person<T> &p) {
	cout << "Age:" << p.mAge << " ID:" << p.mId << endl;
}

//不要滥用友元
void test() {
	Person<int> p(10, 20);
	PrintPerson(p);
}

int main() {
	test();
	return 0;
}



























