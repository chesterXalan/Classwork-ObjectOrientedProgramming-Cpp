#include <iostream>
#include <cstdlib>
#include "CClassData.h"
using namespace std;

int main() {
	string choose, Class;
	CClassData ca("A");
	CClassData cb("B");

reI:
	cout << "�п�ܥ\\�� (1)�s�W�B(2)�R���B(0)�����{���G";
	cin >> choose;
	if(choose == "1") {
reII:
        cout << "�п�J�Z�� (A)��(B)�G";
        cin >> Class;
        if(Class == "A") {
            ca.addData();
            goto reI;
        }
        else if(Class == "B") {
            cb.addData();
            goto reI;
        }
        else {
            cout << "��J���~" << endl << endl;
            goto reII;
        }
	}
	else if(choose == "2") {
        if(ca.number == 0 && cb.number == 0) {
            cout << "�L��ƥi�R��" << endl << endl;
            goto reI;
        }
reIII:
        cout << "�п�J�Z�� (A)��(B)�G";
        cin >> Class;
        if(Class == "A") {
            if(ca.number == 0) {
                cout << "�L��ƥi�R��" << endl << endl;
                goto reIII;
            }
            ca.deleteData();
            goto reI;
        }
        else if(Class == "B") {
            if(cb.number == 0) {
                cout << "�L��ƥi�R��" << endl << endl;
                goto reIII;
            }
            cb.deleteData();
            goto reI;
        }
        else {
            cout << "��J���~" << endl << endl;
            goto reIII;
        }
	}
    else if(choose == "0") {
        if(ca.number == 0 && cb.number == 0) {
            cout << "�L��ƥi�g�J�ɮ�" << endl << endl;
            goto ed;
        }
        ca.sortData();
        cb.sortData();
        ca.outputDataA();
        cb.outputDataB();
        cout << "�w�ƦC�üg�J�ɮ�" << endl << endl;
    }
    else {
        cout << "��J���~" << endl << endl;
        goto reI;
    }
ed:
	system("pause");
	return 0;
}
