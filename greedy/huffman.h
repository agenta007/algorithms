//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_HUFFMAN_H
#define ALGORITHMS_HUFFMAN_H

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <iostream>

struct HuffNode {
    char ch;
    int freq;
    HuffNode* left;
    HuffNode* right;
    HuffNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    HuffNode(int f, HuffNode* l, HuffNode* r) : ch('\0'), freq(f), left(l), right(r) {}
};

struct HuffCmp {
    bool operator()(HuffNode* a, HuffNode* b) { return a->freq > b->freq; }
};

static void buildCodes(HuffNode* node, const std::string& code,
                       std::unordered_map<char, std::string>& table) {
    if (!node) return;
    if (!node->left && !node->right) {
        table[node->ch] = code.empty() ? "0" : code;
        return;
    }
    buildCodes(node->left,  code + "0", table);
    buildCodes(node->right, code + "1", table);
}

// Build Huffman tree and return encoding table
std::unordered_map<char, std::string> huffman(const std::unordered_map<char, int>& freqs) {
    std::priority_queue<HuffNode*, std::vector<HuffNode*>, HuffCmp> pq;
    for (auto& [ch, f] : freqs)
        pq.push(new HuffNode(ch, f));

    while (pq.size() > 1) {
        HuffNode* l = pq.top(); pq.pop();
        HuffNode* r = pq.top(); pq.pop();
        pq.push(new HuffNode(l->freq + r->freq, l, r));
    }

    std::unordered_map<char, std::string> table;
    if (!pq.empty())
        buildCodes(pq.top(), "", table);
    return table;
}

void demoHuffman() {
    std::unordered_map<char, int> freqs = {
        {'a',5},{'b',9},{'c',12},{'d',13},{'e',16},{'f',45}
    };
    auto table = huffman(freqs);
    std::cout << "Huffman codes:\n";
    for (auto& [ch, code] : table)
        std::cout << "  " << ch << ": " << code << "\n";
}

#endif //ALGORITHMS_HUFFMAN_H
