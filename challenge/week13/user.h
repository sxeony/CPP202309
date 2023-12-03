#include <iostream>
using namespace std;

class User {
 private:
  int hp;

 public:
  User(int initHp);             // HP 초기화 함수
  void DecreaseHP(int dec_hp);  // HP 감소하는 멤버함수
  void IncreaseHP(int inc_hp);  // HP 증가하는 멤버함수
  int GetHP();                  // HP 출력하는 멤버함수
  virtual void doAttack() {}    // 적을 만났을 때 공격하는 함수
};