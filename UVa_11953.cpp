#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n, alive, hit, ship_area;
int vec[4][2] = {-1,0, 1,0, 0,-1, 0,1};
char map[105][105];
bool visit[105][105];

void dfs(int r, int c){
  if(map[r][c] == 'x'){
    ship_area++;
  }
  if(map[r][c] == '@'){
    ship_area++;
    hit++;
  }
  int nr, nc;
  visit[r][c] = true;
  for(int i=0; i<4; i++){
    nr = r + vec[i][0];
    nc = c + vec[i][1];
    if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
    if(map[nr][nc] == '.') continue;
    if(!visit[nr][nc])
      dfs(nr, nc);
  }
  return;
}

int main() {
  int t, flag = 0;
  cin >> t;
  while(t--){
    flag++;
    memset(visit, 0, sizeof(visit));
    alive = 0;
    cin >> n;
    for(int i=0; i<n ;i++){
      scanf("%s", map[i]);
    }
    //dfs
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if((map[i][j] == 'x' || map[i][j] == '@') && !visit[i][j]){
          hit = 0;
          ship_area = 0;
          dfs(i, j);
          if(ship_area > hit) alive++;
        }
      }
    }
    cout << "Case " << flag << ": " << alive << endl;
  }
  
  return 0;
}