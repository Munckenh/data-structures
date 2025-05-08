#include <stdlib.h>
#include "trie.h"

TrieNode* trie_node_create(char letter) {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node != NULL) {
        node->letter = letter;
        node->next_letter = NULL;
        node->next_word = NULL;
        node->is_terminal = false;
    }
    return node;
}

void trie_insert(TrieNode** root, const char* word) {
    if (word == NULL || *word == '\0') return;
    TrieNode** current = root;
    TrieNode* previous = NULL;
    while (*word) {
        // Iterate through all siblings until we find the correct letter
        while (*current != NULL && (*current)->letter != *word) {
            current = &(*current)->next_word;
        }

        // If we iterated through all siblings and didn't find the letter, create
        // a new node
        if (*current == NULL) {
            *current = trie_node_create(*word);
        }

        previous = *current;                // Save the previous node
        current = &(*current)->next_letter; // Move to the next letter
        word++;                             // Move to the next character
    }

    // The last node we visited was saved to previous, so we set it as terminal
    if (previous != NULL) {
        previous->is_terminal = true;
    }
}

bool trie_search(TrieNode* root, const char* word) {
    TrieNode* current = root;
    TrieNode* previous = NULL;
    while (*word) {
        while (current != NULL && current->letter != *word) {
            current = current->next_word;
        }
        if (current == NULL) {
            return false;
        }
        previous = current;
        current = current->next_letter;
        word++;
    }
    if (previous != NULL) {
        return previous->is_terminal;
    }
    return false;
}

bool trie_node_is_leaf(TrieNode* node) {
    if (node == NULL) return false;
    return node->next_letter == NULL;
}

void trie_node_remove(TrieNode** node) {
    TrieNode* temp = *node;
    *node = (*node)->next_word;
    free(temp);
}

bool _trie_delete_helper(TrieNode** node, const char* word) {
    // Find the child node containing the current letter
    TrieNode** current = node;
    while (*current != NULL && (*current)->letter != *word) {
        current = &(*current)->next_word;
    }
    if (*current == NULL) return false; // Letter not found

    // Base case: last letter
    if (*(word + 1) == '\0') {
        if ((*current)->is_terminal) {
            (*current)->is_terminal = false;

            // If current node is a leaf node
            if ((*current)->next_letter == NULL) {
                trie_node_remove(current);
                return true;
            }
        }
        return false;
    }

    // If a child node was deleted
    if (_trie_delete_helper(&(*current)->next_letter, word + 1)) {
        // If current node is terminal and a leaf node
        if (!(*current)->is_terminal && (*current)->next_letter == NULL) {
            trie_node_remove(current);
            return true;
        }
    }

    return false;
}

void trie_delete(TrieNode** root, const char* word) {
    if (root == NULL || *root == NULL || word == NULL || *word == '\0')
        return;
    _trie_delete_helper(root, word);
}

void trie_free(TrieNode** root) {
    if (root == NULL || *root == NULL) return;

    if ((*root)->next_letter != NULL) {
        trie_free(&(*root)->next_letter);
    }

    if ((*root)->next_word != NULL) {
        trie_free(&(*root)->next_word);
    }

    free(*root);
    *root == NULL;
}