char* pushDominoes(char* dominoes) {
    int n=strlen(dominoes);

    /*char* st=malloc(n+1);
    int i=0,r=-1,l=-1;
    strcpy(st,dominoes);
    st[n]='\0';
    for(int i=0;i<n;i++){
        if(l==-1 && dominoes[i]=='R'){
            r=i;
        }
        else if(r!=-1 && l==-1 && dominoes[i]=='L'){
            l=i;
            int left=r+1,right=l-1;
            while(left<right){
                st[left]='R';
                st[right]='L';
                left++;right--;
            }
            r=-1;l=-1;
        }
    }*/

    char* st=malloc(n+1);
    st[n]='\0';
    strcpy(st,dominoes);
    char lastchar='L';
    int last=-1;
    for(int i=0;i<=n;i++){ //n because we assume -1 as L and last 'n' as 'R'
        char curr=(i==n)?'R':dominoes[i];
        if(curr=='.') continue;
        
        if(curr==lastchar){
            for(int j=last+1;j<i;j++){
                st[j]=curr;
            }
        }
        else if(curr=='L' && lastchar=='R'){
            int left=last+1,right=i-1;
            while(left<right){
                st[left]='R';
                st[right]='L';
                left++;right--;
            }
        }
        last=i;
        lastchar=curr;
    }

    return st;
}
