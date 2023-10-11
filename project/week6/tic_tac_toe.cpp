#include <iostream>
using namespace std;

int main() {
	const int numCell = 3;
	//배열 초기화하는 방법 :자료형 배열명 [칸][칸]{}
	char board[numCell][numCell]{};
	int x, y;

	//보드판 초기화
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}
	//게임하는 코드
	int k = 0; // 누구 차례인지 체크하는 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수
	while (true) {
		//1. switch 문을 이용해서 누구 차례인지 출력
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		}
		//2. 좌표 입력 받기
		cout << "(x,y)좌표를 입력하세요: ";
		cin >> x >> y;

		//3. 입력받은 좌표의 유효성 체크
		// x , y 둘 중 하나가 3이상을 입력할 경우 벗어난다는 말 출력
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;
		}
		//놓은 돌의 위치가 공백이 아닌경우 돌이 차있다고 출력
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
			continue;
		}
		//4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		//5. 현재 보드판 출력
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

		//6. 승자 체크하기
		bool isWin = false;

		// 6.1 가로/세로 돌 체크하기
		for (int i = 0; i < numCell; i++) {
			// 내가 입력한 좌표와 board[i][0] ,board[i][1], board[i][2] 와 같으면 가로 빙고 
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "가로에 모두 돌이 놓였습니다 !: ";
				isWin = true;
			}
			// 똑같은 방식
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "세로에 모두 돌이 놓였습니다 ! : ";
				isWin = true;
			}
		}
		//6.2 대각선 돌 체크하기
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
			isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
			isWin = true;
		}
		if (isWin == true) {
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다! " << endl;
			cout << "종료합니다" << endl;
			break;
		}


		// 7. 모든 칸이 찼으면 종료
		int checked = 0;
		// i와 j 의 반복문을 이용해 board[i][j]가 공백이면 checked 에 1씩 더해주기
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		//checked가 0이면 종료
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
			break;
		}
	}
	return 0;
}