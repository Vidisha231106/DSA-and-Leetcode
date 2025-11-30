//841

//Correct Logic - Very inefficient

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, int> locks; // vectors are lesser costly that unordered_maps
        int num = rooms.size();
        for (int i=0; i<num; i++){
            locks[i]=0;
        }
        locks[0]=1;
        stack <int> st;
        st.push(0);
        while(st.empty()!=1){
            int top_val=st.top();
            locks[st.top()]=1;
            st.pop();
            vector<int>& open_room = rooms[top_val];
            int n = open_room.size();
            for (int i=0; i<n; i++){
                if (locks[open_room[i]]==0){
                    locks[open_room[i]]=1;
                    st.push(open_room[i]);
                }
            }
        }
        for (int i=0; i<num; i++){
            if (locks[i]!=1) return false;
        }
        return true;
    }
};

//Correct logic - Efficient Code

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num = rooms.size();
        vector <int> locks(num,0); // vectors are lesser costly that unordered_maps
        locks[0]=1;
        stack <int> st;
        st.push(0);
        while(st.empty()!=1){
            int top_val=st.top();
            locks[st.top()]=1;
            st.pop();
            vector<int>& open_room = rooms[top_val];
            for (int i=0; i<open_room.size(); i++){
                if (locks[open_room[i]]==0){
                    locks[open_room[i]]=1;
                    st.push(open_room[i]);
                }
            }
        }
        for (int i=0; i<num; i++){
            if (locks[i]!=1) return false;
        }
        return true;
    }
};