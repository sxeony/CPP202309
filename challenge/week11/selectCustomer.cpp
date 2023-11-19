#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int maxPeople;
  cout << "�� ���� ���� �Է��϶�: ";
  cin >> maxPeople;

  // ���� �迭 Ŭ������ ���� ���
  vector<string> names(maxPeople);  // ���� �ڷ���
  vector<int> ages(maxPeople);      // ������ �ڷ�

  // for���� �̿��ؼ� i�� maxPeople���� �۰� �ݺ�
  for (int i = 0; i < maxPeople; i++) {
    cout << "���" << i + 1 << "�� �̸�:";
    cin >> names[i];
    cout << "���" << i + 1 << "�� ����: ";
    cin >> ages[i];
  }
  int ageThreshold;
  cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
  cin >> ageThreshold;

  cout << ageThreshold << "�� �̻��� ����:\n";

  // detectedPeople �ʱ�ȭ
  int detectedPeople = 0;
  // ���ǹ��� �̿��ؼ� ���̰� ageThreshold���� ũ�� detectedPeople�� �ϳ��� �߰�
  for (int i = 0; i < maxPeople; i++) {
    if (ages[i] >= ageThreshold) {
      cout << names[i] << "(" << ages[i] << "��)\n";
      detectedPeople++;
    }
  }
  // �ƹ��� ���� ���
  if (detectedPeople == 0) {
    cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�.";
  }
  return 0;
}
