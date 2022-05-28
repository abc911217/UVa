#include <iostream>
#include <string>
using namespace std;
#define MAX 32000

int len[MAX];
string s[MAX];

int bsearch(int a[], int n, int x){
    int index = 0;
    for(int jump=n/2; jump>=1; jump/=2){
        while(index + jump < n && a[index + jump] <= x)
            index += jump; 
    }
    if(a[index] == x) return index - 1;
    else return index;
}

int main(){
    int t;
    cin >> t;
    int i = 1;
    for(i=1; len[i-1]>=0; i++){// if overflow then break
        s[i] = s[i-1] + to_string(i);
        len[i] = len[i-1] + s[i].length();
    }
    int size = i;
    while(t--){
        int n;
        cin >> n;
        int a, b;
        a = bsearch(len, size, n);
        b = n - len[a];
        cout << s[a+1][b-1] << endl;
    }
    
    return 0;
}