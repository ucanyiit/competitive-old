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

int main() {
    int n, m, mult, num;
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>m;
        mult=1;
        for(int i=2;i<=m;i++){
          if(isPrime(i)){
            num=i;
            while(num*i<=m){
              num*=i;
            }
            mult*=num;
          }
        }
        cout<<mult<<endl;
    }
    return 0;
}
