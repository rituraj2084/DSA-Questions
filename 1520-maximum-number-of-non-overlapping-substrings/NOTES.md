The greedy logic is quite simple though:
​
There could be no more that 26 valid substrings; each potential valid substring starts from the first occurrence of a given character.
If we find a valid substring, and then another valid substring within the first substring - we can ignore the larger substring.
E.g. if we find "abccba", and then "bccb", and then "cc", we only care about "cc". This can be easily proven by a contradiction.
Algorithm
​
First, collect left (l) and right(r) indices for every character.
Then, go through the string. If the current index i is the left index for the character s[i], it may be a valid substring.
We then use a sliding window pattern to find the length of the substring.
If we find a character that appears before i - we do not have a valid string starting at i.
If substring is valid, we remember it, as well as it's right edge.
This logic, repeated, will ensure that we find the valid substring with the smallest right edge.
If the valid substring starts after the previous right edge, there is no overlap. The previous substring should be included into the result.
FAQ
​
Why the answer for "abab" is "abab", and not "bab"?
According to condition 2 (see the problem description): a substring containing 'a' must also contain all occurrences of 'a'. So, "bab" is simply not a valid substring. This is checked by this line in the code below: if (l[s[j] - 'a'] < i).
The time complexity seems to be O(n ^ 2). There are two nested loops, each goes through n elements in the worst case.
Correct, the inner loop could go through n elements, but we will do it no more than 26 times. We only search for a substring starting form indexes in l, and we have 26 such indexes. This is checked by this line: if (i == l[s[i] - 'a']).
Alternatively, instead of going through n elements in the outer loop, we can just go iterate through indexes in l directly. However, we need to sort l in that case, which complicates the implementation a bit. Some folks suggested to use a stack, but the implementation was just longer :)
Why do we need to do res.push_back("")?
I am using the back of the result to track the last valid substring. We can use a string variable instead, and push that variable to the result. However, that will require another check in the end to make sure the latest substring is included.
We add a new element to the result when a new valid substring that does not overlap with the last valid substring (i > right). Otherwise, we just keep on updating the last valid substring.
We also add a new element for the very first substring (res.empty()).