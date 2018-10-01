#include <bits/stdc++.h>

using namespace std;

/*  medium ( actually easy )  */

/*  find all combinations and compare ( 3^17 ) */

long long solve(vector<int> &a, long long p, long long q, long long r, int mask){
    if(a.size() == 0){
        return ((mask == 7) && (p == q) && (q == r)) ? 1 : 0;
    }

    int elem = a.back();
    a.pop_back();
    
    long long answer = 0;
    answer += solve(a, p+elem, q, r, mask|1);
    answer += solve(a, p, q+elem, r, mask|2);
    answer += solve(a, p, q, r+elem, mask|4);

    a.push_back(elem);

    return answer;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    long long answer = solve(a,0,0,0,0);
    cout << answer << endl;

    return 0;
}