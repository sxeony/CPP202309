#include <iostream>
using namespace std;

int main()
{
	// 상수 선언하기
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 8;

	// sum1=sum1*two와 같다.
	sum1 *= two;
	// sum2 =sum2/eight와 같다.
	sum2 /= eight;

	// 출력하기 
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;


	return 0;

}