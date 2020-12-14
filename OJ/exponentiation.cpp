#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string add_string_string(string s1, string s2){
    string ms, Ms;
    if(s1.size() > s2.size()){
        ms = s2;
        Ms = s1;
    } else{
        ms = s1;
        Ms = s2;
    }
    reverse(ms.begin(),ms.end());
    reverse(Ms.begin(),Ms.end());
    string rs = Ms;
    int pflag = 0;
    for(int i=0;i<ms.size();i++){
        int temp = rs[i] - '0' + ms[i] - '0' + pflag;
        if(temp >= 10) pflag = 1;
        else pflag = 0;
        rs[i] = char((temp %10) + '0');
    }
    for(int i=ms.size();i<Ms.size() && pflag == 1;i++){
        int temp = rs[i] - '0' + pflag;
        if(temp >= 10) pflag = 1;
        else pflag = 0;
        rs[i] = char((temp %10) + '0');
    }
    if(pflag == 1){
        rs += "1";
    }
    reverse(rs.begin(), rs.end());
    return rs;
}
string mul_string_string(string s1, string s2){
    string ms, Ms;
    if(s1.size() > s2.size()){
        ms = s2;
        Ms = s1;
    } else{
        ms = s1;
        Ms = s2;
    }
    reverse(ms.begin(),ms.end());
    reverse(Ms.begin(),Ms.end());
    string rs = "0";
    for(int i=0;i<ms.size();i++){
        int pflag = 0;
        string temp(i + Ms.size(),'0');
        for(int j=0;j<Ms.size();j++){
            int z = pflag + (ms[i] - '0')*(Ms[j] - '0');
            pflag = int((z - (z%10))/10);
            temp[i+j] = char((z%10)+'0');
        }
        if(pflag > 0) temp += char(pflag + '0');
        reverse(temp.begin(),temp.end());
        rs = add_string_string(rs, temp);
    }
    return rs;
}
int main(){
    string s;
    int n;
    while(cin>>s>>n){
        string t = "";
        int p = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] != '.') p++;
            else break;
        }
        for(int i=0;i<s.size();i++){
            if(s[i] != '.') t += s[i];
        }
        string rs = t;
        for(int i=1;i<n;i++){
            rs = mul_string_string(rs, t);
        }
        string fs = rs.substr(0,rs.size() - n * p);
        string es = rs.substr(rs.size() - n * p);
        int i = 0;
        while(i<fs.size()){
            if(fs[i] != '0') break;
            i++;
        }
        fs = fs.substr(i);
        int j = es.size() - 1;
        while(j>=0){
            if(es[j] != '0') break;
            j--;
        }
        es = es.substr(0,j+1);
        if(fs == "" && es == ""){
            cout << 0 << endl;
        }
        else if(fs == ""){
            cout << "." << es << endl;
        }
        else if(es == ""){
            cout << fs << endl;
        }
        else{
            cout << fs << "." << es << endl;
        }
    }
    return 0;
}