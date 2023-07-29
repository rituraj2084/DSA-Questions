class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // Step 1: Read in and ignore any leading whitespace.
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check if the next character is '-' or '+'
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Step 3: Read in next the characters until the next non-digit character or the end of the input is reached.
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Convert digits into an integer
            // Check for overflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // Apply sign to the result
        return result * sign;
    }
};