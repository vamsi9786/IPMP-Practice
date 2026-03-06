bool isval(char* s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;r--;
    }
    return true;
}

bool validPalindrome(char* s) {
    int n=strlen(s),c=0,f=0;
    int l=0,r=n-1;
    while(l<=r){
        if(s[l]!=s[r]){
            return isval(s,l+1,r) || isval(s,l,r-1);
        }
        l++;r--;
    }
    return true;
}
