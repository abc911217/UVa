#include <iostream>
#include <string>
#include <sstream>
 using namespace std;

 int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
 }

 int main(){
    stringstream ss;
    int n, a[100] = {};
    cin >> n;
    cin.ignore();

    while(n--){
        string line;
        memset(a, 0, sizeof(a));
        int length = 0, GCD, M = 1;

        getline(cin, line);
        ss << line;
        for(int i=0; i<100; i++){
            ss >> a[i];
            if(ss.fail()) break;
            length++;
        }
        for(int i=0; i<length; i++){
            for(int j=i+1; j<length; j++){
                GCD = gcd(a[i], a[j]);
                if(GCD > M) M = GCD;
            }
        }
        cout << M << endl;
        ss.str("");
        ss.clear();
    }
    
    return 0;
 }
