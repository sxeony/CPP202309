#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;

	// choice�� 1�� ��� ���� ����
	if (choice==1)
		cout << "���� ������ �����߽��ϴ�." << endl;
	
	//choice�� 2�� ��� ���� �ݱ� 
	else if (choice == 2)
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
		
	//choice�� 3�� ��� ���α׷� ���� 
	else if (choice== 3)
		cout << "���α׷��� �����մϴ�." << endl;
		
	// �ٸ� ���� �Է½� �߸��� ���� ���
	else
		cout << "�߸��� �����Դϴ�." << endl;
		
	
	return 0;
}