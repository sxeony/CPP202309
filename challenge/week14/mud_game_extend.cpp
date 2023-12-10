#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// User Å¬·¡½º »ó¼Ó¹Ş´Â Magician Å¬·¡½º Á¤ÀÇ(¸¶¹ı»ç)
class Magician : public User {
 public:
  Magician(int hp) : User(hp) {}
  // doAttack ÇÔ¼ö Á¤ÀÇ
  void doAttack() override {
    cout << "¸¶¹ıÀ» »ç¿ëÇØ¼­ ÀûÀ» °ø°İÇÕ´Ï´Ù. " << endl;
  }
};

// User Å¬·¡½º »ó¼Ó¹Ş´Â Warrior Å¬·¡½º Á¤ÀÇ(Àü»ç)
class Warrior : public User {
 public:
  Warrior(int hp) : User(hp) {}
  // doAttack ÇÔ¼ö Á¤ÀÇ
  void doAttack() override {
    cout << "º£±â¸¦ »ç¿ëÇØ¼­ ÀûÀ» °ø°İÇÕ´Ï´Ù." << endl;
  }
};

// Game Å¬·¡½º Á¤ÀÇ
class Game {
 private:
  User* user1;  //  µ¿ÀûÀ¸·Î ÇÒ´çµÈ »ç¿ëÀÚ1 (¸¶¹ı»ç)
  User* user2;  // µ¿ÀûÀ¸·Î ÇÒ´çµÈ »ç¿ëÀÚ2 (Àü»ç)
  int map[mapY][mapX];
  int user1_x, user1_y;
  int user2_x, user2_y;

  //  ÆÄÀÏ¿¡¼­ mapÀ» ÀĞ´Â ÇÔ¼ö
  void loadMapFromFile(const string& filename) {
    //  ÆÄÀÏ ÀÔÃâ·Â °ü·Ã ¿À·ù Ã³¸®(¿¹¿Ü Ã³¸®)
    try {
      ifstream is(filename);
      if (!is) {
        //  Ç¥ÁØ ¿¹¿Ü Å¬·¡½º »ç¿ë (std:runtime_error)
        throw runtime_error("ÆÄÀÏÀ» ¿­ ¼ö ¾ø½À´Ï´Ù: " + filename);
      }
      // for ·çÇÁ¸¦ ÅëÇØ 2Â÷¿ø ¹è¿­ map ¿¡ µ¥ÀÌÅÍ ÀĞ±â
      for (int i = 0; i < mapY; ++i) {
        for (int j = 0; j < mapX; ++j) {
          if (!(is >> map[i][j])) {
            throw runtime_error("ÆÄÀÏ ÀĞ±â Áß ¿À·ù ¹ß»ı: " + filename);
          }
        }
      }
    }
    // ¿¹¿Ü Ã³¸®
    catch (const runtime_error& e) {
      // ¿¹¿Ü¿¡ ´ëÇÑ ¼³¸í
      cerr << "¿¡·¯: " << e.what() << endl;
      // ¿À·ù ¹ß»ı½Ã Á¾·á
      exit(1);
    }
  }

