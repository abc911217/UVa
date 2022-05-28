#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    
    string r1, r2;
    int a[105];
    cin.ignore();
    getline(cin, r1);
    getline(cin, r2);

    for(int i=0; i<n; i++){
      if(r1[i] == '1' && r2[i] == '1') a[i] = 0;
      else a[i] = 1;
    }
    for(int i=0; i<n; i++){
      if(a[i] == 0){
        cout << "NO" << endl;
        break;
      }
      else if(i == n-1 && a[i] == 1)
        cout << "YES" << endl;
    }
  }
  
  return 0;
}