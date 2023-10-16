#include <iostream>
using namespace std;

//�������� ����
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userpreferences[NUM_USERS][NUM_ITEMS];

//����ڿ� �׸� ���� ��ȣ���� �Է� �޾� 2���� �迭 �ʱ�ȭ�ϴ� �Լ�
void initializePreferences(int userpreferences[NUM_USERS][NUM_ITEMS]) //��������
{
    for (int i = 0; i < NUM_USERS; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����):";
		// 2���� �迭�� �̿��ؼ� �׸� ���� ��ȣ�� �Է� 
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userpreferences[i][j];
		}
	}

}

//�� ����ڿ� ���� ��õ �׸� ã�� �Լ�
void findRecommendedItems(const int userpreferences[NUM_USERS][NUM_ITEMS])
{
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_USERS; ++j) {
			// ���� ����ڰ� �Է��� ��ȣ���� i��°�� maxpreferenceindex���� ũ�� maxpreferenceindex�� j�� ��(�ִ밪)
			if (userpreferences[i][j] > userpreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}

		}

		// ����ڿ��� ��õ�ϴ� �׸� ���
		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}

int main() {
	initializePreferences(userpreferences);
	findRecommendedItems(userpreferences);

	return 0;
}