 public:
  Game(User* p1, User* p2)
      : user1(p1), user2(p2), user1_x(0), user1_y(0), user2_x(0), user2_y(0) {
    // map.txt file ºÒ·¯¿À±â
    loadMapFromFile("map.txt");
  }
  // »ç¿ëÀÚÀÇ À§Ä¡¸¦ È®ÀÎÇÏ°í, ÀÌµ¿ÀÌ À¯È¿ÇÑÁö °Ë»çÇÏ´Â ÇÔ¼ö
  void Position(User* user, int& x, int& y, string& direction) {
    bool isValidMove = false;  // ÀÌµ¿ À¯È¿¼º °Ë»ç º¯¼ö
    while (!isValidMove) {
      int X = x, Y = y;

      // ¹æÇâ¿¡ µû¸¥ À§Ä¡ º¯°æ
      if (direction == "»ó")
        y--;
      else if (direction == "ÇÏ")
        y++;
      else if (direction == "ÁÂ")
        x--;
      else if (direction == "¿ì")
        x++;

      // ¸Ê ¹üÀ§ °Ë»ç
      if (!checkXY(x, y)) {
        cout << "¸ÊÀ» ¹ş¾î³µ½À´Ï´Ù. ´Ù½Ã µ¹¾Æ°©´Ï´Ù." << endl;
        x = X;  // ÀÌÀü À§Ä¡·Î º¹¿ø
        y = Y;
        cout << "¸í·É¾î¸¦ ´Ù½Ã ÇÑ ¹ø ÀÔ·ÂÇÏ¼¼¿ä (»ó,ÇÏ,ÁÂ,¿ì,Áöµµ,Á¾·á): ";
        cin >> direction;  // »õ·Î¿î ¹æÇâ ÀÔ·Â ¹Ş±â
      } else {
        cout << direction << "(À¸)·Î ÇÑ Ä­ ÀÌµ¿ÇÕ´Ï´Ù." << endl;
        user->DecreaseHP(1);  // HP °¨¼Ò
        isValidMove = true;   // À¯È¿ÇÑ ÀÌµ¿ È®ÀÎ
      }
    }
  }

  // °ÔÀÓ ÁøÇàÇÏ´Â ÇÔ¼ö
  void startGame() {
    int k = 0;  // ´©±¸ Â÷·ÊÀÎÁö Ã¼Å©ÇÏ´Â º¯¼ö

    // °ÔÀÓ ½ÃÀÛ
    while (1) {
      cout
          << "================================================================="
          << endl;

      // ÇöÀç ÇÃ·¹ÀÌ¾î ¼³Á¤
      // k°¡ Â¦¼ö¸é user1Â÷·Ê , È¦¼ö¸é user2 Â÷·Ê
      User* currentPlayer = (k % 2 == 0) ? user1 : user2;
      int& currentX = (k % 2 == 0) ? user1_x : user2_x;
      int& currentY = (k % 2 == 0) ? user1_y : user2_y;

      // »ç¿ëÀÚ ÀÔ·Â ¹Ş±â
      string user_input;
      //  ¼ø¼­ Ãâ·ÂÇÏ±â
      if (currentPlayer == user1) {
        cout << "¸¶¹ı»ç(M) Â÷·ÊÀÔ´Ï´Ù." << endl;
      } else {
        cout << "Àü»ç(W) Â÷·ÊÀÔ´Ï´Ù." << endl;
      }

      cout << "ÇöÀç HP: " << currentPlayer->GetHP()
           << "     ¸í·É¾î¸¦ ÀÔ·ÂÇÏ¼¼¿ä (»ó,ÇÏ,ÁÂ,¿ì,Áöµµ,Á¾·á): ";
      cin >> user_input;

      // »ç¿ëÀÚ°¡ Áöµµ¸¦ ÀÔ·ÂÇßÀ» ¶§
      if (user_input == "Áöµµ") {
        // Áöµµ Ç¥½Ã
        displayMap();
      } else {
        // »ç¿ëÀÚÀÇ ÀÌµ¿ Ã³¸®
        if (user_input == "»ó" || user_input == "ÇÏ" || user_input == "ÁÂ" ||
            user_input == "¿ì") {
          // position ÇÔ¼ö È£ÃâÇØ¼­ »ç¿ëÀÚ À§Ä¡ ¾÷µ¥ÀÌÆ®
          Position(currentPlayer, currentX, currentY, user_input);
          // Áöµµ Ç¥½Ã
          displayMap();
        }
        // Á¾·á¸¦ ÀÔ·ÂÇßÀ» ¶§ ÇÁ·Î±×·¥ Á¾·á
        else if (user_input == "Á¾·á") {
          cout << "Á¾·áÇÕ´Ï´Ù." << endl;
          break;
        }
        // Àß¸ø ÀÔ·ÂÇÒ ¶§
        else {
          cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
          continue;
        }

        k++;  // ´ÙÀ½ ÇÃ·¹ÀÌ¾îÀÇ Â÷·Ê·Î ÀüÈ¯

        // »ç¿ëÀÚÀÇ À§Ä¡ Á¤º¸ Ã¼Å©
        checkState(currentX, currentY, *currentPlayer);

        // HP Ã¼Å©ÇÏ±â
        if (!CheckUser(*currentPlayer)) {
          cout << "HP°¡ 0 ÀÌÇÏ°¡ µÇ¾ú½À´Ï´Ù. ½ÇÆĞÇß½À´Ï´Ù.";
          cout << "°ÔÀÓÀ» Á¾·áÇÕ´Ï´Ù.";
          break;
        }

        // ¸ñÀûÁö¿¡ µµ´ŞÇß´ÂÁö Ã¼Å©
        if (checkGoal(currentX, currentY)) {
          cout << "¸ñÀûÁö¿¡ µµÂøÇß½À´Ï´Ù! ÃàÇÏÇÕ´Ï´Ù!" << endl;
          cout << "°ÔÀÓÀ» Á¾·áÇÕ´Ï´Ù." << endl;
          break;
        }

        // ¸¸¾à HP°¡ 0ÀÌ¸é Á¾·á
        if (currentPlayer->GetHP() == 0) {
          cout << "HP°¡ 0ÀÌ µÇ¾ú½À´Ï´Ù. °ÔÀÓÀ» Á¾·áÇÕ´Ï´Ù.";
          break;
        }
      }
    }
  }

