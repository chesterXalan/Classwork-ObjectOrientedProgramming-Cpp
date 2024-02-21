#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#define SIZE 4
#define MAX 10

int main(){
	unsigned int ansGen[SIZE], usrinp, usrInp[SIZE], i, j, n=1;
	srand(time(NULL));
	cout << "xAxB遊戲" << endl << endl;
	
	for(i=0; i<SIZE; i++){
	regen:	
		ansGen[i]=rand()%MAX;
		for(j=0; j<SIZE; j++){			
			if((ansGen[i]==ansGen[j])&&(i!=j))
				goto regen;
		}
	}
	for(i=0; i<SIZE; i++)
		cout << ansGen[i];
	cout << endl;
	
	while(1){
		unsigned int a=0, b=0;
		cout << endl << "第" << n++ << "次猜測，請輸入：";
		cin >> usrinp;
		usrInp[0]=usrinp/1000;
		usrInp[1]=usrinp/100%10;
		usrInp[2]=usrinp%100/10;
		usrInp[3]=usrinp%10;
		
		for(i=0; i<SIZE; i++){
			if(usrInp[i]==ansGen[i])
				a++;
			for(j=0; j<SIZE; j++){			
				if((usrInp[i]==ansGen[j])&&(i!=j))
				b++;
			}
		}
		if(a==4){
			cout << "Bingo!" << endl;
			break;
		}
		else
			cout << a << "A" << b << "B" << endl;		
	}
	
	system("pause");
	return 0;	
}
