#include <iostream>
using namespace std;

// struct node -->
// HashTable pointer array
// Class hashing
// constructor ->Null
// hashFunction
// createNode
// display
// search element
// delete element
// insert element
// main

struct node
{
    int data;
    struct node *next;
}

    * HashTable[10]; // pounter array created

class Hashing
{
public:
    Hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = NULL;
        }
    }

    int hashfunction(int data)
    {
        return (data % 10);
    }

    struct node *createNode(int x)
    {
        struct node *ptr = new node; // created a pointer
        ptr->next = NULL;            // node's next is always NULL at first
        ptr->data = x;
        return ptr;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            struct node *ptr = new node;
            ptr = HashTable[i];
            cout << "a[" << i << "] : ";

            while (ptr != NULL)
            {
                cout << " ->" << ptr->data;
                ptr = ptr->next;
            }
            cout << "\n";
        }
    }

    int searchElemrnt(int data)
    {
        bool flag = false;
        int hash_val = hashfunction(data);
        struct node *entry = HashTable[hash_val];
        cout << "\nThe Element found at :";

        while (entry != NULL) // For row traversal
        {
            if (entry->data == data)
            {
                cout << hash_val << " : " << entry->data;
                flag = true;
            }
            entry = entry->next;
        }

        if (!flag)
        {
            return -1;
        }
    }

    void deleteElement(int data)
    {
        int hash_val = hashfunction(data);
        struct node *entry = HashTable[hash_val];

        if (entry == NULL)
        {
            cout << "Element can not be deleted! Not found!";
            return;
        }
        if (entry->data == data) // Whern element is found first element to be deleted
        {
            HashTable[hash_val] = entry->next;
            return;
        }
        while ((entry->next)->data != data) // Traversing for element
        {
            entry = entry->next;
        }
        // When element found;
        entry->next = (entry->next)->next;
    }

    void insertElement(int data)
    {
        int hash_val = hashfunction(data);

        struct node *head = new node;
        struct node *ptr = new node;

        head = createNode(data); // will create node of that data
        ptr = HashTable[hash_val];

        if (ptr == NULL)
        {
            HashTable[hash_val] = head;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            // when ptr->next become NULL
            ptr->next = head;
        }
    }
};

int main()
{
    int ch;
    int insertData, search, del;
    Hashing h;

    do
    {
        cout << "\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter phone no. to be inserted : ";
            cin >> insertData;
            h.insertElement(insertData);
            break;

        case 2:
            h.display();
            break;

        case 3:
            cout << "\nEnter the no to be searched : ";
            cin >> search;
            if (h.searchElemrnt(search) == -1)
            {
                cout << "Element not found!";
                continue;
            }
            break;

        case 4:
            cout << "\nEnter the phno. to be deleted : ";
            cin >> del;
            h.deleteElement(del);
            cout << "Phno. Deleted" << endl;
            break;
        }

    } while (ch != 5);

    return 0;
}