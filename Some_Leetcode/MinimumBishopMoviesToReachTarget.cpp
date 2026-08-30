// 4034

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x=abs(target[0]-source[0]);
        int y=abs(target[1]-source[1]);
        if (x%2!=y%2) return -1;
        if (abs(source[0]-target[0])==abs(source[1]-target[1])) return 1;
        return 2;
    }
};