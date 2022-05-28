#include <iostream>
#include <cstring>
using namespace std;

int _find, ans = 0;
int M[105*105];

void clean(int r, int c, int *M, int n, int m, int dr, int dc){
  for(int i=1; i<=m; i++)
    if(M[(r-1)*m+i] == 1) _find = 1;
  for(int i=1; i<=n; i++)
    if(M[(i-1)*m+c] == 1) _find = 1;
  if(_find == 0){
    ans++;
    if((c == 0 && r == 0) || (c == 0 && r == n) || (c == m && r == 0) || (c == m && r == n))
      clean(r-dr, c-dc, M, n, m, -dr, -dc);
    else if(c == 0 || c == m)
      clean(r+dr, c-dc, M, n, m, dr, -dc);
    else if(r == 0 || r == n)
      clean(r-dr, c+dc, M, n, m, -dr, dc);
    else
      clean(r+dr, c+dc, M, n, m, dr, dc);
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m, rb, cb, rd, cd, dr = 1, dc = 1;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    _find = 0;
    ans = 0;
    memset(M, -1, sizeof(M));
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(i!=n+1 && j!=m+1) M[(i-1)*m+j] = 0;
      }
    }
    M[(rd-1)*m+cd] = 1;
    clean(rb, cb, M, n, m, dr, dc);
    cout << ans << endl;
  }
  
  return 0;
}