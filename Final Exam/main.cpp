#include <iostream>
#include <cstdlib>
#include "CClassData.h"
using namespace std;

int main() {
	string choose, Class;
	CClassData ca("A");
	CClassData cb("B");

reI:
	cout << "請選擇功\能 (1)新增、(2)刪除、(0)結束程式：";
	cin >> choose;
	if(choose == "1") {
reII:
        cout << "請輸入班級 (A)或(B)：";
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
            cout << "輸入錯誤" << endl << endl;
            goto reII;
        }
	}
	else if(choose == "2") {
        if(ca.number == 0 && cb.number == 0) {
            cout << "無資料可刪除" << endl << endl;
            goto reI;
        }
reIII:
        cout << "請輸入班級 (A)或(B)：";
        cin >> Class;
        if(Class == "A") {
            if(ca.number == 0) {
                cout << "無資料可刪除" << endl << endl;
                goto reIII;
            }
            ca.deleteData();
            goto reI;
        }
        else if(Class == "B") {
            if(cb.number == 0) {
                cout << "無資料可刪除" << endl << endl;
                goto reIII;
            }
            cb.deleteData();
            goto reI;
        }
        else {
            cout << "輸入錯誤" << endl << endl;
            goto reIII;
        }
	}
    else if(choose == "0") {
        if(ca.number == 0 && cb.number == 0) {
            cout << "無資料可寫入檔案" << endl << endl;
            goto ed;
        }
        ca.sortData();
        cb.sortData();
        ca.outputDataA();
        cb.outputDataB();
        cout << "已排列並寫入檔案" << endl << endl;
    }
    else {
        cout << "輸入錯誤" << endl << endl;
        goto reI;
    }
ed:
	system("pause");
	return 0;
}
