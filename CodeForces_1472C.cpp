#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[200005];
int dp[400005];

int main() {
  int t;
  cin >> t;
  while(t--){
    int n, ans = 0;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++) cin >> a[i];
    
    for(int i=n-1; i>=0; i--){
      if(a[i] > n)
        dp[i] = a[i];
      else
        dp[i] = a[i] + dp[i+a[i]];
      ans = max(dp[i], ans);
    }
    
    cout << ans << endl;
  }

  return 0;
}