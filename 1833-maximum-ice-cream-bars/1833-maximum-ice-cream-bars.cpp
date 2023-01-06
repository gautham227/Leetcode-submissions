class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        if(costs[0]>coins)return 0;
        int ind=0;
        // bool flag=true;
        while(coins>0 && ind<costs.size()){
            // cout<<coins<<" "<<costs[ind]<<endl;
            if(costs[ind]<=coins)coins-=costs[ind];
            else break;
            ind++;
        }
        return ind;
    }
};