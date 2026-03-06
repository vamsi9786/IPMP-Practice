class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1=(int)name.size();
        int n2=(int)typed.size();
        if(n2<n1){
            return false;
        }
        int j=0,i=0;
        while(j<n2){
            if(i<n1 && name[i]==typed[j]){
                i++;
                j++;
            }
            else if(j>0 && typed[j]==typed[j-1] ){
                j++;
            }
            else{
                return false;
            }
        }
        return i==n1;
    }
};
