class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        if(sx>tx || sy>ty)return false;
        
        while(tx>sx && ty>sy){
            if(tx>ty){
                tx%=ty;
            }
            else{
                ty%=tx;
            }
        }
        // cout<<sx<<" "<<sy<<" "<<tx<<" "<<ty<<endl;
        if(tx==sx){
            // cout<<((abs(ty-sy)%tx)==0)<<endl;
            return ((abs(ty-sy)%tx)==0);
        }
        else if(ty==sy){
            return ((abs(tx-sx)%ty)==0);
        }
        return false;
    }
};