  // Áöµµ¿Í »ç¿ëÀÚ À§Ä¡ Ãâ·ÂÇÏ´Â ÇÔ¼ö
  void displayMap() {
    // i°¡ ¼¼·Î ¹øÈ£
    for (int i = 0; i < mapY; i++) {
      // j´Â °¡·Î ¹øÈ£
      for (int j = 0; j < mapX; j++) {
        // i¿Í user_y°¡ °°°í, j¿Í user_x°¡ °°À¸¸é user1 Ãâ·Â
        if (i == user1_y && j == user1_x) {
          cout << "   M  |";  //  ¸¶¹ı»ç À§Ä¡ Ç¥½Ã
        }
        // ±×·¸Áö ¾ÊÀº °æ¿ì user2 Ãâ·Â
        else if (i == user2_y && j == user2_x) {
          cout << "   W  |";  //  Àü»ç À§Ä¡ Ç¥½Ã
        }
        // ´Ù¸£¸é Áöµµ Ãâ·Â (0Àº ºó°ø°£, 1Àº ¾ÆÀÌÅÛ, 2´Â Àû , 3Àº Æ÷¼Ç, 4´Â
        // ¸ñÀûÁö)
        else {
          int posState = map[i][j];
          switch (posState) {
            case 0:
              cout << "      |";  // 6Ä­ °ø¹é
              break;
            case 1:
              cout << "¾ÆÀÌÅÛ|";
              break;
            case 2:
              cout << "  Àû  |";  // ¾ç ¿· 2Ä­ °ø¹é
              break;
            case 3:
              cout << " Æ÷¼Ç |";  // ¾ç ¿· 1Ä­ °ø¹é
              break;
            case 4:
              cout << "¸ñÀûÁö|";
              break;
          }
        }
      }
      cout << endl;
      cout << " -------------------------------- " << endl;
    }
  }
  // À¯ÀúÀÇ À§Ä¡°¡ ¸ñÀûÁöÀÎÁö Ã¼Å©ÇÏ´Â ÇÔ¼ö
  bool checkGoal(int x, int y) {
    // ¸ñÀûÁö µµÂøÇÏ¸é Á¾·á
    if (map[y][x] == 4) {
      return true;
    }
    return false;
  }

