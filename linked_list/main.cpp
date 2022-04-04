#include <iostream>
#include "linked_list.hpp"

using std::cout;
using std::endl;

int main() {
    const unsigned N = 5;
    LinkedList<int> ll;
    for (int i = 0; i < N; i += 1) {
        ll.prepend(i);
    }
    cout << "inorder: " << ll.inorder() << endl;
    cout << "postorder: " << ll.postorder() << endl;
    ll.insert(ll.length() / 2, 9);
    cout << "inorder: " << ll.inorder() << endl;
    cout << "postorder: " << ll.postorder() << endl;
    cout << "mid value: " << ll.get(ll.length() / 2) << endl;
    ll.set(ll.length() / 2, 8);
    cout << "mid value: " << ll.get(ll.length() / 2) << endl;
    ll.remove(ll.length() / 2);
    cout << "inorder: " << ll.inorder() << endl;
    cout << "postorder: " << ll.postorder() << endl;
    ll.pop_first();
    ll.pop_last();
    cout << "inorder: " << ll.inorder() << endl;
    cout << "postorder: " << ll.postorder() << endl;
    cout << "length: " << ll.length() << endl;
    cout << "middle value: " << ll[ll.length() / 2] << endl;
}
