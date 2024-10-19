class Solution {
  public:
    bool search(vector<vector<char> >& board, const string& word, int index, int x,
            int y) {
    if (x < 0 || x == board[0].size() || y < 0 || y == board.size() ||
        word[index] != board[y][x])
        return false;
    if (index == word.length() - 1) return true;
    char cur = board[y][x];
    board[y][x] = '#';
    bool found = search(board, word, index + 1, x + 1, y)        // bottom
                 || search(board, word, index + 1, x - 1, y)     // top
                 || search(board, word, index + 1, x, y + 1)     // right
                 || search(board, word, index + 1, x, y - 1)     // left
                 || search(board, word, index + 1, x + 1, y + 1) // bottom right
                 || search(board, word, index + 1, x - 1, y + 1) // top right
                 || search(board, word, index + 1, x + 1, y - 1) // bottom left
                 || search(board, word, index + 1, x - 1, y - 1); // top left
    board[y][x] = cur;
    return found;
}

bool exist(vector<vector<char> >& board, string word) {
    if (board.size() == 0) return false;
    for (int i = 0; i < board[0].size(); i++)
        for (int j = 0; j < board.size(); j++)
            if (search(board, word, 0, i, j)) return true;

    return false;
}

vector<string> wordBoggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {
    vector<string> result;
    for (int i = 0; i < dictionary.size(); ++i) {
        string word = dictionary[i];
        if (exist(board, word)) result.push_back(word);
    }
    return result;
}
};