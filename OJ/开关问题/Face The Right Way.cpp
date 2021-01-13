#include<iostream>
#define MAX_N 5010
using namespace std;
char s[MAX_N];
int f[MAX_N];
int N;
void solve(){
	int M=MAX_N,K=0;
	for(int k=1;k<=N;k++){
		bool ok=true;
		int t=0;
		for(int i=1;i<=k;i++){
			f[i]=f[i-1];
			
			if((f[i]%2==1&&s[i]=='F')||(f[i]%2==0&&s[i]=='B')){
				f[i]++;
				t++;
			}
		}
		for(int i=k+1;i<=N-k+1;i++){
			f[i]=f[i-1];
			if(((f[i]-f[i-k])%2==1&&s[i]=='F')||((f[i]-f[i-k])%2==0&&s[i]=='B')){
				f[i]++;
				t++;
			}
		}
		for(int i=N-k+2;i<=N;i++){
			f[i]=f[i-1];
			if(((f[i]-f[i-k])%2==1&&s[i]=='F')||((f[i]-f[i-k])%2==0&&s[i]=='B')){
				ok=false;
				break;
			}
		}
		if(ok&&M>t){
			M=t;
			K=k;
		}
	}
	cout<<K<<" "<<M<<endl;
}
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>s[i];
	}
	solve();
	return 0;
} 
