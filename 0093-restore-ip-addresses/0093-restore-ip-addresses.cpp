class Solution {
public:
    vector<string> result;

    void backtrack(const string& s, int start, vector<string>& parts) {
        if (parts.size() == 4) {
            if (start == (int)s.size())
                result.push_back(parts[0]+"."+parts[1]+"."+parts[2]+"."+parts[3]);
            return;
        }

        int remaining = s.size() - start;
        int partsLeft = 4 - parts.size();

        // Prune: each part needs 1-3 digits
        if (remaining < partsLeft || remaining > 3 * partsLeft) return;

        for (int len = 1; len <= 3; len++) {
            if (start + len > (int)s.size()) break;

            string seg = s.substr(start, len);

            // No leading zeros
            if (seg.size() > 1 && seg[0] == '0') break;

            // Value must be <= 255
            if (stoi(seg) > 255) break;

            parts.push_back(seg);
            backtrack(s, start + len, parts);
            parts.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> parts;
        backtrack(s, 0, parts);
        return result;
    }
};