#include <iostream>
#include <vector>
using namespace std;

string s;

void backtrack(vector<char> ans,vector<char> line, int start, int r){
    if(ans.size() == r){
        for(int i=0; i<ans.size(); i++) cout << ans[i];
        cout << endl;
        return;
    }
    if(ans.size() == 0) ans.push_back(line[0]);
    for(int i=0; i<=ans.size(); i++){
        ans.insert(ans.begin() + i, line[start]);
        backtrack(ans, line, start+1, r);
        ans.erase(ans.begin() + i);
    }
}

int main(){
    int flag = 1;
    while(cin >> s){
        if(!flag) cout << endl;
        flag = 0;
        vector<char> line;
        for(int i=0; i<s.length(); i++){
            line.push_back(s[i]);
        }
        vector<char> ans;
        backtrack(ans, line, 1, line.size());
    }
    
    return 0;
}