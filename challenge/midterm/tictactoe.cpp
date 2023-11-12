#include <iostream>
using namespace std;
const int numCell = 4;  // �������� ���� ���� ����
int x, y = 0;  // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

// ����� ���� �Լ�
bool checkWin(char currentUser, char board[numCell][numCell]);
bool isValid(int x, int y, char board[numCell][numCell]);

int main() {
  // ������ �����ϴ� �� �ʿ��� ���� ����

  int k = 0;               // ���� �������� üũ�ϱ� ���� ����
  char currentUser = 'X';  // ���� ������ ���� �����ϱ� ���� ����
  char board[numCell][numCell]{};  // �������� ��Ÿ���� 2���� �迭

  // ������ �ʱ�ȭ
  for (int i = 0; i < numCell; i++) {
    for (int j = 0; j < numCell; j++) {
      board[i][j] = ' ';
    }
  }

  // ������ ���� �ݺ�
  while (true) {
    // 1. ���� �������� ���
    // TODO 1.1: 3�ο� �������� ����
    int number = 3;
    switch (k % number) {
      case 0:
        currentUser = 'X';
        break;
      case 1:
        currentUser = 'O';
        break;
      case 2:
        currentUser = 'H';
    }

    // ���� �˷��ֱ�
    cout << k % number + 1 << "�� ����(" << currentUser
         << ")�� �����Դϴ�. -> ";

    // 2. ��ǥ �Է� �ޱ�
    cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
    int x, y;
    cin >> x >> y;

    // 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
    // TODO FUNC 1: isValid �Լ� ���� �� ȣ��
    if (!isValid(x, y, board)) {
      // ��ȿ���� ���� ���, ����ڿ��� �ٽ� �Է¹ޱ�
      continue;
    }

    // 4. �Է¹��� ��ǥ�� ���� ������ �� ����
    board[x][y] = currentUser;

    // 5. ���� ���� �� ���
    // TODO 1.2: numCell ���ڿ� ���� ������ ���
    // 5. ���� ���� �� ���
    for (int i = 0; i < numCell; i++) {
      // j�� �� �࿡���� �� ��ġ
      for (int j = 0; j < numCell; j++) {
        cout << " " << board[i][j] << " ";
        // ������ ���� �ƴϸ� �� ������ ���
        if (j < numCell - 1) {
          cout << "|";
        }
      }
      cout << endl;

      // ������ ���� �ƴϸ� �� ���м� ���
      if (i < numCell - 1) {
        for (int j = 0; j < numCell; j++) {
          cout << "---";
          // ������ ���� �ƴϸ� �� ������ ���
          if (j < numCell - 1) {
            cout << "|";
          }
        }
        cout << endl;
      }
    }
    // ���� ������ ���� �Ʒ��� ������ ���м� ���
    for (int j = 0; j < numCell; j++) {
      // ���м� ���
      cout << "---";
      if (j < numCell - 1) {
        cout << "|";
      }
    }
    cout << endl;

    bool isWin = false;  // �¸� ����
    // TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
    // 6.1. ����/���� �� üũ�ϱ�
    // checkwin �Լ� ȣ���ؼ� �¸� ���� �ľ��ϱ�
    if (checkWin(currentUser, board)) {
      cout << k % numCell + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!"
           << endl;
      break;
    }

    // 6.2. �밢���� üũ�ϱ�
    // TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
    // HINT: for ��

    bool diagWin1 =
        true;  // ���� ������ ������ �Ʒ��� �̾����� �밢���� ���� �¸� ����
    bool diagWin2 =
        true;  // ������ ������ ���� �Ʒ��� �̾����� �밢���� ���� �¸� ����

    // �¸� ���� Ȯ���ϱ�
    for (int i = 0; i < numCell; i++) {
      if (board[i][i] != currentUser) {
        diagWin1 = false;
      }
      if (board[i][numCell - 1 - i] != currentUser) {
        diagWin2 = false;
      }
    }
    // �¸� ���¸޼��� ����ϱ�
    if (diagWin1) {
      cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!"
           << endl;
      isWin = true;
    }

    if (diagWin2) {
      cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!"
           << endl;
      isWin = true;
    }

    // �¸��� ����ϱ�
    if (isWin == true) {
      cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!"
           << endl;
      break;
    }

    // 7. ��� ĭ �� á���� üũ�ϱ�
    int checked = 0;
    for (int i = 0; i < numCell; i++) {
      for (int j = 0; j < numCell; j++) {
        if (board[i][j] == ' ') {
          checked++;
        }
      }
    }
    if (checked == 0) {
      cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
      break;
    }

    k++;
  }

  return 0;
}
// isValid �Լ� : �Է� ���� ��ǥ�� ��ȿ�� üũ
bool isValid(int x, int y, char board[numCell][numCell]) {
  // ��ǥ ������ �����
  if (x >= numCell || y >= numCell) {
    cout << x << "," << y << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
    return false;
  }
  // ��ǥ������ �Է°��� �ߺ��ɶ�
  if (board[x][y] != ' ') {
    cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
    return false;
  }
  return true;
}

// checkWin �Լ� : ���� üũ
bool checkWin(char currentUser, char board[numCell][numCell]) {
  bool isWin = false;

  // ���� �� ���� ���� üũ
  for (int i = 0; i < numCell; i++) {
    bool rowWin = true;
    bool colWin = true;

    // ���� �� ���� �� �¸� ���� Ȯ��
    for (int j = 0; j < numCell; j++) {
      if (board[i][j] != currentUser) {
        rowWin = false;
      }
      if (board[j][i] != currentUser) {
        colWin = false;
      }
    }
    // �¸� �޼��� ���
    if (rowWin) {
      cout << "���ο� ��� ���� �������ϴ�!!";
      isWin = true;
      break;
    }

    if (colWin) {
      cout << "���ο� ��� ���� �������ϴ�!!";
      isWin = true;
      break;
    }
  }

  return isWin;
}
