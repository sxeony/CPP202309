#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// User Ŭ���� ��ӹ޴� Magician Ŭ���� ����(������)
class Magician : public User {
 public:
  Magician(int hp) : User(hp) {}
  // doAttack �Լ� ����
  void doAttack() override {
    cout << "������ ����ؼ� ���� �����մϴ�. " << endl;
  }
};

// User Ŭ���� ��ӹ޴� Warrior Ŭ���� ����(����)
class Warrior : public User {
 public:
  Warrior(int hp) : User(hp) {}
  // doAttack �Լ� ����
  void doAttack() override {
    cout << "���⸦ ����ؼ� ���� �����մϴ�." << endl;
  }
};

// Game Ŭ���� ����
class Game {
 private:
  User* user1;  //  �������� �Ҵ�� �����1 (������)
  User* user2;  // �������� �Ҵ�� �����2 (����)
  int map[mapY][mapX];
  int user1_x, user1_y;
  int user2_x, user2_y;

  //  ���Ͽ��� map�� �д� �Լ�
  void loadMapFromFile(const string& filename) {
    //  ���� ����� ���� ���� ó��(���� ó��)
    try {
      ifstream is(filename);
      if (!is) {
        //  ǥ�� ���� Ŭ���� ��� (std:runtime_error)
        throw runtime_error("������ �� �� �����ϴ�: " + filename);
      }
      // for ������ ���� 2���� �迭 map �� ������ �б�
      for (int i = 0; i < mapY; ++i) {
        for (int j = 0; j < mapX; ++j) {
          if (!(is >> map[i][j])) {
            throw runtime_error("���� �б� �� ���� �߻�: " + filename);
          }
        }
      }
    }
    // ���� ó��
    catch (const runtime_error& e) {
      // ���ܿ� ���� ����
      cerr << "����: " << e.what() << endl;
      // ���� �߻��� ����
      exit(1);
    }
  }

 public:
  Game(User* p1, User* p2)
      : user1(p1), user2(p2), user1_x(0), user1_y(0), user2_x(0), user2_y(0) {
    // map.txt file �ҷ�����
    loadMapFromFile("map.txt");
  }
  // ������� ��ġ�� Ȯ���ϰ�, �̵��� ��ȿ���� �˻��ϴ� �Լ�
  void Position(User* user, int& x, int& y, string& direction) {
    bool isValidMove = false;  // �̵� ��ȿ�� �˻� ����
    while (!isValidMove) {
      int X = x, Y = y;

      // ���⿡ ���� ��ġ ����
      if (direction == "��")
        y--;
      else if (direction == "��")
        y++;
      else if (direction == "��")
        x--;
      else if (direction == "��")
        x++;

      // �� ���� �˻�
      if (!checkXY(x, y)) {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
        x = X;  // ���� ��ġ�� ����
        y = Y;
        cout << "��ɾ �ٽ� �� �� �Է��ϼ��� (��,��,��,��,����,����): ";
        cin >> direction;  // ���ο� ���� �Է� �ޱ�
      } else {
        cout << direction << "(��)�� �� ĭ �̵��մϴ�." << endl;
        user->DecreaseHP(1);  // HP ����
        isValidMove = true;   // ��ȿ�� �̵� Ȯ��
      }
    }
  }

  // ���� �����ϴ� �Լ�
  void startGame() {
    int k = 0;  // ���� �������� üũ�ϴ� ����

    // ���� ����
    while (1) {
      cout
          << "================================================================="
          << endl;

      // ���� �÷��̾� ����
      // k�� ¦���� user1���� , Ȧ���� user2 ����
      User* currentPlayer = (k % 2 == 0) ? user1 : user2;
      int& currentX = (k % 2 == 0) ? user1_x : user2_x;
      int& currentY = (k % 2 == 0) ? user1_y : user2_y;

      // ����� �Է� �ޱ�
      string user_input;
      //  ���� ����ϱ�
      if (currentPlayer == user1) {
        cout << "������(M) �����Դϴ�." << endl;
      } else {
        cout << "����(W) �����Դϴ�." << endl;
      }

      cout << "���� HP: " << currentPlayer->GetHP()
           << "     ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
      cin >> user_input;

      // ����ڰ� ������ �Է����� ��
      if (user_input == "����") {
        // ���� ǥ��
        displayMap();
      } else {
        // ������� �̵� ó��
        if (user_input == "��" || user_input == "��" || user_input == "��" ||
            user_input == "��") {
          // position �Լ� ȣ���ؼ� ����� ��ġ ������Ʈ
          Position(currentPlayer, currentX, currentY, user_input);
          // ���� ǥ��
          displayMap();
        }
        // ���Ḧ �Է����� �� ���α׷� ����
        else if (user_input == "����") {
          cout << "�����մϴ�." << endl;
          break;
        }
        // �߸� �Է��� ��
        else {
          cout << "�߸��� �Է��Դϴ�." << endl;
          continue;
        }

        k++;  // ���� �÷��̾��� ���ʷ� ��ȯ

        // ������� ��ġ ���� üũ
        checkState(currentX, currentY, *currentPlayer);

        // HP üũ�ϱ�
        if (!CheckUser(*currentPlayer)) {
          cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
          cout << "������ �����մϴ�.";
          break;
        }

        // �������� �����ߴ��� üũ
        if (checkGoal(currentX, currentY)) {
          cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
          cout << "������ �����մϴ�." << endl;
          break;
        }

        // ���� HP�� 0�̸� ����
        if (currentPlayer->GetHP() == 0) {
          cout << "HP�� 0�� �Ǿ����ϴ�. ������ �����մϴ�.";
          break;
        }
      }
    }
  }

