#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
class trienode {
public:
    unordered_map<char, trienode*> children;
    bool wordend;

    trienode() : wordend(false) {}
};
class Trie {
public:
    trienode* root;
    Trie() {
        root = new trienode();
    }
    void insert(const string& word, char charachterend) { //for the longest common substring
        trienode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new trienode();
            }
            current = current->children[ch];
        }
        current->children[charachterend] = new trienode();
    }
    // this adds the spial character to each string
    void buildSuffixTrie(const string& s1, const string& s2) {
        for (size_t i = 0; i < s1.length(); ++i) {
            insert(s1.substr(i), '$');
        }
        for (size_t i = 0; i < s2.length(); ++i) {
            insert(s2.substr(i), '#');
        }
    }
    pair<string, vector<int>> getLongestCommonSubstring(trienode* current, char ch) {
        int dollarcount = 0;
        int hashcount = 0;
        string longestcommonsubstring;
        // this section count the special character for each branch
        for (const auto& child : current->children) {
            if (child.first == '$') {
                dollarcount++;
            }
            else if (child.first == '#') {
                hashcount++;
            }
            else {// this section call the recrusive search in case no special character found
                auto pair = getLongestCommonSubstring(child.second, child.first);
                dollarcount += pair.second[0];
                hashcount += pair.second[1];
                if (pair.first.length() > longestcommonsubstring.length()) {
                    longestcommonsubstring = pair.first;
                }    }  }

        if (dollarcount > 0 && hashcount > 0 && ch != '*') {
            longestcommonsubstring = ch + longestcommonsubstring;
        }
        return { longestcommonsubstring, {dollarcount, hashcount} };
    }

    string longestcommonsubstring(const string& s1, const string& s2) {
        buildSuffixTrie(s1, s2);
        return getLongestCommonSubstring(root, '*').first;
    }
    void buildTree(string& word) { //for the pattern search
        for (int i = 0; i < word.size(); ++i) {
            insertsuffix(word, i);
        }
    }
    void insertsuffix(string& word, int start) { //while building for pattern match
        trienode* current = root;
        for (int i = start; i < word.size(); ++i) {
            char c = word[i];
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new trienode(); }
            current = current->children[c];
        }
        current->wordend = true;
    }

    bool searchpattern(string& pattern) {
        trienode* current = root;
        int i = 0;
        while (i < pattern.size()) {
            bool found = false;
            for (auto& edge : current->children) {
                char edgelabel = edge.first;
                if (pattern.substr(i, 1) == string(1, edgelabel)) {
                    i += 1;
                    current = edge.second;
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Trie trie;
    cout << "Hello, For the Pattern matching : Please enter your DNA or Protein Sequence: "  <<endl;
    string seq;
    cin>>seq;
    trie.buildTree(seq);
    cout << "Hello, Please enter your pattern of sequence to see if it's in your sequence or not;"  <<endl;
    string pattern;
    cin>>pattern;
    if (trie.searchpattern(pattern)) {
        cout << "Pattern found!" << endl;
    }
    else {
        cout << "Pattern not found!" << endl;
    };
    cout << "Hello again, To get the Longest common substring , Please enter your first DNA or Protein Sequence: "  <<endl;
    string seq1;
    cin>>seq1;
    cout << "Now, Please enter your second DNA or Protein Sequence: "  <<endl;
    string seq2;
    cin>>seq2;
    string result = trie.longestcommonsubstring(seq1, seq2);trie.buildTree(seq);
    cout << "Longest Common Substring: " << result << endl;
    cout<<"Thank you for your time";
    return 0;
}
