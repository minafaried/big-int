#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;

int main()
{

	bigint num1;
	/*cout << "enter the number with out sign\n";
	cin >> num1.realnum;                           //"102030445060778090123456789010"
	cout << "enter the sign of the number";
	cin >> num1.sign;*/
	    num1.setnumber("123456789012345678901234567890",'+',30);
	bigint num2;
	    num2.setnumber("113456789011345678901134567890",'+',30);
	bigint num3;
		num3 =num1+num2;
		cout << num1.realnum<<endl<<"+\n"<< num2.realnum <<"\n--------------------------------------\n"<<num3.realnum<<endl<<endl;
	bigint num4;
	num4=num1- num2;
	cout << num1.realnum << endl << "-\n" << num2.realnum << "\n------------------------------------ \n" << num4.realnum << endl;
	//bool a=num1.equal(num2);
	//bool b = num1.notequal(num2);
	//bool c = num1.graterthan(num2);
	//bool d = num1.smallerthan(num2);
	//cout << c<<endl << d;
	//num1.addintnum(9999);
	//num1.Subtractintnumbers(9999);
	//cout << num1.realnum<<endl;

	return 0;
}