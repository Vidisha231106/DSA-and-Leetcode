// 1926

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, entrance[0], entrance[1]}); // {dist, x, y}
        visited[entrance[0]][entrance[1]]=1;
        vector<vector<int>> dir={{0,1}, {0, -1}, {1,0}, {-1, 0}};
        int answer=INT_MAX;
        while (pq.empty()==false){
            vector<int> curr=pq.top();
            pq.pop();
            int dist=curr[0];
            int x=curr[1];
            int y=curr[2];
            
            if ((x!=entrance[0] || y!=entrance[1]) && (x==0 || y==0 || x==n-1 || y==m-1)) return dist;
            //cout<<"here";
            for(int i=0; i<4; i++){
                int nx=dir[i][0]+x;
                int ny=dir[i][1]+y;
                if (nx<0 || nx>=n || ny<0 || ny>=m)continue;
                if (maze[nx][ny]=='+') continue;
                if (visited[nx][ny]!=0) continue;
                //cout<<nx<<" "<<ny<<endl;
                visited[nx][ny]=1;
                pq.push({dist+1, nx, ny});
            }
        }
        
        return -1;    
        //return answer;
    }

};