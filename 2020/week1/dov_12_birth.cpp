#include <iostream>
#include <math.h>

using namespace std;
int year,month,day;
int mday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char week[7][10] = {"wednesday", "thursday", "friday", "saturday","sunday","monday", "tuesday"};
int isleap = 0;
int main(void)
{
	int sum = 0;
	cin>>year>>month>>day;
	int low = min(1800,year);
	int high = max(1800,year);
	for(int index = low ; index < high  ; index++){
		if((index % 4 == 0 && index % 100 != 0) || (index % 400 == 0)) sum+=366;
		else sum += 365;
	}
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) isleap = 1;
	for(int i = 0 ; i < month - 1 ; i++){
		sum += mday[i];
	}
	if(month > 2) sum+= isleap;
	sum += day-1;
	cout<<week[sum%7]<<endl;
}
