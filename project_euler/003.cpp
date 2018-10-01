#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, m;
    cin>>n;
    for(int j=0;j<n;j++){
      cin>>m;
      int a=0;
      while(m%2==0){
        m/=2;
      }
      if(m==1){
        cout<<1<<endl;
        a=1;
      }
      else{
      for(int k=3;k<=sqrt(m);k+=2){
          while(m%k==0){
            m/=k;
            if(m==1){
              cout<<k<<endl;
              a=1;
              break;
            }
          }
        }
      }
      if(a==0){
        cout<<m<<endl;
      }
    }
    return 0;
}
