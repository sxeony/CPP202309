#include "user.h"

User::User(int initHp) : hp(initHp) {}  // Ŭ���� ������ ����
void User::DecreaseHP(int dec_hp) { hp = hp - dec_hp; }
void User::IncreaseHP(int inc_hp) { hp = hp + inc_hp; }  // HP�����ϴ� ���� �߰�
int User::GetHP() { return hp; }