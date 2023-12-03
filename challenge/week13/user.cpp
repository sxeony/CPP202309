#include "user.h"

User::User(int initHp) : hp(initHp) {}  // 클래스 생성자 정의
void User::DecreaseHP(int dec_hp) { hp = hp - dec_hp; }
void User::IncreaseHP(int inc_hp) { hp = hp + inc_hp; }  // HP증가하는 동작 추가
int User::GetHP() { return hp; }