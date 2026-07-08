class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        // Mod value because answer can be very large
        const int MOD = 1e9 + 7;

        int n = arr.size();

        // prev[i] = index of Previous Smaller Element
        vector<int> prev(n);

        // next[i] = index of Next Smaller or Equal Element
        vector<int> next(n);

        stack<int> st;

        //-----------------------------
        // Find Previous Smaller Element
        //-----------------------------

        // We want the nearest element on left
        // which is STRICTLY smaller than current.
        //
        // Stack will maintain increasing values.
        //
        // Example:
        // arr = [3,1,2,4]
        //
        // prev = [-1,-1,1,2]

        for(int i = 0; i < n; i++)
        {
            // Remove all elements
            // greater than or equal to current.
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            // If stack is empty,
            // no smaller element exists.
            if(st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            st.push(i);
        }

        // Empty stack for next pass
        while(!st.empty())
            st.pop();

        //---------------------------------------
        // Find Next Smaller OR Equal Element
        //---------------------------------------

        // Traverse from right to left.
        //
        // Here we remove only elements
        // strictly greater than current.
        //
        // Equal element is kept.
        //
        // This avoids duplicate counting.

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if(st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            st.push(i);
        }

        //-----------------------------
        // Calculate Answer
        //-----------------------------

        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            // Number of choices on left
            long long left = i - prev[i];

            // Number of choices on right
            long long right = next[i] - i;

            // Current element contribution
            long long contribution =
                (1LL * arr[i] * left * right) % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};