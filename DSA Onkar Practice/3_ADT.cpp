#include <iostream>
using namespace std;

const int MAX = 50;
template <class T>

class SET
{
    T data[MAX];
    int n;

public:
    SET()
    {
        n = -1; // made SET empty at first
    }

    int size();
    bool insert(T);
    bool remove(T);
    void print();
    void input(int num);
    SET intersection(SET, SET);
};

template <class T>
bool SET<T>::insert(T element)
{
    if (n >= MAX - 1)
    {
        cout << "\nOverflow. SET is Full!";
        return false;
    }
    else
    {
        data[++n] = element;
        return true;
    }
}

template <class T>
void SET<T>::input(int num)
{
    T element;
    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter element : " << i + 1 << "\n";
        cin >> element;
        insert(element);
    }
}

template <class T>
void SET<T>::print()
{
    for (int i = 0; i <= n; i++)
    {
        cout << " " << data[i];
    }
}

template <class T>
SET<T> SET<T>::intersection(SET<T> s1, SET<T> s2)
{
    SET<T> s3;
    for (int i = 0; i <= s1.n; i++)
    {
        for (int j = 0; j <= s2.n; j++)
        {
            if (s1.data[i] == s2.data[j])
            {
                s3.insert(s1.data[i]);
                break;
            }
        }
    }
    return s3;
}

template <class T>
bool SET<T>::remove(T element)
{
    if (n == -1)
    {
        cout << "Underflow. Cannot perform delete operation on empty SET.";
        return false;
    }
    else
    {
        for (int i = 0; i <= n; i++)
        {
            if (data[i] == element)
            {
                for (int j = i; j < n; j++)
                {
                    data[j] = data[j + 1];
                }
                return true;
            }
        }
        return false;
    }
}

template <class T>
int SET<T>::size()
{
    return n + 1;
}

int main()
{
    SET<int> s1, s2, s3;
    int choice;
    int element;
    cout << "\nEnter number of elements in SET1 : "
         << "\n";
    cin >> element;
    s1.input(element);

    cout << "\nEnter number of elements in SET2 : "
         << "\n";
    cin >> element;
    s2.input(element);

    do
    {
        cout << "\n * ****SET OPERATIONS * ****"
             << "\n1.Insert "
             << "\n2.Remove "
             << "\n3.Size of Set "
             << "\n4.Intersection "
             << "\nEnter Your Choice : "
             << "\n";
        cin >> choice;
        switch (choice)

        {
        case 1:
            cout << "\nEnter Element : "
                 << "\n";
            cin >> element;
            if (s1.insert(element))

            {
                cout << element << " inserted"
                     << "\n";
            }
            else

            {
                cout << "Insertion Failed"
                     << "\n";
            }
            break;
        case 2:
            cout << "\nEnter Element : "
                 << "\n";
            cin >> element;
            if (s1.remove(element))

            {
                cout << element << " deleted"
                     << "\n";
            }
            else

            {
                cout << "Deletion Failed"
                     << "\n";
            }
            break;

        case 3:
            cout << "\nSize = " << s1.size();
            break;
        case 4:
            s3 = s1.intersection(s1, s2);
            cout << "\nSET 1's elements : ";
            s1.print();
            cout << "\nSET 2's elements : ";
            s2.print();
            cout << "\nIntersection : : ";
            s3.print();
            break;
        }
    } while (choice != 0);
    return 0;
}