class Solution {
public:
    int find(int x, vector<int>& p) {
        return p[x] == x ? x : p[x] = find(p[x], p);
    }
    bool join(int a, int b, vector<int>& p, vector<int>& sz) {
        if(find(a, p) == find(b, p)) return false;
        if(sz[find(a, p)] > sz[find(b, p)]) {
            sz[find(a, p)] += sz[find(b, p)];
            p[find(b, p)] = find(a, p);
        } else {
            sz[find(b, p)] += sz[find(a, p)];
            p[find(a, p)] = find(b, p);
        }
        return true;
    }
    int is_prime_optimized(int num, vector<int>& dp) {
        if(dp[num] != -1) return dp[num];
        if (num <= 1) return dp[num] = 0;
        if (num <= 3) return dp[num] = 1; // 2 and 3 are prime
        if (num % 2 == 0 || num % 3 == 0) return dp[num] = 0; // Not divisible by 2 or 3
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return dp[num] = 0;
        }
        return dp[num] = 1;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_set<int> distinct;
        int ones = 0;
        for(auto num: nums) {
            if(num == 1) ones++;
            if(ones == 2) return false;
            distinct.insert(num);
        }
        nums = vector<int>(distinct.begin(), distinct.end());
        if(nums.size() == 1) return true;
        int n = nums.size();
        vector<int> sz(n, 1);
        vector<int> p(n);
        vector<int> dp(100000+1,-1);
        for(int i = 0; i < n; i++) p[i] = i;

        sort(nums.begin(), nums.end());
        unordered_set<int> used;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(nums[i] == 1 || nums[j] == 1 || find(i, p) == find(j, p) || i == j) continue;
                int remainder = nums[j] % nums[i];
                if(remainder == 0) {
                    join(i, j, p, sz);
                    used.insert(i);
                    used.insert(j);
                    break;
                }
                if(is_prime_optimized(nums[j], dp) || is_prime_optimized(nums[i], dp)) continue;
                if(gcd(nums[i], nums[j]) > 1) {
                    join(i, j, p, sz);
                    used.insert(i);
                    used.insert(j);
                    break;
                }
            }
            if(used.find(i) == used.end()) {
                return false;
            }
        }
        for(int i = 0; i < n; i++) {
            if(sz[i] == n) return true;
        }
        return false;       
    }
};