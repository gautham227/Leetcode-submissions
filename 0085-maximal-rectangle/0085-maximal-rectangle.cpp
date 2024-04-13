class Solution {
public:
    int largest(vector<int>& arr){
        int n=arr.size();
        vector<int> ls, rs;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ls.push_back(0);
            }
            else{
                ls.push_back(st.top()+1);
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                rs.push_back(n-1);
            }
            else{
                rs.push_back(st.top()-1);
            }
            st.push(i);
        }
        reverse(rs.begin(), rs.end());
        int ma=0;
        for(int i=0;i<n;i++){
            ma=max(ma,(rs[i]-ls[i]+1)*arr[i]);
        }
        return ma;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int> >ma(n, vector<int>(m,0));
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0')continue;
                ma[i][j]=1;
                if(i!=0)ma[i][j]+=ma[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,largest(ma[i]));
        }
        return ans;
    }
};