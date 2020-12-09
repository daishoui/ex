#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long s = 1;
	for(long long i=2;i<=(long long)sqrt(n);i++){
		if(n%i == 0){
			s += i;
			s += (long long)(n/i);
		}
	}
	if(s == n){
		cout << "Pure" << endl;
	} else if(s > n){
		cout << "Late" << endl;
	}
	else{
		cout << "Early" << endl;
	}
	return 0;
}