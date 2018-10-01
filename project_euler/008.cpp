#include <bits/stdc++.h>

using namespace std;


int main() {
    long long int n, m, k, bmult, mult;
    string str;
    cin>>n;
    for(int j=0;j<n;j++){
        bmult=1;
        cin>>m>>k;
        cin>>str;
        for(int i=0;i<m-k+1;i++){
          mult=1;
          for(int p=0;p<k;p++){
            int a = str[p+i] - '0';
            mult*=a;
          }
          if(bmult==1 || mult>bmult){
            bmult=mult;
          }
        }
        cout<<bmult<<endl;
    }
    return 0;
}
