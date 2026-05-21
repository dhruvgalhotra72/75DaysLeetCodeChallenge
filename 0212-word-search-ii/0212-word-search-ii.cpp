class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:

    void insertWord(TrieNode* root, string word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node, vector<string>& ans) {

        char ch = board[i][j];

        if (ch == '#' || node->children[ch - 'a'] == NULL)
            return;

        node = node->children[ch - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#';

        int rows = board.size();
        int cols = board[0].size();

        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 &&
                ni < rows && nj < cols) {

                dfs(board, ni, nj, node, ans);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        for (string word : words) {
            insertWord(root, word);
        }

        vector<string> ans;

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};