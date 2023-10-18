#include <iostream>
#include <string>
using namespace std;

// �Է� ���� ���ڿ��� �ҹ��ڷ� ��ȯ�ϴ� �Լ�
string toLowerStr(string str) {
	string newStr = str;
	for (char& c : newStr) {
		c = tolower(c);
	}
	return newStr;
}

// �빮�ڷ� ��ȯ�ϴ� �Լ�
string toUpperStr(string str) {
	string newStr = str;
	for (char& c : newStr) {
		c = toupper(c);
	}
	return newStr;
}

// �عְŸ� ���ϴ� �Լ�
int calcHammingDist(string s1, string s2) {
	// �Է¹��� s1, s2 ��� �ҹ��ڷ� ��ȯ�ϱ�
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	int count = 0;
	// ���ڿ��� ��ġ[i]�� �̿��� �ٸ��� count�� 1 �߰�
	for (int i = 0; i < s1.length();i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return count;
}

int main() {
	string s1, s2;
	
	//���̰� ���� ���ڿ��� �Է��� ������ �Է� ��û �ݺ��ϱ� 
	while(1){
		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;

		// s1�� s2 ���̰� �ٸ��� �ٸ��ٰ� ����ϰ� continue
		if (s1.length() != s2.length()) {
			cout << "����: ���̰� �ٸ�" << endl;
			continue;
		}

		//������ calcHammingDist�Լ� �̿��ؼ� �ع� �Ÿ� ���
		else {
			int count = calcHammingDist(s1, s2);
			cout << "�ع� �Ÿ���" << count << endl;
			break;
		}
	}

	return 0;
}