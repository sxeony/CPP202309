#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3;
	// cin >> maxPeople;
	string names[maxPeople];
	int ages[maxPeople];
	
	// for���� �̿��ؼ� i�� maxPeople���� �۰� �ݺ�
	for (int i = 0; i < maxPeople; i++) {
		cout << "���" << i + 1 << "�� �̸�:";
		cin >> names[i];
		cout << "���" << i+1 << "�� ����: " ;
		cin >> ages[i];
	}
	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;

	cout << ageThreshold << "�� �̻��� ����:\n";

	//detectedPeople �ʱ�ȭ
	int detectedPeople = 0;
	// ���ǹ��� �̿��ؼ� ���̰� ageThreshold���� ũ�� detectedPeople�� �ϳ��� �߰�
	for (int i = 0; i < maxPeople; i++) {
		if (ages[i] >= ageThreshold) {
			cout << names[i] << "(" << ages[i] << "��)\n";
			detectedPeople++;
		}
	}
	// �ƹ��� ���� ��쿡�� �̻��� ���̸� ���� ���� ���ٰ� ��� 
	if (detectedPeople == 0) {
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�.";
	}
	return 0;

}