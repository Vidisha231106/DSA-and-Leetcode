// 373

//MLE:

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>> visited(n1, vector<int>(n2, 0));
        int count=0;
        pq.push({nums1[0]+nums2[0], 0, 0});
        //visited[0][0]=1;
        vector<vector<int>> answer;
        while(count<k && pq.empty()!=true){
            int sum=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if (visited[x][y]==1) continue;
            count++;
            answer.push_back({nums1[x],nums2[y]});
            visited[x][y]=1;
            
            if (x<n1-1 && visited[x+1][y]==0) pq.push({nums1[x+1]+nums2[y], x+1, y});
            if (y<n2-1 && visited[x][y+1]==0) pq.push({nums1[x]+nums2[y+1], x, y+1});
        }
        return answer;
    }
};

//Corrected version:

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int n1=nums1.size();
        int n2=nums2.size();
        //vector<vector<int>> visited(n1, vector<int>(n2, 0));
        for(int i=0; i<n2; i++){
            pq.push({nums1[0]+ nums2[i], 0, i});
        }
        int count=0;

        //visited[0][0]=1;
        vector<vector<int>> answer;
        while(count<k && pq.empty()!=true){
            int sum=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            //if (visited[x][y]==1) continue;
            count++;
            answer.push_back({nums1[x],nums2[y]});
            //visited[x][y]=1;
            
            if (x<n1-1) pq.push({nums1[x+1]+nums2[y], x+1, y});
            //if (y<n2-1) pq.push({nums1[x]+nums2[y+1], x, y+1});
        }
        return answer;
    }
};