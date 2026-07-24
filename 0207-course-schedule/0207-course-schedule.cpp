class Solution {
public:
    bool canFinish(int k, vector<vector<int>>& nums) {
        int n=nums.size();
        vector<vector<int>>adj(k);
        for(int i=0;i<n;i++){
            adj[nums[i][0]].push_back(nums[i][1]);
        }
        vector<int>ind(k);
        for(int i=0;i<k;i++){
            for(auto it:adj[i]) ind[it]++;
        }
        queue<int>qu;
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(ind[i]==0) qu.push(i);
        }
        while(!qu.empty()){
            int node=qu.front();
            qu.pop(); ans.push_back(node);
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0) qu.push(it);
            }
        }
        return ans.size()==k;
    }
};