//
// Created by zhuzhengxing on 2020/4/7.
//
#include <iostream>

using namespace std;

template<class T>
class MyArray {
public:
	MyArray(int capacity) {
		this->mCapacity = capacity;
		this->mSize = 0;
		//申请内存；
		this->pAddr = new T[this->mCapacity];
	}

	MyArray(const MyArray &arr) {
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		//申请空间
		this->pAddr = new T[this->mCapacity];
		for ( int i = 0; i < this->mSize; i++ ) {
			this->pAddr[i] = arr.pAddr[i];
		}
	}

	T &operator[](int index) {
		return this->pAddr[index];
	}

	MyArray<T> &operator=(const MyArray<T> &arr) {
		if ( this->pAddr != NULL ) {
			delete[] this->pAddr;
		}
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		this->pAddr = new T[this->mCapacity];
		for ( int i = 0; i < this->mSize; i++ ) {
			this->pAddr[i] = arr.pAddr[i];
		}
		return *this;
	}

	void PushBack(T &&data) {
		//判断容器中是否有位置
		if ( this->mSize = this->mCapacity ) {
			return;
		}
		this->pAddr[this->mSize] = data;
		this->mSize++;
	}

	//void PushBack(T&& data);
	~MyArray() {
		if ( this->pAddr != NULL ) {
			delete[] this->pAddr;
		}
	}

public:
	//一共容纳的元素
	int mCapacity;
	//当前数组有多少元素
	int mSize;
	//保存数组的首地址
	T *pAddr;
};

void test() {
	MyArray<int> marry(20);
	int a = 10, b = 20, c = 30, d = 40;
	marry.PushBack(100);
	marry.PushBack(200);

	for ( int i = 0; i < marry.mSize; i++ ) {
		cout << marry[i] << " " << endl;
	}
}

int main() {
	test();
	return 0;

}
