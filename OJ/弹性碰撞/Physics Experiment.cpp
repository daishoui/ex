#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAX_N 110
using namespace std;
int N,H,R,T;
double dist[MAX_N];
void solve(){
	for(int i=0;i<N;i++){
		if(T-i>0){
			double t=sqrt(2.0*H/10);
			int n=(T-i)/t;
			if(n%2==0){
				t=T-i-n*t;
			}
			else{
				t=(n+1)*t-T+i;
			}
			dist[i]=H-5*t*t;
		}
		else{
			dist[i]=H;
		}
	}
	sort(dist,dist+N);
	for(int i=0;i<N;i++){
		printf("%.2lf%c",dist[i]+2*i*R/100.0,i==N-1?'\n':' ');
	}
}
int main(){
	int C;
	cin>>C;
	while(C--){
		cin>>N>>H>>R>>T;
		solve();
	}
	return 0;
}
