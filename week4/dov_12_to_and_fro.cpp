#include <iostream>
#include <string.h>

using namespace std;
char message[101][21];
int main(void)
{
	char str[200];
	int size;
	cin>>size;
	cin>>str;
	int i = 0;
	while(1){
		if(i*size > strlen(str)) break;
		strncpy(message[i],str + i*size , size);
		if(i%2 == 1){
			int start = 0;
			int end = size -1;
			while(start < end){
				char temp = message[i][start];
				message[i][start] = message[i][end];
				message[i][end] = temp;
				start++;
				end--;
			}
		}
		i++;
	}

  for(int n = 0 ; n < size ; n ++){
        for(int j = 0 ; j < i-1 ; j++){
            cout<<message[j][n];
        }
    }
}
