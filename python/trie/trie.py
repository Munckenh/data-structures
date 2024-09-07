from collections import defaultdict


class Node:
    """A single node of a trie.

    Attributes
    ----------
    children : defaultdict
        A dictionary of the node's children in a character-node pair.
    is_terminal : bool
        Whether this node is an end of a word.
    """

    def __init__(self):
        self.children = defaultdict(Node)
        self.is_terminal = False


class Trie:
    """A simple trie implementation.

    Attributes
    ----------
    root : Node
        The root node of the trie.
    """

    def __init__(self):
        self.root = Node()

    def clear(self) -> None:
        """Clears the entire trie of its nodes."""
        self.root = Node()

    def insert(self, key: str) -> None:
        """Inserts a key into the trie.

        Parameters
        ----------
        key : str
            A key to be inserted into the trie.
        """
        node = self.root
        for character in key:
            node = node.children[character]
        node.is_terminal = True

    def search(self, key: str) -> bool:
        """Searches if a key exists in the trie.

        Parameters
        ----------
        key : str
            A key to be searched in the trie.

        Returns
        -------
        bool
            ``True`` if a key is found.
        """
        node = self.root
        for character in key:
            if character not in node.children:
                return False
            node = node.children[character]
        return node.is_terminal

    def delete(self, key: str) -> bool:
        """Deletes a key from the trie.

        Parameters
        ----------
        key : str
            A key to be deleted from the trie.

        Returns
        -------
        bool
            ``True`` if the deletion is successful. ``False`` if the key is not found.
        """
        node = self.root
        stack = []
        for character in key:
            if character not in node.children:
                return False
            stack.append(node)
            node = node.children[character]
        if not node.is_terminal:
            return False
        node.is_terminal = False
        for character in reversed(key):
            if node.children or node.is_terminal:
                break
            node = stack.pop()
            del node.children[character]
        return True
