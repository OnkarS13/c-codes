// struct node
// class book public
// getnewNode
// addTitle
// addChapter
// addSection
// add subsection
// display
// main

#include <iostream>
using namespace std;

struct node
{
    string name;
    struct node *B[5]; // pointer array
};

class Book
{
    int c, s, sub; // private members

public:
    struct node *temp = new node;

    void getNewNode()
    {
        for (int i = 0; i < 5; i++)
        {
            temp->B[i] = new node;
            temp->B[i]->name = "empty"; // at starting it'll be empty

            for (int j = 0; j < 5; j++)
            {
                temp->B[i]->B[j] = new node;
                temp->B[i]->B[j]->name = "empty";

                for (int k = 0; k < 5; k++)
                {
                    temp->B[i]->B[j]->B[k] = new node;
                    temp->B[i]->B[j]->B[k]->name = "empty";
                }
            }
        }
    }

    void addTitle()
    {
        cout << "\nEnter the title of the book:-";
        cin >> temp->name;
        getNewNode();
    }

    void addChapter()
    {
        string cname;
        int cNum;

        cout << "Enter the number of chapters :-";
        cin >> cNum;
        c = cNum; // updating private values

        for (int i = 0; i < cNum; i++)
        {
            cout << endl
                 << "Chapter :- " << i + 1 << " = ";
            cin >> cname;

            temp->B[i]->name = cname;
        }
    }

    void addSection()
    {
        string sname;
        int chNum;
        int snum;

        cout << "\nEnter Number of Chapter where you want to add section :- ";
        cin >> chNum;

        cout << "\nEnter Number of Sections to add :";
        cin >> snum;

        s = snum; // updating private values

        for (int i = 0; i < snum; i++)
        {
            cout << endl
                 << "Section :- " << chNum << " . " << i + 1 << " = ";
            cin >> sname;

            temp->B[chNum - 1]->B[i]->name = sname;
        }
    }

    void addSubsection()
    {
        string subname; // subSection name
        int chnum;      // chapter number
        int sNum;       // section number
        int subNum;     // Subsection number

        cout << ": CHAPTER NUMBER WHERE YOU NEED TO ADD SUBSECTIONS = ";
        cin >> chnum;

        cout << "\nEnter Number of Section where you want to add Subsection :- ";
        cin >> sNum;

        cout << "\nEnter Number of Subsections to add :";
        cin >> subNum;

        sub = subNum; // updating private values

        for (int i = 0; i < subNum; i++)
        {
            cout << endl
                 << "Subsection :- " << chnum << " . " << sNum << " . " << i + 1 << " = ";
            cin >> subname;

            temp->B[chnum - 1]->B[sNum - 1]->B[i]->name = subname;
        }
    }
    void display()
    {
        cout << endl
             << "======= INDEX =======" << endl;
        cout << endl
             << ": TITLE : " << temp->name;
        cout << endl
             << "Chapters :-" << endl;

        for (int i = 0; i < c; i++)
        {
            if (temp->B[i]->name != "empty")
            {
                cout << endl
                     << ": " << i + 1 << ". " << temp->B[i]->name;
            }

            for (int j = i; j < s; j++)
            {
                if (temp->B[i]->B[j]->name != "empty")
                {
                    cout << endl
                         << " : " << i + 1 << "." << j + 1 << " " << temp->B[i]->B[j]->name;
                }

                for (int k = 0; k < sub; k++)
                {
                    if (temp->B[i]->B[j]->B[k]->name != "empty")
                    {
                       cout << endl
                             << " : " << i + 1 << "." << j + 1 << " " << temp->B[i]->B[j]->B[k]->name;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Book s;

    s.addTitle();

    s.addChapter();
    s.addSection();
    s.addSection();
    s.addSection();

    s.addSubsection();
    s.addSubsection();
    s.addSubsection();

    s.display();
    return 0;
}