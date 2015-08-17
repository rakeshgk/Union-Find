#include "Union_Find.h"

using namespace std;

void makeSetOutput(bool status, int element){
    if (status){
        cout << "Successfully created a Singleton set for the element - " << element << "\n";
    }
    else{
        cout << "Unable to create a Singleton set for the element - " << element << "\n";
    }
}

void findInSetOutput(int representative, int element){
    if (representative != -1){
        cout << "Found the element " << element << " and its representative is " << representative << "\n";
    }
    else{
        cout << "Could not find the element " << element << " in the Disjoint-Union data structure\n";
    }
}

void unionOfSetsOutput(bool status){
    if (status){
        cout << "Successfully created the Union of two disjoint sub sets\n";
    }
    else{
        cout << "Unable to create the union of two disjoint sub sets\n";
    }
}

int main(){
    disjointSet ds_obj;

    // Make some Singleton sets by calling the function makeSet
    bool status;
    status = ds_obj.makeSet(1);
    makeSetOutput(status, 1);

    status = ds_obj.makeSet(2);
    makeSetOutput(status, 2);

    status = ds_obj.makeSet(3);
    makeSetOutput(status, 3);

    status = ds_obj.makeSet(4);
    makeSetOutput(status, 4);

    status = ds_obj.makeSet(5);
    makeSetOutput(status, 5);

    status = ds_obj.makeSet(6);
    makeSetOutput(status, 6);

    // Test some Find operations by calling the function findInSet
    int representative = 0;
    representative = ds_obj.findInSet(1);
    findInSetOutput(representative, 1);
    
    representative = ds_obj.findInSet(2);
    findInSetOutput(representative, 2);

    representative = ds_obj.findInSet(7);
    findInSetOutput(representative, 7);

    representative = ds_obj.findInSet(8);
    findInSetOutput(representative, 8);

    // Test some Union Operations by calling unionOfSets and then check if the representative
    // is set properly by calling the findInSet function
    int representative_1 = 0;
    int representative_2 = 0;
    representative_1 = ds_obj.findInSet(1);
    representative_2 = ds_obj.findInSet(2);
    status = ds_obj.unionOfSets(representative_1, representative_2);
    unionOfSetsOutput(status);  
    representative = ds_obj.findInSet(1);
    findInSetOutput(representative, 1);

    representative_1 = ds_obj.findInSet(4);
    representative_2 = ds_obj.findInSet(5);
    status = ds_obj.unionOfSets(representative_1, representative_2);
    unionOfSetsOutput(status);
    representative = ds_obj.findInSet(4);
    findInSetOutput(representative, 4);

    representative_1 = ds_obj.findInSet(1);
    representative_2 = ds_obj.findInSet(4);
    status = ds_obj.unionOfSets(representative_1, representative_2);
    unionOfSetsOutput(status);
    representative = ds_obj.findInSet(2);
    findInSetOutput(representative, 2);

    representative_1 = ds_obj.findInSet(6);
    representative_2 = ds_obj.findInSet(9);
    status = ds_obj.unionOfSets(representative_1, representative_2);
    unionOfSetsOutput(status);
    representative = ds_obj.findInSet(6);
    findInSetOutput(representative, 6);

    return 0;
}
