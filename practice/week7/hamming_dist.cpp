#include <iostream>
#include <string>
using namespace std;

int main() {
	//���ڿ� ����
	string s1, s2;
	int count = 0;

	//���ڿ� �Է¹ޱ�
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// s1�� s2 ���̰� �ٸ��� �ٸ��ٰ� ���
	if (s1.length() != s2.length())
		cout << "����: ���̰� �ٸ�" << endl;
	// ������ �ݺ����� �̿��ؼ� �ع� �Ÿ� ���
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "�ع� �Ÿ���" << count << endl;
	}
	return 0;
}