class Solution 
{
    public:
        int climbStairs(int n, vector<int>& costs) 
        {
            int first = 0;
            int second = 0;
            int third = 0;
            int current;
            for(int i = 0; i < costs.size(); i++)
            {
                current = min(first+9, min(second+4, third+1)) + costs[i];
                first = second;
                second = third;
                third = current;
            }
            return current;
        }
};