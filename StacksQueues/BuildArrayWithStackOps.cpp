//1441

#include <vector>
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int count=1;
        int index=0;
        vector <string> answer;
        while(count<=n && index < target.size()){
            if (target[index]!=count){
                answer.push_back("Push");
                answer.push_back("Pop");
            }
            else{
                answer.push_back("Push");
                index++;
            }
            count++;
        }
        return answer;
    }
};