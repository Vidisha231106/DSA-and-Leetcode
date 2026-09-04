// 1268

struct Node{
    vector<Node*> links=vector<Node*>(26, nullptr);
    vector<string> words;
    int flag=false;
    bool containsKey(char c){
        return links[c-'a']!=nullptr;
    }
    Node* getchar(char c){
        return links[c-'a']; 
    }
    void putchar(char c, Node* node){
        links[c-'a']=node;
    }
    void setend(){
        flag=true;
    }
    void addword(string s){
        words.push_back(s);
    }
};
class Trie{
private: Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insertWord(string s){
        Node* node=root;
        for(char c:s){
            if (node->containsKey(c)==false){
                node->putchar(c, new Node());
            }
            node=node->getchar(c);
            node->addword(s);
        }
        node->setend();
    }
    bool containsPrefix(string prefix){
        Node* node=root;
        for(char c: prefix){
            if (node->containsKey(c)==false) return false;
            node=node->getchar(c);
        }
        return true;
    }
    vector<string> getwords(string sub){
        Node* node=root;
        for(char c: sub){
            if (node->containsKey(c)==false) return {};
            node=node->getchar(c);
        }
        return node->words;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        int n=products.size();
        vector<vector<string>> answer;
        for(int i=0; i<n; i++){
            t.insertWord(products[i]);
        }
        int x=searchWord.size();
        for(int i=1; i<=x; i++){
            string sub=searchWord.substr(0, i);
            vector<string> curr=t.getwords(sub);
            sort(curr.begin(), curr.end());
            if (curr.size()>3) curr.resize(3);
            answer.push_back(curr);
        }
        return answer;
    }
};