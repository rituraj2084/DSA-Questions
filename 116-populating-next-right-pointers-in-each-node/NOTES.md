Intuition:-
​
We are given a prefect binary tree that means every parent has two children and all the leaves are on the same level .
This question is an superior version of binary level order traversal .
In level order traversal you will traverse each level of binary tree while outputting the data in that form . So the only difference is that somehow we need to connect the previous levels rightmost node to the next level's leftmost node and that's it .
​
Algorithm:-
​
Base case: if the root is null than return null
Now to connect the left subtree of same level with right subtree of that level
The only new line that differentiate from level order traversing is that we need to connect the rightmost node of a level to the leftmost node of the next level.
Now just repeat the steps over and over for every level of tree .