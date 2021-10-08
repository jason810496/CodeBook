#include <iostream>
using namespace std;
  
// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_map tree<pair<int,int>, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/*
The tree-based container has the following declaration:
/// insert, erase
/// order_of_key rank
/// find_by_order() kth
/// lower_bound() 前繼， >=x 最小的叠代器
/// upper_bound() 後繼   >x  最小的叠代器
/// a.join(b) b並入a，前提是兩顆樹的取值範圍不相交
/// a.split(v, b) key <= v的屬於a，其他屬於
/// 註意，插入的元素會去重，如set
*/
// Driver program to test above functions
int main()
{
    // Ordered set declared with name o_set
    ordered_set o_set;
    ordered_map o_map;
  
    // insert function to insert in
    // ordered set same as SET STL
    o_set.insert(5);
    o_set.insert(1);
    o_set.insert(2);
  
    // Finding the second smallest element
    // in the set using * because
    //  find_by_order returns an iterator
    cout << *(o_set.find_by_order(1)) 
         << endl;
  
    // Finding the number of elements
    // strictly less than k=4
    cout << o_set.order_of_key(4) 
         << endl;
  
    // Finding the count of elements less 
    // than or equal to 4 i.e. strictly less
    // than 5 if integers are present
    cout << o_set.order_of_key(5) 
         << endl;
  
    // Deleting 2 from the set if it exists
    if (o_set.find(2) != o_set.end())
        o_set.erase(o_set.find(2));
  
    // Now after deleting 2 from the set
    // Finding the second smallest element in the set
    cout << *(o_set.find_by_order(1)) 
         << endl;
  
    // Finding the number of
    // elements strictly less than k=4
    cout << o_set.order_of_key(4) 
         << endl;
    //__________________
    cout<<*(o_set.upper_bound(10) )<<endl;
    cout<<*(o_set.lower_bound(10) ) <<endl;

    return 0;
}