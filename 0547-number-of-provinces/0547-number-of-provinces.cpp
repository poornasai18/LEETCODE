class Solution {
private:
    void bfs(int node, vector<vector<int>> &adjList, vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int nei = q.front();
            q.pop();
            for(auto it: adjList[nei]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList(isConnected.size());
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected[0].size(); j++){
                if(i!= j && isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < adjList[i].size(); j++){
                cout<<adjList[i][j]<<" ";
            }
            cout<<endl;
        }

        int cnt = 0;
        vector<int> vis(isConnected.size(), 0);

        for(int i = 0; i < isConnected.size(); i++){
            if(!vis[i]){
                bfs(i, adjList, vis);
                cnt++;
            }
        }
        return cnt;
    }
};