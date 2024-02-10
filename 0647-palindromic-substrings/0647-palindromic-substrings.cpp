class Solution {
public:
    int countSubstrings(string s) {
         int count = 0;
        int n = s.length();

    for (int i = 0; i < n; i++) {
    
        for (int j = 0; i - j >= 0 and i + j < n and s[i - j] == s[i + j]; j++) 
        {
            count++;
        }

        for (int j = 0; i - j >= 0 and i + 1 + j < n and s[i - j] == s[i + 1 + j]; j++)
         {
            count++;
        }
    }

    return count;
    }
};