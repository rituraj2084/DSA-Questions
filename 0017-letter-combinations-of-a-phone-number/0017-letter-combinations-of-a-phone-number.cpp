class Solution {
private:
    void generateCombinations(const string &digits, int index, string current, const vector<string> &mapping, vector<string> &result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char c : mapping[digit]) {
            generateCombinations(digits, index + 1, current + c, mapping, result);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty())
            return result;

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        generateCombinations(digits, 0, "", mapping, result);
        return result;
    }
};
