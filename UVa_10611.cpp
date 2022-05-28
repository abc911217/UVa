#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;
long long a[50005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> a[i];
    cin >> Q;
    long long height;
    for(int i=0; i<Q; i++){
        cin >> height;
        int _lower = lower_bound(a, a + N, height) - a;
        int _upper = upper_bound(a, a + N, height) - a;
        
        if(_lower >= N || a[_lower] >= height)
            _lower--;

        if(_lower < N && _lower >=0)
            cout << a[_lower] << " ";
        else
            cout << "X ";

        if(_upper < N)
            cout << a[_upper] << endl;
        else
            cout << "X" << endl;
    }

    return 0;
}