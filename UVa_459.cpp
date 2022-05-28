#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define N 100000

vector<int> adj[N];
bool visit[N];
int _count = 0;

void dfs(int s){
  visit[s] = true;
  for(int u:adj[s]){
    if(!visit[u]){
          dfs(u);
    }
  }
  return;
}

int main() {
  int n, flag = 0;
  cin >> n;
  while(n--){
    if(flag == 0) flag = 1;
    else cout << endl;
    memset(visit, 0, sizeof(visit));
    _count = 0;

    char c;
    scanf("\n%c", &c);
    int _size = c - 64;
    cin.ignore();

    string s;

    while(1){
      getline(cin, s);
      if(s.length() == 0) break;
      int a = (int)s[0] - 65;
      int b = (int)s[1] - 65;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for(int i=0; i<_size; i++){
      if(!visit[i]){
        _count++;
        dfs(i);
      }
    }

    cout << _count << endl;
    for(int i=0; i<_size; i++){
      adj[i].clear();
    }
  }
  
  return 0;
}
