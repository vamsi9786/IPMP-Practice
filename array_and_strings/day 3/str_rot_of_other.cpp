class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if(s1.size()!=s2.size()) return 0;
        int l=s1.size();
        string temp=s1+s1;
        //find if s2 is substring in temp i.e s1+s1
        return (temp.find(s2) != string::npos);
    }
};
