class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;

        // Sort intervals based on their start points in ascending order
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int nonOverlappingCount = 1; // At least one interval is non-overlapping
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= prevEnd) {
                // The current interval doesn't overlap with the previous one
                nonOverlappingCount++;
                prevEnd = intervals[i][1];
            } else {
                // Overlapping with the previous one; remove the one with the larger endpoint
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }

        // Calculate the number of intervals to be removed to make the rest non-overlapping
        int toRemove = intervals.size() - nonOverlappingCount;
        return toRemove;
    }
};