#include <iostream>
// PI ��� ����
#define PI 3.141592
using namespace std;

int main()
{
	// 1000�� ���ͷ� ���
	int income = 1000; 
	// TAX_RATE ��� ����
	const double TAX_RATE = 0.25;
	income = income - TAX_RATE * income;

	double x = 100;
	x = x * PI;
	
	cout << x << endl;
	return 0;
}