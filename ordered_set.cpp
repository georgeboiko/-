//find_by_order(x) – возвращает итератор на k-ый по величине элемент
//order_of_key(x) – количество элементов в множестве, строго меньших чем x

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    ordered_set o_set;
    o_set.insert(5);
    o_set.insert(1);
    o_set.insert(2);
    cout << *(o_set.find_by_order(1)) << '\n';
    cout << o_set.order_of_key(4) << '\n';
    cout << o_set.order_of_key(5) << '\n';
    if (o_set.find(2) != o_set.end()) o_set.erase(o_set.find(2));
    cout << *(o_set.find_by_order(1)) << '\n';
    cout << o_set.order_of_key(4) << '\n';
}
