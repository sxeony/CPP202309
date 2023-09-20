#include <iostream>
using namespace std;

int main() {
	int userInput;

	//정수 10번째까지 입력하는 반복문
	for (int i = 0; i < 10; i++) {
		cout << "정수를 10번 입력하세요 (0을 입력하면 종료): ";
		cin >> userInput;
		cout << "입력값 : " << userInput << "횟수" << i << endl;
		//i가 10이면 종료
		if (i == 10) {
			break;
		}

	}
	return 0;
}