class Solution {
public:
    
    // This is just a utility function to return the iterator of the last element of the set 
    
    auto retit(multiset<vector<int> >& ms){
        return (--ms.end());
    }
    
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        
        // lw-> left waiting,  lr->left ready, rw->right waiting, rr-> right ready         
        multiset<vector<int> >lr,rr;
        multiset<vector<int> >lw, rw;
        int timer=0;
        for(int i=0;i<time.size();i++){
            lr.insert({time[i][0]+time[i][2], i});
        }
        
        // st denotes the no of workers that have gone to right to take the boxes, comp denotes the no of times workers have returned back to left side         
        int st=0, comp=0;
        while(st<n || comp<n){
            // flag denotes that some activity has happened at this time or now, if there are no activity to be done at this point, we just increase timer             
            bool flag=false;
            while(1){
                while(rw.size()>0 && (*rw.begin())[0]<=timer){
                    flag=true;
                    rr.insert({(*rw.begin())[1], (*rw.begin())[2]});
                    rw.erase(rw.begin());
                }
                if(rr.size()>0){
                    flag=true;
                    timer+=time[((*(retit(rr)))[1])][2];
                    lw.insert({timer+ time[(*(retit(rr)))[1]][3],(*(retit(rr)))[0], (*(retit(rr)))[1]});
                    rr.erase(retit(rr));
                    comp++;
                }
                if(rr.size()==0 && (rw.size()==0 || (*rw.begin())[0]>timer))break;
            }
            
            while(lw.size()>0 && ((*lw.begin())[0])<=timer){
                flag=true;
                lr.insert({(*lw.begin())[1], (*lw.begin())[2]});
                lw.erase(lw.begin());
            }
            
            if(lr.size()>0 && st<n){
                flag=true;
                timer+=time[((*(retit(lr)))[1])][0];
                rw.insert({timer+ time[(*(retit(lr)))[1]][1],(*(retit(lr)))[0], (*(retit(lr)))[1]});
                lr.erase(retit(lr));
                st++;
            }
            if(flag==false)timer++;
        }
        
        return timer;
    }
};