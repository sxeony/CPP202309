#include <iostream>
#include <string>
using namespace std;

// 입력 받은 문자열을 소문자로 변환하는 함수
string toLowerStr(string str) {
	string newStr = str;
	for (char& c : newStr) {
		c = tolower(c);
	}
	return newStr;
}

// 대문자로 변환하는 함수
string toUpperStr(string str) {
	string newStr = str;
	for (char& c : newStr) {
		c = toupper(c);
	}
	return newStr;
}

// 해밍거리 구하는 함수
int calcHammingDist(string s1, string s2) {
	// 입력받은 s1, s2 모두 소문자로 변환하기
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	int count = 0;
	// 문자열의 위치[i]를 이용해 다르면 count에 1 추가
	for (int i = 0; i < s1.length();i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return count;
}

int main() {
	string s1, s2;
	
	//길이가 같은 문자열을 입력할 때까지 입력 요청 반복하기 
	while(1){
		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;

		// s1과 s2 길이가 다르면 다르다고 출력하고 continue
		if (s1.length() != s2.length()) {
			cout << "오류: 길이가 다름" << endl;
			continue;
		}

		//같으면 calcHammingDist함수 이용해서 해밍 거리 출력
		else {
			int count = calcHammingDist(s1, s2);
			cout << "해밍 거리는" << count << endl;
			break;
		}
	}

	return 0;
}