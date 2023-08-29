class Solution {
public:
    int bestClosingTime(string customers) {
        int len=customers.size();
        int ind=0;
        int pen;
        vector<int> v1, v2;
        int cnt=0;
        v1.push_back(0);
        for(int i=0;i<len;i++){
            if(customers[i]=='N'){
                cnt++;
                v1.push_back(cnt);
                v2.push_back(i+1-cnt);
            }
            else{
                v1.push_back(cnt);
                v2.push_back(i+1-cnt);
            }
        }
        for(int i=0;i<len;i++){
            v2[i]=v2[len-1]-v2[i];
        }
        pen=len-cnt;
        for(int i=0;i<len;i++){
            int pen1=v1[i]+v2[i];
            if(pen1<pen){
                pen=pen1;
                ind=i+1;
            }
        }
        return ind;
    }
};