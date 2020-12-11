#include<iostream>
#include <iomanip>
using namespace std;
int main(){
	double s;
	double m = 0;
	for(int i=0;i<12;i++){
		cin >> s;
		m += s;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout << "$" << (m / 12.0) << endl;
	return 0;
}