class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
        /*
        for(char c: letters){
            if(c > target) return c;
        }
        return letters[0];
        */
    }
};