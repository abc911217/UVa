#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int black, white;
bool bound[2]; //black = bound[0] white = bound[1]
int vec[4][2] = {-1,0, 1,0, 0,-1, 0,1};
char go[10][10];
bool visit[10][10];

int dfs(int r, int c){
  int nr, nc, count = 1;
  visit[r][c] = true;
  for(int i=0; i<4; i++){
    nr = r + vec[i][0];
    nc = c + vec[i][1];
    if(nr < 0 || nr >= 9 || nc < 0 || nc >=9) continue;
    if(go[nr][nc] == 'X'){
      bound[0] = true;
      continue;
    }
    if(go[nr][nc] == 'O'){
      bound[1] = true;
      continue;
    }
    if(!visit[nr][nc])
      count += dfs(nr, nc);
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while(t--){
    memset(visit, 0, sizeof(visit));
    black = 0;
    white = 0;
    for(int i=0; i<9; i++){
      scanf("%s", go[i]);
    }
    //dfs
    for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
        if(go[i][j] == '.' && !visit[i][j]){
          bound[0] = false;
          bound[1] = false;
          int count = dfs(i, j);
          if(bound[0] && bound[1]){}
          else if(bound[0]) black += count;
          else if(bound[1]) white += count;
        }
        else if(go[i][j] == 'X') black++;
        else if(go[i][j] == 'O') white++;
      }
    }
    cout << "Black " << black << " White " << white << endl;
  }
  
  return 0;
}