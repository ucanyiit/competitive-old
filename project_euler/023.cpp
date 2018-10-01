#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, p, a;
    map<string, int> names;
    string m;
    cin>>n;
    vector<string> strs;
    for(int j=0;j<n;j++){
        cin>>m;
        names[m]=0;
        strs.push_back(m);
        for(int i=0;i<m.length();i++){
          names[m]+=(m[i]-'A'+1);
        }
    }
    sort(strs.begin(), strs.end());
    cin>>p;
    for(int j=0;j<p;j++){
        cin>>m;
        a=names[m];
        a=a*distance(strs.begin(), find(strs.begin(), strs.end(), m)+1);
        cout<<a<<endl;
    }
    return 0;
}
