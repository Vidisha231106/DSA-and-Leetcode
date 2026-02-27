//229

//Better approach - not mine!!

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //in  any size array there are only 2 elements possible 
        //which can appear m=ore than n/3 times
        int n =nums.size();
        if(n == 1) return {nums[0]};
        int majorityNums1 = INT_MIN;
        int majorityNums2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        for(auto&i:nums){
            if(count1 ==0 && i!=majorityNums2){
                majorityNums1 = i;
                count1++;
            }else if(count2 ==0 && i!=majorityNums1){
                majorityNums2 = i;
                count2++;
            }else if(i == majorityNums2) count2++;
            else if(i == majorityNums1) count1++;
            else{
                count1--;
                count2--;
            }
        }
        int appearCount1 = 0;
        int appearCount2 = 0;
        for(auto&i : nums){
            if(i == majorityNums1) appearCount1++;
            else if(i == majorityNums2) appearCount2++;
        }
        if(appearCount1 > n/3 && appearCount2 > n/3) return {majorityNums1, majorityNums2};
        else if(appearCount1 > n/3) return {majorityNums1};
        else if(appearCount2 > n/3) return {majorityNums2};
        return {};
    }
};

// Brute force approach

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> answer;
        int nums_size=nums.size();
        unordered_map <int, int> freq;
        for (int i=0; i<nums_size; i++){
            freq[nums[i]]++;
        }
        int n=freq.size();
        int max=nums_size/3;
        int count=0;
        for (const auto& pair : freq) {
            if(pair.second>max){
                answer.push_back(pair.first);
                count++;
            }
            if (count==2) break;
        }
        return answer;
    }
};