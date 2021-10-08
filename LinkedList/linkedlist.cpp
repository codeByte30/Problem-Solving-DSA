#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class node {
public:
    int data;
    node*next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};
void insertAtHead(node*&head, int data) {
    node*n = new node(data);
    n->next = head;
    head = n;
}
void insertAtTail(node*&head, int data) {
    if (head == NULL) {
        insertAtHead(head, data);
        return;
    }
    node*temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    node*n = new node(data);
    temp->next = n;
}
void printList(node*head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}
node*merge2LL(node*head1, node*head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node*temp = NULL;

    if (head1->data <= head2->data) {
        temp = head1;
        temp->next = merge2LL(head1->next, head2);
    }
    else {
        temp = head2;
        temp->next = merge2LL(head1, head2->next);
    }

    return temp;
}
node*midPoint(node*head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    node*slow = head;
    node*fast = head->next;
    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node*mergeSort(node*head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node*mid = midPoint(head);
    node*first = head;
    node*second = mid->next;
    mid->next = NULL;
    first = mergeSort(first);
    second = mergeSort(second);
    node*c = merge2LL(first, second);
    return c;
}
// bool cycle_exists(node*head) {
//     node*fast = head;
//     node*slow = head;
//     while (fast and fast->next) {
//         fast = fast->next->next;
//         slow = slow->next;
//         if (fast == slow) {
//             return true;
//         }
//     }
//     return false;
// }
bool cycle(node*head){
    map<node*,bool>mp;
    node*temp = head;
    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            return true;
        }
        mp[node] = 1;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n;
    int x;
    node*head1 = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        insertAtTail(head1, x);
    }
    // node*temp = head1;
    // while (temp->next != NULL) {
    //     temp = temp->next;
    // }
    // temp->next = head1;
    cout << cycle_exists(head1);
    // printList(head1);
    // for (int i = 0; i < m; ++i)
    // {
    //     cin >> x;
    //     insertAtTail(head2, x);
    // }

    // printList(head1);

    // printList(head2);

    // node*ans = merge2LL(head1, head2);

    // printList(ans);

    // node*ans = mergeSort(head1);
    // printList(ans);
    return 0;
}