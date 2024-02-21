#include <iostream>
#include <cstdlib>
using namespace std;

class Caaa {
	public:
		int num1, num2;		
};
class Cbbb : public Caaa {
	public:
		void set_num() {
			num1 = 10;
			num2 = 20;
			return;
		}
		void show() {
			cout << "num1 = " << num1 << endl;
			cout << "num2 = " << num2 << endl;
			return;
		}		
};

int main() {	
	Cbbb obj;	
	obj.set_num();
	obj.show();
		
	system("pause");
	return 0;
}
