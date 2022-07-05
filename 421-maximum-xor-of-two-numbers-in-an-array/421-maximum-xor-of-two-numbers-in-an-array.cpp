struct Node
{
    Node *links[2];

    bool containsKey(int ch)
    {
        return links[ch] != NULL;
    }
    // Updates the key and inserts a reference Node
    void putKey(int ch, Node *node)
    {
        links[ch] = node;
    }
    // Returns the reference trie
    Node *get(int ch)
    {
        return links[ch];
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

    void insert(string &num)
    {
        Node *node = root;
        for (int i = 0; i < num.length(); i++)
        {
            if (!node->containsKey(num[i]-'0'))
            {
                node->putKey(num[i]-'0', new Node());
            }

            // Moves to the reference trie
            node = node->get(num[i]-'0');
        }
    }
    int findMaxXOR(string &num)
    {
        int res = 0;
        Node *node = root;
        int p = 31;
        for (int i = 0; i < num.size(); i++)
        {
            if (node->containsKey(!(num[i]-'0')))
            {
                res += (pow(2, p--)) * (!(num[i]-'0'));
                 node = node->get(!(num[i]-'0'));
            }
            else
            {
                res += (pow(2, p--)) * (num[i]-'0');
                node = node->get(num[i]-'0');
            }
        }
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
    Trie t;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        string binary = bitset<32>(nums[i]).to_string();
        t.insert(binary);
    }
    for (int i = 0; i < n; i++)
    {
        string binary = bitset<32>(nums[i]).to_string();
        int res = t.findMaxXOR(binary);
        mx = max(mx, nums[i] ^ res);
    }
    return mx;
    }
};