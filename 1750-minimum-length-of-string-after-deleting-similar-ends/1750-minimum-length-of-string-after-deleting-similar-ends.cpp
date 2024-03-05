class Solution {
public:
    int minimumLength(string s) {
      int n = s.length();
        int i = 0;
        int j = n - 1;
        int count = 0;
        while (i < j) {
            char ch1 = s[i];
            char ch2 = s[j];
            if (ch1 == ch2) {
                while (i < j && ch1 == s[j]) {
                    j--;
                    count++;
                }
                while (i <= j && s[i] == ch2) {
                    i++;
                    count++;
                }
            } else {
                break;
            }
        }
        return n - count;  
    }
};