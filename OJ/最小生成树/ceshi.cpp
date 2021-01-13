#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
int a[110][110],n;
int main(){
	ofstream fout("²âÊÔÊı¾İ.txt");
	srand((unsigned)time(NULL));
	n=100;
	fout<<n<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j<=i) fout<<a[j][i]<<" ";
			else fout<<(a[i][j]=(rand()%100000)+1)<<" ";
		}
		fout<<endl;
	}
	return 0;
} 
