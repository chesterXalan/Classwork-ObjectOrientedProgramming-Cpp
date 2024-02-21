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
		cout << "��Ƥw���A�L�k�s�W��ơI" << endl << endl;
		return;
	}
	for(int i = 0; i < MaxVal; i++){
		if(lpsdata[i] != NULL){
			if(lpsdata[i]->sID == sid){
				cout << "�w��������ơI" << endl << endl;
				return;
			}
		}
		else{
			add.sID = sid;
			lpsdata[i] = new SDATA;
			cout << "�п�J�Z�šG";
			cin >> add.sCLASS;
			cout << "�п�J�m�W�G";
			cin >> add.sNAME;
			*lpsdata[i] = add;
			cout << "��Ʒs�W���\\�I" << endl << endl;
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
	cout << "�d�L����ơI" << endl << endl;
	return;

conti:
	mod.sID = Sid;
	cout << "�п�J�m�W�G";
	cin >> mod.sNAME;
reE:
	cout << "�O�_�n�ק�Z�šH (1)�O / (0)�_�G";
	cin >> choose;

	switch(choose){
		case 1:
			cout << "�п�J�Z�šG";
			cin >> mod.sCLASS;
			modify(mod.sID, mod.sNAME, mod.sCLASS);
			return;
		case 0:
			modify(mod.sID, mod.sNAME);
		 	return;
        default:
			cout << "��J���~�I" << endl << endl;
			goto reE;
	}
}
void CDATA::modify(string Sid, string Sname){
	for(int i = 0; i < MaxVal; i++){
		if(lpsdata[i]->sID == Sid){
			lpsdata[i]->sNAME = Sname;
			cout << "��ƭק令�\\�I" << endl << endl;
			return;
		}
	}
}
void CDATA::modify(string Sid, string Sname, string Sclass){
	for(int i = 0; i < MaxVal; i++){
		if(lpsdata[i]->sID == Sid){
			lpsdata[i]->sNAME = Sname;
			lpsdata[i]->sCLASS = Sclass;
			cout << "��ƭק令�\\�I" << endl << endl;
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
				cout << "��ƧR�����\\�I" << endl << endl;
				number--;
				return;
			}
		}
	}
	cout << "�d�L����ơI" << endl << endl;
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
	cout << "�@�� " << number << " �����" << endl;
    printf("%-12s%-12s%-12s\n", "�Ǹ�", "�Z��", "�m�W");

	for(int i = 0; i < number; i++){
        cout << lpsdata[i]->sID << "�@�@";
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
	cout << "�п�ܥ\\�� (1)�s�W�B(2)�ק�B(3)�R���B(0)�����{���G";
	cin >> choose;
	switch(choose){
		case 1:

			cout << "�п�J�Ǹ��G";
			cin >> temp.sID;
			edit.addData(temp.sID);
			goto reS;
		case 2:
		    if(edit.number == 0){
                cout << "�L��ƥi�ק�" << endl << endl;
                goto reS;
	        }
			cout << "�п�J�Ǹ��G";
			cin >> temp.sID;
			edit.modifyData(temp.sID);
			goto reS;
		case 3:
		    if(edit.number == 0){
                cout << "�L��ƥi�R��" << endl << endl;
                goto reS;
            }
			cout << "�п�J�Ǹ��G";
			cin >> temp.sID;
			edit.deleteData(temp.sID);
			goto reS;
		case 0:
		    if(edit.number == 0){
		        cout << "�L��ƥi��X" << endl << endl;
		        break;
		    }
			edit.printOut();
			break;
        default:
			cout << "��J���~�I" << endl << endl;
			goto reS;
	}
	system("pause");
	return 0;
}
