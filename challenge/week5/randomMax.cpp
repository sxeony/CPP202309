#include <iostream>
#include <stdlib.h> 
using namespace std;

int main() {
	const int numCell = 10;
	int numlist[numCell][numCell];
	// numlist 의 2차원 배열을 만들기 위해 i,j 2중 for문 사용
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell;j++) {
			// rand() % 1000 : 1000으로 나눈 나머지, 즉 0부터 999 생성 
			int elem = rand() % 1000;
			numlist[i][j] = elem;
			cout << i << ":" << j << ":" << elem << endl;

		}
	}
	cout << endl;

	int max = 0; // 큰 값 저장을 위한 변수
	int maxi; // 큰 값이 있는 i를 저장하기 위한 변수
	int maxj; // 믄 값이 있는 j를 저장하기 위한 변수
	for (int i = 0; i < numCell; i++) {
		int j = 0;

		//범위기반 작성
		//i줄의 값 하나하나를 j로 받음
		for (auto value : numlist[i]){ 
			if (value > max) {
					max = value;
					maxi = i;
					maxj = j;
				}
		j++;
		}
	}

	cout << "가장 큰 값은 " << max << "이고,";
	cout << "i와 j는 각각 " << maxi << ", " << maxj << "입니다." << endl;
	cout << "검증 결과: " << numlist[maxi][maxj] << endl;

	return 0;
}