#include<iostream>
using namespace std;

int main()
{
    int money, candy_price, candy, change;
    cout << "���� ������ �ִ� ��: ";
    cin >> money;
    cout << "ĵ���� ����: ";
    cin >> candy_price;

    //�ִ��� �� �� �ִ� ���� ��
    int candy = money / candy_price;
    cout << "�ִ�� �� �� �ִ� ĵ���� ����: " << candy << endl;

    // ������ �����ϰ� ���� �� (% ������ ������� �̿�)
    int change = money % candy_price;
    cout << "ĵ�� ���� �� ���� �� : " << change << endl;
    return 0;
}