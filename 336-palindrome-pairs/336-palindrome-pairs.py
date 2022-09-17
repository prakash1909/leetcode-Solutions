class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        root = TrieNode()
        wd_idxs = {}
        for wd_idx, wd in enumerate(words):
            rev_wd = ''.join(reversed(wd))
            root.insert(rev_wd, wd_idx)
            wd_idxs[wd] = wd_idx

        result = []
        for wd_idx, wd in enumerate(words):
            if wd == '':
                continue
            trieNode = root
            for ci, c in enumerate(wd):
                rem_wd = wd[ci:]
                if PalindromeUtility.is_palindrome(rem_wd) and '#' in trieNode.trie:
                    # case 1: word could possibly continue and remaining word is a palindrome
                    result.append([wd_idx, trieNode.trie['#'].ei])

                if c not in trieNode.trie:
                    break

                if ci == len(wd)-1 and '#' in trieNode.trie[c].trie:
                    # case 2: word ends trie ends
                    if trieNode.trie[c].trie['#'].ei != wd_idx:
                        result.append([wd_idx, trieNode.trie[c].trie['#'].ei])

                trieNode = trieNode.trie[c]

                if ci == len(wd)-1:
                    # case 3: word ends and trie continues
                    for pi in trieNode.pali_idxs:
                        result.append([wd_idx, pi])

            if PalindromeUtility.is_palindrome(wd) and '' in wd_idxs:
                result.append([wd_idxs[''], wd_idx])

        return result


class PalindromeUtility:
    def __init__(self) -> None:
        pass

    @classmethod
    def is_palindrome(cls, wd):
        return wd == wd[::-1]


class TrieNode:
    def __init__(self):
        self.trie = {}
        self.ei = None
        self.pali_idxs = []

    def insert(self, wd, idx):
        trieNode = self
        for i, c in enumerate(wd):
            if c not in trieNode.trie:
                trieNode.trie[c] = TrieNode()

            rm_wd = wd[i+1:]
            if len(rm_wd) > 0 and PalindromeUtility.is_palindrome(rm_wd):
                trieNode.trie[c].pali_idxs.append(idx)
            trieNode = trieNode.trie[c]
        trieNode.trie['#'] = TrieNode()
        trieNode.trie['#'].ei = idx