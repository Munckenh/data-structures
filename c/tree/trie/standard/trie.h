#ifndef TRIE_H
#define TRIE_H

#define TOTAL_CHARACTERS 256

#include <stdbool.h>

typedef struct trie_node {
    struct trie_node* children[TOTAL_CHARACTERS];
    bool is_terminal;
} TrieNode;

typedef struct {
   TrieNode* root;
} Trie;

Trie* trie_create();
void trie_destroy(Trie* trie);
TrieNode* trie_node_create();
void trie_node_destroy(TrieNode* node);
void trie_insert(Trie* trie, const char* word);
bool trie_search(Trie* trie, const char* word);
void trie_delete(Trie* trie, const char* word);
bool trie_delete_node(TrieNode* node, const char* word, int depth);
bool trie_is_leaf(TrieNode* node);

#endif