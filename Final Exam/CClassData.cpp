#include "CClassData.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

CClassData::CClassData(string Class):ClassName(Class) {
	number = 0;
	for(int i = 0; i < 100; i++)
		lpsdata[i] = NULL;
}
CClassData::~CClassData() {
    if(number != 0) {
        for(int i = 0; i < number; i++)
        	delete lpsdata[i];
        cout << "�w�M�� " << this->ClassName << " �Z���O������" << endl << endl;
        system("pause");
    }
}
void CClassData::addData(void) {
	string sID;
	StudentData sData;

	if(number == 100) {
		cout << "��Ƥw���A�L�k�s�W���" << endl << endl;
		return;
	}
reIV:
	cout << "�п�J�Ǹ��G";
	cin >> sID;
	for(int i = 0; i < 100; i++) {
		if(lpsdata[i] != NULL) {
			if(lpsdata[i]->SID == sID) {
				cout << "�w���������" << endl << endl;
				goto reIV;
			}
		}
	}
	for(int i = 0; i < 100; i++) {
        if(lpsdata[i] == NULL) {
			lpsdata[i] = new StudentData;
			sData.SClass = ClassName;
			sData.SID = sID;
			cout << "�п�J�m�W�G";
			cin >> sData.SName;
			*lpsdata[i] = sData;
			cout << "��Ʒs�W���\\�I" << endl << endl;

			number++;
			return;
		}
	}
}
void CClassData::deleteData(void) {
    string siD;

reV:
    cout << "�п�J�Ǹ��G";
	cin >> siD;
    for(int i = 0; i < 100; i++) {
        if(lpsdata[i] != NULL) {
            if(lpsdata[i]->SID == siD) {
                delete lpsdata[i];
                lpsdata[i] = NULL;
                cout << "��ƧR�����\\�I" << endl << endl;

                number--;
                return;
            }
        }
    }
    cout << "�d�L���Ǹ�" << endl << endl;
    goto reV;
}
void CClassData::sortData(void) {
    StudentData *temp;

    for(int i = 1; i < 100; i++) {
	    for(int j = 0; j < 100 - 1; j++) {
            if(lpsdata[j] == NULL){
                temp = lpsdata[j];
                lpsdata[j] = lpsdata[j + 1];
                lpsdata[j + 1] = temp;
            }
	    }
	}
	for(int i = 1; i < number; i++) {
	    for(int j = 0; j < number - 1; j++) {
            if(lpsdata[j]->SID > lpsdata[j + 1]->SID) {
                temp = lpsdata[j];
                lpsdata[j] = lpsdata[j + 1];
                lpsdata[j + 1] = temp;
	        }
	    }
	}
	return;
}
void CClassData::outputDataA(void) {
    ofstream ofile("A�Z.txt", ios::out);
    ofile << "�Ǹ��@�@�@�@" << "�m�W" << endl;
    for(int i = 0; i < number; i++) {
        ofile << lpsdata[i]->SID << "�@�@";
        ofile << lpsdata[i]->SName << endl;
    }
    ofile.close();
    return;
}
void CClassData::outputDataB(void) {
    ofstream ofile("B�Z.txt", ios::out);
    ofile << "�Ǹ��@�@�@�@" << "�m�W" << endl;
    for(int i = 0; i < number; i++) {
        ofile << lpsdata[i]->SID << "�@�@";;
        ofile << lpsdata[i]->SName << endl;
    }
    ofile.close();
    return;
}
