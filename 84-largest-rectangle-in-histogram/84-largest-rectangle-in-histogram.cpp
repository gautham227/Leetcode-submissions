class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
    int n=arr.size();
    stack<long long> st;
    vector<long long> ls, rs;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
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
    
    long long ans=0;
    
    for(int i=0;i<n;i++){
        ans=max(ans, (rs[i]-ls[i]+1)*arr[i]);
    }

    
    return ans;
    
        
    }
};