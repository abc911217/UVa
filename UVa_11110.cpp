#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int n;
int a[105][105];
int visit[105][105];
int vec[4][2] = {-1,0, 1,0, 0,-1, 0,1};
int _count, n_count;
bool err;

void dfs(int r, int c){
  int nr, nc;
  visit[r][c] = true;
  for(int i=0; i<4; i++){
    nr = r + vec[i][0];
    nc = c + vec[i][1];
    if(nr <= 0 || nr > n || nc <= 0 || nc > n) continue;
    if(a[nr][nc] != a[r][c]) continue;
    if(!visit[nr][nc])
      dfs(nr, nc);
  }
  return;
}

int main() {
  while(true){
    memset(visit, 0, sizeof(visit));
    memset(a, 0, sizeof(a));
    _count = 0;
    n_count = 0;
    err = false;

    cin >> n;
    if(n == 0) break;
    
    string line;
    cin.ignore();
    int y, x;
    for(int i=1; i<n; i++){
      getline(cin, line);
      stringstream ss(line);
      while(ss >> x >> y)
        a[y][x] = i;
    }
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++){
      if(a[i][j] == 0){
        a[i][j] = n;
        n_count++;
      }
    }
    if(n_count > n) err = true;
    if(err == false){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(!visit[i][j]){
          dfs(i, j);
          _count++;
        }
      }
    }
      if(_count != n) err = true;
    }
    
    if(err == false) cout << "good" << endl;
    else cout << "wrong" << endl;
  }
  
  return 0;
}