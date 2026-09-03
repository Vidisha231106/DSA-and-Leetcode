// 649

// Crazyy Q

class Solution {
public:
    string answer(int curr){
        if (curr==0) return "Dire";
        return "Radiant"; 
    }
    string predictPartyVictory(string senate) {
        deque <int> q;
        int r=0;
        int d=0;
        for(char c: senate){
            if (c=='R') {
                q.push_back(1);
                r++;
            }
            else {
                q.push_back(0);
                d++;
            }
        }
        int banr=0;
        int band=0;
        while(r>0 && d>0){
            int curr=q.front();
            q.pop_front();
            if (curr==1 && banr>0){
                banr--;
                continue;
            }
            else if (curr==0 && band>0){
                band--;
                continue;
            }
            if (r==0) return answer(0);
            if (d==0) return answer(1);
            if (curr==1){
                d--;
                band++;
            }
            else if (curr==0){
                r--;
                banr++;
            }
            q.push_back(curr);
        }
        return (r==0)? answer(0): answer(1);
    }
};