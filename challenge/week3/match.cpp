#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;
	i = 0;
	cout << "��� ������ �ڵ����� �����մϴ�. " << endl;

	while (true) {
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		cout << firstNum << "+" << secondNum << "=";
		cin >> ans;
		
		// �� ���ڸ� ���� ���� ������ �¾ҽ��ϴ� ���
		if (firstNum + secondNum == ans) {
			
			cout << "�¾ҽ��ϴ�." << endl;
			// 5�� ������ ȭ�� ������
			i += 1;
			if (i > 4) {
				break;
			}

		}
		//Ʋ���� "Ʋ�Ƚ��ϴ�" ���
		else {
			cout << "Ʋ�Ƚ��ϴ�." << endl;
		
		}

	}
	return 0;
}