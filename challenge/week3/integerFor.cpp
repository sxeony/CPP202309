#include <iostream>
using namespace std;

int main() {
	int userInput;

	//���� 10��°���� �Է��ϴ� �ݺ���
	for (int i = 0; i < 10; i++) {
		cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����): ";
		cin >> userInput;
		cout << "�Է°� : " << userInput << "Ƚ��" << i << endl;
		//i�� 10�̸� ����
		if (i == 10) {
			break;
		}

	}
	return 0;
}