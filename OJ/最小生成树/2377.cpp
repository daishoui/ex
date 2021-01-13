#include<iostream>
#include<algorithm>
#define MAX_M 20010
#define MAX_N 1010
using namespace std;
struct edge{
	int u,v,cost;
	bool operator <(const edge&e)const{
		return cost>e.cost;
	}
};
int N,M;
int d[MAX_N];
edge e[MAX_M];
int findpa(int x){	//并查集 
	if(d[x]==x) return x;
	return d[x]=findpa(d[x]);
}
void solve(){
	for(int i=1;i<=N;i++){	//初始化 
		d[i]=i;
	}
	sort(e,e+M);
	int zcost=0;
	int t=0;
	for(int i=0;i<M;i++){
		int px=findpa(e[i].u),py=findpa(e[i].v);
		if(px!=py){
			d[px]=py;
			zcost+=e[i].cost;
			t++;
			if(t==N-1){
				break;
			}
		}
	}
	if(t<N-1){
		cout<<-1<<endl;
	}
	else{
		cout<<zcost<<endl;
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
