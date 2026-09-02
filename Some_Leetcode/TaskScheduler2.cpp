// 2365

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> last_day;
        int n=tasks.size();
        long long count=0;
        for(int i=0; i<n; i++){
            last_day[tasks[i]]=-1;
        }
        for(int i=0; i<n; i++){
            if (last_day[tasks[i]]==-1 || count>=last_day[tasks[i]]) {
                
                count++;
                //cout<<"Normal: "<< tasks[i]<<" "<< last_day[tasks[i]]<<endl;
            }
            else{
                count=last_day[tasks[i]]+1;
                //cout<<"Abnormal: "<< tasks[i]<<" "<< last_day[tasks[i]]<<endl;
            }
            last_day[tasks[i]]=count+space;
        }
        return count;
    }
};