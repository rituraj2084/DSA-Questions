class Solution {
public:
    bool isPalindrome(string& word) {
        int i = 0, j = word.size() - 1;
        while (i < j) {
            if (word[i++] != word[j--]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (auto& word: words) {
            if (isPalindrome(word)) return word;
        }
        return "";  
    }
};