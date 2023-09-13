#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "Good";
	string s2 = "Bad";
	bool b = (s1 == s2); // s1과 s2 가 다르면 False = 0
	cout << b << endl;

	s2 = "Good";
	b = (s1 == s2); // s1과 s2가 같으면 True = 1
	cout << b << endl;

}