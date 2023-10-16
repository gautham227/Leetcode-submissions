typedef long long ll;
class Solution {
public:
    
    ll ncr(int n, int r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
 
    else
        p = 1;
    return p;
}
    
    vector<int> getRow(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(ncr(n,i));
        }
        return ans;
    }
};