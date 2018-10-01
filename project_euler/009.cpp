#include <bits/stdc++.h>

using namespace std;


int main() {
    long long int n, m, a, flag, b, k, c;
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>m;
        k=0;
        if(m%2!=0){
          cout<<-1<<endl;
          continue;
        }
        flag=0;
        for(a=3;a<m/3;a++){
          b=a*a-(a-m)*(a-m);
          b/=2*a-2*m;
          c=m-(a+b);
          if(c==sqrt(b*b+a*a)){
            flag=1;
            if(a*b*c>k){
              k=a*b*c;
            }
          }
        }
        if(flag==0){
          cout<<-1<<endl;
        }
        else{
          cout<<k<<endl;
        }
    }
    return 0;
}
