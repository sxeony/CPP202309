#include <iostream>
using namespace std;

int main()
{
	// f_temp 와 c_temp는 실수이기 때문에 자료형 double 
	double f_temp,c_temp;
	cout << "화씨온도 : " ;

	//f_temp 입력받기
	cin >> f_temp; 

	//화씨에서 섭씨로 바꾸기
	c_temp = (5.0 / 9.0) * (f_temp - 32);

	//섭씨온도 출력
	cout << "섭씨온도 " << c_temp  << endl;

	return 0;
	

}


