#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, t;
    cin>>n;
    vector<int> v;
    int c=n;
    for(int i=0;i<n;i++){
        cin>>t;
        vector<int>::iterator p = find(v.begin(), v.end(), t+1);
        if(p!=v.end()){
            v.erase(p);
            c--;
        }
        v.push_back(t);
    }

    cout<<c;

    
}