#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// User 클래스 상속받는 Magician 클래스 정의(마법사)
class Magician : public User {
 public:
  Magician(int hp) : User(hp) {}
  // doAttack 함수 정의
  void doAttack() override {
    cout << "마법을 사용해서 적을 공격합니다. " << endl;
  }
};

// User 클래스 상속받는 Warrior 클래스 정의(전사)
class Warrior : public User {
 public:
  Warrior(int hp) : User(hp) {}
  // doAttack 함수 정의
  void doAttack() override {
    cout << "베기를 사용해서 적을 공격합니다." << endl;
  }
};

// Game 클래스 정의
class Game {
 private:
  User* user1;  //  동적으로 할당된 사용자1 (마법사)
  User* user2;  // 동적으로 할당된 사용자2 (전사)
  int map[mapY][mapX];
  int user1_x, user1_y;
  int user2_x, user2_y;

  //  파일에서 map을 읽는 함수
  void loadMapFromFile(const string& filename) {
    //  파일 입출력 관련 오류 처리(예외 처리)
    try {
      ifstream is(filename);
      if (!is) {
        //  표준 예외 클래스 사용 (std:runtime_error)
        throw runtime_error("파일을 열 수 없습니다: " + filename);
      }
      // for 루프를 통해 2차원 배열 map 에 데이터 읽기
      for (int i = 0; i < mapY; ++i) {
        for (int j = 0; j < mapX; ++j) {
          if (!(is >> map[i][j])) {
            throw runtime_error("파일 읽기 중 오류 발생: " + filename);
          }
        }
      }
    }
    // 예외 처리
    catch (const runtime_error& e) {
      // 예외에 대한 설명
      cerr << "에러: " << e.what() << endl;
      // 오류 발생시 종료
      exit(1);
    }
  }

 public:
  Game(User* p1, User* p2)
      : user1(p1), user2(p2), user1_x(0), user1_y(0), user2_x(0), user2_y(0) {
    // map.txt file 불러오기
    loadMapFromFile("map.txt");
  }
  // 사용자의 위치를 확인하고, 이동이 유효한지 검사하는 함수
  void Position(User* user, int& x, int& y, string& direction) {
    bool isValidMove = false;  // 이동 유효성 검사 변수
    while (!isValidMove) {
      int X = x, Y = y;

      // 방향에 따른 위치 변경
      if (direction == "상")
        y--;
      else if (direction == "하")
        y++;
      else if (direction == "좌")
        x--;
      else if (direction == "우")
        x++;

      // 맵 범위 검사
      if (!checkXY(x, y)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        x = X;  // 이전 위치로 복원
        y = Y;
        cout << "명령어를 다시 한 번 입력하세요 (상,하,좌,우,지도,종료): ";
        cin >> direction;  // 새로운 방향 입력 받기
      } else {
        cout << direction << "(으)로 한 칸 이동합니다." << endl;
        user->DecreaseHP(1);  // HP 감소
        isValidMove = true;   // 유효한 이동 확인
      }
    }
  }

  // 게임 진행하는 함수
  void startGame() {
    int k = 0;  // 누구 차례인지 체크하는 변수

    // 게임 시작
    while (1) {
      cout
          << "================================================================="
          << endl;

      // 현재 플레이어 설정
      // k가 짝수면 user1차례 , 홀수면 user2 차례
      User* currentPlayer = (k % 2 == 0) ? user1 : user2;
      int& currentX = (k % 2 == 0) ? user1_x : user2_x;
      int& currentY = (k % 2 == 0) ? user1_y : user2_y;

      // 사용자 입력 받기
      string user_input;
      //  순서 출력하기
      if (currentPlayer == user1) {
        cout << "마법사(M) 차례입니다." << endl;
      } else {
        cout << "전사(W) 차례입니다." << endl;
      }

      cout << "현재 HP: " << currentPlayer->GetHP()
           << "     명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
      cin >> user_input;

      // 사용자가 지도를 입력했을 때
      if (user_input == "지도") {
        // 지도 표시
        displayMap();
      } else {
        // 사용자의 이동 처리
        if (user_input == "상" || user_input == "하" || user_input == "좌" ||
            user_input == "우") {
          // position 함수 호출해서 사용자 위치 업데이트
          Position(currentPlayer, currentX, currentY, user_input);
          // 지도 표시
          displayMap();
        }
        // 종료를 입력했을 때 프로그램 종료
        else if (user_input == "종료") {
          cout << "종료합니다." << endl;
          break;
        }
        // 잘못 입력할 때
        else {
          cout << "잘못된 입력입니다." << endl;
          continue;
        }

        k++;  // 다음 플레이어의 차례로 전환

        // 사용자의 위치 정보 체크
        checkState(currentX, currentY, *currentPlayer);

        // HP 체크하기
        if (!CheckUser(*currentPlayer)) {
          cout << "HP가 0 이하가 되었습니다. 실패했습니다.";
          cout << "게임을 종료합니다.";
          break;
        }

        // 목적지에 도달했는지 체크
        if (checkGoal(currentX, currentY)) {
          cout << "목적지에 도착했습니다! 축하합니다!" << endl;
          cout << "게임을 종료합니다." << endl;
          break;
        }

        // 만약 HP가 0이면 종료
        if (currentPlayer->GetHP() == 0) {
          cout << "HP가 0이 되었습니다. 게임을 종료합니다.";
          break;
        }
      }
    }
  }

