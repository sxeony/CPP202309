#include <iostream>
using namespace std;

// auto : 자동 타입 추론 : 변수 표현식의 데이터 형식을 컴파일러가 자동으로 추론
auto add(int x, int y) {
	return x + y;

}

int main()
{
	auto sum = add(5, 6);
	cout << sum;
	return 0;
}