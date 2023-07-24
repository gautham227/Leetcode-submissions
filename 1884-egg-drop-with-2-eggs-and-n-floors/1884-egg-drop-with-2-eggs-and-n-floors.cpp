class Solution {
public:
    int twoEggDrop(int n) {
        int x=(-1+(sqrt(1+8*n)))/2;
        if(x*(x+1)/2>=n)return x;
        return x+1;
    }
};