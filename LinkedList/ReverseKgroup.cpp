#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start=head;
        ListNode* end=head;
        ListNode* ans=head;
        ListNode* temp;
        int i=k;
        while(i--){
            end=end->next;
        }
        int t=0;
        int r=0;
        while(1){
            int c=k;
            while(c--){
                ListNode* next = start->next;
                start->next=end;
                end=start;
                start=next;
                if(r==1){
                    cout << "end: " << end->val<< endl;
                }
            }
            if(r==0){
                ans=end;
            }
            
            if(r==1){
                temp->next = end;
            }
            if(t==1) return ans;
            int j=0;
            while(j<2*k){
                if(j==k-1){
                    temp=end;
                } 
                if(t==1) return ans;
                end=end->next;
                
                if(end==nullptr){ t=1;
                    cout << j << " end: " <<  "null"   << endl;
                }
                else cout << j << " end: " <<  end->val   << endl;
                j++;
            }
            cout << "temp: " << temp->val << endl; 
            r=1;
        }
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    //list1->next->next->next->next = new ListNode(5);
    printList(list1);

    Solution sol;
    ListNode* ans = sol.reverseKGroup(list1, 2);
    printList(ans);

}
