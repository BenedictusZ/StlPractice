//
// Created by zhuzhengxing on 2020/4/8.
//
#include <iostream>
#include <string>

using namespace std;

//TODO string��ʼ��_ƴ��_��ֵ_����_�滻_�Ƚ�_����_ɾ��

void test01() {
	cout << "Init";
	string s1;  //�����޲ι��캯��
	string s2(10, 'a');
	string s3("abcdefg");
	string s4(s3);//��������

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
	//��Ա����assign
	s1.assign("jkl");
	cout << s1 << endl;
	cout << "-------------------" << endl;
}

void test03() {
	string s1 = "abcdefhg";

	//���ء���������
	for ( int i = 0; i < s1.size(); i++ ) {
		cout << s1[i] << " ";
	}
	cout << endl;

	//at��Ա����
	for ( int i = 0; i < s1.size(); i++ ) {
		cout << s1.at(i) << " ";
	}
	cout << endl;
	//���𣺡�����ʽ���������Խ�磬ֱ��down
	//at��ʽ ����Խ�磬�׳��쳣out_of_range
	cout << "-------------------" << endl;
}

//ƴ�Ӳ���
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

//���Ҳ���
void test05() {
	cout << "find operate";
	string s = "adfghjnbg";
	int pos = s.find("fg");
	cout << "pos=" << pos << endl;

	//�������һ�γ��ֵ�λ��
	pos = s.rfind("g");
	cout << "pos=" << pos << endl;
	cout << "-------------------" << endl;
}

//string�滻
void test06() {
	cout << "�滻" << endl;
	string s = "abcdefg";
	s.replace(0, 2, "111");
	cout << s << endl;
	cout << "-------------------" << endl;
}

//string�Ƚ�
void test07() {
	cout << "compare:";
	string s1 = "abcd";
	string s2 = "abcde";

	if ( s1.compare(s2) == 0 ) {
		cout << "�ַ������" << endl;
	} else {
		cout << "�����" << endl;
	}
	cout << "-------------------" << endl;
}

//�Ӵ�����
void test08() {
	cout << "�Ӵ�������" << endl;
	string s = "abcdefg";
	string mysubstr = s.substr(1, 3);
	cout << mysubstr << endl;
	cout << "-------------------" << endl;
}

//�����ɾ��
void test09() {
	cout << "�����ɾ����" << endl;
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