  // ������ ����� ��ġ ����ϴ� �Լ�
  void displayMap() {
    // i�� ���� ��ȣ
    for (int i = 0; i < mapY; i++) {
      // j�� ���� ��ȣ
      for (int j = 0; j < mapX; j++) {
        // i�� user_y�� ����, j�� user_x�� ������ user1 ���
        if (i == user1_y && j == user1_x) {
          cout << "   M  |";  //  ������ ��ġ ǥ��
        }
        // �׷��� ���� ��� user2 ���
        else if (i == user2_y && j == user2_x) {
          cout << "   W  |";  //  ���� ��ġ ǥ��
        }
        // �ٸ��� ���� ��� (0�� �����, 1�� ������, 2�� �� , 3�� ����, 4��
        // ������)
        else {
          int posState = map[i][j];
          switch (posState) {
            case 0:
              cout << "      |";  // 6ĭ ����
              break;
            case 1:
              cout << "������|";
              break;
            case 2:
              cout << "  ��  |";  // �� �� 2ĭ ����
              break;
            case 3:
              cout << " ���� |";  // �� �� 1ĭ ����
              break;
            case 4:
              cout << "������|";
              break;
          }
        }
      }
      cout << endl;
      cout << " -------------------------------- " << endl;
    }
  }
  // ������ ��ġ�� ���������� üũ�ϴ� �Լ�
  bool checkGoal(int x, int y) {
    // ������ �����ϸ� ����
    if (map[y][x] == 4) {
      return true;
    }
    return false;
  }

  // ������, ����,���� ������ �� �׿� ���� �޽��� ���
  void checkState(int x, int y, User& user) {
    switch (map[y][x]) {
      case 0:
        // ������ ���� ���� ü���� ���
        cout << "< ���� ü�� (������): " << user1->GetHP()
             << " ���� ü�� (����): " << user2->GetHP() << " >" << endl;
        break;
      case 1:
        cout << "�������� �ֽ��ϴ�." << endl;
        cout << "< ���� ü�� (������): " << user1->GetHP()
             << " ���� ü�� (����): " << user2->GetHP() << " >" << endl;
        break;
      case 2:
        user.doAttack();  // doAttack �Լ� ȣ��
        cout << "< ���� ü�� (������): " << user1->GetHP()
             << " ���� ü�� (����): " << user2->GetHP() << " >" << endl;
        break;
      case 3:
        cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
        user.IncreaseHP(2);  // �����ϴ� ��ü ���� ���
        cout << "< ���� ü�� (������): " << user1->GetHP()
             << " ���� ü�� (����): " << user2->GetHP() << " >" << endl;
        break;
    }
  }

  // �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
  bool checkXY(int x, int y) {
    bool checkFlag = false;
    // ���� user_x,user_y�� 0���� ũ�ų� ����, mapX,mapY���� ������ ��ȿ��
    // ��ǥ�̱� ������ true
    if (x >= 0 && x < mapX && y >= 0 && y < mapY) {
      checkFlag = true;
    }
    return checkFlag;
  }

  // HP üũ�ϴ� �Լ�
  bool CheckUser(User& user) {
    if (user.GetHP() <= 0) {
      return false;  // hp�� 0 �����̸� false ��ȯ
    } else {
      return true;  // �׷��� ������ true ��ȯ
    }
  }
};

// main �Լ�
int main() {
  User* magician = new Magician(20);  // Ŭ���� ��ü ����(������)
  User* warrior = new Warrior(20);    // Ŭ���� ��ü ����(����)

  // Game Ŭ������ ��ü�� ����
  Game game(magician, warrior);
  // startGame ȣ���Ͽ� ���� ����
  game.startGame();

  delete magician;  // ������ ��ü �޸𸮿��� ����
  delete warrior;

  return 0;
}