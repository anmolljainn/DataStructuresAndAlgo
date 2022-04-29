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

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */