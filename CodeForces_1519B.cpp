#include <iostream>
using namespace std;

int a[101][101];

int main() {
  int t;
  cin >> t;
  while(t--){
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i=1; i<=m; i++) a[1][i] = i-1;
    for(int i=1; i<=n; i++) a[i][1] = i-1;

    for(int i=2; i<=n; i++){
      for(int j=2; j<=m; j++){
        a[i][j] = a[i][j-1]+i;
      }
    }
    if(a[n][m] == k) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
  return 0;
}