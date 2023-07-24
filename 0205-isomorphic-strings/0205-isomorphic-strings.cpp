class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMap; // To store the character mapping
    
        for (int i = 0; i < s.length(); i++) {
            char sChar = s[i];
            char tChar = t[i];

            // If sChar already has a mapping and it's not equal to tChar, return false
            if (charMap.count(sChar) && charMap[sChar] != tChar) {
                return false;
            }

            // If tChar is already mapped to a different character, return false
            for (const auto& entry : charMap) {
                if (entry.second == tChar && entry.first != sChar) {
                    return false;
                }
            }

            // Create the mapping if not already present
            charMap[sChar] = tChar;
        }

        return true; // If no conflicts found, strings are isomorphic
    }
};