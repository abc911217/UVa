#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];

int main() {
  int n;

  while(1){
    cin >> n;
    if(n == 0) break;
    int a[10005], ans = 0;
    for(int i=0; i<n; i++){
      cin >> a[i];
    }
    for(int i=1; i<=n; i++){
      dp[i] = max(a[i-1], dp[i-1]+a[i-1]);
      ans = max(dp[i], ans);
    }
    if(ans > 0) cout << "The maximum winning streak is " << ans << "." << endl; 
    else cout << "Losing streak." << endl;
  }
  
  return 0;
}