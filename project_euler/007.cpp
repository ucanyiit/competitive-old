#include <bits/stdc++.h>

using namespace std;

int isPrime(int number) {
    if (number <= 1)
		return 0;

    for (int i = 2; i*i <= number; i++)
        if (number % i == 0)
			return 0;

    return 1;
}

map<int, int> res;

int rec(int m){
  if(res[m]!=0){
    return res[m];
  }
  if(m==1){
    res[1]=2;
    return 2;
  }
  int a=rec(m-1);
  a++;
  while(!isPrime(a)){
    a++;
  }
  res[m]=a;
  return res[m];
}

int main() {
    long long int n, m;
    cin>>n;
    for(int j=0;j<n;j++){
      cin>>m;
      cout<<rec(m)<<endl;
    }
    return 0;
}
