class Solution {
public:
    
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
        int st=0, comp=0;
        while(st<n || comp<n){
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
                // comp++;
            }
            
            // if(st==n && rr.size()==0){
            //     int val1=0, val2=0;
            //     if(rw.size()>0) val1=(*rw.begin())[0];
            //     if(lw.size()>0) val2=(*lw.begin())[0];
            //     timer=max(timer, min(val1, val2));
            // }
            
            if(lr.size()>0 && st<n){
                flag=true;
                timer+=time[((*(retit(lr)))[1])][0];
                rw.insert({timer+ time[(*(retit(lr)))[1]][1],(*(retit(lr)))[0], (*(retit(lr)))[1]});
                lr.erase(retit(lr));
                st++;
            }
//             cout<<"lw "<<" ";
//             for(auto ele: lw){cout<<"{"; for(auto x: ele){cout<<x<<" ";}cout<<"}";}
//             cout<<endl;
            
//             cout<<"lr ";
//             for(auto ele: lr){cout<<"{"; for(auto x: ele){cout<<x<<" ";}cout<<"}";}
//             cout<<endl;
            
//             cout<<"rw ";
//             for(auto ele: rw){cout<<"{"; for(auto x: ele){cout<<x<<" ";}cout<<"}";}
//             cout<<endl;
            
//             cout<<"rr ";
//             for(auto ele: rr){cout<<"{"; for(auto x: ele){cout<<x<<" ";}cout<<"}";}
//             cout<<endl;
            
//             cout<<"timer "<<timer<<endl;
            if(flag==false)timer++;
        }
        
        return timer;
    }
};