#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL)); // random 함수 관련 설정

	int answer = rand() % 100; //정답
	int tries = 0; //시도 횟수 저장하는 변수

	int guess; //사용자 입력 저장하기 위한 변수

	do {
		cout << "정답을 추측하여 보시오 : "; 
		cin >> guess;
		tries++;

		if (guess > answer) // guess가 answer 보다 높을 때
			cout << "제시한 정수가 높습니다." << endl;
		if (guess < answer) // guess가 answer 보다 낮을 때 
			cout << "제시한 정수가 낮습니다." << endl;

	} while (guess != answer); // guess와 answer 값이 같을 때까지 반복문 실행 

		cout << "축하합니다. 시도 횟수 = " << tries << endl;
		return 0;

	
}