#include <bits/stdc++.h>

using namespace std;


int main() {
    long long int n, m;
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>m;
        m=m-1;
        cout<<(3*(m/3)*(m/3+1)+5*(m/5)*(m/5+1)-15*(m/15)*(m/15+1))/2<<endl;
    }
    return 0;
}
