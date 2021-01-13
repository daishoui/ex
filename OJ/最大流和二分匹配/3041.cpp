#include<iostream>
#include<vector>
#define MAX_N 510
#define INF 1000000000
using namespace std;
struct edge {
	int to, cap, rev;
};
bool used[MAX_N * 2 + 2];
vector<edge> G[MAX_N * 2 + 2];
int N, K;
int min(int x, int y) {
	return (x < y ? x: y);
}
void add_edge(int u, int v) {
	edge e;
	e.to = v; e.cap = 1; e.rev = G[v].size();
	G[u].push_back(e);
	e.to = u; e.cap = 0; e.rev = G[u].size() - 1;
	G[v].push_back(e);
}
int dfs(int u, int v, int f) {
	if (u == v) return 1;
	used[u] = true;
	for (int i = 0; i<G[u].size(); i++) {
		edge &e = G[u][i];
		if (!used[e.to] && e.cap>0) {
			int d = dfs(e.to, v, min(f, 1));
			if (d>0) {
				e.cap = 0;
				G[e.to][e.rev].cap = 1;
				return d;
			}
		}
	}
	return 0;
}
int solve() {
	for (int i = 1; i <= N; i++) {
		add_edge(0, i);
	}
	for (int i = N + 1; i <= 2 * N; i++) {
		add_edge(i, 2 * N + 1);
	}
	int flow = 0;
	for (;;) {
		fill(used, used + N * 2 + 2, 0);
		int f = dfs(0, N * 2 + 1, INF);
		if (f == 0) return flow;
		flow += f;
	}
}
int main() {
	cin >> N >> K;
	int R, C;
	for (int i = 0; i<K; i++) {
		cin >> R >> C;
		add_edge(R, C + N);
	}
	cout << solve() << endl;
	return 0;
}
