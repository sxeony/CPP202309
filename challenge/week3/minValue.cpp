#include<iostream>
using namespace std;

int main() {
	int a, b, c, minimum_value;
	cout << "3개의 정수를 입력하시오 : ";
	cin >> a >> b >> c;

	if (a < b && a < c) //a가 b보다 작고, a가 c보다 작은가?
		minimum_value = a; //작으면 minimum_value에 a 값 저장 

	else if (b < a && b < c) //b가 a보다 작고, b가 c보다 작은가?
		minimum_value = b;
	else
		minimum_value = c;

	cout << "가장 작은 수는" << minimum_value << endl; //출력 
	return 0;




}