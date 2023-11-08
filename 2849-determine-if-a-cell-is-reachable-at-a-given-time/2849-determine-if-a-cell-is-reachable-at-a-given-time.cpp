class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1)return false;
        int dia=min(abs(sx-fx), abs(sy-fy));
        int mini=abs(sx-fx)+ abs(sy-fy)-dia;
        if(t>=mini)return true;
        return false;
    }
};