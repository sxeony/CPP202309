#include <iostream>
using namespace std;

int main()
{
	int a, b, c ,largest;

	cout << "3���� ������ �Է��Ͻÿ�: ";
	cin >> a >> b >> c;

	if (a > b && a > c) // a�� b���� ũ�� a�� c���� ū��? (and ������)
		largest = a;
	else if (b > a && b > c) //b�� a���� ũ�� b�� c���� ū��? (and ������)
		largest = b;  
	else
		largest = c;

	cout << "���� ū ������ " << largest << endl;
	return 0;
}