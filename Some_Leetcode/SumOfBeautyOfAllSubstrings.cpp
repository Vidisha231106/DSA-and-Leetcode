//1781

class Solution {
public:
    int sum=0;
    int beautySum(string s) {
        int n=s.length();
        for (int i=0; i< n-2; i++){
            vector<int> freq(26, 0);
            freq[s[i]   - 'a']++;
            freq[s[i+1] - 'a']++;
            for (int j=i+2; j< n; j++){
                int min=INT_MAX;
                int max=INT_MIN;
                freq[s[j] - 'a']++;
                for (int l = 0; l<26; l++){
                    if (freq[l]>0){
                        if (freq[l] < min) min = freq[l];
                        if (freq[l]>max) max =freq[l];
                    }
                }
                sum+= max-min;
            }
        }
        return sum;
    }
};