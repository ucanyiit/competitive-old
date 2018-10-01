#include <bits/stdc++.h>

using namespace std;


int main() {
    long long int n, m, flag;
    string str;
    vector<int> arr;
    for(int x=999;x>100;x--){
      for(int y=999;y>100;y--){
        int k=x*y;
        if(k>101100 && k<1000000 && k%10==k/100000 && (k/10)%10==(k/10000)%10 && (k/100)%10==(k/1000)%10){
          arr.push_back(k);
        }
      }
    }
    cin>>n;
    for(int j=0;j<n;j++){
        int diff=1000000, o=0;
        cin>>m;
        for(int i=0;i<arr.size();i++){
          if(m-arr[i]<diff && m-arr[i]>0){
            diff=m-arr[i];
            o=arr[i];
          }
        }
        cout<<o<<endl;
    }
     return 0;
}
