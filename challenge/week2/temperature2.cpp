#include <iostream>
using namespace std;

int main()
{
	// f_temp �� c_temp�� �Ǽ��̱� ������ �ڷ��� double 
	double f_temp, c_temp;
	cout << "�����µ� : ";

	//c_temp �Է¹ޱ� (�����µ�)
	cin >> c_temp;

	//�������� ȭ���� �ٲٱ�
	f_temp = (9.0 / 5.0) * c_temp + 32;
	
	//ȭ���µ� ��� 
	cout << "ȭ���µ� " << f_temp << endl;

	return 0;
}