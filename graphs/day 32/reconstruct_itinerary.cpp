https://leetcode.com/problems/reconstruct-itinerary/description/

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. 
Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Algo/Idea: 
        We cant we just choose smallest? Because the requirement is:  Find the lexicographically smallest complete Eulerian path.
        It does not mean: At every step choose the smallest edge. Those are different.
        For ex: JFK → KUL is lexicographically smaller initially, but it does not allow us to use all tickets.

  Correct Approach: Hierholzer
    We still use the smallest destination first, but we dont immediately commit it to the final answer.
    dfs(next) and only after all outgoing edges are exhausted: ans.push_back(src);

Code:

class Solution {
public:
    vector<string> res;
    unordered_map<string,priority_queue<string,vector<string>,greater<>>> mp;

    void dfs(string from){
        while(!mp[from].empty()){
            string to=mp[from].top();
            mp[from].pop();
            dfs(to);
        }
        res.push_back(from);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int m=tickets.size();

        int id=1;
        for(int i=0;i<tickets.size();i++){
            string s1=tickets[i][0];
            string s2=tickets[i][1];

            mp[s1].push(s2);            
        }

        dfs("JFK");
        reverse(res.begin(),res.end());

        return res;
    }
};
