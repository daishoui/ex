#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX_N 110
using namespace std;
int n,a[MAX_N][MAX_N],d[MAX_N];
struct edge{
	int v,u;
	int cost;
	bool operator<(const edge&e)const{
		return cost<e.cost;
	}
};
vector<edge> ve;
void initd(){
	for(int i=0;i<n;i++){
		d[i]=i;
	}
}
int findparent(int x){
	if(d[x]==x) return x;
	return d[x]=findparent(d[x]);
}
void solve(){
	ve.clear();
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			edge e;
			e.v=i;
			e.u=j;
			e.cost=a[i][j];
			ve.push_back(e);
		}
	}
	sort(ve.begin(),ve.end());
	initd();
	int cnt=0;
	for(int i=0;i<n*(n-1)/2;i++){	//ÍùÀï¼Ó±ß 
		int x=ve[i].v,y=ve[i].u;
		int px=findparent(x),py=findparent(y);
		if(px!=py){
			d[py]=px;
			cnt+=ve[i].cost;
		}
	}
	printf("%d\n",cnt);
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		solve();
	}
	return 0;
}

