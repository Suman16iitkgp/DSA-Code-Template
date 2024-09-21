/*
Given an array of integers. find the maximum XOR subarray value in the given array.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

class trieNode {
public:
    int freq;
    trieNode* left;
    trieNode* right;
    trieNode() {
        freq = 0;
        left = NULL;
        right = NULL;
    }
};

void insert(int n, trieNode* head) {
    trieNode* cur = head;
    for (int i = 31; i >= 0; --i) {
        int bit = (n >> i)&1;
        if(bit) {
            if(!cur->right) {
                cur->right = new trieNode();
            }
            cur = cur->right;
            cur->freq++;
        }
        else {
            if(!cur->left) {
                cur->left = new trieNode();
            }
            cur = cur->left;
            cur->freq++;
        }
    }
}

int findMaxXOR(int n, trieNode* head) {
    trieNode* cur = head;
    int ans = 0;
    for (int j = 31; j >= 0; --j) {
        int bit = (n >> j)&1;
        if(bit) {
            if(cur->left && cur->left->freq > 0) {
                ans += (1<<j);
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        else {
            if(cur->right && cur->right->freq > 0) {
                ans += (1<<j);
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        trieNode* head = new trieNode();
        int pre = 0;
        int ans = 0;
        insert(0, head);
        for (int i = 0; i < n; ++i) {
            pre ^= v[i];
            ans = max(ans, findMaxXOR(pre, head));
            insert(pre, head);
        }
        cout << ans << "\n";
    }
    return 0;
}