/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1,r=n;
        while(r-l>1){
            int mid= l + (r-l)/2;
            int x= guess(mid);
            if(x==0)return mid;
            else if(x==-1){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(guess(l)==0)return l;
        return r;
    }
};