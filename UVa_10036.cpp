#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;

int dp[10005][105];
int a[10005];
int main() {
  int M;
  cin >> M;
  while(M--){
    int N, K, from = 0, to = 1;
    cin >> N >> K;
    for(int i=0; i<N; i++){
      cin >> a[i];
      a[i] %= K;
    } 

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int i=0; i<N; i++){
      for(int j=0; j<K; j++){
        if(dp[i][j]){
          dp[i+1][(j+a[i]+K) % K] = 1;
          dp[i+1][(j-a[i]+K) % K] = 1;
        }
      }
    }

    if(dp[N][0]) cout << "Divisible" << endl;
    else cout << "Not divisible" << endl;
  }
  
  return 0;
}