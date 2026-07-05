https://leetcode.com/problems/sliding-puzzle/description/

On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. 
A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. 
If it is impossible for the state of the board to be solved, return -1.

Algo: 1. Convert board into string.
      2. Goal = "123450".
      3. Push initial string into queue.
      4. While queue not empty:
                Pop current state.
                If curr==target, return level.
                Find position of '0'.
                Swap with every possible neighbor.
                If new state not visited: Push into queue.
      5. If BFS ends, return -1.
  
Code:  
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=char(board[i][j]+'0');
            }
        }
        string target="123450";

        vector<vector<int>> moves={
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };
        queue<string> que;
        unordered_set<string> vis;
        que.push(start);
        vis.insert(start);
        int ans=0;
        while(!que.empty()){
            int n=que.size();
            for(int i=0;i<n;i++){
                string curr=que.front();
                que.pop();

                if(curr==target) return ans;

                int zero_idx=curr.find('0');
                for(int next:moves[zero_idx]){
                    string temp=curr;
                    swap(temp[next],temp[zero_idx]);
                    if(!vis.count(temp)){
                        vis.insert(temp);
                        que.push(temp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
