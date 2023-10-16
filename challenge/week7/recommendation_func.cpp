#include <iostream>
using namespace std;

//전역변수 정의
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userpreferences[NUM_USERS][NUM_ITEMS];

//사용자와 항목 간의 선호도를 입력 받아 2차원 배열 초기화하는 함수
void initializePreferences(int userpreferences[NUM_USERS][NUM_ITEMS]) //지역변수
{
    for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해):";
		// 2차원 배열을 이용해서 항목에 대한 선호도 입력 
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userpreferences[i][j];
		}
	}

}

//각 사용자에 대한 추천 항목 찾는 함수
void findRecommendedItems(const int userpreferences[NUM_USERS][NUM_ITEMS])
{
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_USERS; ++j) {
			// 만약 사용자가 입력한 선호도가 i번째의 maxpreferenceindex보다 크면 maxpreferenceindex에 j가 들어감(최대값)
			if (userpreferences[i][j] > userpreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}

		}

		// 사용자에게 추천하는 항목 출력
		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}

int main() {
	initializePreferences(userpreferences);
	findRecommendedItems(userpreferences);

	return 0;
}

