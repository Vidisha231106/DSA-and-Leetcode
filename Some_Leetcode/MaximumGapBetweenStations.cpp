// 4026

class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        int diff=0;
        vector<int> lowest(n,0);
        vector<int> highest(n, 0);
        int i=0, j=0;
        while (i<n && j<m){
            if (skill[i]==station[j]){
                lowest[i]=j;
                i++;
            }
            j++;
        }
        i=n-1; 
        j=m-1;
        while (i>=0 && j>=0){
            if (skill[i]==station[j]){
                highest[i]=j;
                i--;
            }
            j--;
        }
        for(int i=0; i<n; i++){
            if (i-1>=0) diff=max(diff, abs(highest[i-1]-lowest[i]));
            if (i+1<n) diff=max(diff, abs(highest[i+1]-lowest[i]));
        }
        for(int i=1; i<n-1; i++){
            if (i-1>=0) diff=max(diff, abs(highest[i]-lowest[i-1]));
            if (i+1<n) diff=max(diff, abs(highest[i]-lowest[i+1]));
        }
        return diff;
    }
};