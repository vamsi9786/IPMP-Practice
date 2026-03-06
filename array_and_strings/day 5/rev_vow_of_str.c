#include <string.h>
int isvow(char c){
    if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' ||c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U') return 1;
    else return 0;
}

char* reverseVowels(char* s) {
    int len=strlen(s);
    int l=0,r=len-1;
    while(l<r){
        if(!isvow(s[l])) l++;
        else if(!isvow(s[r])) r--;
        if(isvow(s[l]) && isvow(s[r])){
            char t=s[l];
            s[l]=s[r];
            s[r]=t;
            l++;r--;
        }
    }
    return s;
}
