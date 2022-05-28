#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int vec[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
int adj[30][30];
bool visit[30][30];
int col, row;

int dfs(int r, int c){
  int count = 1;
  int nr, nc;
  visit[r][c] = true;
  for(int i=0; i<8; i++){
    nr = r + vec[i][0];
    nc = c + vec[i][1];
    if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
    if(adj[nr][nc] == 0) continue;
    if(adj[nr][nc] == 1 && !visit[nr][nc])
      count += dfs(nr, nc);
  }
  return count;
}

int main() {
  int n, flag = 0;
  cin >> n;
  while(n--){
    if(flag == 0)
      flag = 1;
    else
      cout << endl;
    memset(visit, 0, sizeof(visit));
    scanf("\n");
    string s;
    int k = 0;
    row = 0;
    while(1){
      getline(cin, s);
      if(s.length() == 0) break;
      col = s.length();
      for(int i=0; i<col; i++){
        adj[row][i] = (int)(s[i] - '0');
      }
      row++;
    }
    //dfs
    int _max = 0;
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        if(adj[i][j] == 1 && !visit[i][j]){
          _max = max(_max, dfs(i, j));
        }
      }
    }
    cout << _max << endl;
  }
  return 0;
}