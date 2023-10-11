#include <iostream>
using namespace std;

int main() {
	const int numCell = 3;
	//�迭 �ʱ�ȭ�ϴ� ��� :�ڷ��� �迭�� [ĭ][ĭ]{}
	char board[numCell][numCell]{};
	int x, y;

	//������ �ʱ�ȭ
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}
	//�����ϴ� �ڵ�
	int k = 0; // ���� �������� üũ�ϴ� ����
	char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ���� ����
	while (true) {
		//1. switch ���� �̿��ؼ� ���� �������� ���
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(O)�� �����Դϴ� -> ";
			currentUser = 'O';
			break;
		}
		//2. ��ǥ �Է� �ޱ�
		cout << "(x,y)��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;

		//3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// x , y �� �� �ϳ��� 3�̻��� �Է��� ��� ����ٴ� �� ���
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;
		}
		//���� ���� ��ġ�� ������ �ƴѰ�� ���� ���ִٰ� ���
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
			continue;
		}
		//4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		//5. ���� ������ ���
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl;
		k++;

		//6. ���� üũ�ϱ�
		bool isWin = false;

		// 6.1 ����/���� �� üũ�ϱ�
		for (int i = 0; i < numCell; i++) {
			// ���� �Է��� ��ǥ�� board[i][0] ,board[i][1], board[i][2] �� ������ ���� ���� 
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ� !: ";
				isWin = true;
			}
			// �Ȱ��� ���
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ� ! : ";
				isWin = true;
			}
		}
		//6.2 �밢�� �� üũ�ϱ�
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
			isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
			isWin = true;
		}
		if (isWin == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�! " << endl;
			cout << "�����մϴ�" << endl;
			break;
		}


		// 7. ��� ĭ�� á���� ����
		int checked = 0;
		// i�� j �� �ݺ����� �̿��� board[i][j]�� �����̸� checked �� 1�� �����ֱ�
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		//checked�� 0�̸� ����
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�." << endl;
			break;
		}
	}
	return 0;
}