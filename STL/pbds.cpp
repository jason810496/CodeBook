#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_map tree<pair<int,int>, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
int main(){
    ordered_set o_set;
    o_set.insert( 10 );
    // Finding the second smallest element
    // in the set using * because
    //  find_by_order returns an iterator
    cout << *(o_set.find_by_order(1))<<"\n";
    // Finding the number of elements
    // strictly less than k=4
    cout << o_set.order_of_key(4)<<"\n";
    // Deleting 2 from the set if it exists
    if (o_set.find(2) != o_set.end())
        o_set.erase(o_set.find(2));
}