// 4093

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        priority_queue <vector< int>> mp;
        vector<int> fine;
        int n=nums.size();
        for(int i=0; i<n; i++){
            priority_queue<int> d;
            int temp=nums[i];
            while (temp>0){
                d.push(temp%10);
                temp/=10;
            }
            int x=0;
            while (d.empty()!=true){
                x*=10;
                x+=d.top();
                d.pop();
            }
            if (x>nums[i]) mp.push({x-nums[i], x,nums[i]});
            else fine.push_back(nums[i]);
        }
        //cout<<mp.size()<<"          "<<fine.size()<<endl;
        long long sum=0;
        int count=0;
        while (count<k && mp.empty()!=true){
            int t=mp.top()[1];
            //cout<<t<<endl;
            sum+=mp.top()[1];
            mp.pop();
            count++;
        }
        cout<<"here";
        while (mp.empty()!=true){
            int t=mp.top()[2];
            //cout<<t<<endl;
            sum+=mp.top()[2];
            mp.pop();
        }
        for(int x: fine) {
            //cout<<x<<endl;
            sum+=x;
        }
        return sum;
    }
};