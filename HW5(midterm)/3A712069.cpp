#include <iostream>
#include <cstdlib>
#include <string>
#define MaxVal 1000
using namespace std;

struct SDATA{
	string sID, sNAME, sCLASS;
};
class CDATA{
public:
	SDATA *lpsdata[MaxVal];
	int number;
	void Init(void);
	void addData(string sid);
	void modifyData(string sId);
	void deleteData(string Sid);
	void modify(string Sid, string Sname);
	void modify(string Sid, string Sname, string Sclass);
	void printOut(void);
};

void CDATA::Init(void){
	for(int i = 0; i < MaxVal; i++)
		lpsdata[i] = NULL;
    number = 0;
	return;
}
void CDATA::addData(string sid){
	SDATA add;

	if(number == MaxVal){
		cout << "資料已滿，無法新增資料！" << endl << endl;
		return;
	}
	for(int i = 0; i < MaxVal; i++){
		if(lpsdata[i] != NULL){
			if(lpsdata[i]->sID == sid){
				cout << "已有此筆資料！" << endl << endl;
				return;
			}
		}
		else{
			add.sID = sid;
			lpsdata[i] = new SDATA;
			cout << "請輸入班級：";
			cin >> add.sCLASS;
			cout << "請輸入姓名：";
			cin >> add.sNAME;
			*lpsdata[i] = add;
			cout << "資料新增成功\！" << endl << endl;
			break;
		}
	}
	number++;
	return;
}
void CDATA::modifyData(string Sid){
	SDATA mod;
	int choose;

	for(int i = 0; i < MaxVal; i++){
		if(lpsdata[i] != NULL){
			if(lpsdata[i]->sID == Sid)
				goto conti;
		}
	}
	cout << "查無此資料！" << endl << endl;
	return;

conti:
	mod.sID = Sid;
	cout << "請輸入姓名：";
	cin >> mod.sNAME;
reE:
	cout << "是否要修改班級？ (1)是 / (0)否：";
	cin >> choose;

	switch(choose){
		case 1:
			cout << "請輸入班級：";
			cin >> mod.sCLASS;
			modify(mod.sID, mod.sNAME, mod.sCLASS);
			return;
		case 0:
			modify(mod.sID, mod.sNAME);
		 	return;
        default:
			cout << "輸入錯誤！" << endl << endl;
			goto reE;
	}
}
void CDATA::modify(string Sid, string Sname){
	for(int i = 0; i < MaxVal; i++){
		if(lpsdata[i]->sID == Sid){
			lpsdata[i]->sNAME = Sname;
			cout << "資料修改成功\！" << endl << endl;
			return;
		}
	}
}
void CDATA::modify(string Sid, string Sname, string Sclass){
	for(int i = 0; i < MaxVal; i++){
		if(lpsdata[i]->sID == Sid){
			lpsdata[i]->sNAME = Sname;
			lpsdata[i]->sCLASS = Sclass;
			cout << "資料修改成功\！" << endl << endl;
			return;
		}
	}
}
void CDATA::deleteData(string sId){
	for(int i = 0; i < MaxVal; i++){
		if(lpsdata[i] != NULL){
			if(lpsdata[i]->sID == sId){
				delete lpsdata[i];
				lpsdata[i] = NULL;
				cout << "資料刪除成功\！" << endl << endl;
				number--;
				return;
			}
		}
	}
	cout << "查無此資料！" << endl << endl;
	return;
}
void CDATA::printOut(void){
	SDATA *temp;

	for(int i = 1; i < MaxVal; i++){
	    for(int j = 0; j < MaxVal-1; j++){
            if(lpsdata[j] == NULL){
                temp = lpsdata[j];
                lpsdata[j] = lpsdata[j+1];
                lpsdata[j+1] = temp;
            }
	    }
	}
	for(int i = 1; i < number; i++){
	    for(int j = 0; j < number-1; j++){
            if(lpsdata[j]->sID > lpsdata[j+1]->sID){
                temp = lpsdata[j];
                lpsdata[j] = lpsdata[j+1];
                lpsdata[j+1] = temp;
	        }
	    }
	}
	cout << "共有 " << number << " 筆資料" << endl;
    printf("%-12s%-12s%-12s\n", "學號", "班級", "姓名");

	for(int i = 0; i < number; i++){
        cout << lpsdata[i]->sID << "　　";
        cout << lpsdata[i]->sCLASS << '\t';
        cout << lpsdata[i]->sNAME << endl;
	}
	cout << endl;
	return;
}

int main(){
	SDATA temp;
	CDATA edit;
	int choose;
	edit.Init();

reS:
	cout << "請選擇功\能 (1)新增、(2)修改、(3)刪除、(0)結束程式：";
	cin >> choose;
	switch(choose){
		case 1:

			cout << "請輸入學號：";
			cin >> temp.sID;
			edit.addData(temp.sID);
			goto reS;
		case 2:
		    if(edit.number == 0){
                cout << "無資料可修改" << endl << endl;
                goto reS;
	        }
			cout << "請輸入學號：";
			cin >> temp.sID;
			edit.modifyData(temp.sID);
			goto reS;
		case 3:
		    if(edit.number == 0){
                cout << "無資料可刪除" << endl << endl;
                goto reS;
            }
			cout << "請輸入學號：";
			cin >> temp.sID;
			edit.deleteData(temp.sID);
			goto reS;
		case 0:
		    if(edit.number == 0){
		        cout << "無資料可輸出" << endl << endl;
		        break;
		    }
			edit.printOut();
			break;
        default:
			cout << "輸入錯誤！" << endl << endl;
			goto reS;
	}
	system("pause");
	return 0;
}
