// 480

// TLE

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> s;
        vector<double> answer;
        unordered_map<int, int> mp;
        int left=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
            mp[nums[i]]++;
            cout<<" i: "<<i <<"size: " << s.size()<<endl;
            if (s.size()>=k){
                if(k%2==0){
                    long long one=*next(s.begin(), k/2-1);
                    long long two=*next(s.begin(), k/2);
                    answer.push_back((double)(one+two)/2);
                }
                else{
                    answer.push_back(*next(s.begin(), k/2));
                }
                s.erase(nums[left]);
                mp[nums[left]]--;
                int x=mp[nums[left]];
                for(int j=0; j<x; j++) s.insert(nums[left]);
                left++;
            }
        }
        return answer;
    }
};

//Corrected version

class Solution {
public:
    multiset<int> lesser;
    multiset<int> greater;
    void balance(){
        if (lesser.size()>greater.size()+1){
            int last=*prev(lesser.end());
            lesser.erase(lesser.find(last));
            greater.insert(last);
        }
        else if (lesser.size()<greater.size()){
            int first=*greater.begin();
            greater.erase(greater.find(first));
            lesser.insert(first);
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        vector<double> answer;
        for(int i=0; i<n; i++){
            if (lesser.empty()==true || nums[i]<=*prev(lesser.end())) lesser.insert(nums[i]);
            else greater.insert(nums[i]);
            balance();
            if ((lesser.size()+greater.size())>=k){
                if (k%2==0){
                    long long one =*prev(lesser.end());
                    long long two=*greater.begin();
                    answer.push_back((double)(one+two)/2);
                }
                else{
                    if (lesser.size()>greater.size()) answer.push_back(*prev(lesser.end()));
                    else answer.push_back(*greater.begin());
                }
                if (lesser.find(nums[left])!=lesser.end()){
                    lesser.erase(lesser.find(nums[left]));
                }
                else{
                    greater.erase(greater.find(nums[left]));
                }
                balance();
                left++;
            }
        }
        return answer;
    }
};