#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "Good";
	string s2 = "Bad";
	bool b = (s1 == s2); // s1�� s2 �� �ٸ��� False = 0
	cout << b << endl;

	s2 = "Good";
	b = (s1 == s2); // s1�� s2�� ������ True = 1
	cout << b << endl;

}