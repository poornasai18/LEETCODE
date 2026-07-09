class Solution {
public:
    vector<bool> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries) {

        // group[i] stores the connected component
        // number of node i.
        vector<int> group(n);

        // Current connected component ID.
        int component = 0;

        // The first node always belongs to component 0.
        group[0] = 0;

        // Traverse the sorted array.
        for (int i = 1; i < n; i++) {

            // If the difference between consecutive
            // elements is greater than maxDiff,
            // then the current node cannot be connected
            // to the previous node.
            //
            // Therefore, start a new component.
            if (nums[i] - nums[i - 1] > maxDiff)
                component++;

            // Assign the current component number.
            group[i] = component;
        }

        // Store answers for all queries.
        vector<bool> answer;

        // Process every query.
        for (auto &q : queries) {

            int u = q[0];
            int v = q[1];

            // If both nodes belong to the same
            // connected component, a path exists.
            answer.push_back(group[u] == group[v]);
        }

        return answer;
    }
};