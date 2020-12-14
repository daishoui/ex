#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int> m;
vector<string> v;
int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        string cs = "";
        for(int j=0;j<s.size();j++){
            switch(s[j]){
                case 'A':
                case 'B':
                case 'C':
                    cs += "2";
                    break;
                case 'D':
                case 'E':
                case 'F':
                    cs += "3";
                    break;
                case 'G':
                case 'H':
                case 'I':
                    cs += "4";
                    break;
                case 'J':
                case 'K':
                case 'L':
                    cs += "5";
                    break;
                case 'M':
                case 'N':
                case 'O':
                    cs += "6";
                    break;
                case 'P':
                case 'R':
                case 'S':
                    cs += "7";
                    break;
                case 'T':
                case 'U':
                case 'V':
                    cs += "8";
                    break;
                case 'W':
                case 'X':
                case 'Y':
                    cs += "9";
                    break;
                case '-':
                    break;
                default:
                    cs += s[j];
                    break;
            }
        }
        if(m.count(cs) == 0){
            m[cs] = 0;
            v.push_back(cs);
        }
        m[cs] += 1;
    }
    sort(v.begin(),v.end());
    bool flag = true;
    for(int i=0;i<v.size();i++){
        string outstr = v[i];
        if(m[outstr] > 1){
            flag = false;
            cout << outstr.substr(0,3) << "-" << outstr.substr(3) << " " << m[outstr] << endl;
        }
    }
    if(flag){
        cout << "No duplicates." << endl;
    }
    return 0;
}
