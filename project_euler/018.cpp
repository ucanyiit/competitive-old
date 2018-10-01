#include <bits/stdc++.h>

using namespace std;
int biggest=0;

struct node {
  int data;
  int height;
  int place;
};

node manymanynodes[1000][1000];


void go(struct node *n, int sum){
  sum+=n->data;
  if(n->height==1){
    if(sum>biggest){
      biggest=sum;
      return;
    }
  }
  if(n->place!=0){
    go(&manymanynodes[n->height-1][n->place-1], sum);
  }
  if(n->place!=n->height){
    go(&manymanynodes[n->height-1][n->place], sum);
  }
}


struct node newNode(int data, int height, int place){
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->height = height;
  node->place = place;
  return *node;
}

int main() {
  int n, temp, yeman;
  cin>>yeman;
  while(yeman--){
    cin>>n;
    for(int i=1;i<=n;i++){
      for(int j=i;j>0;j--){
        cin>>temp;
        manymanynodes[i][j] = newNode(temp, i, j);
      }
    }
    biggest=0;
    for(int i=1;i<=n;i++){
      go(&manymanynodes[n][i], 0);
    }
    cout<<biggest<<endl;

  }
  return 0;
}
