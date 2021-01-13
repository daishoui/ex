#include<iostream>
#define MAX_N 15
using namespace std;
int N,a[MAX_N][MAX_N];
int b[MAX_N][MAX_N][MAX_N];
int dis[4][2]={0,0,-1,0,0,-1,-1,-1};
int solve(){
	if(N==1) return a[0][0];
	b[0][0][0]=a[0][0];
	b[0][1][1]=b[0][0][0]+a[0][1]+a[1][0];
	for(int i=2;i<=2*N-3;i++){
		for(int x1=0;x1<i&&x1<N;x1++){
			for(int x2=x1+1;x2<=i&&x2<N;x2++){
				int y1=i-x1,y2=i-x2;
				for(int j=0;j<4;j++){
					int xx1=dis[j][0]+x1,xx2=dis[j][1]+x2;
					int yy1=i-1-xx1,yy2=i-1-xx2;
					if(xx1>=0&&yy2>=0&&xx1<xx2){
						b[x1][x2][i]=max(b[x1][x2][i],b[xx1][xx2][i-1]+a[x1][y1]+a[x2][y2]);
					}
				}
				//cout<<"i="<<i<<" x1="<<x1<<" x2="<<x2<<" b="<<b[x1][x2][i]<<endl;
			}
		}
	}
	return b[N-1][N-1][2*N-2]=a[N-1][N-1]+b[N-2][N-1][2*N-3];
}
int main(){
	cin>>N;
	int x,y,c;
	while(cin>>x>>y>>c){
		if(x==0&&y==0&&c==0){
			break;
		}
		a[x-1][y-1]=c;
	}
	cout<<solve()<<endl;
	return 0;
}
