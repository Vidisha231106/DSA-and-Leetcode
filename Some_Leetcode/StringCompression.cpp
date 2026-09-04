// 443

class Solution {
public:
    int check(int num){
        int count=0;
        while (num>0){
            num/=10;
            count++;
        }
        return count;
    }
    vector<char> convert(int curr){
        vector<char> nums;
        while(curr>0){
            nums.push_back((char)((curr%10)+'0'));curr/=10;
        }
        reverse (nums.begin(), nums.end());
        return nums;
    }
    int compress(vector<char>& chars) {
        int n=chars.size();
        int curr=1;
        int answer=0;
        int s=0;

        for(int i=n-2; i>=0; i--){
            if (chars[i]==chars[i+1]) curr++;
            else {
                chars.erase(chars.begin()+i+2, chars.begin()+i+curr+1);
                vector<char> nums=convert(curr);
                if (curr!=1) chars.insert(chars.begin()+i+2, nums.begin(), nums.end());
                answer+=(curr==1) ? 1: 1+check(curr);
                // s+=(curr==1) ? 1: 1+curr;
                curr=1;
            }
        }
        cout<<curr;
        int start=chars.size()-curr;
        chars.erase(chars.begin()+1, chars.begin()+curr);
        vector<char> nums=convert(curr);
        if (curr!=1) chars.insert(chars.begin()+1, nums.begin(), nums.end());
        answer+=(curr==1) ? 1: 1+check(curr);
        // s+=(curr==1) ? 1: 1+curr;
        // chars.resize(s);
        return answer;
    }
};