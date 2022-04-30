#include<iostream>
#include<vector>

using namespace std;

class mynode{
    public:
    int data;
    mynode* next;
};

class myLinkedList{
    mynode* head;

    public:
    myLinkedList() {
        head = NULL;
    }

    //Adding the elements
    void myAddList(int element) {
        mynode* newnode = new mynode();

        newnode -> data = element;
        newnode -> next = NULL;

        if(head == NULL) {
            head = newnode;
        } else {
            mynode* pointer = head;

            while(pointer -> next != NULL) {
                pointer = pointer -> next;
            }
            pointer -> next = newnode;
        }
    }

    //Insertion Sort
    void insertionSort() {
        mynode* i = head -> next;

        while (i != NULL){
            mynode* key = i;
            mynode* j = head;

            while (j != i){
                if (key -> data < j -> data){
                    int pointer = key -> data;
                    key -> data = j -> data;
                    j -> data = pointer;
                }
                j = j -> next;
            }
            i = i -> next;
        }
    }

    void myprintList() {
        mynode* pointer = head;

        while (pointer != NULL) {
            cout << pointer -> data << " ";
            pointer = pointer -> next;
        }
    }

    bool binarySearch(int target){
        vector<int> myvector;
        mynode* head;
        while(head != NULL){
            myvector.push_back(head -> data);
            head = head -> next;
        }
        return search(myvector, 0, myvector.size(), target);
    }

    bool search(vector<int> vec, int left, int right, int target){
        if (right >= left){
            int mid = left+(right-left)/2;
            if (vec[mid] == target){
                cout << target << " is found." << endl;
                return true;
            }
            if (target < vec[mid]){
                return search(vec, left, mid-1, target);
            }
            if (target > vec[mid]){
                return search(vec, mid+1, right, target);
            }
        }
        cout << target << " is not found." << endl;
        return 0;
    }
};

int main(){
    myLinkedList myll;
    myll.myAddList(22);
    myll.myAddList(76);
    myll.myAddList(32);
    myll.myAddList(46);
    myll.myAddList(73);
    myll.myAddList(44);

    cout << "Linked List before sorting" << endl;
    myll.myprintList();
    cout << endl << "Linked List after sorting" << endl;
    myll.insertionSort();
    myll.myprintList();
    cout << endl;

    int val = 76;
    myll.binarySearch(val);
}