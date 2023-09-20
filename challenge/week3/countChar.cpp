#include <iostream>
using namespace std;

int main() {
	int vowel = 0;
	int consonant = 0;
	cout << "영문자를 입력하고 ctrl +z를 치세요" << endl;

	char ch;
	while (cin >> ch) {
		// ch가 a,e,i,o,u 모음일 경우 vowel 에 1씩 추가
		switch (ch) {
			case 'a':
				vowel += 1;
				break;
			case 'e':
				vowel+=1;
				break;
			case 'i':
				vowel+=1;
				break;
			case 'o':
				vowel+=1;
				break;
			case 'u':
				vowel+=1;
				break;
			// 자음일 경우 consonant에 1씩 추가
			default:
				consonant+=1;
				break;
				
		}
			

	}

	cout << "모음" << vowel << endl;
	cout << "자음" << consonant << endl;
	return 0;
		
}