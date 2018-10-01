#include <bits/stdc++.h>

using namespace std;


int main() {
    long long int n, m;
    cin>>n;
    for(int j=0;j<n;j++){
      long long int a1=1, a2=1, temp, sum=0;
      cin>>m;
      while(a2<m){
        if(a2%2==0){
          sum+=a2;
        }
        temp=a1+a2;
        a1=a2;
        a2=temp;
      }
      cout<<sum<<endl;
    }
    return 0;
}
