class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        int em=0;
        while(1){
            ans+=numBottles;
            em+=numBottles;
            numBottles=0;
            if(em<numExchange)break;
            numBottles++;
            em-=numExchange;
            numExchange++;
        }
        return ans;
    }
};