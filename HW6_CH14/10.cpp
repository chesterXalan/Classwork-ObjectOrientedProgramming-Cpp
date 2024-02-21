#include <iostream>
#include <cstdlib>
using namespace std;

#define Number 5

class Caaa {
	private:
		int total, *ptr;
	public:
		Caaa(int num);
		void show();
		Caaa(const Caaa &aaa);
		~Caaa();
};

Caaa::Caaa(int num): total(num) {
    cout << "已呼叫結構元" << endl;
	ptr = new int[total];
	for(int i = 0; i <total; i++)
		ptr[i] = 8;
}
void Caaa::show() {
	for(int i = 0; i < total; i++)
		cout << "元素[" << i << "] = " << ptr[i] << endl;

	return;
}
Caaa::Caaa(const Caaa &aaa) {
    cout << "已呼叫拷貝結構元" << endl << endl;
	total = aaa.total;
	ptr = aaa.ptr;
}
Caaa::~Caaa() {
	cout << endl << "已呼叫解構元" << endl;
    delete [] ptr;

	system("pause");
}

int main() {
	Caaa aaa1(Number);
	Caaa aaa2(aaa1);

	aaa1.show();
	cout << "--------------------" << endl;
	aaa2.show();
	cout << endl;

	system("pause");
	return 0;
}
