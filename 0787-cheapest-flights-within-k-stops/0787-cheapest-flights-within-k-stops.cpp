class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // creating adjecency list
        vector<vector<pair<int,int>>>adj(n);
        for(auto & flight:flights){
            int price=flight[2];
            int from=flight[0];
            int to=flight[1];
            adj[from].push_back({to,price});;
        }
        // stopUsed, node, price
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{src,0}});
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
       
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;

            if(stops>k) continue;

            for(auto nbr:adj[node]){
                int nextTo=nbr.first;
                int nextCost=nbr.second + cost;

                if (nextCost < dist[nextTo]) {
                    dist[nextTo] = nextCost;
                    pq.push({stops + 1, {nextTo, nextCost}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};