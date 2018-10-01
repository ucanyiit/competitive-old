#include <bits/stdc++.h>

using namespace std;

long long int sqrOfSum(int m){
  long long int sum=m*(m+1)/2;
  return sum*sum;
}

long long int sumOfSqr(int m){
  long long int sum=0;
  for(int i=1;i<=m;i++){
    sum+=i*i;
  }
  return sum;
}

int main() {
    long long int n, m;
    cin>>n;
    for(int j=0;j<n;j++){
      cin>>m;
      cout<<sqrOfSum(m)-sumOfSqr(m)<<endl;
    }
    return 0;
}
