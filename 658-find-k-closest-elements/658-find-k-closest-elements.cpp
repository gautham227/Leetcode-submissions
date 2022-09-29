class Solution {
public:
    static int comp(int a, int b){
        if(abs(a)>abs(b))return false;
        if(abs(a)==abs(b) && a>=b)return false;
        return true;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        for(auto &ele: arr){
            ele-=x;
        }
        sort(arr.begin(), arr.end());
        sort(arr.begin(), arr.end(), comp);
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i]+x);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};