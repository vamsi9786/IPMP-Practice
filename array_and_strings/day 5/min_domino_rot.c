Algorithm:
  for tops[0] check no of swaps to be made
  for bottoms[0] check no of swaps to be made


int check(int x,int* tops,int* bottoms,int n){
    int st=0,sb=0;
    for(int i=0;i<n;i++){
        if(tops[i]!=x && bottoms[i]!=x) return -1;
        if(tops[i]!=x) st++;
        else if(bottoms[i]!=x) sb++;
    }
    return (st<sb)?st:sb;
}

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    int n=topsSize;
    int res1=check(tops[0],tops,bottoms,n);
    int res2=check(bottoms[0],tops,bottoms,n);
    if(res1==-1 && res2==-1) return -1;
    else if(res1!=-1 && res2==-1) return res1;
    else if(res1==-1 && res2!=-1) return res2;
    else return (res1<res2)?res1:res2;
}
