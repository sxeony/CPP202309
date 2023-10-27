#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
int HP = 20; // ������ ü�� 20�� ������ ���� ���� 

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y);

// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "���� HP: " << HP << "     ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		//����ڰ� ���� �Է����� ��
		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			HP -= 1; //������ ������ HP 1�� ����

			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
				// ���� ��� �� �ٽ� �̵��ϱ� ������ 1�� �ٽ� ������
				HP += 1;
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);

			}
		}
		//����ڰ� �ϸ� �Է����� ��
		else if (user_input == "��") {
			// �Ʒ��� �� ĭ ��������
			user_y += 1;
			HP -= 1;

			//checkXY�� �̿��� ��ȿ�� ��ǥ���� Ȯ���ϰ�, ������ �������� �ƴϸ� �ٽ� ���ư���
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
				HP += 1;
			}
			else {
				cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);

			}
		}
		//����ڰ� �¸� �Է����� ��
		else if (user_input == "��") {
			// �������� �̵��ϱ�
			// user_x�� ������ �迭�̱� ������ 1�� ���ָ� �������� �̵�
			user_x -= 1;
			HP -= 1;

			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
				HP += 1;
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);

			}
		}
		//����ڰ� �츦 �Է����� ��
		else if (user_input == "��") {
			// ���������� �̵��ϱ�
			user_x += 1;
			HP -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
				HP += 1;
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);

			}
		}


		//����ڰ� ������ �Է����� ��
		else if (user_input == "����") {
			// ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		//����ڰ� ���Ḧ �Է����� ��
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		//�߸� �Է����� ��
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// ������� ��ġ ���� üũ
		checkState(map, user_x, user_y);

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

		// ���� HP�� 0�̸� ���� 
		if (HP == 0) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
			cout << "������ �����մϴ�.";
			break;
		}

	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	//i�� ���� ��ȣ
	for (int i = 0; i < mapY; i++) {
		//j�� ���� ��ȣ 
		for (int j = 0; j < mapX; j++) {
			//i�� user_y�� ����, j�� user_x�� ������ user | ���
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			//�ٸ��� ���� ��� (0�� �����, 1�� ������, 2�� �� , 3�� ����, 4�� ������)
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	//���� user_x,user_y�� 0���� ũ�ų� ����, mapX,mapY���� ������ ��ȿ�� ��ǥ�̱� ������ true
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// ������, ����,���� ������ �� �׿� ���� �޽��� ��� 
void checkState(int map[][mapX], int user_x, int user_y) {

	switch (map[user_y][user_x]) {
	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;
		break;
	case 2:
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		HP -= 2;
		break;
	case 3:
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;

		HP += 2;
		break;
	}
}