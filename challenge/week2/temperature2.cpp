#include <iostream>
using namespace std;

int main()
{
	// f_temp 와 c_temp는 실수이기 때문에 자료형 double 
	double f_temp, c_temp;
	cout << "섭씨온도 : ";

	//c_temp 입력받기 (섭씨온도)
	cin >> c_temp;

	//섭씨에서 화씨로 바꾸기
	f_temp = (9.0 / 5.0) * c_temp + 32;
	
	//화씨온도 출력 
	cout << "화씨온도 " << f_temp << endl;

	return 0;
}