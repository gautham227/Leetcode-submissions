class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if(ladders>heights.size())return heights.size()-1;
        priority_queue<int> pq;
        int ind=0;
        while(ladders>0 && ind<heights.size()-1){
            if(heights[ind]>=heights[ind+1]){
                ind++;
                continue;
            }
            pq.push(-heights[ind+1]+heights[ind]);
            ladders--;
            ind++;
        }
        int val;
        while(bricks>=0 && ind<heights.size()-1){
            if(heights[ind+1]<=heights[ind]){
                ind++;
                continue;
            }
            pq.push(-heights[ind+1]+heights[ind]);
            val=pq.top();
            pq.pop();
            if(-1*val>bricks)break;
            bricks+=val;
            ind++;
        }
        return ind;
    }
};