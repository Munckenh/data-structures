#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

typedef struct trie_node {
   char letter;
   bool is_terminal;
   struct trie_node* next_letter;
   struct trie_node* next_word;
} TrieNode;

TrieNode* trie_node_create(char letter);
void trie_insert(TrieNode** root, const char* word);
bool trie_search(TrieNode* root, const char* word);
bool trie_node_is_leaf(TrieNode* node);
void trie_node_remove(TrieNode** node);
bool _trie_delete_helper(TrieNode** node, const char* word);
void trie_delete(TrieNode** root, const char* word);
void trie_free(TrieNode** root);



#endif