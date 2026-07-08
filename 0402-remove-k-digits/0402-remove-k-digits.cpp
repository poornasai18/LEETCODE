/*
=========================================================
LeetCode 402 - Remove K Digits
Difficulty: Medium

Problem:
Given a non-negative integer num represented as a string,
remove k digits from the number so that the new number is
the smallest possible.

Example:
Input:
num = "1432219"
k = 3

Output:
"1219"

Explanation:
Remove digits 4, 3, and 2 to get the smallest number.

---------------------------------------------------------
Approach:
Use a Monotonic Increasing Stack.

Idea:
Whenever we find a digit that is smaller than the previous
digit, removing the previous larger digit will make the
number smaller.

For example:

num = "1432219"

Stack:
1
1 4

Current digit = 3

Since 4 > 3
Remove 4

Stack becomes:
1

Push 3

Continue until k becomes 0.

---------------------------------------------------------
Time Complexity:
O(N)

Each digit is pushed once and popped at most once.

Space Complexity:
O(N)

=========================================================
*/

class Solution {
public:
    string removeKdigits(string num, int k) {

        // Corner case:
        // If we remove all digits,
        // answer is simply "0".
        if (k >= num.size())
            return "0";

        // We'll use string as a stack.
        // push_back() = push
        // pop_back() = pop
        string st;

        // Traverse every digit in the number
        for (char digit : num) {

            /*
            Remove previous larger digits while:

            1. Stack is not empty
            2. Still have digits to remove
            3. Previous digit is greater than current digit

            Why?

            Example:

            Stack = 143
            Current = 2

            3 > 2 -> remove 3
            4 > 2 -> remove 4

            Smaller digits should come first to
            minimize the final number.
            */
            while (!st.empty() &&
                   k > 0 &&
                   st.back() > digit) {

                st.pop_back();   // Remove larger digit
                k--;             // One removal used
            }

            // Push current digit
            st.push_back(digit);
        }

        /*
        If removals are still left,

        Example:
        num = "12345"
        k = 2

        Number is already increasing,
        so nothing was removed inside the loop.

        Best option:
        Remove digits from the end.

        Result:
        123
        */
        while (!st.empty() && k > 0) {
            st.pop_back();
            k--;
        }

        /*
        Remove leading zeros.

        Example:
        "000123"

        Answer should become:
        "123"
        */
        int start = 0;

        while (start < st.size() && st[start] == '0')
            start++;

        // Remove leading zeros
        string ans = st.substr(start);

        /*
        If everything becomes empty

        Example:
        "10"
        k = 1

        After removing '1'
        Remaining = "0"

        Or

        "000"

        After removing zeros,
        answer becomes empty.

        Return "0".
        */
        if (ans.empty())
            return "0";

        return ans;
    }
};