#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;
	i = 0;
	cout << "산수 문제를 자동으로 출제합니다. " << endl;

	while (true) {
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		cout << firstNum << "+" << secondNum << "=";
		cin >> ans;
		
		// 두 숫자를 더한 값이 맞으면 맞았습니다 출력
		if (firstNum + secondNum == ans) {
			
			cout << "맞았습니다." << endl;
			// 5번 맞으면 화면 나가기
			i += 1;
			if (i > 4) {
				break;
			}

		}
		//틀리면 "틀렸습니다" 출력
		else {
			cout << "틀렸습니다." << endl;
		
		}

	}
	return 0;
}