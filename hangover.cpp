#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double c;
	while(cin >> c){
		if(fabs(c) <= 1e-4){
			break;
		}
		int num = 1;
		double s = 0.0;
		while(s < c){
			s += 1.0 / (num+1);
			num += 1;
		}
		cout << num - 1 <<  " card(s)" << endl;
	}
	return 0;
}