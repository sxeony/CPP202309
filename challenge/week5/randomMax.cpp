#include <iostream>
#include <stdlib.h> 
using namespace std;

int main() {
	const int numCell = 10;
	int numlist[numCell][numCell];
	// numlist �� 2���� �迭�� ����� ���� i,j 2�� for�� ���
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell;j++) {
			// rand() % 1000 : 1000���� ���� ������, �� 0���� 999 ���� 
			int elem = rand() % 1000;
			numlist[i][j] = elem;
			cout << i << ":" << j << ":" << elem << endl;

		}
	}
	cout << endl;

	int max = 0; // ū �� ������ ���� ����
	int maxi; // ū ���� �ִ� i�� �����ϱ� ���� ����
	int maxj; // �� ���� �ִ� j�� �����ϱ� ���� ����
	for (int i = 0; i < numCell; i++) {
		int j = 0;

		//������� �ۼ�
		//i���� �� �ϳ��ϳ��� j�� ����
		for (auto value : numlist[i]){ 
			if (value > max) {
					max = value;
					maxi = i;
					maxj = j;
				}
		j++;
		}
	}

	cout << "���� ū ���� " << max << "�̰�,";
	cout << "i�� j�� ���� " << maxi << ", " << maxj << "�Դϴ�." << endl;
	cout << "���� ���: " << numlist[maxi][maxj] << endl;

	return 0;
}