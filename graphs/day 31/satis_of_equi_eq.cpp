https://leetcode.com/problems/satisfiability-of-equality-equations/description/

You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 
and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) 
that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

class DSU{
    public:
        vector<int> par;
        vector<int> size;
        DSU(){
            par.resize(26);
            size.resize(26,1);
            for(int i=0;i<26;i++){
                par[i]=i;
            }
        }

        void unionjoin(char c1,char c2){
            char u=findPar(c1);
            char v=findPar(c2);

            if(u==v) return;

            if(size[u-'a']<size[v-'a']) swap(u,v);

            par[v-'a']=u-'a';
            size[u-'a']+=size[v-'a'];
        }

        char findPar(char c1){
            int t=c1-'a';
            while(par[t]!=t){
                t=par[t];
            }
            return t+'a';
        }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();

        DSU ds;
        for(string &s:equations){
            char c1=s[0];
            char c2=s[1];
            char c3=s[3];

            if(c2=='=' && ds.findPar(c1)!=ds.findPar(c3)) ds.unionjoin(c1,c3);
        }
        for(string &s:equations){
            char c1=s[0];
            char c2=s[1];
            char c3=s[3];
            if(c2=='!' && ds.findPar(c1)==ds.findPar(c3)){
                return false;
            }
        }

        return true;
    }
};
