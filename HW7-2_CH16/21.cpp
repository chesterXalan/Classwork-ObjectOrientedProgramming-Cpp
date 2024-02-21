#include <iostream>
#include <cstdlib>
using namespace std;

class Caaa {
	public:
		void display() {
			cout << "printed from Caaa class" << endl;
			return;
		}		
};
class Cbbb : public Caaa {
	public:
		void display() {
			cout << "printed from Cbbb class" << endl;
			return;
		}		
};

int main() {	
	Caaa obj1;
	Cbbb obj2;
	
	obj1.display();
	obj2.display();
		
	system("pause");
	return 0;
}
