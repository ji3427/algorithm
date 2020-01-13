#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>

using namespace std;  

const int maxn = 1001000;  

char arrn[maxn];  

void preKMP(char x[], int m, int kmpNext[]){
    int i, j;  
    j=kmpNext[0]=-1;  
    i=0;  
    while(i < m){
        while(-1 != j && x[i] != x[j]) j = kmpNext[j];  
        kmpNext[++i] = ++j;  
    }
}

int nxt[maxn];  

int main(){  
    int n;  
    while(~scanf("%s", arrn)){
        if(arrn[0] == '.') break;  
        int n = strlen(arrn);  
        preKMP(arrn, n, nxt);  
        int len = n - nxt[n];  
        if( n % len )printf("1\n");  //不能表示为循环节
        else printf("%d\n",  n/len);  
    }

    return 0;  
}
