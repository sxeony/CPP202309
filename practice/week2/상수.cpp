#include <iostream>
// PI 상수 정의
#define PI 3.141592
using namespace std;

int main()
{
	// 1000이 리터럴 상수
	int income = 1000; 
	// TAX_RATE 상수 변수
	const double TAX_RATE = 0.25;
	income = income - TAX_RATE * income;

	double x = 100;
	x = x * PI;
	
	cout << x << endl;
	return 0;
}