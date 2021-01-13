#include<iostream>
#include<cstring>
#define MAX_N 20
#define MAX_M 20
using namespace std;
int M,N;
int a[MAX_M][MAX_N];
int b[MAX_M][MAX_N];
int dis[5][2]={0,0,0,1,0,-1,-1,0,1,0};
void solve(){
	bool ok=true;
	for(int i=0;i<=(1<<N)-1;i++){
		ok=true;
		memset(b,0,sizeof(b));
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(j==0){
					b[0][k]=(i>>k)&1;
				}
				else{
					int t=0;
					if(j-2>=0) t+=b[j-2][k];
					if(k-1>=0) t+=b[j-1][k-1];
					if(k+1<N) t+=b[j-1][k+1];
					t+=(a[j-1][k]+b[j-1][k]);
					if(t%2==1) b[j][k]=1;
				}
			}
		}
		for(int k=0;k<N;k++){
			int t=0;
			if(k-1>=0) t+=b[M-1][k-1];
			if(k+1<N) t+=b[M-1][k+1];
			if(M-2>=0) t+=b[M-2][k];
			t+=(a[M-1][k]+b[M-1][k]);
			if(t%2==1){
				ok=false;
				break;
			}
		}
		if(ok){
			for(int j=0;j<M;j++){
				for(int k=0;k<N;k++){
					cout<<b[j][k]<<" ";
				}
				cout<<endl;
			} 
			break;
		}
	}
	if(ok==false){
		cout<<"IMPOSSIBLE"<<endl;
	}
}
int main(){
	cin>>M>>N;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>a[i][j];
		}
	}
	solve();
	return 0;
}
