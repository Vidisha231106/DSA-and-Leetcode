// 6

class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if (numRows==1) return s;
        vector<string> v(numRows*n);
        int count=0;
        int dir=1;
        for(int i=0; i<n; i++){
            v[count]+=s[i];
            cout<<count<<" ";
            count=(count+dir);
            if ((count+1)%numRows==0){
                dir=-1;
                //change direction
            }
            else if (count%(numRows*2-2)==0){
                dir=1;
            }
        }
        string ans="";
        for(string s: v){
            ans+=s;
        }
        return ans;
    }
};