#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "���ڸ� �Է��Ͻÿ� : ";
	//number ���� �Է¹ޱ� 
	cin >> number;
	if (number == 0) // number �� 0�̸� zero ��� 
		cout << "zero" << endl;
	else if (number == 1) //number �� 1�̸� one ���
		cout << "one" << endl;
	else //�ٸ� ���� �Է½� many ��� 
		cout << "many" << endl;

	return 0;

}