#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#define SIZE 5
#define MAX 39

int main(){
	unsigned int comGen[SIZE], usrInp[SIZE], RitNum[SIZE], num=0;
	srand(time(NULL));
	cout << "5/39�ֳz�{��" << endl << endl;
	cout << "�п�J5�Ӹ��X�G" << endl;
	
	for(int i=0; i<SIZE; i++){
		cin >> usrInp[i];
		comGen[i]=0;
	}
	
	for(int i=0; i<SIZE; i++){
	regen:	
		comGen[i]=(rand())%MAX+1;
		for(int j=0; j<SIZE; j++){			
			if((comGen[i]==comGen[j])&&(i!=j))
				goto regen;
		}
	}
	
	for(unsigned int pass=1; pass<SIZE; pass++){
		for(int i=0; i<SIZE-1; i++){
			if(usrInp[i]>usrInp[i+1]){
				int hold=usrInp[i];
				usrInp[i]=usrInp[i+1];
				usrInp[i+1]=hold;
			}
		}
	}
	cout << endl << "��X���X�q�w�Ƨǡr�G" ;
	for(int i=0; i<SIZE; i++)
		cout << usrInp[i] << " ";
	
	cout << endl << "�}�����X�q���Ƨǡr�G";	
	for(int i=0; i<SIZE; i++)
		cout << comGen[i] << " ";

	for(unsigned int pass=1; pass<SIZE; pass++){
		for(int i=0; i<SIZE-1; i++){
			if(comGen[i]>comGen[i+1]){
				int hold=comGen[i];
				comGen[i]=comGen[i+1];
				comGen[i+1]=hold;
			}
		}
	}
	cout << endl << "�}�����X�q�w�Ƨǡr�G";	
	for(int i=0; i<SIZE; i++)
		cout << comGen[i] << " ";
	
	cout << endl << "�}�����G�G";
	for(int i=0; i<SIZE; i++){
		if(comGen[i]==usrInp[i]){
			RitNum[i]=usrInp[i];
			num++;
		}					
	}
	if(num!=0){
		cout << "���F" << num << "�Ӹ��X�G";
		for(int i=0; i<num; i++)
			cout << RitNum[i] << " ";
	}
	else
		cout << "������" << endl;
		
	system("pause");
	return 0;
}				
	
	
	

