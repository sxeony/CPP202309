#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL)); // random �Լ� ���� ����

	int answer = rand() % 100; //����
	int tries = 0; //�õ� Ƚ�� �����ϴ� ����

	int guess; //����� �Է� �����ϱ� ���� ����

	do {
		cout << "������ �����Ͽ� ���ÿ� : "; 
		cin >> guess;
		tries++;

		if (guess > answer) // guess�� answer ���� ���� ��
			cout << "������ ������ �����ϴ�." << endl;
		if (guess < answer) // guess�� answer ���� ���� �� 
			cout << "������ ������ �����ϴ�." << endl;

	} while (guess != answer); // guess�� answer ���� ���� ������ �ݺ��� ���� 

		cout << "�����մϴ�. �õ� Ƚ�� = " << tries << endl;
		return 0;

	
}