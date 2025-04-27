#include <stdlib.h>
#include <stdio.h> // TODO: Remove
#include "trie.h"

Trie* trie_create() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    if (trie == NULL) return NULL;
    trie->root = NULL;
    return trie;
}

void trie_destroy(Trie* trie) {
    if (trie == NULL) return;
    trie_node_destroy(trie->root);
    free(trie);
}

TrieNode* trie_node_create() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node == NULL) return NULL;
    for (int i = 0; i < TOTAL_CHARACTERS; ++i)
        node->children[i] = NULL;
    node->is_terminal = false;
    return node;
}

void trie_node_destroy(TrieNode* node) {
    if (node == NULL) return;
    for (int i = 0; i < TOTAL_CHARACTERS; ++i) {
        if (node->children[i] != NULL)
            trie_node_destroy(node->children[i]);
    }
    free(node);
}

void trie_insert(Trie* trie, const char* word) {
    if (trie == NULL || word == NULL) return;

    // Create root node
    if (trie->root == NULL) {
        trie->root = trie_node_create();
        if (trie->root == NULL) return;
    }

    TrieNode* current = trie->root;
    for (int i = 0; word[i] != '\0'; ++i) {
        unsigned char index = (unsigned char)word[i];

        // Create new node if it doesn't exist
        if (current->children[index] == NULL) {
            current->children[index] = trie_node_create();
            if (current->children[index] == NULL) return;
        }

        current = current->children[index];
    }
    current->is_terminal = true;
}

bool trie_search(Trie* trie, const char* word) {
    if (trie == NULL || trie->root == NULL || word == NULL)
        return false;

    // Go through the trie
    TrieNode* current = trie->root;
    for (int i = 0; word[i] != '\0'; ++i) {
        unsigned char index = (unsigned char)word[i];
        if (current->children[index] == NULL) return false;
        current = current->children[index];
    }

    return current->is_terminal;
}

void trie_delete(Trie* trie, const char* word) {
    if (trie == NULL || trie->root == NULL || word == NULL)
        return;
    trie_delete_node(trie->root, word, 0);
}

// True if passed node is to be deleted, false otherwise
bool trie_delete_node(TrieNode* node, const char* word, int depth) {
    if (node == NULL) return false;

    // Base case: last character
    if (word[depth] == '\0') {  // This is a look-ahead
        // If it's a valid end of word
        if (node->is_terminal) {
            node->is_terminal = false;
            return trie_is_leaf(node);
        }
        return false;
    }

    unsigned char index = (unsigned char)word[depth];

    // If word doesn't exist. This can be omitted and the function will still
    // work, but it will be less efficient. This prevents unnecessary recursion.
    if (node->children[index] == NULL) return false;

    // If child should be deleted
    if (trie_delete_node(node->children[index], word, depth + 1)) {
        free(node->children[index]);
        node->children[index] = NULL;

        // Return true if current node is to be deleted
        return !node->is_terminal && trie_is_leaf(node);
    }
    return false;
}

bool trie_is_leaf(TrieNode* node) {
    if (node == NULL) return false;
    for (int i = 0; i < TOTAL_CHARACTERS; ++i) {
        if (node->children[i] != NULL) return false;
    }
    return true;
}

int main() {
    Trie* trie = trie_create();
    trie_insert(trie, "abc");
    printf("%d", trie_search(trie, "a"));
    printf("%d", trie_search(trie, "abc"));
    printf("%d", trie_search(trie, "ab"));
    printf("%d", trie_search(trie, "abcc"));
    return 0;
}
