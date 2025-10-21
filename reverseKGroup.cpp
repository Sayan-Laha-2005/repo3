class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;

        //check if k nodes exists
        while(cnt<k){
            if(temp==NULL){
                return head;
            }
            temp=temp->next;
            cnt++;
        }
        
        //recursively call for rest of the LL
        ListNode* prevNode = reverseKGroup(temp,k);

        //reverse current grp
        temp=head;cnt=0;

        while(cnt<k){
            ListNode* next=temp->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=next;

            cnt++;
        }
        return prevNode;
    }
};
