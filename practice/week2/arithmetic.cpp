#include <iostream>
using namespace std;

int main()
{
	// 상수 선언하기
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;

	// 사칙연산 출력하기 
	cout << "1+3 = " << one + three << endl;
	cout << "4-2 = " << four - two << endl;
	cout << "2*3 = " << two* three << endl;
	cout << "4/2 = " << four / two << endl;

	cout << "2+3*4 = " << two + three *four << endl;
	cout << "2+3*4 = " << two + three * four << endl;
	cout << "1+4/2 = " << one + four/two << endl;
	

	return 0;
}