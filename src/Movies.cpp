#include "Movies.h"
#include <iostream>
using namespace std;

Movies::Movies()
{
    Name = "";
    Year = "";
    Nomination = "";
    Rating = "";
    Duration="";
    Genre1="";
    Genre2="";
    Release="";
    Metacritic="";
    Synopsis= "";
}


Movies::Movies(string newName,string newYear, string newNomination, string newRating, string newDuration, string newGenre1, string newGenre2, string newRelease,string newMetacritic, string newSynopsis){
    Name = newName;
    Year=newYear;
    Nomination = newNomination;
    Rating = newRating;
    Duration=newDuration;
    Genre1=newGenre1;
    Genre2=newGenre2;
    Release=newRelease;
    Metacritic=newMetacritic;
    Synopsis= newSynopsis;
}
string Movies::getName() {
    return Name;
}
string Movies::getYear()  {
    return Year;
}
string Movies::getNomination() {
    return Nomination;
}
string Movies::getDuration() {
    return Duration;
}
string Movies::getRating() {
    return Rating;
}
string Movies::getGenre1() {
    return Genre1;
}
string Movies::getGenre2() {
    return Genre2;
}
string Movies::getRelease() {
    return Release;
}
string Movies::getMetacritic() {
    return Metacritic;
}
string Movies::getSynopsis() {
    return Synopsis;
}

void Movies:: setName(string newName) {
    Name = newName;
}
void Movies::setYear(string newYear) {
    Year = newYear;
}
void Movies::setDuration(string newDuration) {
    Duration = newDuration;
}
void Movies::setRating(string newRating) {
    Rating = newRating;
}
void Movies::setGenre1(string newGenre1) {
    Genre1 = newGenre1;
}
void Movies::setGenre2(string newGenre2) {
    Genre2 = newGenre2;
}
void Movies::setMetacritic(string newMetacritic) {
    Metacritic=newMetacritic;
}
void Movies::setNomination(string newNomination) {
    Nomination=newNomination;
}
void Movies::setRelease(string newRelease) {
    Release=newRelease;
}
void Movies::setSynopsis(string newSynopsis) {
    Synopsis=newSynopsis;
}



