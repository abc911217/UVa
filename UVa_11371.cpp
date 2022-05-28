#include <iostream>
#include <string>
#include <algorithm>
 using namespace std;

int main(){
    long long n;
    while(cin >> n){
        string s(to_string(n));

        string min_s = s, max_s = s;
        sort(min_s.begin(), min_s.end());
        if(min_s[0] == '0'){
            int index = min_s.rfind('0') + 1;
            swap(min_s[0], min_s[index]);
        }
        sort(max_s.rbegin(), max_s.rend());
        long long a = stoll(max_s);
        long long b = stoll(min_s);
        cout << a << " - " << b << " = " << a - b << " = 9 * " << (a - b)/9 << endl; 
    }

    return 0;
}
