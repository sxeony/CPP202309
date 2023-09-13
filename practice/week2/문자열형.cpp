#include <iostream>
// string 헤더파일 추가
#include <string>
using namespace std;

int main()
{
	string s1 = "GOOD";
	string s2 = "Morning";
	string s3 = s1 + " " + s2 + "!";
	cout << s3 << endl;
	return 0;
}