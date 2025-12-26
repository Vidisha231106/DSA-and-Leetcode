//2483

// Less Efficient Code:

class Solution {
public:
    int bestClosingTime(string customers) {
        vector <int>losses;
        int n = customers.size();
        int N_num_till_there=0;
        int count=0;
        int Y_total=0;
        
        for (int i=0; i<n; i++){
            if (customers[i]=='Y') Y_total++;
        }

        int Y_num_from_there = Y_total;

        for (int i=0; i<n; i++){
            count = Y_num_from_there + N_num_till_there;
            losses.push_back(count);
            if (customers[i]=='N') N_num_till_there++;
            else Y_num_from_there--;
        }

        losses.push_back(N_num_till_there);
        int min = losses[0];
        int min_index=0;
        for (int i=0; i<=n; i++){
            if (min>losses[i]){
min_index = i;
min = losses[i];
            } 
        }
        return min_index;
    }
};

// More Efficient Code:

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int N_num_till_there=0;
        int Y_total=0;
        for (int i=0; i<n; i++){
            if (customers[i]=='Y') Y_total++;
        }
        int min = Y_total;
        int min_index=0;
        for (int i=0; i<n; i++){
            if (customers[i]=='N') N_num_till_there++;
            else Y_total--;
            if (min>Y_total + N_num_till_there){
                min_index = i+1;
                min = Y_total + N_num_till_there;
            } 
        }
        if (min>N_num_till_there) return n;
        return min_index;
    }
};