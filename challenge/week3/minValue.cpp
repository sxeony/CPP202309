#include<iostream>
using namespace std;

int main() {
	int a, b, c, minimum_value;
	cout << "3���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c;

	if (a < b && a < c) //a�� b���� �۰�, a�� c���� ������?
		minimum_value = a; //������ minimum_value�� a �� ���� 

	else if (b < a && b < c) //b�� a���� �۰�, b�� c���� ������?
		minimum_value = b;
	else
		minimum_value = c;

	cout << "���� ���� ����" << minimum_value << endl; //��� 
	return 0;




}