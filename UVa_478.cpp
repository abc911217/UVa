#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define ERROR 1e-9

vector<float> fig[105];
double a, b, c, d;
double x, y, r;
double dis, area[3];
bool _find;

double Area(double a1, double a2, double b1, double b2, double c1, double c2){
    return fabs((b1 - a1) * (c2 - a2) - (b2 - a2) * (c1 - a1)) / 2.0;
}

bool error_bound(double x, double y){
    return fabs(x - y) < ERROR;
}

int main(){
    char ch;
    int n = 1;
    while (true){
        cin >> ch;
        if (ch == '*') break;

        if (ch == 'r'){
            for (int i=0; i<2; i++){
                cin >> x >> y;
                fig[n].push_back(x);
                fig[n].push_back(y);
            }
        }
        else if (ch == 'c'){
            cin >> x >> y >> r;
            fig[n].push_back(x);
            fig[n].push_back(y);
            fig[n].push_back(r);
        }
        else if (ch == 't'){
            for (int i=0; i<3; i++){
                cin >> x >> y;
                fig[n].push_back(x);
                fig[n].push_back(y);                
            }
        }
        n++;
    }
    int t = 1;
    while (true){
        cin >> x >> y;
        if (error_bound(x, 9999.9) && error_bound(y, 9999.9)) break;
        _find = false;
        
        for (int i=1; i<n; i++){
            if      (fig[i].size() == 4){
                if (x > fig[i][0] && x < fig[i][2] && y < fig[i][1] && y > fig[i][3]){
                    cout << "Point " << t << " is contained in figure " << i << endl;
                    _find = true;
                }
            }
            else if (fig[i].size() == 3){
                dis = sqrt(pow(x - fig[i][0], (double)2.0) + pow(y - fig[i][1], (double)2.0));
                if (dis < fig[i][2]){
                    cout << "Point " << t << " is contained in figure " << i << endl;
                    _find = true;
                }
            }
            else if (fig[i].size() == 6){
                area[0] = Area(x, y, fig[i][0], fig[i][1], fig[i][2], fig[i][3]);
                area[1] = Area(x, y, fig[i][2], fig[i][3], fig[i][4], fig[i][5]);
                area[2] = Area(x, y, fig[i][4], fig[i][5], fig[i][0], fig[i][1]);
                if (error_bound(area[0] + area[1] + area[2], Area(fig[i][0], fig[i][1], fig[i][2], fig[i][3], fig[i][4], fig[i][5])) &&
                    !error_bound(area[0], 0.0) &&
                    !error_bound(area[1], 0.0) &&
                    !error_bound(area[2], 0.0) ){
                    cout << "Point " << t << " is contained in figure " << i << endl;
                    _find = true;
                }
            }
        }
        if(!_find) cout << "Point " << t <<  " is not contained in any figure" << endl;
        t++;
    }
    return 0;
}