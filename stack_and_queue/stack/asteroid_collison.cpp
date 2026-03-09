https://leetcode.com/problems/asteroid-collision/description/

We are given an array asteroids of integers representing asteroids in a row. 
The indices of the asteroid in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> stk;

        for(int curr:asteroids){
            int destroyed=0;
            while(!stk.empty() && stk.top()>0 && curr<0){
                if(abs(curr)>stk.top()){
                    stk.pop();continue;
                }
                else if(abs(curr)==stk.top()){
                    stk.pop();
                }
                destroyed=1;
                break;
            }
            if(!destroyed) stk.push(curr);
        }
        vector<int> res(stk.size());
        for(int i=stk.size()-1;i>=0;i--){
            res[i]=stk.top();
            stk.pop();
        }
        return res;
    }
};
