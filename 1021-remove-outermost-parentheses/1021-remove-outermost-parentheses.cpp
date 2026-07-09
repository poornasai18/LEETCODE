class Solution {
public:
    string removeOuterParentheses(string s) {

        // This string will store the final answer.
        string ans = "";

        // 'depth' represents the current nesting level.
        //
        // Example:
        // "("  -> depth becomes 1
        // "((" -> depth becomes 2
        //
        // Whenever depth becomes 0,
        // one primitive parentheses string is completed.
        int depth = 0;

        // Traverse every character in the string.
        for (char ch : s) {

            // ----------------------------
            // CASE 1 : Opening Bracket '('
            // ----------------------------
            if (ch == '(') {

                // If depth is greater than 0,
                // then this '(' is NOT the outermost bracket.
                // So keep it.
                if (depth > 0)
                    ans += ch;

                // Increase nesting level after processing '('.
                depth++;
            }

            // ----------------------------
            // CASE 2 : Closing Bracket ')'
            // ----------------------------
            else {

                // Decrease depth first because
                // this ')' closes one opening bracket.
                depth--;

                // If depth is still greater than 0,
                // then this ')' is NOT the outermost closing bracket.
                // So keep it.
                if (depth > 0)
                    ans += ch;
            }
        }

        // Return the final string after removing
        // outermost parentheses from every primitive.
        return ans;
    }
};