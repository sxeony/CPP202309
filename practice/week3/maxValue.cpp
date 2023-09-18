#include <iostream>
using namespace std;

int main()
{
	int a, b, c ,largest;

	cout << "3개의 정수를 입력하시오: ";
	cin >> a >> b >> c;

	if (a > b && a > c) // a가 b보다 크고 a가 c보다 큰가? (and 연산자)
		largest = a;
	else if (b > a && b > c) //b가 a보다 크고 b가 c보다 큰가? (and 연산자)
		largest = b;  
	else
		largest = c;

	cout << "가장 큰 정수는 " << largest << endl;
	return 0;
}