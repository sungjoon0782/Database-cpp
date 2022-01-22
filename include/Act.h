#ifndef SHEIKHMOVIEDATABASE_ACT_H
#define SHEIKHMOVIEDATABASE_ACT_H

#include <iostream>
#include <string>
using namespace std;

class Act {
private:
    string Name,Award,Film, Year,Winner;
public:
    Act();
    Act(string Year,string Award, string Winner,string Name, string Film);
    string getYear();
    string getAward();
    string getWinner();
    string getName();
    string getFilm();
    void setYear(string newYear);
    void setAward(string newAward);
    void setWinner(string newWinner);
    void setName(string newName);
    void setFilm(string newFilm);
};
#endif

