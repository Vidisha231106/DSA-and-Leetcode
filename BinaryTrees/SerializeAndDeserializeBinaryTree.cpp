// 297

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string null=to_string(11111010001); // 1001 in binary
    //let binary of 1001 be the null value since all nodes values are between -1000 to 1000
    string decimal_to_binary(int num){
        num+=1000;
        string answer="";
        if (num==0) answer="00000000000";
        while(num>0){
            answer+=((num%2)+'0');
            num/=2;
        }
        while (answer.length()<11){
            answer+='0';
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
    int binary_to_decimal(string s){
        int answer=0;
        for (int i=0; i<s.length(); i++){
            answer=answer*2+(s[i]-'0');
        }
        return answer;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string answer;
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty()!=true){
            TreeNode* curr=q.front();
            q.pop();
            if (curr!=nullptr) answer+=(decimal_to_binary(curr->val));
            else answer+=(null);
            if (curr==nullptr) continue;
            q.push(curr->left);
            q.push(curr->right);
        }
        return answer;
    }
    // TreeNode* buildTree(vector<int> &v, int i){
    //     if (i>=v.size()) return nullptr;
    //     if (v[i]==1001) return nullptr;
    //     TreeNode* root=new TreeNode(v[i]);
    //     if (2*i+1 <v.size()){
    //         root->left=buildTree(v, 2*i+1);
    //     }
    //     if (2*i+2 <v.size()){
    //         root->right=buildTree(v, 2*i+2);
    //     }
    //     return root;
    // }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v;
        for (int i=0; i<data.length(); i+=11){
            v.push_back(binary_to_decimal(data.substr(i,11))-1000);
        }
        if (v.empty() || v[0]==1001) return nullptr;
        TreeNode* root=new TreeNode(v[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while (q.empty()!=true && i<v.size()){
            TreeNode* curr=q.front();
            q.pop();
            if (i<v.size() && v[i]!=1001){
                curr->left=new TreeNode(v[i]);
                q.push(curr->left);
            }
            i++;
            if (i<v.size() && v[i]!=1001){
                curr->right=new TreeNode(v[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));