  // 지도와 사용자 위치 출력하는 함수
  void displayMap() {
    // i가 세로 번호
    for (int i = 0; i < mapY; i++) {
      // j는 가로 번호
      for (int j = 0; j < mapX; j++) {
        // i와 user_y가 같고, j와 user_x가 같으면 user1 출력
        if (i == user1_y && j == user1_x) {
          cout << "   M  |";  //  마법사 위치 표시
        }
        // 그렇지 않은 경우 user2 출력
        else if (i == user2_y && j == user2_x) {
          cout << "   W  |";  //  전사 위치 표시
        }
        // 다르면 지도 출력 (0은 빈공간, 1은 아이템, 2는 적 , 3은 포션, 4는
        // 목적지)
        else {
          int posState = map[i][j];
          switch (posState) {
            case 0:
              cout << "      |";  // 6칸 공백
              break;
            case 1:
              cout << "아이템|";
              break;
            case 2:
              cout << "  적  |";  // 양 옆 2칸 공백
              break;
            case 3:
              cout << " 포션 |";  // 양 옆 1칸 공백
              break;
            case 4:
              cout << "목적지|";
              break;
          }
        }
      }
      cout << endl;
      cout << " -------------------------------- " << endl;
    }
  }
  // 유저의 위치가 목적지인지 체크하는 함수
  bool checkGoal(int x, int y) {
    // 목적지 도착하면 종료
    if (map[y][x] == 4) {
      return true;
    }
    return false;
  }

  // 아이템, 포션,적을 만났을 때 그에 대한 메시지 출력
  void checkState(int x, int y, User& user) {
    switch (map[y][x]) {
      case 0:
        // 공백일 때도 남은 체력을 출력
        cout << "< 남은 체력 (마법사): " << user1->GetHP()
             << " 남은 체력 (전사): " << user2->GetHP() << " >" << endl;
        break;
      case 1:
        cout << "아이템이 있습니다." << endl;
        cout << "< 남은 체력 (마법사): " << user1->GetHP()
             << " 남은 체력 (전사): " << user2->GetHP() << " >" << endl;
        break;
      case 2:
        user.doAttack();  // doAttack 함수 호춣
        cout << "< 남은 체력 (마법사): " << user1->GetHP()
             << " 남은 체력 (전사): " << user2->GetHP() << " >" << endl;
        break;
      case 3:
        cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
        user.IncreaseHP(2);  // 증가하는 객체 동작 사용
        cout << "< 남은 체력 (마법사): " << user1->GetHP()
             << " 남은 체력 (전사): " << user2->GetHP() << " >" << endl;
        break;
    }
  }

  // 이동하려는 곳이 유효한 좌표인지 체크하는 함수
  bool checkXY(int x, int y) {
    bool checkFlag = false;
    // 만약 user_x,user_y가 0보다 크거나 같고, mapX,mapY보다 작으면 유효한
    // 좌표이기 때문에 true
    if (x >= 0 && x < mapX && y >= 0 && y < mapY) {
      checkFlag = true;
    }
    return checkFlag;
  }

  // HP 체크하는 함수
  bool CheckUser(User& user) {
    if (user.GetHP() <= 0) {
      return false;  // hp가 0 이하이면 false 반환
    } else {
      return true;  // 그렇지 않으면 true 반환
    }
  }
};

// main 함수
int main() {
  User* magician = new Magician(20);  // 클래스 객체 생성(마법사)
  User* warrior = new Warrior(20);    // 클래스 객체 생성(전사)

  // Game 클래스의 객체를 생성
  Game game(magician, warrior);
  // startGame 호출하여 게임 시작
  game.startGame();

  delete magician;  // 생성한 객체 메모리에서 해제
  delete warrior;

  return 0;
}