  // ¾ÆÀÌÅÛ, Æ÷¼Ç,ÀûÀ» ¸¸³µÀ» ¶§ ±×¿¡ ´ëÇÑ ¸Ş½ÃÁö Ãâ·Â
  void checkState(int x, int y, User& user) {
    switch (map[y][x]) {
      case 0:
        // °ø¹éÀÏ ¶§µµ ³²Àº Ã¼·ÂÀ» Ãâ·Â
        cout << "< ³²Àº Ã¼·Â (¸¶¹ı»ç): " << user1->GetHP()
             << " ³²Àº Ã¼·Â (Àü»ç): " << user2->GetHP() << " >" << endl;
        break;
      case 1:
        cout << "¾ÆÀÌÅÛÀÌ ÀÖ½À´Ï´Ù." << endl;
        cout << "< ³²Àº Ã¼·Â (¸¶¹ı»ç): " << user1->GetHP()
             << " ³²Àº Ã¼·Â (Àü»ç): " << user2->GetHP() << " >" << endl;
        break;
      case 2:
        user.doAttack();  // doAttack ÇÔ¼ö È£­„
        cout << "< ³²Àº Ã¼·Â (¸¶¹ı»ç): " << user1->GetHP()
             << " ³²Àº Ã¼·Â (Àü»ç): " << user2->GetHP() << " >" << endl;
        break;
      case 3:
        cout << "Æ÷¼ÇÀÌ ÀÖ½À´Ï´Ù. HP°¡ 2 ´Ã¾î³³´Ï´Ù." << endl;
        user.IncreaseHP(2);  // Áõ°¡ÇÏ´Â °´Ã¼ µ¿ÀÛ »ç¿ë
        cout << "< ³²Àº Ã¼·Â (¸¶¹ı»ç): " << user1->GetHP()
             << " ³²Àº Ã¼·Â (Àü»ç): " << user2->GetHP() << " >" << endl;
        break;
    }
  }

  // ÀÌµ¿ÇÏ·Á´Â °÷ÀÌ À¯È¿ÇÑ ÁÂÇ¥ÀÎÁö Ã¼Å©ÇÏ´Â ÇÔ¼ö
  bool checkXY(int x, int y) {
    bool checkFlag = false;
    // ¸¸¾à user_x,user_y°¡ 0º¸´Ù Å©°Å³ª °°°í, mapX,mapYº¸´Ù ÀÛÀ¸¸é À¯È¿ÇÑ
    // ÁÂÇ¥ÀÌ±â ¶§¹®¿¡ true
    if (x >= 0 && x < mapX && y >= 0 && y < mapY) {
      checkFlag = true;
    }
    return checkFlag;
  }

  // HP Ã¼Å©ÇÏ´Â ÇÔ¼ö
  bool CheckUser(User& user) {
    if (user.GetHP() <= 0) {
      return false;  // hp°¡ 0 ÀÌÇÏÀÌ¸é false ¹İÈ¯
    } else {
      return true;  // ±×·¸Áö ¾ÊÀ¸¸é true ¹İÈ¯
    }
  }
};

// main ÇÔ¼ö
int main() {
  User* magician = new Magician(20);  // Å¬·¡½º °´Ã¼ »ı¼º(¸¶¹ı»ç)
  User* warrior = new Warrior(20);    // Å¬·¡½º °´Ã¼ »ı¼º(Àü»ç)

  // Game Å¬·¡½ºÀÇ °´Ã¼¸¦ »ı¼º
  Game game(magician, warrior);
  // startGame È£ÃâÇÏ¿© °ÔÀÓ ½ÃÀÛ
  game.startGame();

  delete magician;  // »ı¼ºÇÑ °´Ã¼ ¸Ş¸ğ¸®¿¡¼­ ÇØÁ¦
  delete warrior;

  return 0;
}