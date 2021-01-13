#include<iostream>
#include<vector>
#define MAX_N 210
#define MAX_M 210
#define INF 100000000
using namespace std;
struct edge{
	int to,cap,rev;
};
vector<edge> G[MAX_N+MAX_M+2];
bool used[MAX_N+MAX_M+2];
int N,M;
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
		if(e.cap>0&&!used[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
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
	for(int i=1;i<=N;i++)
		add_edge(0,i,1);
	for(int i=N+1;i<=N+M;i++)
		add_edge(i,N+M+1,1);
	int flow=0;
	for(;;){
		fill(used,used+N+M+2,0);
		int f=dfs(0,N+M+1,INF);
		if(f==0) return flow;
		flow+=f;
	}
}
int main(){
	while(cin>>N>>M){
		for(int i=1;i<=N;i++){
			int t;
			cin>>t;
			for(int j=1;j<=t;j++){
				int g;
				cin>>g;
				add_edge(i,N+g,1);
			}
		}
		cout<<solve()<<endl;
		for(int i=0;i<N+M+2;i++){
			G[i].clear();
		}
	}
	return 0;
}
