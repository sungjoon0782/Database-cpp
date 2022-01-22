#ifndef SHEIKHMOVIEDATABASE_TREEACT_H
#define SHEIKHMOVIEDATABASE_TREEACT_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Act.h"
using namespace std;

struct tree_node
{
    tree_node* left;
    tree_node* right;
    //treeType data;
    Act data;
};

class TreeAct {
private:
    tree_node* root;
    int size;

public:
    TreeAct()
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

    tree_node* getRoot();
    void insert(Act p);
    void remove(string);
    bool search(string key);
    void NamePartialSearch(tree_node* R, string partialStr, int &counter);
    void FilmPartialSearch(tree_node* R, string partialStr, int &counter);
    void AwardPartialSearch(tree_node* R, string partialStr, int &counter);

    void NameCompleteSearch(tree_node* R, string Str, int &counter);
    void FilmCompleteSearch(tree_node* R, string Str, int &counter);
    void YearCompleteSearch(tree_node* R, string Str, int &counter);
    void WinnerCompleteSearch(tree_node* R, string Str, int &counter);

    void makeVec(tree_node* R, vector<Act> &sort);

    void NameSort(tree_node *R, vector<Act> &sort);
    void FilmSort(tree_node *R, vector<Act> &sort);
    void YearSort(tree_node* R, vector<Act> &sotr);

    void changeAward(string key, string newAward);
    void changeYear(string key, string newYear);
    void changeWinner(string key, string newWinner);
    void changeFilm(string key, string newFilm);

    void ActOut(tree_node* R, ofstream &out);

    void YearMod(tree_node* R, string Str1, string Str2,  int &counter);
    void AwardMod(tree_node* R, string Str1, string Str2,  int &counter);
    void WinnerMod(tree_node* R, string Str1, string Str2,  int &counter);
    void FilmMod(tree_node* R, string Str1, string Str2,  int &counter);


};

#endif

