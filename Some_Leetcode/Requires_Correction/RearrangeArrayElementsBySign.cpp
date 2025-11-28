//2149

//inefficient code
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map <int, int> mymap;
        vector <int> answer;
        int size=nums.size();
        //v.erase(v.begin() + 2);
        for (int i=0; i<size; i++){
            if (nums[i]>0){
                answer.push_back(nums[i]);
            }
        }   
        int end = answer.size();
        for (int i=0; i<size; i++){
            if (nums[i]<0){
                answer.push_back(nums[i]);
            }
        }
        vector <int> final_answer(size);
        int pos_index=0;
        int neg_index=end;
        for (int i=0; i<size; i++){
            if (i%2==0){
                final_answer[i]=answer[pos_index];
                pos_index++;
            }
            else{
                final_answer[i]=answer[neg_index];
                neg_index++;
            }
        }
        return final_answer;
    }
};

//efficient solution
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posindex = 0 ;
        int negindex = 1;
        vector<int> ans(nums.size());
        for( int i=0 ; i < nums.size() ; i++){
             if( nums[i]>0){
                 ans[posindex]= nums[i];
                 posindex +=2;
             }
             else{
                ans[negindex] = nums[i];
                negindex += 2 ;
             }
        }
        return ans;
    }
};