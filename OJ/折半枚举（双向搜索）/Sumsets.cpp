#include<iostream>
#include<algorithm>
#define MAX_N 1010
using namespace std;
int A[MAX_N];
struct ps{
	int x,y;
	int sum;
	bool operator<(const ps&e)const{
		return sum<e.sum;
	}
};
ps AB[MAX_N*(MAX_N-1)/2];
int main(){
	int n;
	while((cin>>n)&&n){
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		int t=0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				AB[t].x=i;
				AB[t].y=j;
				AB[t].sum=A[i]+A[j];
				t++;
			}
		}
		sort(AB,AB+n*(n-1)/2);
		int g=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j&&g<A[j]){
					int d=A[j],c=A[i];
					ps P;
					P.sum=d-c;
					ps *t1=upper_bound(AB,AB+n*(n-1)/2,P),*t2=lower_bound(AB,AB+(n-1)*n/2,P);
					for(ps *k=t2;t1-k>0;k++){
						if(k->x!=i&&k->x!=j&&k->y!=i&&k->y!=j){
							g=d;
							break;
						}
					}
				}
			}
		}
		if(g==-1)
			cout<<"no solution"<<endl;
		else
			cout<<g<<endl;
	}
	return 0;
}
