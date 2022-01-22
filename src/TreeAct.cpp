#include <fstream>
#include "TreeAct.h"
using namespace std;
// this will insert new nodes into the tree when the user asks to insert new
// data
void TreeAct::insert(Act p)
{// blank tree
    tree_node* t = new tree_node;
    tree_node* parent;// Root node
    t->data = p;// The data inside 
    t->left = NULL;// the sub branching 
    t->right = NULL;
    parent = NULL;
    // is this a new tree?
    if(isEmpty())
    {
        root = t;
        size++;
    }
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t->data.getName() > curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
        if(t->data.getName() < parent->data.getName()) {
            parent->left = t;
            size++;
        }
        else {
            parent->right = t;
            size++;
        }
    }
}
// May be used for the search and modify class , will look at all the nodes

bool TreeAct::search(string key)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return found;
    }

    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL && !found)
    {
        if(curr->data.getName() == key)
        {
            found = true;
            return found;
            break;
        }
        else
        {
            parent = curr;
            if(key>curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
}
// Will allow the user to change 
void TreeAct::changeAward(string p, string newAward)  {
    bool found = false;// Assume it is false 
    if(isEmpty())// If the search cannot find the name with the specific data
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;// the current pointer 
    tree_node* parent;// the parent pointer 
    curr = root;// The current will be the root 
    while(curr != NULL)// While it has not reached the end 
    {
        if(curr->data.getName() == p)// Find the node with the input data
        {
            found = true;// if it is found then found is true 
            break;
        }
        else
        {
            parent = curr;// Else the parent is the current root 
            if(p>curr->data.getName()) curr = curr->right;// Parent will find the 
// data within 
            else curr = curr->left;// traverse 
        }
    }
    if(!found)
    {
        cout<<" Name not found. "<<endl;
        return;
    }
   
    curr->data.setAward(newAward);// change the data to the input data 
    cout<< "Award changed successfully. " << endl;
}
void TreeAct::changeYear(string p, string newYear)   {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
        if(curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(p>curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
    if(!found)
    {
        cout<<" Name not found. "<<endl;
        return;
    }
  
    curr->data.setYear(newYear);
    cout<< "Year changed successfully. " << endl;
}
void TreeAct::changeWinner(string p, string newWinner)  {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
        if(curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(p>curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
    if(!found)
    {
        cout<<" Name not found. "<<endl;
        return;
    }
   
    curr->data.setWinner(newWinner);
    cout<< "Winner changed successfully. " << endl;
}
void TreeAct::changeFilm(string p, string newFilm)  {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
        if(curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(p>curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
    if(!found)
    {
        cout<<" Name not found. "<<endl;
        return;
    }
    
    curr->data.setFilm(newFilm);
    cout<< "Film changed successfully. " << endl;
}
// To partially search for  a name 
void TreeAct::NamePartialSearch(tree_node* R, string partialStr, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)// if the R is null then it has reached the end 
    {return;}
    tree_node* curr;// curr pointer
    bool found = false;// if it has not been found 
    curr = R;// The current is the R pointer
    while(curr != NULL && !found) {// WHile it has not reached the end and not found 
        if (curr->data.getName().find(partialStr) != -1) {// Find the name, and partial string 
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;// The counter will increment 
        }
        else{break;}
    }
    NamePartialSearch(curr->left, partialStr, counter);// The current is set to the left node 
    NamePartialSearch(curr->right, partialStr, counter);// set to the right


    return;
}

void TreeAct::FilmPartialSearch(tree_node *R, string partialStr, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getFilm().find(partialStr) != -1) {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    FilmPartialSearch(curr->left, partialStr, counter);
    FilmPartialSearch(curr->right, partialStr, counter);

    return;
}

void TreeAct::AwardPartialSearch(tree_node *R, string partialStr, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getAward().find(partialStr) != -1) {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    AwardPartialSearch(curr->left, partialStr, counter);
    AwardPartialSearch(curr->right, partialStr, counter);

    return;
}

void TreeAct::NameCompleteSearch(tree_node* R, string Str, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getName() == Str) {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    NameCompleteSearch(curr->left, Str, counter);
    NameCompleteSearch(curr->right, Str, counter);

    return;
}

void TreeAct::FilmCompleteSearch(tree_node* R, string Str, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getFilm() == Str) {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    FilmCompleteSearch(curr->left, Str, counter);
    FilmCompleteSearch(curr->right, Str, counter);

    return;
}



// Same as the partial but it will look more exactly rather than just a part of the data 
void TreeAct::YearCompleteSearch(tree_node *R, string Str, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getYear() == Str) {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;
        }
        else{break;}
    }

    YearCompleteSearch(curr->left, Str, counter);
    YearCompleteSearch(curr->right, Str, counter);

    return;
}

void TreeAct::WinnerCompleteSearch(tree_node *R, string Str, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getWinner() == Str) {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    WinnerCompleteSearch(curr->left, Str, counter);
    WinnerCompleteSearch(curr->right, Str, counter);

    return;
}
// Creating a vector to sort 
void TreeAct::makeVec(tree_node* R, vector<Act> &sort)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}

    makeVec(R->left, sort);
    sort.push_back(R->data);
    makeVec(R->right, sort);
}

// WIll create a vector of nodes 
void TreeAct::NameSort(tree_node *R, vector<Act> &sort)
{
    makeVec(R, sort);// The vector will sort 

    cout << "Sorted data: " << endl;

    int size = sort.size();

    for(int i = 0; i < size; i++)
    {
        cout << sort[i].getYear() << "    " << sort[i].getAward() << "    "
             << sort[i].getWinner() << "    " << sort[i].getName() << "    "
             << sort[i].getFilm() << "    " << endl;
    }
}

void TreeAct::FilmSort(tree_node *R, vector<Act> &sort)
{
    makeVec(R, sort);

    Act temp;

    int size = sort.size();

    for(int i = 0; i < size; i++)
    {
        for(int j = size - 1; j > i; j--)
        {
            if(sort[j].getFilm() < sort[j-1].getFilm())
            {
                temp = sort[j];
                sort[j] = sort[j-1];
                sort[j-1] = temp;
            }
        }
    }

    cout << "Sorted data: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << sort[i].getYear() << "    " << sort[i].getAward() << "    "
             << sort[i].getWinner() << "    " << sort[i].getName() << "    "
             << sort[i].getFilm() << "    " << endl;
    }
}

void TreeAct::YearSort(tree_node *R, vector<Act> &sort)
{
    makeVec(R, sort);

    Act temp;

    int size = sort.size();

    for(int i = 0; i < size; i++)
    {
        for(int j = size-1; j > i; j--)
        {
            if(stoi(sort[j].getYear()) < stoi(sort[j-1].getYear()))
            {
                temp = sort[j];
                sort[j] = sort[j-1];
                sort[j-1] = temp;
            }

        }
    }

    cout << "Sorted data: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << sort[i].getYear() << "    " << sort[i].getAward() << "    "
             << sort[i].getWinner() << "    " << sort[i].getName() << "    "
             << sort[i].getFilm() << "    " << endl;
    }
}

// Will retrieve the root for the other functions to work. 
tree_node* TreeAct::getRoot()
{
    return root;
}
// WIll write out the root 
void TreeAct::ActOut(tree_node* R, ofstream &out)
{
    if(R == NULL)
    {return;}
    tree_node* curr = R;
// since it csv you will use commmas
    out << curr->data.getYear() << ',' << curr->data.getAward() << ',' << curr->data.getWinner()
        << ',' << curr->data.getName() << ',' << curr->data.getFilm() << endl;
// It will print out the nodes 
    ActOut(curr->left, out);
    ActOut(curr->right, out);
}
// This is another modify function
void TreeAct::YearMod(tree_node* R, string Str1, string Str2, int &counter)
{// Will check to see if it is empty 
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
// If the pointer is already at the end then it will just end 
    if(R == NULL)
    {return;}
    tree_node* curr;// Will create a current pointer
    bool found = false;// Will check to see if it is found
    curr = R;// Wil have the current equal the entered root
    while(curr != NULL && !found) {
        if (curr->data.getName() == Str1 && curr->data.getFilm() == Str2)
        {// If the entered data is equal the first string and second string is equal 
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;

            string year;
            cout << " Enter the new year: ";
            getline(cin, year);// will insert the new year 
            curr->data.setYear(year);
        }
        else{break;}
    }
    YearMod(curr->left, Str1, Str2, counter);// the left and right will equal the root 
    YearMod(curr->right, Str1, Str2, counter);

    return;
}



void TreeAct::FilmMod(tree_node* R, string Str1, string Str2, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getName() == Str1 && curr->data.getFilm() == Str2)
        {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;

            string film;
            cout << " Enter the new film: ";
            getline(cin, film);
            curr->data.setFilm(film);
        }
        else{break;}
    }
    YearMod(curr->left, Str1, Str2, counter);
    YearMod(curr->right, Str1, Str2, counter);

    return;
}



void TreeAct::AwardMod(tree_node* R, string Str1, string Str2, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getName() == Str1 && curr->data.getFilm() == Str2)
        {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;

            string award;
            cout << " Enter the new award: ";
            getline(cin, award);
            curr->data.setAward(award);
        }
        else{break;}
    }
    YearMod(curr->left, Str1, Str2, counter);
    YearMod(curr->right, Str1, Str2, counter);

    return;
}




void TreeAct::WinnerMod(tree_node* R, string Str1, string Str2, int &counter)
{
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    if(R == NULL)
    {return;}
    tree_node* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getName() == Str1 && curr->data.getFilm() == Str2)
        {
            cout << curr->data.getYear() << "    " << curr->data.getAward() <<
                 "    " << curr->data.getWinner() << "    " << curr->data.getName() << "    "
                 << curr->data.getFilm() << "    " << endl;

            found = true;
            counter++;

            string winner;
            cout << " Enter the new winner: ";
            getline(cin, winner);
            curr->data.setWinner(winner);
        }
        else{break;}
    }
    YearMod(curr->left, Str1, Str2, counter);
    YearMod(curr->right, Str1, Str2, counter);

    return;
}
