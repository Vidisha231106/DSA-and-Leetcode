// 1401

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x=max(x1, min(xCenter, x2));
        int y=max(y1, min(yCenter, y2));
        cout<<x<<" "<<y<<endl;
        if ((xCenter-x)*(xCenter-x)+(yCenter-y)*(yCenter-y)<=radius*radius)return true;
        return false;
    }
};