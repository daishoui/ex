#include<cstdio>
#include<algorithm>
#define MAX_N 50010
using namespace std;
int L,N,M;
int d[MAX_N];
bool Judge(int n){
	int j=0,k=0;
	for(int i=0;i<N;i++){
		if(d[i]-k<n||L-d[i]<n){
			j++;
		}
		else{
			k=d[i];
		}
		if(j>M) return false;
	}
	return true;
}
int main(){
	scanf("%d%d%d",&L,&N,&M);
	int mdis=1,Mdis=L+1;
	for(int i=0;i<N;i++){
		scanf("%d",d+i);
	}
	sort(d,d+N);
	while(mdis+1<Mdis){
		int ave=(mdis+Mdis)/2;
		if(Judge(ave)){
			mdis=ave;
		}
		else{
			Mdis=ave;
		}
	}
	printf("%d\n",mdis);
	return 0;
}

