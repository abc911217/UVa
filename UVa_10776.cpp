#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> record;
string s;
int r;

void solution(vector<char> ans, int k){
    if(ans.size() == r){
        for(int i=0; i<r; i++)
            cout << ans[i];
        cout << endl;
        return;
    }
    
    for(int i=k; i<s.size(); i){
        char c = s[i];
        ans.push_back(c);
        solution(ans, i + 1);
        ans.pop_back();
        while(c == s[i]) i++;
    }
}

int main(){
    while(cin >> s >> r){
        sort(s.begin(), s.end());
        vector<char> ans;
        solution(ans, 0);
    }

    return 0;
}