https://leetcode.com/problems/car-fleet/description/

There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
  
You are given two integer arrays position and speed, both of length n, where position[i] is the starting mile of the ith car and 
speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
A car fleet is a single car or a group of cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.
If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.


Algo
  1. A car cannot overtake another car. If a faster car catches a slower car before reaching the target: they become one fleet.
  2. calc Time required for each car to reach target:   time = (target - position[i]) / speed[i]
  3. Sort the Cars based on position. Cars nearer to target determine whether cars behind merge. So sort by position.
  4. Traverse from Right (i=n-1 to 0) Because the frontmost car decides whether the car behind merges.
      Stack: Maintain stack of fleet times.
             if (currentTime <= stack.top()) then merge into curr fleet
             else push(currentTime) into stack. new fleet.
      Finally return stk.size()

      Greedy: The stack always stores increasing fleet times. We only need the last fleet time.
                if(cars[i].second > lastTime){
                    fleets++;
                    lastTime = cars[i].second;
                }

 5. Why currentTime <= lastTime Means Merge? 
      ex: front car time = 7 and Back Car time = 5 then The back car reaches target earlier if alone.
          Since it cannot overtake, it catches the front car before the target and travels at the slower speed.
          Hence one fleet.

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,double>> cars(n);
        for(int i=0;i<n;i++){
            cars[i].first=position[i];
            cars[i].second=(double)(target-position[i])/speed[i];
        }
        sort(cars.begin(),cars.end());

        // Greedy Soln
        int res=0;
        double lastTime=0;
        for(int i=n-1;i>=0;i--){
            if(cars[i].second > lastTime){
                res++;
                lastTime=cars[i].second;
            }
        }
        return res;

        //Stack soln
        stack<double> stk;
        for(int i=n-1;i>=0;i--){
            if(stk.empty() || stk.top()<cars[i].second){
                stk.push(cars[i].second);
            }
        }
        return stk.size();
    }
};
