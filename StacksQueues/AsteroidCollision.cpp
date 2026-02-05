// 735

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> s;
        int i=0;
        int n = asteroids.size();
        while (i<n){
            if (s.empty()!=true && s.top()>0 && asteroids[i]<0){
                int flag=0;
                if (s.top()>abs(asteroids[i])){
                    flag=1;
                }
                while (s.empty()!=true && s.top()>0 && s.top()<abs(asteroids[i])){
                    s.pop();
                }

                if (s.empty()!=true && s.top()>=abs(asteroids[i])) flag=1;
                if (s.empty()!=true && s.top()==abs(asteroids[i])) {
                    s.pop();
                    flag=1;
                }
                if (flag!=1){
                    s.push(asteroids[i]);
                }
            }
            else{
                s.push(asteroids[i]);
            }
            i++;
        }
        vector<int> ans;
        while (s.empty()!=true){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};