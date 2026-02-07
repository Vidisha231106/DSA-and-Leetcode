//133

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map <Node*, Node*> mymap;
    Node* createAdj(Node* node){
        if (node==nullptr) return nullptr;
        if (mymap.count(node)!=0){
            return mymap[node];
        }
        int n = node->neighbors.size();
        Node* new_node=new Node(node->val);
        mymap[node]=new_node;
        for (int j=0; j<node->neighbors.size(); j++){
            Node* neig=createAdj(node->neighbors[j]);
            new_node->neighbors.push_back(neig);
        }
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        return createAdj(node);
    }
};