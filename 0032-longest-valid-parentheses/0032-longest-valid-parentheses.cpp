class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> isval(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) continue;
                isval[i] = true;
                isval[st.top()] = true;
                st.pop();
            }
        }

        int ans = 0, i = 0;
        while (i < n) {
            if (isval[i]) {
                int j = i;
                while (j < n && isval[j]) {
                    j++;
                }
                ans = max(ans, j - i);
                i = j;
            }
            i++;
        }

        return ans;
    }
};