// 3975

//VERY VERY IRRITATING TO GET THE LOGIC: FIRST MERGE THEN REMOVE THE INTERVAL

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n=occupiedIntervals.size();
        vector<vector<int>> v;
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        for (int i=0; i<n; i++){
            int start=occupiedIntervals[i][0];
            int end=occupiedIntervals[i][1];
            while (i+1<n && occupiedIntervals[i+1][0]<=end+1) {
                end=max(end, occupiedIntervals[i+1][1]);
                i++;
            }
            v.push_back({start, end});
        }
        occupiedIntervals.clear();
        int m=v.size();
        for (int i=0; i<m; i++){
            if (v[i][0]<freeStart) occupiedIntervals.push_back({v[i][0], min(freeStart-1, v[i][1])});
            if (v[i][1]>freeEnd) occupiedIntervals.push_back({max(freeEnd+1, v[i][0]), v[i][1]});
        }
        return occupiedIntervals;
    }
};

//EXTREMELY INNEFICIENT SOLUTION - TLE

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n=occupiedIntervals.size();
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        int max_num=INT_MIN;
        for(int i=0; i<n; i++){
            for (int j=occupiedIntervals[i][0]; j<=occupiedIntervals[i][1]; j++){
                max_num=max(max_num, occupiedIntervals[i][1]);
            }
        }
        vector<int> temp(max_num+1, 0);
        //int m=new_v.size();
        for(int i=0; i<n; i++){
            for (int j=occupiedIntervals[i][0]; j<=occupiedIntervals[i][1]; j++){
                if (j<freeStart || j>freeEnd){
                    temp[j]=1;
                    //cout<< j<<" ";
                }
            }
            //cout<<endl;
        }
        int start=0;
        vector<vector<int>> answer;
        int end=0;
        int i=1;
        while (i<temp.size()){
            //cout<<i<<" " <<temp[i]<<endl;
            if (i==0 || (temp[i]==1 && temp[i-1]==0)){
                if (start!=0 && end!=0) answer.push_back({start, end-1});
                start=i;
                end=i;
            } 
            if (temp[i]==1) end++;
            i++;
        }
        if (end-1<0 || start>end-1) return answer;
        answer.push_back({start, end-1});
        return answer;
    }
};