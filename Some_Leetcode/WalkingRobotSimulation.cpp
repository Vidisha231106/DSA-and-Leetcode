// 874

class Solution {
public:
    // 1 -> y, 
    // -1-> -y, 
    // 2->x, 
    // -2->-x 
    vector<int> final(int ind, vector<int>& commands, vector<int> curr, int& dir){
        if (commands[ind]==-1){
            if (dir==1) dir=2;
            else if (dir==-1) dir =-2;
            else if (dir==2) dir = -1;
            else dir=1;
            return curr;
        }
        else if (commands[ind]==-2){
            if (dir==1) dir=-2;
            else if (dir==-1) dir =2;
            else if (dir==2) dir =1;
            else dir=-1;
            return curr;
        }
        int x=curr[0], y=curr[1];
        if (dir%2==0) curr[0]= x+commands[ind]*(dir/2); // dir/2 gives the direction +-
        else curr[1]= y+commands[ind]*dir; // dir multiplication gives the +-
        return curr;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir = 1; // initially in positive y direction
        int answer=0;
        int n = commands.size();
        int m = obstacles.size();
        vector<int> prev({0,0});
        for (int i=0; i<n; i++){
            vector <int> curr= final(i, commands, prev, dir);
            if (dir%2==0){
                // moving in x axis path - check 0 indices of obstacles
                for (int j=0; j<m; j++){
                    if (obstacles[j][1]==curr[1]){
                        if (dir>0 && obstacles[j][0]>prev[0] && obstacles[j][0]<=curr[0]) curr[0]=obstacles[j][0]-1;
                        else if (dir<0 && obstacles[j][0]<prev[0] && obstacles[j][0]>=curr[0]) curr[0] = obstacles[j][0]+1;
                    }
                }
            }
            else{
                // moving in y axis path - check 1 indices of obstacles
                for (int j=0; j<m; j++){
                    if (obstacles[j][0]==curr[0]){
                        if (dir>0 && obstacles[j][1]>prev[1] && obstacles[j][1]<=curr[1]) curr[1]=obstacles[j][1]-1;
                        else if (dir<0 && obstacles[j][1]<prev[1] && obstacles[j][1]>=curr[1]) curr[1] = obstacles[j][1]+1;
                    }
                }
            }
            answer=max(answer, curr[0]*curr[0] + curr[1]*curr[1]);
            prev[0]=curr[0];
            prev[1]=curr[1];
        }
        return answer;
    }
};