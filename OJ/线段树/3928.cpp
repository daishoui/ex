#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX_N 20010
using namespace std;
int a[14][MAX_N],N;
int c[14][MAX_N];
void buildTree(int x[15][MAX_N],int t){
	//创建线段树每一个结点是一个区间 
	for(int i=1;i<=t-1;i++){
		int k=N/(1<<i);
		if(k*(1<<i)!=N) k++;
		for(int j=0;j<k;j++){
			int t1=(1<<(i-1))*j*2,t2=(1<<(i-1))*(j*2+1);
			int g=t1;
			while(t2<N&&g<N&&t1<(1<<(i-1))*(j*2+1)&&t2<(1<<(i-1))*(j*2+2)){
				if(x[i-1][t1]<x[i-1][t2]){
					x[i][g++]=x[i-1][t1++];
				}
				else{
					x[i][g++]=x[i-1][t2++];
				}
			}
			while(g<N&&t1<N&&t1<(1<<(i-1))*(j*2+1)){
				x[i][g++]=x[i-1][t1++];
			}
			while(g<N&&t2<N&&t2<(1<<(i-1))*(j*2+2)){
				x[i][g++]=x[i-1][t2++];
			}
		}
	}
}
void solve(){
	int t=0;
	while((1<<t)<N) t++;
	buildTree(a,t);
	buildTree(c,t);
	long long s=0;
	int b[20];
	for(int i=1;i<=N-2;i++){
		//s2为左边比a[0][i]小的数的个数,sr2为右边比c[0][n-i-1]小的数的个数 
		int g=i,j=0,s1=0,s2=0,sr1=0,sr2=0,t1=0,t2=0;
		memset(b,0,sizeof(b));
		while(g>0){
			b[j++]=g&1;
			g>>=1;
		}
		for(int k=j-1;k>=0;k--){
			if(b[k]){
				t2+=1<<k;
				s2+=lower_bound(a[k]+t1,a[k]+t2,a[0][i])-a[k]-t1;
				s1+=t2-(upper_bound(a[k]+t1,a[k]+t2,a[0][i])-a[k]);
				t1=t2;
			}
		}
		g=N-i-1;j=0;
		memset(b,0,sizeof(b));
		while(g>0){
			b[j++]=g&1;
			g>>=1;
		}
		t1=0,t2=0;
		for(int k=j-1;k>=0;k--){
			if(b[k]){
				t2+=1<<k;
				sr2+=lower_bound(c[k]+t1,c[k]+t2,c[0][N-i-1])-c[k]-t1;
				sr1+=t2-(upper_bound(c[k]+t1,c[k]+t2,c[0][N-i-1])-c[k]);
				t1=t2;
			}
		}
		s+=sr1*s2+sr2*s1;
	}
	cout<<s<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d",&a[0][i]);
		}
		for(int i=0;i<N;i++){
			c[0][N-i-1]=a[0][i];
		}
		solve();
	}
	return 0;
}
