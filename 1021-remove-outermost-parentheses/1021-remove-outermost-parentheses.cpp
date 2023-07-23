class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        stack<char> parenthesesStack;

        for (char c : s) {
            if (c == '(') {
                // Add the opening parenthesis to the stack
                if (!parenthesesStack.empty()) {
                    // If the stack is not empty, this is not the outermost parenthesis
                    result += c;
                }
                parenthesesStack.push(c);
            } else {
                // Add the closing parenthesis to the stack
                parenthesesStack.pop();
                if (!parenthesesStack.empty()) {
                    // If the stack is not empty, this is not the outermost parenthesis
                    result += c;
                }
            }
        }

        return result;
    }
};