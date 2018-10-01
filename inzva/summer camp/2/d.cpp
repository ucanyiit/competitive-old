#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }    

    deque<int> yeye;
    yeye.push_back(arr[0]);
    for(int i=1;i<k;i++){
        while(!yeye.empty() && arr[i]>yeye.back()){
            yeye.pop_back();
        }
        yeye.push_back(arr[i]);
    }
    cout<<yeye.front()<<" ";

    for(int i=k;i<n;i++){
        if(yeye.front()==arr[i-k]){
            yeye.pop_front();
        }
        while(!yeye.empty() && arr[i]>yeye.back()){
            yeye.pop_back();
        }
        yeye.push_back(arr[i]);
        cout<<yeye.front()<<" ";
    }

}