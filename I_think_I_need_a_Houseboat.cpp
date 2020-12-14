#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
using namespace std;
int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		double x,y;
		cin >> x >> y;
		cout<<"Property "<< i + 1<<": This property will begin eroding in year "<< int(M_PI * (x*x + y*y)/100.0) + 1 <<"." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
