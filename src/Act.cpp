#include "Act.h"
#include <iostream>
using namespace std;


Act::Act()
{
}
Act::Act(string newYear,string newAward, string newWinner,string newName, string newFilm)
{
    Year=newYear;
    Award=newAward;
    Winner=newWinner;
    Name = newName;
    Film=newFilm;
}
string Act::getYear() {
    return Year;
}
string Act::getAward() {
    return Award;
}
string Act::getWinner() {
    return Winner;
}
string Act::getFilm() {
    return Film;
}
string Act::getName() {
    return Name;
}
void Act::setYear(string newYear) {
    Year=newYear;
}
void Act::setAward(string newAward) {
    Award=newAward;
}
void Act::setWinner(string newWinner) {
    Winner=newWinner;
}
void Act::setName(string newName) {
    Name=newName;
}
void Act::setFilm(string newFilm) {
    Film=newFilm;
}

