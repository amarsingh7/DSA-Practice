
class Node{
    public : 
    Node* tree[26];
    bool End;
    Node(){
        memset(tree,0,sizeof(tree));
        End = false;
    }
    
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
         Node* cur=root;
        for(int i=0;i<word.size();i++){
            int val=word[i]-'a';
            if(cur->tree[val]==NULL)cur->tree[val]=new Node();
            cur=cur->tree[val];
        }
        cur->End=true;
    }
    
    bool search(string word) {
        return a_search(word,root);
        
    }
    bool a_search(string word,Node* cur){
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                for(auto it : cur->tree){
                    if(it && a_search(word.substr(i+1),it))return true;
                    
                }return false;
            }
            int val=word[i]-'a';
            if(cur->tree[val]==NULL)return false;
            cur=cur->tree[val];
        }
        return cur->End;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */