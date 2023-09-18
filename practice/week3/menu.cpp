#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;

	switch (choice) {
	// 1일 경우 파일 저장
	case 1: 
		cout << "파일 저장을 선택했습니다." << endl;
		break;
	//2일 경우 파일 닫기 
	case 2: 
		cout << "파일 닫기를 선택했습니다." << endl;
		break;
	//3일 경우 프로그램 종료 
	case 3: 
		cout << "프로그램을 종료합니다." << endl;
		break;
	// 다른 숫자 입력시 잘못된 선택 출력
	default: 
		cout << "잘못된 선택입니다." << endl;
		break;
	}
	return 0;
}
