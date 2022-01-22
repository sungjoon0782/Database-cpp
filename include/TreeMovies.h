#ifndef SHEIKHMOVIEDATABASE_TREEMOVIE_H
#define SHEIKHMOVIEDATABASE_TREEMOVIE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include "Movies.h"
using namespace std;

struct tree_node_movie
{
    tree_node_movie* left;
    tree_node_movie* right;
    //treeType data;
    Movies data;
};

class TreeMovie {
private:
    int size;
    tree_node_movie* root;

public:
    TreeMovie()
    {
        size = 0;
        root = NULL;
    }
    bool isEmpty() const { return root==NULL; }
    /*void print_inorder();
    void inorder(tree_node*);
    void print_preorder();
    void preorder(tree_node*);
    void print_postorder();
    void postorder(tree_node*);*/

    void search(tree_node_movie* R, string Str, int &counter);
    void insert(Movies m);
    void remove(string str);

    void makeVec(tree_node_movie* R, vector<Movies> &sort);

    void NameSort(tree_node_movie* R, vector<Movies> &sort);
    void YearSort(tree_node_movie* R, vector<Movies> &sort);
    void NominationSort(tree_node_movie* R, vector<Movies> &sort);
    void RatingSort(tree_node_movie* R, vector<Movies> &sort);
    void DurationSort(tree_node_movie* R, vector<Movies> &sort);
    void MetacriticSort(tree_node_movie* R, vector<Movies> &sort);

    void NamePartialSearch(tree_node_movie* R, string partialStr, int &counter);
    void SynopsisPartialSearch(tree_node_movie* R, string partialStr, int &counter);
    void RatingPartialSearch(tree_node_movie* R, int int1, int int2, int &counter);
    void NominationPartialSearch(tree_node_movie* R, int int1, int int2, int &counter);
    void DurationPartialSearch(tree_node_movie* R, int int1, int int2, int &counter);
    void MetacriticPartialSearch(tree_node_movie* R, int int1, int int2, int &counter);

    void NameCompleteSearch(tree_node_movie* R, string Str, int &counter);
    void YearCompleteSearch(tree_node_movie* R, string Str, int &counter);
    void GenreCompleteSearch(tree_node_movie* R, string Str, int &counter);
    void ReleaseCompleteSearch(tree_node_movie* R, string Str, int &counter);

    void changeRelease(string key, string newRelease);
    void changeYear(string key, string newYear);
    void changeRating(string key, string newRating);
    void changeNomination(string key, string newNominationRating);
    void changeMetacritic(string key, string newMetacritic);
    void changeDuration(string key, string newDuration);
    void changeGenre2(string key, string newGenre2);
    void changeGenre1(string key, string newGenre1);
    void changeName(string key, string newName);
    void changeSynopsis(string key, string newSynopsis);
    tree_node_movie* getRoot();

    void MovieOut(tree_node_movie* R, ofstream &out);
};


#endif //SHEIKHMOVIEDATABASE_TREEMOVIE_H
