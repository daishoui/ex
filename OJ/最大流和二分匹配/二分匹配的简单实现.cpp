#include<iostream>
#include<vector>
#include<cstring>
#define MAX_V (200+200+10+2)
using namespace std;
int V;	//顶点数
vector<int>	G[MAX_V];	//图的邻接表表示 
int match[MAX_V];		//所匹配的顶点 
int used[MAX_V];		//DFS中用到的访问标记
int M,N;
void add_edge(int s,int t){
	G[s].push_back(t);
	G[t].push_back(s);
} 
bool dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i],w=match[u];
		if(w<0||!used[w]&&dfs(w)){
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}
//求解二分图的最大匹配
int bipartite_matching(){
	int res=0;
	memset(match,-1,sizeof(match));
	for(int v=0;v<V;v++){
		if(match[v]<0){
			memset(used,0,sizeof(used));
			if(dfs(v)){
				res++;
			}
		}
	}
	return res;
} 
int main(){
	while(cin>>N>>M){
		V=N+M;
		for(int i=0;i<N;i++){
			int t;
			cin>>t;
			for(int j=1;j<=t;j++){
				int g;
				cin>>g;
				add_edge(i,g+N-1);
			}
		}
		cout<<bipartite_matching()<<endl;
		for(int i=0;i<N+M;i++){
			G[i].clear();
		}
	}
	return 0;
}
