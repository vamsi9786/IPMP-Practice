https://leetcode.com/problems/gas-station/

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
You begin the journey with an empty tank at one of the gas stations.Given two integer arrays gas and cost, 
return the starting gas station's index if you can travel around the circuit once in the clockwise direction, 
otherwise return -1. If there exists a solution, it is guaranteed to be unique.

Algorithm:
  Greedy: all indices between i and j are invalid starts then, all indices between i and j are invalid starts
   reason: let start = i, we reach j and tank becomes negative(at j)
            i.e sum(diff[i → j]) < 0
            now try for any k, i< k< j  then sum(diff[k → j]) < sum(diff[i → j]) will be even worse as at each station it contributes extra 0 to anything
            if we remove a non-negative it even becomes worse than diff[i->j]
          so,  skip all indices from i to j
  
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,tank=0,start=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            tank+=diff;
            if(tank<0){
                tank=0;
                start=i+1;
            }
        }
        return (total>=0)?start:-1;
    }
};
