class Solution {
public:
    set<int> s;
    void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }
        
    if(n>2)s.insert(n);
}
    int distinctPrimeFactors(vector<int>& nums) {
        
        for(auto ele: nums){
            primeFactors(ele);
        }
        
        return s.size();
        
        
    }
};