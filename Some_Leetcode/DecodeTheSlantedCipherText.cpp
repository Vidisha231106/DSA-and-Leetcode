// 2075

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int cols=n/rows;
        string answer;
        for (int i=0; i<cols; i++){
            int count=0;
            for (int j=i; j<n; j+=cols+1){
                if (count>=rows) break;
                answer.push_back(encodedText[j]);
                count++;
            }
        }
        while (answer.empty()!=true && answer.back()==' ') answer.pop_back();
        return answer;
    }
};