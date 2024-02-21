#include <iostream>
#include <cstdlib>
using namespace std;

void BestSeller(int, int, int);
void BestProduct(int, int, int, int, int);
int main(){
	cout << "學號：3A712069，姓名：徐茂桓" << endl;
	cout << "第8章 第5題 作業" << endl << endl;
	
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
	cout << "(a) 每一個銷售員的銷售總金額：" << endl;
	cout << "　　銷售員1: " << seller1 << endl;
	cout << "　　銷售員2: " << seller2 << endl;
	cout << "　　銷售員3: " << seller3 << endl << endl;
	
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
	cout << "(b) 每一項產品的銷售總金額：" << endl;
	cout << "　　產品A: " << productA << endl;
	cout << "　　產品B: " << productB << endl;
	cout << "　　產品C: " << productC << endl;
	cout << "　　產品D: " << productD << endl;
	cout << "　　產品E: " << productE << endl << endl;
	
	BestSeller(seller1, seller2, seller3);
	BestProduct(productA, productB, productC, productD, productE);
	
	system("pause");
	return 0;
}
void BestSeller(int s1, int s2, int s3){
	cout << "(c) 有最好業績的銷售員："; 
	if(s1>s2 && s1>s3)
		cout << "銷售員1" << endl << endl;
	else if(s2>s1 && s2>s3)
		cout << "銷售員2" << endl << endl;
	else
		cout << "銷售員3" << endl << endl;
	return;
}
void BestProduct(int pA, int pB, int pC, int pD, int pE){
	cout << "(d) 銷售總金額為最多的產品：";
	if(pA>pB && pA>pC && pA>pD && pA>pE)
		cout << "產品A" << endl;
	else if(pB>pA && pB>pC && pB>pD && pB>pE)
		cout << "產品B" << endl;
	else if(pC>pA && pC>pB && pC>pD && pC>pE)
		cout << "產品C" << endl;
	else if(pD>pA && pD>pB && pD>pC && pD>pE)
		cout << "產品D" << endl;
	else
		cout << "產品E" << endl;
	return;
}
