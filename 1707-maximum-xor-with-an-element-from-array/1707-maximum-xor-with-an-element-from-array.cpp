struct Node
{
    Node *links[2];

    bool containsKey(int num)
    {
        return links[num] != NULL;
    }
    void putKey(int num, Node *node)
    {
        links[num] = node;
    }
    Node *getKey(int num)
    {
        return links[num];
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
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = num >> i & 1;
            if (!node->containsKey(bit))
            {
                node->putKey(bit, new Node());
            }
            node = node->getKey(bit);
        }
    }
    int getMax(string &num)
    {
        int mxNum = 0;
        Node *node = root;
        for (int i = 0; i <= 31; i++)
        {
            if (node->containsKey(!(num[i] - '0')))
            {
                mxNum+=pow(2, 31 - i) * (!(num[i] - '0'));
                node = node->getKey(!(num[i] - '0'));
            }
            else if (node->containsKey(num[i] - '0'))
            {
                mxNum += (num[i] - '0') * pow(2, 31 - i);
                node = node->getKey(num[i] - '0');
            }
            else
            {
                return -1;
            }
        }
        return mxNum;
    }
};

static bool custom(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        for (int i = 0; i < q; i++)
    {
        queries[i].push_back(i);
    }
    sort(nums.begin(), nums.end());
    sort(queries.begin(), queries.end(), custom);
    vector<int> res(q, 0);
    int k = 0, it = 0;
    Trie t;
    while (it < q)
    {
        int mx = INT_MIN;
        while (k<n && nums[k] <= queries[it][1])
        {
            t.insert(nums[k]);
            k++;
        }
        string binary = bitset<32>(queries[it][0]).to_string();
        int tmp = t.getMax(binary);
        if(tmp==-1){
            res[queries[it][2]] = -1;
        }
        else{mx = max(mx, queries[it][0] ^ tmp);
        res[queries[it][2]] = mx;
            }
        it++;
    }
        return res;
    }
};