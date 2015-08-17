#include "Union_Find.h"

using namespace std;

bool disjointSet::makeSet(int value){
    /*
        This function can be used to create a new Singleton set within the Disjoint-Union
        data structure. Here "value" represents the value of the element that needs to be
        inserted in to the Disjoint-Union Data Structure.

        We will follow the convention of having the largest element within a particular
        Disjoint-Union set be the representative.

        In a Singleton, since there is just one element both the head_node and the new_node
        would have the same value to begin with
    */

    Node* head_node = new Node(value);
    Node* new_node = new Node(value);
    head_node->next = new_node;
    return insertIntoContainer(head_node);
}

bool disjointSet::insertIntoContainer(Node* set_head_pointer){
    /*
        Once a new Singleton set has been constructed insert it in to the container
        that holds all the Disjoint sets created till date.
    */

    disjointSetList* current_dsl_node = dsl_head;
    disjointSetList* new_dsl_node = new disjointSetList(set_head_pointer);

    // Traverse till the end of the Doubly Linked List and insert the new_dsl_node at the end
    while (current_dsl_node->next != NULL){
        current_dsl_node = current_dsl_node->next;
    }

    current_dsl_node->next = new_dsl_node;
    new_dsl_node->prev = current_dsl_node;
    return true;
}

int disjointSet::findInSet(int value){
    /*
        Given a "value" find out whether it belongs to a particular Disjoint set and if yes
        then return the "representative" for that set.

        If the element cannot be found in any of the Disjoint sub sets then return -1
    */

    Node* set_node = NULL;
    Node* set_head_node = NULL;
    disjointSetList* current_dsl_node = dsl_head->next;

    // Iterate through all the set nodes for each DSL Node
    while (current_dsl_node != NULL){
        set_head_node = current_dsl_node->set_head_pointer;
        set_node = set_head_node->next;
        while (set_node != NULL){
            if (set_node->value == value){
                return set_head_node->value;
            }
            set_node = set_node->next;
        }
        current_dsl_node = current_dsl_node->next;
    }

    return -1;
}

bool disjointSet::unionOfSets(int rep_1, int rep_2){
    /*
        Given two "representatives" perform the Union of the Disjoint subsets
        pointed to by the representatives.
    */

    if (rep_1 == rep_2){
        // The two representatives have to be distinct
        return false;
    }

    if (rep_1 == -1 || rep_2 == -1){
        // Only valid disjoint subsets can be concatenated
        return false;
    }

    Node* set_head = NULL;
    Node* head_ptr_1 = NULL;
    Node* head_ptr_2 = NULL;
    disjointSetList* dsl_current_node = dsl_head->next;

    while (dsl_current_node != NULL){
        set_head = dsl_current_node->set_head_pointer;
        if (head_ptr_1 == NULL && (set_head->value == rep_1 || set_head->value == rep_2)){
            head_ptr_1 = set_head;
        }
        else if (head_ptr_2 == NULL && (set_head->value == rep_1 || set_head->value == rep_2)){
            head_ptr_2 = set_head;
        }

        if (head_ptr_1 != NULL && head_ptr_2 != NULL){
            // We peform the Union of the two Disjoint subsets only in this case
            // It is assumed that the second subset is appended to the first
            set_head = head_ptr_1;

            // Change the representative of the first set to contain the maximum value
            // of the two disjoint subsets being merged
            head_ptr_1->value = max(head_ptr_1->value, head_ptr_2->value);

            // Traverse till the end of the first disjoint sub set
            while (set_head->next != NULL){
                set_head = set_head->next;
            }
            // Perfrom the Union by linking the first node of the second subset to
            // the last node of the first sub set
            set_head->next = head_ptr_2->next;

            // De-allocate the memory previously allocated for head_pointer_2. The memory
            // was created while creating the Singleton sets
            delete head_ptr_2;

            // De-allocate the memory that was created for the container in the DSL for the
            // second sub set which is now merged with the first
            disjointSetList* prev_dsl_node = dsl_current_node->prev;
            disjointSetList* next_dsl_node = dsl_current_node->next;
            prev_dsl_node->next = next_dsl_node;
            next_dsl_node->prev = prev_dsl_node;

            return true;
        }

        dsl_current_node = dsl_current_node->next;
    }
    return false;
}
