// 3955

class Solution {
public:
    vector <string> answer;
    void recursion(int n, int k, string curr){
        if (curr.length()==n){
            int sum=0;
            for (int i=0; i<n; i++){
                if (curr[i]=='1')sum+=i;
            }
            if (sum<=k) answer.push_back(curr);
            return;
        } 
        if (curr=="") {
            recursion(n, k, "0");
            recursion(n, k, "1");
        }
        else{
            recursion(n, k, curr+"0");
            int c=curr.length();
            if (curr[c-1]!='1') recursion(n, k, curr+"1");
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        recursion(n, k, "");
        return answer;
        //no of possible combinations: pow(2,12)-1

    }
};