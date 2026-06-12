// 978

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if (n==1) return 1;
        if (n==2) return (arr[0]==arr[1])? 1: 2;
        int left=0;
        int answer=0;
        for (int i=1; i<n-1; i++){
            if ((arr[i]<arr[i-1] && arr[i]<arr[i+1]) || (arr[i]>arr[i-1] && arr[i]>arr[i+1])){
                continue;
            }
            if (arr[i]==arr[i-1]) {
                answer=max(answer, i-left);
            }
            else{
                answer=max(answer, i-left+1);
            }

            if (arr[i]==arr[i+1]){
                left=i+1;
            }
            else{
                left=i;
            }
        }
        answer=max(answer, n-left);
        return answer;
    }
};