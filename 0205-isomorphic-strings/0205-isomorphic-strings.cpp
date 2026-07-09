class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // If lengths are different,
        // they cannot be isomorphic.
        if (s.length() != t.length())
            return false;

        // HashMap to store mapping:
        // character from s -> character from t
        unordered_map<char, char> mapST;

        // HashMap to store reverse mapping:
        // character from t -> character from s
        //
        // This prevents two different characters
        // in s from mapping to the same character in t.
        unordered_map<char, char> mapTS;

        // Traverse both strings together.
        for (int i = 0; i < s.length(); i++) {

            char chS = s[i];
            char chT = t[i];

            // -----------------------------
            // Check mapping from s -> t
            // -----------------------------
            if (mapST.count(chS)) {

                // Character already mapped.
                // If current mapping is different,
                // strings are not isomorphic.
                if (mapST[chS] != chT)
                    return false;
            }
            else {

                // Create new mapping.
                mapST[chS] = chT;
            }

            // -----------------------------
            // Check reverse mapping
            // t -> s
            // -----------------------------
            if (mapTS.count(chT)) {

                // If reverse mapping differs,
                // two characters from s are trying
                // to map to the same character in t.
                if (mapTS[chT] != chS)
                    return false;
            }
            else {

                // Store reverse mapping.
                mapTS[chT] = chS;
            }
        }

        // All mappings are valid.
        return true;
    }
};