// 2452

//Brute Force

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int q_n = queries.size();
        int d_n = dictionary.size();
        vector<string> answer;
        int num = queries[0].size();
        for  (int i=0; i<q_n; i++){
            for (int j=0; j<d_n; j++){
                int bad_alphas=0;
                for (int k=0; k<num; k++){
                    if (dictionary[j][k]!=queries[i][k]) bad_alphas++;
                }
                if (bad_alphas<=2){
                    answer.push_back(queries[i]);
                    break;
                } 
            }
            
        }
        return answer;
    }
};