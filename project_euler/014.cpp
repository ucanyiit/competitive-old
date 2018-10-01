#include <bits/stdc++.h>


using namespace std;



 int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arr;
  int* cache = new int[5000001];
  for (long int i = 0; i < 5000001; i++) {
    cache[i] = -1;
  }
  cache[1]=1;

  long int k=0;

  for(long int i=2;i<5000001;i++){

    long long int a=i, m=0;
    while(a!=1 && a>=i){
      if(a%2){
        a=(3*a)+1;
      }
      else{
        a/=2;
      }
      m++;
    }
    cache[i]=cache[a]+m;
    if(cache[i]>=k){
      k=cache[i];
      arr.push_back(i);
    }
  }
  int arr2[arr.size()];
  copy(arr.begin(), arr.end(), arr2);

  long int annen, baban;
  cin>>annen;
  while(annen--){
    cin>>baban;
    for(int i=arr.size()-1;i>-1;i--){
      if(arr2[i]<=baban){
        cout<<arr2[i]<<endl;
        break;
      }
    }

  }
  return 0;
}
