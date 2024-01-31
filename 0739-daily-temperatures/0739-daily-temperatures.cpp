class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int> >st;
        int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int val=temperatures[i];
            while(!st.empty() && val>(st.top()).first){
                ans[(st.top()).second]=i-(st.top()).second;
                st.pop();
            }
            st.push({val,i});
        }
        return ans;
    }
};