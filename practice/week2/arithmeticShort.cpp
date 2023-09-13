#include <iostream>
using namespace std;

int main()
{
	// 상수 선언하기
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;
	
	// sum1 과 two 값을 더해서 sum1에 저장
	sum1 = sum1 + two;
	// += 증감연산자
	// sum2 =sum2+ eight = sum2+= eight 
	sum2 += eight;

	// 출력하기 
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;


	return 0;

}