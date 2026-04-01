//2751

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = directions.size();

        for (int i = 0; i < n; i++) {
            if (directions[i] == 'L') {
                healths[i] *= -1;
            }
        }
        vector<vector<int>> v; // map <int, int> mp;
        for (int i = 0; i < n; i++) {
            v.push_back(
                {positions[i], i, healths[i]}); // mp[positions[i]]=healths[i];
        }
        sort(v.begin(), v.end());
        stack<vector<int>> st;

        for (int i = 0; i < n; i++) {
            if (st.empty() == true)
                st.push({v[i][1], v[i][2]});
            else if (st.top()[1] > 0 && v[i][2] < 0) { // opposite directions
                int is_alive = 1;
                while (st.empty() != true && st.top()[1] > 0 && v[i][2] < 0) {
                    if (abs(v[i][2]) == st.top()[1]) { // 10, -10
                        st.pop();
                        is_alive = 0;
                        break;
                    } else if (abs(v[i][2]) > st.top()[1]) { //-5, 10; -10, 5
                        st.pop();
                        v[i][2] += 1;
                        is_alive = 1;
                    } else { // 15, -10
                        st.top()[1]--;
                        is_alive = 0;
                        break;
                    }
                }
                if (is_alive == 1) { // (newer one is bigger) or (opposite
                                     // direction and dont collide)
                    st.push({v[i][1], v[i][2]});
                }
            } else { // same directions
                st.push({v[i][1], v[i][2]});
            }
        }
        vector<vector<int>> answer;
        while (st.empty() != true) {
            answer.push_back(st.top());
            st.pop();
        }
        sort(answer.begin(), answer.end());
        n = answer.size();
        vector<int> ordered_answer;
        for (int i = 0; i < n; i++) {
            ordered_answer.push_back(abs(answer[i][1]));
        }
        return ordered_answer;
    }
};