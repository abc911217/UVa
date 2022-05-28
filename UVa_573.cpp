#include <iostream>
using namespace std;

float H, U, D, F;
int day;
float h;// current hight
float d;// current up per day
bool success;

int main() {
  while(true){
    day = 0;
    success = false;
    h = 0;
    
    cin >> H >> U >> D >> F;
    if(H == 0) break;
    d = U;
    float down = (float)U * (F / 100);
    while(h >= 0){
      day++;// increase the day
      if(d >= 0){
        h += d;// the day
      }
      if(h > H){
        success = true;
        break;
      }
      h -= D;// the night
      d -= down;// fatigue factor
    }
    if(h < 0) success = false;
    if(success == true) cout << "success on day " << day << endl;
    else if(success == false) cout << "failure on day " << day << endl;
  }

  return 0;
}