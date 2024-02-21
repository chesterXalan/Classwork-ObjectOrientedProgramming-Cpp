#ifndef CCLASSDATA_H
#define CCLASSDATA_H

#include "CAccessData.h"
#include <string>
using namespace std;

struct StudentData {
	string SID, SName, SClass;
};
class CClassData:public CAccessData {
	private:
		StudentData *lpsdata[100];
		string ClassName;
	public:
		int number;
		CClassData(string Class);
		~CClassData(void);
		virtual void addData(void);
		virtual void deleteData(void);
		void sortData(void);
		void outputDataA(void);
		void outputDataB(void);
};
#endif
