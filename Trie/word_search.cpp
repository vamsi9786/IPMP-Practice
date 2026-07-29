https://leetcode.com/problems/word-search-ii/description/

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

//Trie Solution

class TrieNode{
public:
    TrieNode* child[26];
    bool end;
    string word;

    TrieNode(){
        end=false;
        word="";
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};

class Solution {
public:
    TrieNode* root=new TrieNode();
    vector<string> ans;
    int m,n;

    void insert(string& s){
        TrieNode* node=root;

        for(char &c:s){
            if(node->child[c-'a']==NULL){
                node->child[c-'a']=new TrieNode();
            }
            node=node->child[c-'a'];
        }
        node->end=true;
        node->word=s;
    }

    void dfs(int i,int j,TrieNode* node,vector<vector<char>>& board){
        if(i<0 || j<0 || i>=m || j>=n) return;

        char ch=board[i][j];

        if(ch=='#') return;

        node=node->child[ch-'a'];
        if(node==NULL) return;

        if(node->end){
            ans.push_back(node->word);
            node->end=false; //to avoid adding duplicates
        }

        board[i][j]='#';
        dfs(i-1,j,node,board);
        dfs(i,j-1,node,board);
        dfs(i+1,j,node,board);
        dfs(i,j+1,node,board);
        board[i][j]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int l=words.size();
        m=board.size(),n=board[0].size();

        for(int i=0;i<l;i++){
            insert(words[i]);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,root,board);
            }
        }
        return ans;
    }
};



//TLE (Backtracking)
class Solution {
public:
    int m,n;
    bool helper(int i,int j,int k,string& s,vector<vector<char>>& board,vector<vector<bool>>& vis){
        if(k==s.size()) return true;
        if(i>=m || j>=n || i<0 || j<0) return false;
        
        if(board[i][j]!=s[k] || vis[i][j]) return false;

        vis[i][j]=true;

        bool ans= helper(i-1,j,k+1,s,board,vis) || helper(i,j-1,k+1,s,board,vis) ||
                helper(i+1,j,k+1,s,board,vis) || helper(i,j+1,k+1,s,board,vis);

        vis[i][j]=false;

        return ans;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        int l=words.size();
        m=board.size(),n=board[0].size();

        unordered_map<char,vector<pair<int,int>>> pii;
        unordered_set<char> st;
        for(int i=0;i<l;i++){
            st.insert(words[i][0]);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(st.count(board[i][j])){
                    pii[board[i][j]].push_back({i,j});
                }
            }
        }

        for(int i=0;i<l;i++){
            vector<pair<int,int>> temp=pii[words[i][0]];
            for(int j=0;j<temp.size();j++){
                auto it=temp[j];
                vector<vector<bool>> vis(m,vector<bool>(n,false));
                if(helper(it.first,it.second,0,words[i],board,vis)){
                    ans.push_back(words[i]);
                    break;
                }
            }   
        }

        return ans;
    }
};
