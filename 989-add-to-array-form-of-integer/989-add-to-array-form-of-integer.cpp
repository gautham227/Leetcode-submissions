class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        // this is the vector where we will store the ans
        vector<int> v;
        int n=num.size();
        int ind=n-1;
        // carry is the variable where we will store the carry value after each addition
        int carry=0;
        
        // condition when they have to be added
        while(k>0 && ind>-1){
            int nu=(k%10)+carry+num[ind];
            carry=nu/10;
            v.push_back(nu%10);
            ind--;
            k/=10;
        }
        
        // when num array is already completed and k>0
        
        while(k>0){
            int nu=(k%10)+carry;
            v.push_back(nu%10);
            carry=nu/10;
            k/=10;
        }
        
        // when k has become 0 but nums array is still remaining
        
        while(ind>-1){
            int nu=num[ind]+carry;
            v.push_back(nu%10);
            carry=nu/10;
            ind--;
        }
        
        // corner case when after all this, there is a carry
        
        if(carry>0)v.push_back(carry);
        
        // here the vector we got will be the reverse of the required answer
        
        reverse(v.begin(), v.end());
        
        // here v is the final ans
        return v;
    }
};