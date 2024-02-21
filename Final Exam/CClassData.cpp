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
        cout << "已清除 " << this->ClassName << " 班的記憶體資料" << endl << endl;
        system("pause");
    }
}
void CClassData::addData(void) {
	string sID;
	StudentData sData;

	if(number == 100) {
		cout << "資料已滿，無法新增資料" << endl << endl;
		return;
	}
reIV:
	cout << "請輸入學號：";
	cin >> sID;
	for(int i = 0; i < 100; i++) {
		if(lpsdata[i] != NULL) {
			if(lpsdata[i]->SID == sID) {
				cout << "已有此筆資料" << endl << endl;
				goto reIV;
			}
		}
	}
	for(int i = 0; i < 100; i++) {
        if(lpsdata[i] == NULL) {
			lpsdata[i] = new StudentData;
			sData.SClass = ClassName;
			sData.SID = sID;
			cout << "請輸入姓名：";
			cin >> sData.SName;
			*lpsdata[i] = sData;
			cout << "資料新增成功\！" << endl << endl;

			number++;
			return;
		}
	}
}
void CClassData::deleteData(void) {
    string siD;

reV:
    cout << "請輸入學號：";
	cin >> siD;
    for(int i = 0; i < 100; i++) {
        if(lpsdata[i] != NULL) {
            if(lpsdata[i]->SID == siD) {
                delete lpsdata[i];
                lpsdata[i] = NULL;
                cout << "資料刪除成功\！" << endl << endl;

                number--;
                return;
            }
        }
    }
    cout << "查無此學號" << endl << endl;
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
    ofstream ofile("A班.txt", ios::out);
    ofile << "學號　　　　" << "姓名" << endl;
    for(int i = 0; i < number; i++) {
        ofile << lpsdata[i]->SID << "　　";
        ofile << lpsdata[i]->SName << endl;
    }
    ofile.close();
    return;
}
void CClassData::outputDataB(void) {
    ofstream ofile("B班.txt", ios::out);
    ofile << "學號　　　　" << "姓名" << endl;
    for(int i = 0; i < number; i++) {
        ofile << lpsdata[i]->SID << "　　";;
        ofile << lpsdata[i]->SName << endl;
    }
    ofile.close();
    return;
}
