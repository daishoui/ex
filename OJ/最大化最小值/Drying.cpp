#include<cstdio>
#define MAX_N 100010
int d[MAX_N];
int n,k;
bool Judge(int v){
	int t=0;
	for(int i=0;i<n;i++){
		if(d[i]>v){
			if((d[i]-v)/(k-1)*(k-1)==d[i]-v){
				t+=(d[i]-v)/(k-1);
			}
			else{
				t+=(d[i]-v)/(k-1)+1;
			}
		}
		if(t>v) return false;
	}
	return true;
}
int main(){
	int x=0,y=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",d+i);
		if(d[i]>y) y=d[i];
	}
	scanf("%d",&k);
	if(k==1){
		printf("%d\n",y);
	}
	else{
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
	}
	
	return 0;
}
