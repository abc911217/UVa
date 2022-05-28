#include <iostream>
#include <algorithm>
using namespace std;

int a[10005];
int b[10005];
int T = 1;

int main(){
    while(true){
        int N, Q;
        cin >> N >> Q;
        if(N == 0 && Q == 0) break;
        for(int i=0; i<N; i++){
            cin >> a[i];
        }
        for(int i=0; i<Q; i++){
            cin >> b[i];
        }
        sort(a, a+N);
        cout << "CASE# " << T << ":" << endl;
        for(int i=0; i<Q; i++){
            auto k = lower_bound(a, a+N, b[i]) - a;
            if(k < N && a[k] == b[i])
                cout << b[i] << " found at " << k + 1 << endl;
            else
                cout << b[i] << " not found" << endl;
        }
        T++;
    }
    
    return 0;
}