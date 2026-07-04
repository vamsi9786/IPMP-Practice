https://leetcode.com/problems/word-ladder/description/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
          Every adjacent pair of words differs by a single letter.
          Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
          sk == endWord
  
Given two words, beginWord and endWord, and a dictionary wordList, 
return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Idea/Algo: store wordList is hash set (unordered_set) and 
           maintain a queue which stores(string and trans level): (push beginWord to queue and level 1)
                    for each word in queue: for each letter in word change it by 1 letter (a to z) 
                                            and check its existance in hash set(WordList):  
                                                        if exists then push it to queue and remove that word from set

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(!st.count(endWord)) return 0;

        queue<pair<string,int>> que;
        que.push({beginWord,1});
        while(!que.empty()){
            auto [word,level]=que.front();
            que.pop();

            if(word==endWord) return level;
            for(int i=0;i<word.size();i++){
                int ori_char=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        que.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i]=ori_char;
            }
        }
        return 0;
    }
};
                            
