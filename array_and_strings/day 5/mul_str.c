#include <string.h>
#include <stdlib.h>
#include <math.h>
char* multiply(char* num1, char* num2) {
    int d1=strlen(num1),d2=strlen(num2);
    if(d1==0 || d2==0) return "0";
    int* res=calloc(d1+d2,sizeof(int));
    if(!res) return NULL;

    for(int i=d1-1;i>=0;i--){
        int c1=num1[i]-'0';
        for(int j=d2-1;j>=0;j--){
            int c2=num2[j]-'0';
            res[i+j+1]+=c1*c2;
        }
    }
    for(int i=d1+d2-1;i>0;i--){
        res[i-1]=res[i-1] + res[i]/10;
        res[i]=res[i]%10;
    }

    int st=0;
    while(st<d1+d2 && res[st]==0) st++;

    int len=d1+d2-st;
    if(len==0) len=1;

    char* s=malloc(len+1);
    if(!s){
        free(res);
        return NULL;
    }

    for(int i = 0; i < len; i++){
        s[i] = (st+i < d1+d2)? res[st+i] + '0' : '0';
    }
    s[len]='\0';

    free(res);
    return s;
}
