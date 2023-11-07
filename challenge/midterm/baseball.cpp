#include <iostream>
#include <string>
using namespace std;
// ����� ���� �Լ�
bool checkNumber(int randomNum);

int main() {
  int userNumber;  // ����ڰ� �Է��� ���ڸ��� ���� ����
  int randomNum;   // ����� �ϴ� 3�ڸ����� ���� ���� ����
  int firstNum;    // ������ ù��° �ڸ���
  int secondNum;   // ������ �ι�° �ڸ���
  int thirdNum;    // ������ ����° �ڸ���

  while (1) {
    randomNum = rand() % 900 + 100;  // ������ 3�ڸ��� ����

    bool same = false;  // ��� ���� �ٸ� ��� true�� ���� ����

    // TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ�
    // �ڵ��� �ۼ�
    same = checkNumber(randomNum);

    if (same == true) {
      break;
    }
  }

  int turn = 0;
  while (1) {
    cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

    int guessFirst;   // ������ ������ ù��° �ڸ���
    int guessSecond;  // ������ ������ �ι�° �ڸ���
    int guessThird;   // ������ ������ ����° �ڸ���

    // ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
    while (1) {
      cout << "���ڸ� ���� �Է����ּ���: ";
      cin >> userNumber;

      bool same = false;  // ��� ���� �ٸ� ��� true�� ���� ����

      // TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ�
      // �ڵ��� �ۼ�
      same = checkNumber(userNumber);

      // 3�ڸ����� �Է����� �ʾ��� ��
      if (to_string(userNumber).length() != 3) {
        cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
        continue;
      }
      // �ߺ��� ���ڸ� �Է����� ��
      if (same == false) {
        cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���."
             << endl;
        continue;
      }
      if (same == true) {
        break;
      }
    }

    int strike = 0;  // ��Ʈ����ũ ������ �����ϴ� ����
    int ball = 0;    // �� ������ �����ϴ� ����

    // TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ����
    // �ڵ��� �ۼ� ���ڿ��� ��ȯ
    string randomStr = to_string(randomNum);
    string userStr = to_string(userNumber);

    // strike �� ball ���� ����
    for (int i = 0; i < 3; i++) {
      if (randomStr[i] == userStr[i]) {
        strike++;
      } else if (randomStr.find(userStr[i]) != string::npos) {
        ball++;
      }
    }

    cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball
         << "�� �Դϴ�." << endl;

    if (strike == 3) {
      cout << "������ ������ϴ�. �����մϴ�.";
      break;
    }

    turn += 1;
  }

  return 0;
}

// checkNumber �Լ� ����
bool checkNumber(int userNumber) {
  int guessFirst, guessSecond, guessThird;
  bool same = false;

  // �ڸ��� ����
  guessFirst = userNumber / 100;
  guessSecond = (userNumber / 10) % 10;
  guessThird = userNumber % 10;

  if (guessFirst != guessSecond && guessSecond != guessThird &&
      guessThird != guessFirst) {
    same = true;
  }

  return same;
}