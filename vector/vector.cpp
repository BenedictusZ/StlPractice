//
// Created by zhuzhengxing on 2020/4/8.
//
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v) {
	for ( vector<int>::iterator it = v.begin(); it != v.end(); it++ ) {
		cout << *it << " ";
	}
	cout << endl;
}

//初始化
void test01() {
	vector<int> v1;

	int arr[] = {10, 20, 30, 40};
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);

	printVector(v2);
	printVector(v3);
	printVector(v4);

	v2.assign(v1.begin(), v1.end());
	v3 = v2;
	v4.swap(v1);
	cout << "----------------------" << endl;
}

//大小操作
void test03() {
	int arr[] = {100, 200, 300, 400};
	vector<int> v4(arr, arr + sizeof(arr) / sizeof(int));
	cout << "size: " << v4.size() << endl;
	if ( v4.empty()) {
		cout << "NULL" << endl;
	} else {
		cout << "NOT NULL" << endl;
	}

	v4.resize(2);
	printVector(v4);
	v4.resize(6);
	printVector(v4);
	v4.resize(6);
	printVector(v4);

	for ( int i = 0; i < 10000; i++ ) {
		v4.push_back(i);
	}
	cout << "size:" << v4.size() << endl;
	cout << "capacity:" << v4.capacity() << endl;//容量
	cout << "----------------------" << endl;
}

//vector存取数据
void test04() {
	int arr1[] = {100, 200, 300, 400};
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));

	for ( int i = 0; i < v4.size(); i++ ) {
		cout << v4[i] << " ";
	}
	cout << endl;

	for ( int i = 0; i < v4.size(); i++ ) {
		cout << v4.at(i) << " ";
	}
	cout << endl;
	//区别：at()抛异常，【】不抛异常
	cout << "front:" << v4.front() << endl;
	cout << "front:" << v4.back() << endl;
	cout << "----------------------" << endl;
}

//c插入和删除
void test05() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	//头插法
	v.insert(v.begin(), 30);
	v.insert(v.end(), 40);

	v.insert(v.begin() + 2, 100);//vector支持随机访问
	//支持数组下标，一般支持随机访问
	//迭代器可以直接+2,+3,-2,-5操作

	printVector(v);

	//删除
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin() + 1, v.end());
	v.clear();
	cout << "size:" << v.size() << endl;
	cout << "----------------------" << endl;
}

//巧用swap缩减空间
void test06() {
	//vector添加元素 自动增长
	vector<int> v;
	for ( int i = 0; i < 100000; i++ ) {
		v.push_back(i);
	}
	cout << "size:" << v.size() << endl;
	cout << "capacity:    " << v.capacity() << endl;

	v.resize(10);
	cout << "change size:" << endl;
	cout << "size:" << v.size() << endl;
	cout << "capacity:    " << v.capacity() << endl;

	//收缩空间
	cout << "******" << endl;
	vector<int>(v).swap(v);
	cout << "size:" << v.size() << endl;
	cout << "----------------------" << endl;
}

void test07() {
	//reserve预留空间 resize区别
	int num = 0;
	int *address = NULL;
	vector<int> v;
	v.reserve(100000);
	for ( int i = 0; i < 100000; i++ ) {
		v.push_back(i);
		if ( address != &(v[0])) {
			address = &(v[0]);
			num++;
		}
	}
	cout << "num:" << num << endl;

	cout << "----------------------" << endl;
}

int main() {
	test01();
	test03();
	test04();
	test05();
	test06();
	test07();
	return 0;
}