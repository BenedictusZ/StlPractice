//
// Created by zhuzhengxing on 2020/4/10.
//
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

//TODO deque简单操作
/*void printDeque(deque<int>& d){
	for ( deque<int>::iterator it=d.begin();it!=d.end();it++ ) {
		cout<<*it<<" ";
	}
	cout<<endl;
}
//deque初始化
void test01(){
	deque<int> d1;
	deque<int> d2(10,5);
	deque<int> d3(d2.begin(),d2.end());
	deque<int> d4(d3);

	//打印d4
	printDeque(d4);
	cout<<"-----------------"<<endl;
}
//赋值大小操作
void test02(){
	cout<<"赋值大小操作"<<endl;
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;
	d1.assign(10,5);
	d2.assign(d1.begin(),d2.end()); //迭代器指定区间赋值
	d3=d2;  //  等号赋值

	//d1.swap(d2);    //交换两个空间的元素
//	if(d1.empty()){
//		cout<<"NULL"<<endl;
//	} else
//		cout<<"NOT NULL"<<endl;
	//d1.resize(5);
	printDeque(d1);

	cout<<"-----------------"<<endl;
}
//deuqe容器插入删除
void test03(){
	deque<int> d1;
	d1.push_back(100);
	d1.push_front(200);
	d1.push_back(300);
	d1.push_back(400);
	d1.push_front(500);

	printDeque(d1);

	cout<<"-----------------"<<endl;

}
int main(){
	test01();
	test02();
	test03();
	return 0;
}*/

//TODO 打分案例

//选手类
class Player {
public:
	Player() {};

	Player(string name, int score) : mName(name), mScore(score) {}

public:
	string mName;
	int mScore;
};

//创建选手
void Create_Player(vector<Player>(&v)) {
	string nameSeed = "ABCDE";
	for ( int i = 0; i < 5; i++ ) {
		Player p;
		p.mName = "选手";
		p.mName += nameSeed[i];
		p.mScore = 0;
		v.push_back(p);
	}
}

void PrintScore(int val) {
	cout << val << " ";
}

//打分
void Set_Score(vector<Player>(&v)) {
	for ( vector<Player>::iterator it = v.begin(); it != v.end(); it++ ) {
		//当前学生进行打分
		deque<int> dScore;
		for ( int i = 0; i < 10; i++ ) {
			int score = rand() % 41 + 60;
			dScore.push_back(score);
		}
		//分数排序 默认从小到大
		sort(dScore.begin(), dScore.end());
		//去除最高最低
		dScore.pop_front();
		dScore.pop_back();
		//求平均分
		int totalScore = 0;
		for ( deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); it++ ) {
			totalScore += (*dit);
		}
		int avgScore = totalScore / dScore.size();
		//保存分数
		(*it).mScore = avgScore;
	}
}

//排序规则
bool mycompare(const Player &p1, const Player &p2) {
	return p1.mScore > p2.mScore;
}

//根据分数排序 默认从小到大 希望从大到小
void Print_Rank(vector<Player> &v) {
	//排序
	sort(v.begin(), v.end(), mycompare);
	//打印
	for ( vector<Player>::iterator it = v.begin(); it != v.end(); it++ ) {
		cout << "name:" << (*it).mName << " score:" << (*it).mScore << endl;
	}
}

int main() {
	//定义vector容器保存选手信息
	vector<Player> vPlist;
	Create_Player(vPlist);
	Set_Score(vPlist);
	Print_Rank(vPlist);

	return 0;
}














