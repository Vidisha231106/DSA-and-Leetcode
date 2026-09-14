//836 

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long left=max(rec1[0], rec2[0]);
        long long right=min(rec1[2], rec2[2]);
        long long up=min(rec1[3], rec2[3]);
        long long down=max(rec1[1], rec2[1]);
        if (right<left || up<down) return false;
        if ((right-left)*(up-down)>0)return true;
        return false;
    }
};