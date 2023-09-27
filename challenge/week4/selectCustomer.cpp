#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3;
	// cin >> maxPeople;
	string names[maxPeople];
	int ages[maxPeople];
	
	// for문을 이용해서 i가 maxPeople보다 작게 반복
	for (int i = 0; i < maxPeople; i++) {
		cout << "사람" << i + 1 << "의 이름:";
		cin >> names[i];
		cout << "사람" << i+1 << "의 나이: " ;
		cin >> ages[i];
	}
	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;

	cout << ageThreshold << "세 이상인 고객들:\n";

	//detectedPeople 초기화
	int detectedPeople = 0;
	// 조건문을 이용해서 나이가 ageThreshold보다 크면 detectedPeople에 하나씩 추가
	for (int i = 0; i < maxPeople; i++) {
		if (ages[i] >= ageThreshold) {
			cout << names[i] << "(" << ages[i] << "세)\n";
			detectedPeople++;
		}
	}
	// 아무도 없을 경우에는 이상의 나이를 가진 고객이 없다고 출력 
	if (detectedPeople == 0) {
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다.";
	}
	return 0;

}