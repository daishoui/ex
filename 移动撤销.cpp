#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
stack <pair <int, int> > s;
int main(){
    int n;
    cin >> n;
    char ch;
    int x=0, y=0;
    s.push(pair<int, int>(0,0));
    while(n--){
    	cin >> ch;
        if(ch == 'Z' && s.size() > 1){
            s.pop();
        }else if (ch == 'W'){
            pair<int,int> t;
            t.first = s.top().first;
            t.second = s.top().second + 1;
            s.push(t);
        }
        else if (ch == 'S'){
            pair<int,int> t;
            t.first = s.top().first;
            t.second = s.top().second - 1;
            s.push(t);
        }
        else if (ch == 'A'){
            pair<int,int> t;
            t.first = s.top().first -1;
            t.second = s.top().second;
            s.push(t);
        }else if (ch == 'D'){
            pair<int,int> t;
            t.first = s.top().first + 1;
            t.second = s.top().second;
            s.push(t);
        }
    }

    cout << s.top().first << " " << s.top().second << endl;
    return 0;
}