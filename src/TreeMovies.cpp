// Exactly the same as TreeAct.cpp but it will do the functions on the 
// Pictures.csv 
#include "TreeMovies.h"
#include <typeinfo>

void TreeMovie::search(tree_node_movie* R, string Str, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getName() == Str) {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    NameCompleteSearch(curr->left, Str, counter);
    NameCompleteSearch(curr->right, Str, counter);

    return;
}

void TreeMovie::insert(Movies m)
{
    tree_node_movie* t = new tree_node_movie;
    tree_node_movie* parent;
    t->data = m;
    t->left = NULL;
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
        tree_node_movie* curr;
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

void TreeMovie::changeName(string p, string newName)  {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setName(newName);
    cout<< "Name changed successfully. " << endl;
}
void TreeMovie::changeYear(string p, string newYear)   {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setYear(newYear);
    cout<< "Year changed successfully. " << endl;
}
void TreeMovie::changeNomination(string p, string newNomination)  {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setNomination(newNomination);
    cout<< "Nomination Rating changed successfully. " << endl;
}
void TreeMovie::changeRating(string p, string newRating)  {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setNomination(newRating);
    cout<< "Rating changed successfully. " << endl;
}
void TreeMovie::changeDuration(string p, string newDuration)  {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setDuration(newDuration);
    cout<< "Duration changed successfully. " << endl;
}
void TreeMovie::changeGenre1(string p, string newGenre1)  {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setGenre1(newGenre1);
    cout<< "Genre1 changed successfully. " << endl;
}

void TreeMovie::changeGenre2(string p, string newGenre2)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setGenre2(newGenre2);
    cout<< "Genre2 changed successfully. " << endl;
}


void TreeMovie::changeRelease(string p, string newRelease)  {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setRelease(newRelease);
    cout<< "Release changed successfully. " << endl;
}
void TreeMovie::changeMetacritic(string p, string newMetacritic)   {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setMetacritic(newMetacritic);
    cout<< "Metacritic changed successfully. " << endl;
}
void TreeMovie::changeSynopsis(string p, string newSynopsis)   {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node_movie* curr;
    tree_node_movie* parent;
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
    //change the phonenumber associated with the node
    curr->data.setSynopsis(newSynopsis);
    cout<< "synopsis changed successfully. " << endl;
}





void TreeMovie::NamePartialSearch(tree_node_movie* R, string partialStr, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getName().find(partialStr) != -1) {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;

            counter++;
        }
        else{break;}
    }
    NamePartialSearch(curr->left, partialStr, counter);
    NamePartialSearch(curr->right, partialStr, counter);

    return;
}

void TreeMovie::SynopsisPartialSearch(tree_node_movie* R, string partialStr, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getSynopsis().find(partialStr) != -1) {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;

            counter++;
        }
        else{break;}
    }
    SynopsisPartialSearch(curr->left, partialStr, counter);
    SynopsisPartialSearch(curr->right, partialStr, counter);

    return;
}

