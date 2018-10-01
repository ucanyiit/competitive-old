#include <bits/stdc++.h>

using namespace std;


int main() {
    long double n, m, sum, plus, num;
    cin>>n;
    string str;
    for(int j=0;j<n;j++){
        cin>>m;
        num=1, sum=0;
        while(m--){
          num*=2;
        }
        str=to_string(num);
        for(int i=0;i<str.length();i++){
          plus=str[i]-'0';
          sum+=plus;
        }
        cout<<sum+2<<endl;
    }
    return 0;
}
