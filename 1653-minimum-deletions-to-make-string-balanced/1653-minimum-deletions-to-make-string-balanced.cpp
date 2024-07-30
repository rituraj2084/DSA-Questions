class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int i = 0, c = 0;
        while (i < s.size()) {
            if (!st.empty() && st.top() == 'b' && s[i] == 'a') {
                st.pop();
                c++;
                // i is incremented here so we move to the next character
                i++;
            } else {
                st.push(s[i]);
                i++;
            }
        }
        return c;
    }
};