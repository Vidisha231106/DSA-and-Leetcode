// Strivers Sheet

class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        int n=val.size();
        vector<vector<double>> v(n, vector<double> (3, 0));
        for (int i=0; i<n; i++){
            v[i][0]=(double)val[i]/(double)wt[i];
            v[i][1]=val[i];
            v[i][2]=wt[i];
        }
        sort (v.begin(), v.end(), [](vector<double> &a, vector<double> &b){
            if (a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]>b[0];
        });
        int i=0;
        double total=0;
        while (i<n && v[i][2]<=capacity && capacity>0){
            capacity-=v[i][2];
            total+=v[i][1];
            i++;
        }
            if (i<n && capacity>0){
                total+=v[i][0]*capacity;
            }
        return total;
    }
};