// 3847

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        //let player a -> a, player b -> b,if 1 then that player is greater, other is 0
        int n = nums.size();
        int a=1; //this tells who is active
        int b=0; // this tells b is  inactive
        int a_marks=0;
        int b_marks=0;
        for (int i=0; i<n; i++){
            if (nums[i]%2==1){
                b=(b==0)?1:0;
                a=(b==0)?1:0;
            }
            if ((i+1)%6==0){
                b=(b==0)?1:0;
                a=(b==0)?1:0;    
            }
            if (a==1){
                a_marks+=nums[i];
                cout<<"a " << a_marks<<" "<<nums[i]<<endl;
            } 
            else{
                b_marks+=nums[i];
                cout<<"b " <<b_marks<<" "<<nums[i]<<endl;
            } 
        }
        return a_marks-b_marks;
    }
};