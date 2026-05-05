// 3899

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> answer;
        sort(sides.begin(), sides.end());
        if ((sides[0])+(sides[1])<=(sides[2])) return answer;
        vector<double> s(3);
        for (int i=0; i<3; i++){
            s[i]=(double) sides[i];
        }
        int a=s[0];
        int b=s[1];
        int c=s[2];
        answer.push_back((acos((pow(b,2)+ pow(c,2) - pow(a,2))/(2*b*c)))*180/M_PI);
        b=s[0];
        c=s[1];
        a=s[2];
        answer.push_back((acos((pow(b,2)+ pow(c,2) - pow(a,2))/(2*b*c)))*180/M_PI);
        answer.push_back((double) 180 - answer[0]-answer[1]);

        sort(answer.begin(), answer.end());
        return answer;
    }
};