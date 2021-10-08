#include <iostream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> Tr;

int main(){

    Tr Tree,other;
    string str;
    Tree.insert(str);
    Tree.erase(str);

    return 0;
}