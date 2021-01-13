#include<cstdio>
#define MAX_N 100010
using namespace std;
int N,M;
int d[MAX_N];
bool Judge(int n){
	int sum=0,t=1;
	for(int i=0;i<N;i++){
		if(d[i]>n) return false;
		else if(sum+d[i]<=n){
			 sum+=d[i];
		}
		else{
			sum=d[i];
			t++;
			if(t>M){
				return false;
			}
		}
	}
	return true;
}
int main(){
	scanf("%d%d",&N,&M);
	int sum=0;
	for(int i=0;i<N;i++){
		scanf("%d",d+i);
		if(i<N-M+1){
			sum+=d[i];
		}
		else{
			if(sum<d[i]) sum=d[i];
		}
	}
	int x=0,y=sum;
	while(x<y-1){
		int ave=(x+y)/2;
		if(Judge(ave)){
			y=ave;
		}
		else{
			x=ave;
		}
	}
	printf("%d\n",y);
	return 0;
}
