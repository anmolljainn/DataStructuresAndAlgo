struct Node
{
    Node *links[26];
    bool flag = false;

    // Tells if the key is present or not

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    // Updates the key and inserts a reference Node

    void putKey(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // Returns the reference trie

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // Sets the end to the word while inserting

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

/* Trie Class */

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->putKey(word[i], new Node());
            }

            // Moves to the reference trie
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
    }
};
class Solution {
    vector<string> res;
    
    void solver(string &s,string st,int pos,Trie &t){
        if(pos==s.size()){
            res.push_back(st);
            return;
        }
        st+=" ";
        for(int i=pos;i<s.size();i++){
            if(t.search(s.substr(pos,i+1-pos))==true){
                solver(s,st+s.substr(pos,i+1-pos),i+1,t);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        res.clear();
        
        Trie t;
        for(int i=0;i<wordDict.size();i++){
            t.insert(wordDict[i]);
        }
        
        for(int i=0;i<s.size();i++){
            if(t.search(s.substr(0,i+1))==true){
                solver(s,s.substr(0,i+1),i+1,t);
            }
        }
        return res;
    }
};