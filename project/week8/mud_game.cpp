#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
int HP = 20; // 유저는 체력 20을 가지고 게임 시작 

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << HP << "     명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		//사용자가 상을 입력했을 때
		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			HP -= 1; //움직일 때마다 HP 1씩 감소

			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
				// 맵을 벗어날 땐 다시 이동하기 때문에 1을 다시 더해줌
				HP += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);

			}
		}
		//사용자가 하를 입력했을 때
		else if (user_input == "하") {
			// 아래로 한 칸 내려가기
			user_y += 1;
			HP -= 1;

			//checkXY를 이용해 유효한 좌표인지 확인하고, 맞으면 내려가고 아니면 다시 돌아가기
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
				HP += 1;
			}
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);

			}
		}
		//사용자가 좌를 입력했을 때
		else if (user_input == "좌") {
			// 왼쪽으로 이동하기
			// user_x는 가로측 배열이기 때문에 1을 빼주면 왼쪽으로 이동
			user_x -= 1;
			HP -= 1;

			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
				HP += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);

			}
		}
		//사용자가 우를 입력했을 때
		else if (user_input == "우") {
			// 오른쪽으로 이동하기
			user_x += 1;
			HP -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
				HP += 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);

			}
		}


		//사용자가 지도를 입력했을 때
		else if (user_input == "지도") {
			// 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		//사용자가 종료를 입력했을 때
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		//잘못 입력했을 때
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 사용자의 위치 정보 체크
		checkState(map, user_x, user_y);

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 만약 HP가 0이면 종료 
		if (HP == 0) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다.";
			cout << "게임을 종료합니다.";
			break;
		}

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	//i가 세로 번호
	for (int i = 0; i < mapY; i++) {
		//j는 가로 번호 
		for (int j = 0; j < mapX; j++) {
			//i와 user_y가 같고, j와 user_x가 같으면 user | 출력
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			//다르면 지도 출력 (0은 빈공간, 1은 아이템, 2는 적 , 3은 포션, 4는 목적지)
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	//만약 user_x,user_y가 0보다 크거나 같고, mapX,mapY보다 작으면 유효한 좌표이기 때문에 true
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 아이템, 포션,적을 만났을 때 그에 대한 메시지 출력 
void checkState(int map[][mapX], int user_x, int user_y) {

	switch (map[user_y][user_x]) {
	case 1:
		cout << "아이템이 있습니다" << endl;
		break;
	case 2:
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		HP -= 2;
		break;
	case 3:
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;

		HP += 2;
		break;
	}
}