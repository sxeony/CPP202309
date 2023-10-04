#include <iostream>
#include <string>
using namespace std;

int main()
{
	//상수 정의
	const int STUDENT = 5;
	const int SUBJECT = 3;
	//scoress 의 이차원 배열
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT] = { "영수","영희","철수","미미","쥬쥬" };
	string subjectNames[SUBJECT] = { "수학","영어","CPP" };

	// i와 j의 이중 for문을 이용해서 1씩 더해주기
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 성적을 하나씩 입력하세요." << endl;
		for ( int j = 0; j < SUBJECT; j++){
			cout << subjectNames[j] << ":";
	// 학생들 한명씩 과목 점수 입력하기
			cin >> scores[i][j];
		}
	}
	// 학생들의 평균점수 구하기
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 평균 점수는";
		//평균점수는 실수
		double sum = 0;
		double average = 0;
	// 과목들 점수 더해서 sum 에 저장 
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "입니다" << endl;
	}
	return 0;
}