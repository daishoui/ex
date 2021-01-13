#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAX_N 60
#define MAX_M 1010
using namespace std;
struct edge{
	int u,v,cost;
	bool operator<(const edge& e)const{
		return cost<e.cost;
	}
};
edge ed[MAX_M];
int d[MAX_N],N,M,cc;
int g[MAX_N];
void init(int n){
	for(int i=1;i<=n;i++){
		d[i]=i;
	}
}
int findpa(int x){
	if(d[x]==x) return x;
	return d[x]=findpa(d[x]);
}
void solve(){
	sort(ed,ed+M);
	double count=1250000.0;
	for(int i=0;i<M;i++){
		init(N);
		int t=0,tt=i;
		int t1=i-1,t2=i+1;
		while(tt>=0&&tt<M){
			edge &e1=ed[tt];	
			int pu=findpa(e1.u),pv=findpa(e1.v);
			if(pu!=pv){
				d[pu]=pv;
				g[t++]=e1.cost;
				if(t==N-1) break;
			}
			if(t1>=0&&t2<M){
				if(abs(ed[t1].cost-ed[i].cost)>abs(ed[t2].cost-ed[i].cost)){
					tt=t2;
					t2++;
				}
				else{ tt=t1;t1--;}
			}
			else if(t1<0){ tt=t2;t2++;}
			else{ tt=t1;t1--;}
		}
		int e=0;
		for(int i=0;i<N-1;i++){
			e+=g[i];
			printf("g[%d]=%d ",i,g[i]); 
		}
		printf("\n");
		double gg=0,E=1.0*e/(N-1);
		for(int i=0;i<N-1;i++){
			gg+=(g[i]-E)*(g[i]-E);
		}
		gg=gg/(N-1);
		if(gg<count) count=gg;
	}
	printf("Case %d: %.2lf\n",++cc,count);
}
int main(){
	while(scanf("%d%d",&N,&M)&&N){
		for(int i=0;i<M;i++){
			scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].cost);
		}
		solve();
	}
	return 0;
}
