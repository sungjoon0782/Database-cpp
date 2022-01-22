#ifndef SHEIKHMOVIEDATABASE_MOVIES_H
#define SHEIKHMOVIEDATABASE_MOVIES_H

#include <iostream>
#include <string>
using namespace std;

class Movies { //pictures
private:
    string Name, Genre1, Genre2, Release, Synopsis, Year,Nomination, Duration, Metacritic, Rating;
public:
    Movies();
    Movies(string newName,string newYear, string newNomination, string newRating, string newDuration, string newGenre1, string newGenre2,
           string newRelease,string newMetacritic, string newSynopsis);
    string getName();
    string getYear();
    string getNomination();
    string getDuration();
    string getRating();
    string getGenre1();
    string getGenre2();
    string getRelease();
    string getMetacritic();
    string getSynopsis();

    void setName(string newName);
    void setYear(string newYear);
    void setNomination(string newNomination);
    void setDuration(string newDuration);
    void setGenre1(string newGenre1);
    void setGenre2(string newGenre2);
    void setRating(string newRating);
    void setRelease(string newRelease);
    void setMetacritic(string newMetacritic);
    void setSynopsis(string newSynopsis);
};


#endif

