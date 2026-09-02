// 1953

//Wrong Solution - TLE

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        priority_queue<vector<int>> pq;
        //unordered_map<int, int> next_day;
        int prev=-1;
        int previ=-1;
        //int m=*max_element(milestones.begin(), milestones.end());
        // pq element : {milestones_left, index}
        int n=milestones.size();
        for(int i=0; i<n; i++){
            pq.push({milestones[i], i});
            //next_day[milestones[i]]=INT_MIN;
        }
        long long count=0;
        while (pq.empty()!=true){
            if (previ==pq.top()[1]) return count;
            int ms=pq.top()[0];
            int index=pq.top()[1];
            pq.pop();
            if (ms<=0) return count; 
            count++;
            if (prev!=-1) pq.push({prev,previ});
            //cout<<ms<<" "<<index<<endl;
            prev=ms-1;
            previ=index;
        }
        return count;
    }
};

//Correct Solution

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long m=*max_element(milestones.begin(), milestones.end());
        long long total=0;
        for(int x: milestones){
            total+=x;
        }
        long long remaining=total-m;
        return min(total, 2*remaining+1);
    }
};