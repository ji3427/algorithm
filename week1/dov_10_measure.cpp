#include <iostream>
#include <algorithm>

using namespace std;

int point[3][2];
int main(void)
{
  double length;
  cin>>length;
  double mid;
  for(int i = 0 ; i < 3; i ++){
    cin>>point[i][0]>>point[i][1];
  }
  for(int i = 0 ; i < 3; i++){
    if(point[i][0] != point[i][1]){
      mid = (double)(point[i][0] + point[i][1]) / 2;
      if(mid < length/2){
        for(int j = i + 1; j < 3 ; j++){
          for(int k = 0 ; k < 2 ; k++){
            if(point[j][k] <= mid){
              point[j][k] += (length - mid * 2);
            }
            else{
              point[j][k] = length - point[j][k]; 
            }
          }
        }
        length-= mid;
      }
      else{
        for(int j = i + 1 ; j < 3 ; j++){
          for(int k = 0 ; k < 2 ; k++){
            if(point[j][k] > mid)
              point[j][k] = mid - (point[j][k] - mid);
          }
        }
        length = mid;
      }
    }
  }
  printf("%0.1f", length);
  return 0;
}
