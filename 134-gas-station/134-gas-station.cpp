class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int ind1=0, ind2=n-1;
        int cur=0;
        int cnt=0;
        bool flag=true;
        for(;ind1!=ind2;ind1=(ind1+1)%n){
            if(ind1==0)cnt++;
            if(cnt>2){
                flag=false;
                break;
            }
            cur+=gas[ind1];
            cur-=cost[ind1];
            if(cur<0){
                ind2=ind1;
                cur=0;
            }
        }
        // cout<<ind2<<endl;
        if(!flag) return -1;
        if(cur+gas[ind2]-cost[ind2]>=0)return (ind2+1)%n;
        return -1;
    }
};