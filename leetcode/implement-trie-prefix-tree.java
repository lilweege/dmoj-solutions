// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
    private boolean wordEnd = false;
	private HashMap<Character, Trie> child = new HashMap<Character, Trie>();

    /** Initialize your data structure here. */
    public Trie() {}
    
    /** Inserts a word into the trie. */
    public void insert(String s) {
		Trie node = this;
		for (int i = 0, n = s.length(); i < n; ++i) {
            // if (!node.child.containsKey(s.charAt(i)))
            //     node.child.put(s.charAt(i), new Trie());
			node.child.putIfAbsent(s.charAt(i), new Trie());
			node = node.child.get(s.charAt(i));
		}
		node.wordEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String s) {
        // return true;
		Trie node = this;
		for (int i = 0, n = s.length(); i < n; ++i) {
			if (!node.child.containsKey(s.charAt(i)))
				return false;
			node = node.child.get(s.charAt(i));
		}
		return node.wordEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String s) {
        // return true;
		Trie node = this;
		for (int i = 0, n = s.length(); i < n; ++i) {
			if (!node.child.containsKey(s.charAt(i)))
				return false;
			node = node.child.get(s.charAt(i));
		}
		return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */