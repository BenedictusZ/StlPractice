//
// Created by zhuzhengxing on 2020/4/8.
//
#include <iostream>
#include <string>

using namespace std;

//TODO string初始化_拼接_赋值_查找_替换_比较_插入_删除

void test01() {
	cout << "Init";
	string s1;  //调用无参构造函数
	string s2(10, 'a');
	string s3("abcdefg");
	string s4(s3);//拷贝构造

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << "-------------------" << endl;
}

void test02() {
	cout << "replace";
	string s1;
	string s2("apppp");
	s1 = "asgdfh";
	cout << s1 << endl;
	s1 = s2;
	cout << s1 << endl;
	s1 = 'a';
	cout << s1 << endl;
	//成员方法assign
	s1.assign("jkl");
	cout << s1 << endl;
	cout << "-------------------" << endl;
}

void test03() {
	string s1 = "abcdefhg";

	//重载【】操作符
	for ( int i = 0; i < s1.size(); i++ ) {
		cout << s1[i] << " ";
	}
	cout << endl;

	//at成员函数
	for ( int i = 0; i < s1.size(); i++ ) {
		cout << s1.at(i) << " ";
	}
	cout << endl;
	//区别：【】方式，如果访问越界，直接down
	//at方式 访问越界，抛出异常out_of_range
	cout << "-------------------" << endl;
}

//拼接操作
void test04() {
	string s = "adcd";
	string s2 = "adcd";
	s += "abcd0";
	s += s2;
	cout << s2 << endl;

	string s3 = "22222";
	s2.append(s3);
	cout << s2 << endl;

	string s4 = s3 + s2;
	cout << s4 << endl;
	cout << "-------------------" << endl;
}

//查找操作
void test05() {
	cout << "find operate";
	string s = "adfghjnbg";
	int pos = s.find("fg");
	cout << "pos=" << pos << endl;

	//查找最后一次出现的位置
	pos = s.rfind("g");
	cout << "pos=" << pos << endl;
	cout << "-------------------" << endl;
}

//string替换
void test06() {
	cout << "替换" << endl;
	string s = "abcdefg";
	s.replace(0, 2, "111");
	cout << s << endl;
	cout << "-------------------" << endl;
}

//string比较
void test07() {
	cout << "compare:";
	string s1 = "abcd";
	string s2 = "abcde";

	if ( s1.compare(s2) == 0 ) {
		cout << "字符串相等" << endl;
	} else {
		cout << "不相等" << endl;
	}
	cout << "-------------------" << endl;
}

//子串操作
void test08() {
	cout << "子串操作：" << endl;
	string s = "abcdefg";
	string mysubstr = s.substr(1, 3);
	cout << mysubstr << endl;
	cout << "-------------------" << endl;
}

//插入和删除
void test09() {
	cout << "插入和删除：" << endl;
	string s = "abcdefg";
	s.insert(3, "111");
	cout << s << endl;
	s.erase(0, 2);
	cout << s << endl;
	cout << "-------------------" << endl;
}

int main() {
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	return 0;
}
