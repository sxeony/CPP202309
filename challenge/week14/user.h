#include <iostream>
using namespace std;

class User {
 private:
  int hp;

 public:
  User(int initHp);             // HP �ʱ�ȭ �Լ�
  void DecreaseHP(int dec_hp);  // HP �����ϴ� ����Լ�
  void IncreaseHP(int inc_hp);  // HP �����ϴ� ����Լ�
  int GetHP();                  // HP ����ϴ� ����Լ�
  virtual void doAttack() {}    // ���� ������ �� �����ϴ� �Լ�
};