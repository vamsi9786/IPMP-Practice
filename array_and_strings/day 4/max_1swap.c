int maximumSwap(int num) {
    int dig[10],last[10],x=num,y=0;
    if(num>=0 && num<=9) return num;

    while(x>0){
        dig[y++]=x%10;
        x=x/10;
    }
    for(int i=0;i<y/2;i++){
        int temp=dig[i];
        dig[i]=dig[y-i-1];
        dig[y-i-1]=temp;
    }
    for(int i=0;i<y;i++) last[dig[i]]=i;

    for(int i=0;i<y;i++){
        for(int d=9;d>dig[i];d--){
            if(last[d]>i){
                int t=dig[i];
                dig[i]=dig[last[d]];
                dig[last[d]]=t;
                goto done;
            }
        }
    }

    done:
        int ans=0;
        for(int i=0;i<y;i++){
            ans=ans*10+dig[i];
        }
        return ans;

}
