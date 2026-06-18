// 1344

class Solution {
    const double PI=std::numbers::pi;
public:
    double angleClock(int hour, int minutes) {
        
        double a1=(hour%12 + minutes/60.0)*360.0/12;
        double a2= minutes*360.0/60;
        return min(abs(a1-a2), 360.0-abs(a1-a2));
    }
};