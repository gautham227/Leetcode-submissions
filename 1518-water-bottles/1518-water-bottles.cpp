class Solution {
public:
    int numWaterBottles(int numbottles, int numExchange) {
        int ans=numbottles;
        while(numbottles>=numExchange){
            int rem=numbottles%numExchange;
            numbottles/=numExchange;
            ans+=numbottles;
            numbottles+=rem;
        }
        return ans;
    }
};