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
	cout << "�Ǹ��G3A712069�A�m�W�G�}�Z��" << endl;
	cout << "��11�� ��1�D �@�~" << endl << endl;
	 
	float total;
	cout << "�п�J�ǥͪ��Ǹ��G"; 
	getline(cin, student.ID);
	cout << "�п�J�ǥͪ��m�W�G";
	getline(cin, student.name);
	cout << "�п�J�ǥͪ������Ҧ��Z�G";
	cin >> student.midGrade;
	cout << "�п�J�ǥͪ������Ҧ��Z�G";
	cin >> student.finGrade;
	cout << "�п�J�ǥͪ����ɦ��Z�G";
	cin >> student.clsGrade;
	
	total=(float)student.midGrade*0.3+(float)student.finGrade*0.3+(float)student.clsGrade*0.4;
	cout << endl << "�Ǹ��G" << student.ID << "�A�m�W�G" << student.name << " �P�Ǫ�";
	cout << "�Ǵ����Z���G" << total << endl;
	
	system("pause");
	return 0;
}
