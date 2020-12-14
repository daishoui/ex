#include<iostream>
using namespace std;
int main(){
    long long n, a[3], b[3];
    long long s = 0;
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    for(int i=0;i<3;i++){
        long long num = min(a[i],b[(i+1)%3]);
        s += num*2;
        a[i] -= num;
        b[(i+1)%3] -= num;
    }
    for(int i=0;i<3;i++){
        s += min(a[i],b[i]);
    }
    cout << s << endl;
    return 0;
}
