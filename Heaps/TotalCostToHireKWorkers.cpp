// 2462

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<int, vector<int>, greater<>> pq1;
        priority_queue<int, vector<int>, greater<>> pq2;
        int left=0;
        int right=n-1;
        //vector<int> visited(n,0);
        int count=0;
        long long answer=0;
        while(count<k){
            while (left<=right && pq1.size()<candidates){
                pq1.push(costs[left]);
                left++;
            }
            while (right>=left && pq2.size()<candidates){
                pq2.push(costs[right]);
                right--;
            }           
            if (pq2.empty() || (pq1.empty()==false && pq1.top()<=pq2.top())){
                answer+=pq1.top();
                pq1.pop();
            }
            else{
                answer+=pq2.top();
                pq2.pop();
            }
            cout<<answer<<endl;
            count++;
        }
        while (pq1.empty()!=true && pq2.empty()!=true && count<k){
            if (pq1.top()<=pq2.top()){
                answer+=pq1.top();
                pq1.pop();
            }
            else{
                answer+=pq2.top();
                pq2.pop();
            }
            count++;
        }
        if (pq2.empty()==true){
            while (pq1.empty()!=true  && count<k){
                answer+=pq1.top();
                pq1.pop();
                count++;
            }
        }
        if (pq1.empty()==true){
            while (pq2.empty()!=true  && count<k){
                answer+=pq2.top();
                pq2.pop();
                count++;
            }
        }
        return answer;
    }
};