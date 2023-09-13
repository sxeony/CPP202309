#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "사과";
	string s2 ;
	// s2 = s1 + " " + 10 + "개"; -> 10은 숫자이기 때문에 에러가 뜸
	// s2 = s1 + " " +"10" + "개"; -> 이렇게 하면 에러는 안 뜨지만 주로 쓰진 않음
	s2 = s1 + " " + to_string(10) + "개";
	cout << s2 << endl;

}