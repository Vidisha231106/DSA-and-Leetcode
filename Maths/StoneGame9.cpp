// 2029

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int> v(3, 0);
        for(int i=0; i<n; i++) v[stones[i]%3]++;
        // if (v[1]%2==0 && v[0]%2==0) return false; // e(1)+e(3) -> next is Alice takes 2 ->loses
        // if (v[1]%2==0 && v[0]%2!=0) return true; // bob will use the next number from 2 and will make sum divisble by 3
        // if (v[1]%2!=0 && v[0]%2==0) return true;
        // return false;
        // // if (v[1]%2==0 && v[2]%2==0){
        // //     if (v[0]%2==0) return false;
        // //     else return true;
        // // } 
        // // else if  (v[1]%2!=0 && v[2]%2!=0){
        // //     if (v[0]%2==0) return false;
        // //     else return true;
        // // }
        // // else if ((v[1]%2==0 && v[2]%2!=0) || (v[1]%2!=0 && v[2]%2==0)){
        // //     if (v[0]%2==0) return true;
        // //     return false;
        // // }
        // // return false;
        if (v[0]%2==0){
            return v[1]>0 && v[2]>0; // this is because, after alice chooses v[1], bob and alice choose v[0], then because v[0] is even, bob will play next after v[0] is over
            // thus, bob chooses v[2] and makes sum divisible by 3;
        }
        return abs(v[1]-v[2])>2;//this ensures that if alice chooses the greater one of v[1] and v[2], she will always have values of same to choose from when bob's (lesser of v[1] and v[2]) gets over. thus, bob will take alice's (greater one of v[1] and v[2]) and will make sum divisble by 3;
    }
};