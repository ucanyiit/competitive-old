#include <bits/stdc++.h>
using namespace std;
long long res[1000001];
bool prime[1000001];
void primes(int n) {
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++){
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true){
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 }

int main() {
    primes(1000001);
    res[0]=res[1]=0;
    long long int n, m;
    cin>>n;
    for(int j=2;j<=1000000;j++){
        res[j] = res[j-1] + (prime[j] ? j : 0);
    }
    for(int j=0;j<n;j++){
        cin>>m;
        cout<<res[m]<<endl;
    }
    return 0;
}