void TreeMovie::RatingPartialSearch(tree_node_movie* R, int int1, int int2, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    curr = R;
    double theRating = stod(curr->data.getRating());
    bool found = false;
    while(curr != NULL && !found) {
        if ((theRating >= double(int1) && theRating <= double(int2)) || (theRating <= double(int1) && theRating >= double(int2)))
        {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    RatingPartialSearch(curr->left, int1, int2, counter);
    RatingPartialSearch(curr->right, int1, int2, counter);

    return;
}

void TreeMovie::NominationPartialSearch(tree_node_movie* R, int int1, int int2, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    curr = R;
    int theRating = stoi(curr->data.getNomination());
    bool found = false;
    while(curr != NULL && !found) {
        if ((theRating >= int1 && theRating <= int2) || (theRating <= int1 && theRating >= int2))
        {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    NominationPartialSearch(curr->left, int1, int2, counter);
    NominationPartialSearch(curr->right, int1, int2, counter);

    return;
}

void TreeMovie::DurationPartialSearch(tree_node_movie* R, int int1, int int2, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    curr = R;
    int theRating = stoi(curr->data.getDuration());
    bool found = false;
    while(curr != NULL && !found) {
        if ((theRating >= int1 && theRating <= int2) || (theRating <= int1 && theRating >= int2))
        {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    DurationPartialSearch(curr->left, int1, int2, counter);
    DurationPartialSearch(curr->right, int1, int2, counter);

    return;
}

void TreeMovie::MetacriticPartialSearch(tree_node_movie* R, int int1, int int2, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    curr = R;
    int theRating = stoi(curr->data.getMetacritic());
    bool found = false;
    while(curr != NULL && !found) {
        if ((theRating >= int1 && theRating <= int2) || (theRating <= int1 && theRating >= int2))
        {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    MetacriticPartialSearch(curr->left, int1, int2, counter);
    MetacriticPartialSearch(curr->right, int1, int2, counter);

    return;
}

void TreeMovie::NameCompleteSearch(tree_node_movie* R, string Str, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getName() == Str) {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    NameCompleteSearch(curr->left, Str, counter);
    NameCompleteSearch(curr->right, Str, counter);

    return;
}

void TreeMovie::YearCompleteSearch(tree_node_movie* R, string Str, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getYear() == Str) {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    YearCompleteSearch(curr->left, Str, counter);
    YearCompleteSearch(curr->right, Str, counter);

    return;
}

void TreeMovie::GenreCompleteSearch(tree_node_movie* R, string Str, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found)
    {
        if ((curr->data.getGenre1() == Str) || curr->data.getGenre2() == Str) {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    GenreCompleteSearch(curr->left, Str, counter);
    GenreCompleteSearch(curr->right, Str, counter);

    return;
}

void TreeMovie::ReleaseCompleteSearch(tree_node_movie* R, string Str, int &counter)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr;
    bool found = false;
    curr = R;
    while(curr != NULL && !found) {
        if (curr->data.getRelease() == Str) {
            cout << curr->data.getName() << "    " << curr->data.getYear() << "    "
                 << curr->data.getNomination() << "    " << curr->data.getRating() << "    "
                 << curr->data.getDuration() << "    " << curr->data.getGenre1() << "    "
                 << curr->data.getGenre2() << "    " << curr->data.getRelease() << "    "
                 << curr->data.getMetacritic() << "    " << curr->data.getSynopsis() << endl;

            found = true;
            counter++;
        }
        else{break;}
    }
    ReleaseCompleteSearch(curr->left, Str, counter);
    ReleaseCompleteSearch(curr->right, Str, counter);

    return;
}

void TreeMovie::makeVec(tree_node_movie* R, vector<Movies> &sort)
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



void TreeMovie::NameSort(tree_node_movie *R, vector<Movies> &sort)
{
    makeVec(R, sort);

    int size = sort.size();

    cout << "Sorted data: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << sort[i].getName() << "    " << sort[i].getYear() << "    "
             << sort[i].getNomination() << "    " << sort[i].getRating() << "    "
             << sort[i].getDuration() << "    " << sort[i].getGenre1() << "    "
             << sort[i].getGenre2() << "    " << sort[i].getRelease() << "    "
             << sort[i].getMetacritic() << "    " << sort[i].getSynopsis() << endl;

    }
}

void TreeMovie::YearSort(tree_node_movie* R, vector<Movies> &sort)
{
    makeVec(R, sort);

    Movies temp;

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
        cout << sort[i].getName() << "    " << sort[i].getYear() << "    "
             << sort[i].getNomination() << "    " << sort[i].getRating() << "    "
             << sort[i].getDuration() << "    " << sort[i].getGenre1() << "    "
             << sort[i].getGenre2() << "    " << sort[i].getRelease() << "    "
             << sort[i].getMetacritic() << "    " << sort[i].getSynopsis() << endl;

    }

}

void TreeMovie::NominationSort(tree_node_movie* R, vector<Movies> &sort)
{
    makeVec(R, sort);

    Movies temp;

    int size = sort.size();

    for(int i = 0; i < size; i++)
    {
        for(int j = size-1; j > i; j--)
        {

            if((sort[j].getNomination() == "") && (sort[j - 1].getNomination() == ""))
            {}

            else if(sort[j].getNomination() == "")
            {}

            else if(sort[j - 1].getNomination() == "")
            {
                temp = sort[j];
                sort[j] = sort[j - 1];
                sort[j - 1] = temp;
            }

            else
            {
                if (stoi(sort[j].getNomination()) < stoi(sort[j - 1].getNomination())) {
                      temp = sort[j];
                    sort[j] = sort[j - 1];
                    sort[j - 1] = temp;
                }
            }
        }
    }

    cout << "Sorted data: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << sort[i].getName() << "    " << sort[i].getYear() << "    "
             << sort[i].getNomination() << "    " << sort[i].getRating() << "    "
             << sort[i].getDuration() << "    " << sort[i].getGenre1() << "    "
             << sort[i].getGenre2() << "    " << sort[i].getRelease() << "    "
             << sort[i].getMetacritic() << "    " << sort[i].getSynopsis() << endl;

    }
}

void TreeMovie::RatingSort(tree_node_movie* R, vector<Movies> &sort)
{
    makeVec(R, sort);

    Movies temp;

    int size = sort.size();

    for(int i = 0; i < size; i++)
    {
        for(int j = size-1; j > i; j--)
        {
            if(stod(sort[j].getRating()) < stod(sort[j-1].getRating()))
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
        cout << sort[i].getName() << "    " << sort[i].getYear() << "    "
             << sort[i].getNomination() << "    " << sort[i].getRating() << "    "
             << sort[i].getDuration() << "    " << sort[i].getGenre1() << "    "
             << sort[i].getGenre2() << "    " << sort[i].getRelease() << "    "
             << sort[i].getMetacritic() << "    " << sort[i].getSynopsis() << endl;

    }
}


void TreeMovie::DurationSort(tree_node_movie* R, vector<Movies> &sort)
{
    makeVec(R, sort);

    Movies temp;

    int size = sort.size();

    for(int i = 0; i < size; i++)
    {
        for(int j = size-1; j > i; j--)
        {
            if(stoi(sort[j].getDuration()) < stoi(sort[j-1].getDuration()))
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
        cout << sort[i].getName() << "    " << sort[i].getYear() << "    "
             << sort[i].getNomination() << "    " << sort[i].getRating() << "    "
             << sort[i].getDuration() << "    " << sort[i].getGenre1() << "    "
             << sort[i].getGenre2() << "    " << sort[i].getRelease() << "    "
             << sort[i].getMetacritic() << "    " << sort[i].getSynopsis() << endl;

    }
}

void TreeMovie::MetacriticSort(tree_node_movie* R, vector<Movies> &sort)
{
    makeVec(R, sort);

    Movies temp;

    int size = sort.size();

    for(int i = 0; i < size; i++)
    {
        for(int j = size-1; j > i; j--)
        {
            if((sort[j].getMetacritic() == "") && (sort[j - 1].getMetacritic() == ""))
            {}

            else if(sort[j].getMetacritic() == "")
            {}

            else if(sort[j - 1].getMetacritic() == "")
            {
                temp = sort[j];
                sort[j] = sort[j - 1];
                sort[j - 1] = temp;
            }

            else
            {
                if (stoi(sort[j].getMetacritic()) < stoi(sort[j - 1].getMetacritic())) {
                    temp = sort[j];
                    sort[j] = sort[j - 1];
                    sort[j - 1] = temp;
                }
            }
        }
    }

    cout << "Sorted data: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << sort[i].getName() << "    " << sort[i].getYear() << "    "
             << sort[i].getNomination() << "    " << sort[i].getRating() << "    "
             << sort[i].getDuration() << "    " << sort[i].getGenre1() << "    "
             << sort[i].getGenre2() << "    " << sort[i].getRelease() << "    "
             << sort[i].getMetacritic() << "    " << sort[i].getSynopsis() << endl;

    }
}


tree_node_movie* TreeMovie::getRoot()
{
    return root;
}

void TreeMovie::MovieOut(struct tree_node_movie * R, std::ofstream & out)
{
    if(R == NULL)
    {return;}
    tree_node_movie* curr = R;

    out << curr->data.getName() << ',' << curr->data.getYear() << ',' << curr->data.getNomination() << ','
        << curr->data.getRating() << ',' << curr->data.getDuration() << ',' << curr->data.getGenre1()
        << ',' << curr->data.getGenre2() << ',' << curr->data.getRelease() << ',' << curr->data.getMetacritic()
        << ',' << curr->data.getSynopsis() << endl;

    MovieOut(curr->left, out);
    MovieOut(curr->right, out);

}


