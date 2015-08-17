#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

#include <iostream>
#include <algorithm>

#define NULL 0

struct Node{
	/*
		The simplest way to implement a Disjoint-Union Data Structure is to use Linked Lists.
		Each element of this Disjoint-Union Data Structure would be represented as a Node whose
		definition is provided below
	*/
	int value;
	struct Node* next;
	Node() : value(0), next(NULL) {}
	Node(int value) : value(value), next(NULL) {}
	~Node() {}
};

struct disjointSetList{
	/*
		This is the container that would hold all the Disjoint subsets of the type struct Node
		under consideration. The container is a Doubly Linked List and each element would point
		to the head node of a single Disjoint-Set Data Structure
	*/
	struct Node* set_head_pointer;
	struct disjointSetList* prev;
	struct disjointSetList* next;
	disjointSetList() : set_head_pointer(NULL), prev(NULL), next(NULL) {}
	disjointSetList(Node* set_head_pointer) : set_head_pointer(set_head_pointer), prev(NULL), next(NULL) {}
	~disjointSetList() {}
};

class disjointSet{
	/*
		The operations of the Disjoint-Union Data Structure are defined as a part of this class
	*/
public:
	disjointSet(){
		dsl_head = new disjointSetList();
	}

	~disjointSet(){
		/*
			Use this destructor to de-allocate all the memory that has been allocated
			There are two types of memory allocation that one has to look at
			1. Memory allocated at an element level for each Disjoint sub set
			2. Memory allocated to the container itself
		*/
		Node* prev_node = NULL;
		Node* curr_node = NULL;
		disjointSetList* prev_cont_node = NULL;
		disjointSetList* curr_cont_node = dsl_head;
		while (curr_cont_node != NULL){
			prev_cont_node = curr_cont_node;
			curr_cont_node = curr_cont_node->next;

			curr_node = prev_cont_node->set_head_pointer;
			while (curr_node != NULL){
				prev_node = curr_node;
				curr_node = curr_node->next;
				delete prev_node;
			}

			delete prev_cont_node;
		}
	}

	bool makeSet(int value);
	int findInSet(int value);
	bool unionOfSets(int rep_1, int rep_2);
	bool insertIntoContainer(Node* set_head_pointer);

private:
	struct disjointSetList* dsl_head;
};

#endif
