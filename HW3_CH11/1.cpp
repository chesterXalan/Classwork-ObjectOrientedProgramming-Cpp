#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct data{
	string ID;
	string name;
	unsigned int midGrade;
	unsigned int finGrade;
	unsigned int clsGrade;
} student;

int main(){
	cout << "學號：3A712069，姓名：徐茂桓" << endl;
	cout << "第11章 第1題 作業" << endl << endl;
	 
	float total;
	cout << "請輸入學生的學號："; 
	getline(cin, student.ID);
	cout << "請輸入學生的姓名：";
	getline(cin, student.name);
	cout << "請輸入學生的期中考成績：";
	cin >> student.midGrade;
	cout << "請輸入學生的期末考成績：";
	cin >> student.finGrade;
	cout << "請輸入學生的平時成績：";
	cin >> student.clsGrade;
	
	total=(float)student.midGrade*0.3+(float)student.finGrade*0.3+(float)student.clsGrade*0.4;
	cout << endl << "學號：" << student.ID << "，姓名：" << student.name << " 同學的";
	cout << "學期成績為：" << total << endl;
	
	system("pause");
	return 0;
}
