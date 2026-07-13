class Solution {
public:
    string convert(string s, int numRows) {

        // If there is only one row or the number of rows is
        // greater than/equal to the string length, no zigzag occurs.
        if (numRows == 1 || numRows >= s.size())
            return s;

        // Create one string for each row
        vector<string> rows(numRows);

        int currentRow = 0;      // Current row where character is placed
        bool goingDown = true;   // Direction of movement

        // Traverse every character in the string
        for (char ch : s) {

            // Add current character to the current row
            rows[currentRow] += ch;

            // If we reach the last row,
            // start moving upward
            if (currentRow == numRows - 1)
                goingDown = false;

            // If we reach the first row,
            // start moving downward
            else if (currentRow == 0)
                goingDown = true;

            // Move according to current direction
            if (goingDown)
                currentRow++;
            else
                currentRow--;
        }

        // Combine all rows to get the final answer
        string answer;

        for (string row : rows)
            answer += row;

        return answer;
    }
};