#include <iostream>
using namespace std;

int main()
{
	// f_temp �� c_temp�� �Ǽ��̱� ������ �ڷ��� double 
	double f_temp,c_temp;
	cout << "ȭ���µ� : " ;

	//f_temp �Է¹ޱ�
	cin >> f_temp; 

	//ȭ������ ������ �ٲٱ�
	c_temp = (5.0 / 9.0) * (f_temp - 32);

	//�����µ� ���
	cout << "�����µ� " << c_temp  << endl;

	return 0;
	

}


