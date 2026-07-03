https://leetcode.com/problems/bus-routes/description/

You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. 
You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

Idea/Algo: Instead of asking: Which stop comes next?
           we ask: From this stop, which buses can I board?
  1. Use a hash map: map for each stop ==> which buses we can board.
  2. Use unorded_set: use visStop and visBus to not process bus and stops which are processed already.
  3. Use BFS (queue): in BFS for each level we increase busCount.
  
      BFS Idea ===> For each stop:
                        For each bus we can board from that stop: (if bus already vis skip the bus)
                                  Process each next stop we can go from that bus: 
                                                    if(nextStop==tar) return BusCount.
                                                    if(!visStop.count(nextStop)) push the stop to queue.
  
      (Inorder to avoid repeated processing of stops and buses ===> we use sets for storing vis bus and stops)




class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int,vector<int>> stop_to_buses;

        for(int bus=0;bus<routes.size();bus++){
            for(int stop:routes[bus]){
                stop_to_buses[stop].push_back(bus);
            }
        }

        int busCount=0;

        unordered_set<int> visStop;
        unordered_set<int> visBus;

        queue<int> que;
        que.push(source);
        visStop.insert(source);

        while(!que.empty()){
            int n=que.size();

            busCount++;            

            for(int i=0;i<n;i++){
                int stop=que.front();
                que.pop();

                for(int bus:stop_to_buses[stop]){
                    if(visBus.count(bus)) continue;

                    visBus.insert(bus);

                    for(int nextStop:routes[bus]){
                        if(nextStop==target) return busCount;

                        if(!visStop.count(nextStop)){
                            visStop.insert(nextStop);
                            que.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
