#include <iostream>
#include <string>
using namespace std;

int main()
{
	//��� ����
	const int STUDENT = 5;
	const int SUBJECT = 3;
	//scoress �� ������ �迭
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT] = { "����","����","ö��","�̹�","����" };
	string subjectNames[SUBJECT] = { "����","����","CPP" };

	// i�� j�� ���� for���� �̿��ؼ� 1�� �����ֱ�
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ������ �ϳ��� �Է��ϼ���." << endl;
		for ( int j = 0; j < SUBJECT; j++){
			cout << subjectNames[j] << ":";
	// �л��� �Ѹ� ���� ���� �Է��ϱ�
			cin >> scores[i][j];
		}
	}
	// �л����� ������� ���ϱ�
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ��� ������";
		//��������� �Ǽ�
		double sum = 0;
		double average = 0;
	// ����� ���� ���ؼ� sum �� ���� 
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "�Դϴ�" << endl;
	}
	return 0;
}