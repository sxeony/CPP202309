#include <iostream>
using namespace std;

int main() {
	int vowel = 0;
	int consonant = 0;
	cout << "�����ڸ� �Է��ϰ� ctrl +z�� ġ����" << endl;

	char ch;
	while (cin >> ch) {
		// ch�� a,e,i,o,u ������ ��� vowel �� 1�� �߰�
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
			// ������ ��� consonant�� 1�� �߰�
			default:
				consonant+=1;
				break;
				
		}
			

	}

	cout << "����" << vowel << endl;
	cout << "����" << consonant << endl;
	return 0;
		
}