#include<iostream>
#include<algorithm>
#define MAX_M 10010
#define MAX_N 2010
using namespace std;
struct edge{
	int u;
	int v;
	int cost;
	bool operator <(const edge &e)const{
		return cost<e.cost;
	}
};
edge e[MAX_M];
int d[MAX_N];
int N,M;
int findpa(int x){
	if(d[x]==x) return x;
	return d[x]=findpa(d[x]);
}
void solve(){
	for(int i=0;i<N;i++){
		d[i]=i;
	}
	sort(e,e+M);
	int t=0;
	for(int i=0;i<M;i++){
		int x=e[i].u,y=e[i].v;
		int px=findpa(x),py=findpa(y);
		if(px!=py){
			t++;
			d[px]=py;
			if(t==N-1){
				cout<<e[i].cost<<endl;
				break;
			}
		}
	}
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>e[i].u>>e[i].v>>e[i].cost;
	}
	solve();
	return 0;
}
