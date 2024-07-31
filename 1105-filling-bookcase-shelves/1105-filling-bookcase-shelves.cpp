class Solution {
public:
    int maxShelf=0;
    int dp[1001][1001];
    int minHeightAfterThisIndex(vector<vector<int>>& books, int shelfLeft, int i, int maxInShelf) {
        // Node wont fit, ignore it immediately
        if(shelfLeft < books[i][0]) {
            return dp[i][shelfLeft] = maxInShelf + minHeightAfterThisIndex(books, maxShelf, i, 0);
        }
        // Last Node -> Always take it
        if(i==books.size()-1) {
            return dp[i][shelfLeft] = max(maxInShelf, books[i][1]);
        }
        if(dp[i][shelfLeft]!=-1) {
            return dp[i][shelfLeft];
        }
        // Add book in shelf
        int newmaxInShelf = max(maxInShelf, books[i][1]);
        int a = minHeightAfterThisIndex(books, shelfLeft - books[i][0], i+1, newmaxInShelf);
        // Dont add book in shelf
        int b=INT_MAX;
        if(shelfLeft != maxShelf) {
            b = maxInShelf + minHeightAfterThisIndex(books, maxShelf, i, 0);
        }
        return dp[i][shelfLeft] = min(a, b);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        maxShelf = shelfWidth;
        memset(dp, -1, sizeof(dp));
        return minHeightAfterThisIndex(books, shelfWidth, 0, 0);
    }
};