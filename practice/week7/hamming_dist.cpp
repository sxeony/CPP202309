#include <iostream>
#include <string>
using namespace std;

int main() {
	//문자열 선언
	string s1, s2;
	int count = 0;

	//문자열 입력받기
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// s1과 s2 길이가 다르면 다르다고 출력
	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;
	// 같으면 반복문을 이용해서 해밍 거리 출력
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "해밍 거리는" << count << endl;
	}
	return 0;
}