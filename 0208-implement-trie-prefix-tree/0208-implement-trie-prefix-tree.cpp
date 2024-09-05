#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[26];
	bool flag = false;
	
	bool containKey(char ch){
		return links[ch-'a'] != NULL;
	}
	
	void put(char ch, Node* node){
		links[ch-'a'] = node;
	}
	
	Node* get(char ch){
		return links[ch-'a'];
	}
	
	// Mark this node as the end of a word
	void setEnd(){
		flag = true;
	}
	
	// Check if this node is the end of a word
	bool isEnd(){
		return flag;
	}
};

class Trie{
private:
	Node* root;
public:
	Trie(){
		root = new Node();
	}
	
	void insert(string word){
		Node* node = root;
		for(int i = 0; i < word.size(); i++){
			if(!node->containKey(word[i])){
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();  // Corrected the call to set the end of a word
	}
	
	bool search(string word){
		Node* node = root;
		for(int i = 0; i < word.size(); i++){
			if(!node->containKey(word[i])) return false;
			node = node->get(word[i]);
		}
		return node->isEnd();  // Corrected to return a boolean value
	}
	
	bool startsWith(string word){
		Node* node = root;
		for(int i = 0; i < word.size(); i++){
			if(!node->containKey(word[i])) return false;
			node = node->get(word[i]);
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */