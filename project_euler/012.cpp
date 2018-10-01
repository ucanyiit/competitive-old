#include <bits/stdc++.h>

using namespace std;

map<int,int> arr;

int factor(int n){
  long long int number=1, sum, trinum=1;
  while(number=trinum*(trinum+1)/2){
    if(arr[trinum]==0){
      sum=1;
      for (int i=2; i <= sqrt(number); i++){
        int a=1;
        while(number % i == 0){
          a++;
          number /= i;// "num" divided by "i" is now "num"
        }
        sum*=a;
      }
      if(number>1){
        number /= number;
        sum*=2;
      }
      arr[trinum]=sum;
    }
    if(arr[trinum]>n){
      return trinum*(trinum+1)/2;
    }
    trinum++;
  }
  return -1;
}


int main() {
    long long int n, m;
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>m;
        cout<<factor(m)<<endl;
    }
    return 0;
}
