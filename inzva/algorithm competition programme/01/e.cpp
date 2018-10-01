#include <bits/stdc++.h>

using namespace std;

/*  easy  */

/*  1- ans=n
    2- read the number
        - if the number+1 isn't in the vector add number to vector
        - else ( ans-- ) and ( add number to vector )
    3- repeat 2  */

int main(){
    int n, t;
    cin>>n;
    vector<int> v;
    int ans=n;
    for(int i=0;i<n;i++){
        cin>>t;
        vector<int>::iterator p = find(v.begin(), v.end(), t+1);
        if(p!=v.end()){
            v.erase(p);
            ans--;
        }
        v.push_back(t);
    }

    cout<<ans;
}