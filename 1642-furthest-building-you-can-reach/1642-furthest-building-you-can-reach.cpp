class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0;
        priority_queue<int>q;
        for(i;i<heights.size() - 1;i++)
        {
            if(heights[i] >= heights[i+1])
            {
                continue;
            }

            int d = heights[i+1] - heights[i];
            if(d<=bricks)
            {
                bricks -= d;
                q.push(d);
            }

            else if(ladders > 0)
            {
                if(q.size())
                {
                    int x = q.top();
                    if(x > d)
                    {
                        bricks +=x;
                        q.pop();
                        q.push(d);
                        bricks -=d;
                    }
                }
                ladders--;
            }
            else
            {
                break;
            }
        }
        return i;
    }
};