// 2300

//Binary Search - Good Method

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int s =spells.size();
        int p=potions.size();
        sort(potions.begin(), potions.end());
        vector<int> answer;
        for (int i=0; i<s;i++){
            int left=0;
            int right=p-1;
            int index=p;
            while (left<=right){
                int mid=(left+right)/2;
                if (1LL*spells[i]*potions[mid]<success){
                    left=mid+1;
                }
                else{
                    index=mid;
                    right=mid-1;
                }
            }
            answer.push_back(p-index);
        }
        return answer;
    }
};

//Postfix - Better Method

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int s =spells.size();
        int p=potions.size();
        vector<int> answer(s,0);
        
        int m=*max_element(potions.begin(), potions.end());
        vector<int> postfix(m+1, 0);

        for (int i=0; i<p; i++){
            postfix[potions[i]]++;
        }
        for (int i=m-1; i>=0; i--){
            postfix[i]+=postfix[i+1];
        }
        for(int i=0; i<s;i++){
            long long num=success/(long long) spells[i];
            if(success%(long long) spells[i]!=0) num++;
            if (num<=m) answer[i]=postfix[num];
            else answer[i]=0;
        }
        return answer;
    }
};