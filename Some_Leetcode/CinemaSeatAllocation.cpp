// 1386

class Solution {
public:
    int check(unordered_set<int> blocked){
        int count=0;
        if (!blocked.contains(4) && !blocked.contains(5) && !blocked.contains(6) && !blocked.contains(7) && (blocked.contains(2) || blocked.contains(3) || blocked.contains(8) || blocked.contains(9))) count++;
        else {
            if (!blocked.contains(2) && !blocked.contains(3) && !blocked.contains(4) && !blocked.contains(5)) count++;
            if (!blocked.contains(6) && !blocked.contains(7) && !blocked.contains(8) && !blocked.contains(9)) count++;
        }
        cout<<count<<endl;
        return count;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map <int, unordered_set<int>> mp; // row = <cols>
        int x=reservedSeats.size();
        for (int i=0; i<x; i++){
            mp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        int answer=2*(n-mp.size());
        for(auto x: mp){
            cout<<x.first<<" : ";
            answer+=check(x.second);
        }
        return answer;
    }
};