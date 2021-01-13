#include<iostream>
#include<vector>
#define MAX_N 110
#define MAX_F 110
#define MAX_D 110
#define INF 1000000000
using namespace std;
int N,F,D;
struct edge{
	int to,cap,rev;
};
vector<edge> G[MAX_N*2+MAX_F+MAX_D+2];
bool used[MAX_N*2+MAX_F+MAX_D+2];
void add_edge(int s,int t,int cap){
	edge e;
	e.to=t;e.cap=cap;e.rev=G[t].size();
	G[s].push_back(e);
	e.to=s;e.cap=0;e.rev=G[s].size()-1;
	G[t].push_back(e);
}
int dfs(int s,int t,int f){
	if(s==t) return f;
	used[s]=true;
	for(int i=0;i<G[s].size();i++){
		edge &e=G[s][i];
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,1));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;	
			}
		}
	} 
	return 0;
}
int solve(){
	for(int i=1;i<=F;i++)
		add_edge(0,i,1);
	for(int i=F+1;i<=N+F;i++)
		add_edge(i,i+N,1);
	for(int i=2*N+F+1;i<=2*N+D+F;i++)
		add_edge(i,2*N+D+F+1,1);
	int flow=0;
	for(;;){
		fill(used,used+2*N+F+D+2,0);
		int f=dfs(0,2*N+F+D+1,INF);
		if(f==0) return flow;
		flow+=f;
	}
}
int main(){
	cin>>N>>F>>D;
	for(int i=0;i<N;i++){
		int f,d;
		cin>>f>>d;
		for(int j=0;j<f;j++){
			int ff;
			cin>>ff;
			add_edge(ff,F+i+1,1);
		}
		for(int j=0;j<d;j++){
			int dd;
			cin>>dd;
			add_edge(N+F+i+1,2*N+F+dd,1);
		}
	}
	cout<<solve()<<endl;
	return 0;
}
