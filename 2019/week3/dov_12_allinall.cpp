#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
    char ori_str[100001];
    char new_str[100001];
    while(1){
START:
		memset(ori_str,0,sizeof(ori_str));
		memset(new_str,0,sizeof(new_str));
        cin>>ori_str>>new_str;
        if(cin.eof() == true) break;
        char * cur = new_str;
        for(int i = 0 ; i < strlen(ori_str) ; i++){
            cur = strchr(cur,ori_str[i]);
            if(cur == NULL){
                cout<<"No"<<endl;
                goto START;
            }
            cur = cur + 1;
        }
        cout<<"Yes"<<endl;
    }
}
