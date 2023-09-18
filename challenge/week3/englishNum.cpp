#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "숫자를 입력하시오 : ";
	//number 숫자 입력받기 
	cin >> number;
	if (number == 0) // number 가 0이면 zero 출력 
		cout << "zero" << endl;
	else if (number == 1) //number 가 1이면 one 출력
		cout << "one" << endl;
	else //다른 숫자 입력시 many 출력 
		cout << "many" << endl;

	return 0;

}