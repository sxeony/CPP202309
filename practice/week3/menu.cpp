#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;

	switch (choice) {
	// 1�� ��� ���� ����
	case 1: 
		cout << "���� ������ �����߽��ϴ�." << endl;
		break;
	//2�� ��� ���� �ݱ� 
	case 2: 
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
		break;
	//3�� ��� ���α׷� ���� 
	case 3: 
		cout << "���α׷��� �����մϴ�." << endl;
		break;
	// �ٸ� ���� �Է½� �߸��� ���� ���
	default: 
		cout << "�߸��� �����Դϴ�." << endl;
		break;
	}
	return 0;
}
