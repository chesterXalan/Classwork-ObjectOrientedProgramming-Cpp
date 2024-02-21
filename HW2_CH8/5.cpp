#include <iostream>
#include <cstdlib>
using namespace std;

void BestSeller(int, int, int);
void BestProduct(int, int, int, int, int);
int main(){
	cout << "�Ǹ��G3A712069�A�m�W�G�}�Z��" << endl;
	cout << "��8�� ��5�D �@�~" << endl << endl;
	
	int seller1=0, seller2=0, seller3=0;
	int productA=0, productB=0, productC=0, productD=0, productE=0;
	int productsPrice[5]={
		12, 16, 10, 14, 15};
	int productsTable[3][5]={
		33, 32, 56, 45, 33,
		77, 33, 68, 45, 23,
		43, 55, 43, 67, 65};

	for(int i=0; i<3; i++){
		for(int j=0; j<5; j++){
			switch(i){
				case 0:
					seller1+=productsPrice[j]*productsTable[i][j];
					break;					
				case 1:
					seller2+=productsPrice[j]*productsTable[i][j];
					break;
				case 2:
					seller3+=productsPrice[j]*productsTable[i][j];
					break;
			}			
		}
	}
	cout << "(a) �C�@�ӾP������P���`���B�G" << endl;
	cout << "�@�@�P���1: " << seller1 << endl;
	cout << "�@�@�P���2: " << seller2 << endl;
	cout << "�@�@�P���3: " << seller3 << endl << endl;
	
	for(int i=0; i<5; i++){
		for(int j=0; j<3; j++){
			switch(i){
				case 0:
					productA+=productsPrice[i]*productsTable[j][i];
					break;
				case 1:
					productB+=productsPrice[i]*productsTable[j][i];
					break;
				case 2:
					productC+=productsPrice[i]*productsTable[j][i];
					break;
				case 3:
					productD+=productsPrice[i]*productsTable[j][i];
					break;
				case 4:
					productE+=productsPrice[i]*productsTable[j][i];
					break;
			}
		}
	}
	cout << "(b) �C�@�����~���P���`���B�G" << endl;
	cout << "�@�@���~A: " << productA << endl;
	cout << "�@�@���~B: " << productB << endl;
	cout << "�@�@���~C: " << productC << endl;
	cout << "�@�@���~D: " << productD << endl;
	cout << "�@�@���~E: " << productE << endl << endl;
	
	BestSeller(seller1, seller2, seller3);
	BestProduct(productA, productB, productC, productD, productE);
	
	system("pause");
	return 0;
}
void BestSeller(int s1, int s2, int s3){
	cout << "(c) ���̦n�~�Z���P����G"; 
	if(s1>s2 && s1>s3)
		cout << "�P���1" << endl << endl;
	else if(s2>s1 && s2>s3)
		cout << "�P���2" << endl << endl;
	else
		cout << "�P���3" << endl << endl;
	return;
}
void BestProduct(int pA, int pB, int pC, int pD, int pE){
	cout << "(d) �P���`���B���̦h�����~�G";
	if(pA>pB && pA>pC && pA>pD && pA>pE)
		cout << "���~A" << endl;
	else if(pB>pA && pB>pC && pB>pD && pB>pE)
		cout << "���~B" << endl;
	else if(pC>pA && pC>pB && pC>pD && pC>pE)
		cout << "���~C" << endl;
	else if(pD>pA && pD>pB && pD>pC && pD>pE)
		cout << "���~D" << endl;
	else
		cout << "���~E" << endl;
	return;
}
