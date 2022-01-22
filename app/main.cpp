#include <iostream>
#include <fstream>
#include <vector>
#include "Act.h"
#include "Movies.h"
#include "TreeAct.h"
#include "TreeMovies.h"


using namespace std;


/*void fillAct(TreeAct &a, ifstream &input)
{
    string tempYear, tempAward, tempWinner, tempName, tempFilm;


    tempYear = "1928";
    tempAward = "Actress in a Leading";
    tempWinner = "1";
    tempName = "Emil Jannings";
    tempFilm = "The Last Command";

    Act tempAct1(tempYear, tempAward, tempWinner, tempName, tempFilm);

    a.insert(tempAct1);

    tempYear = "1928";
    tempAward = "Actor in a Leading Role";
    tempWinner = "1";
    tempName = "Janet Gaynor";
    tempFilm = "7th Heaven";

    Act tempAct2(tempYear, tempAward, tempWinner, tempName, tempFilm);

    a.insert(tempAct2);


    tempYear = "1928";
    tempAward = "Actress in a Leading";
    tempWinner = "0";
    tempName = "Richard Barthelmess";
    tempFilm = "The Noose";

    Act tempAct3(tempYear, tempAward, tempWinner, tempName, tempFilm);

    a.insert(tempAct3);



    tempYear = "1928";
    tempAward = "Actor in a Leading Role";
    tempWinner = "0";
    tempName = "Louise Dresser";
    tempFilm = "A Ship Comes In";

    Act tempAct4(tempYear, tempAward, tempWinner, tempName, tempFilm);

    a.insert(tempAct4);



    tempYear = "1928";
    tempAward = "Actress in a Leading";
    tempWinner = "0";
    tempName = "Gloria Swanson";
    tempFilm = "Sadie Thompson";

    Act tempAct5(tempYear, tempAward, tempWinner, tempName, tempFilm);

    a.insert(tempAct5);


}
*/
// Will fill the tree by reading the csv file for actors and actresses
void fillAct(TreeAct &a, ifstream &input)
{
    input.open("actor-actress.csv");

    string tempYear, tempAward, tempWinner, tempName, tempFilm;

    if(input.good())
    {
        getline(input, tempYear, ',');
        getline(input, tempAward, ',');
        getline(input, tempWinner, ',');
        getline(input, tempName, ',');
        getline(input, tempFilm);

        while (!input.eof())
        {
            getline(input, tempYear, ',');
            if(tempYear == ""){break;}
            getline(input, tempAward, ',');
            getline(input, tempWinner, ',');
            getline(input, tempName, ',');
            getline(input, tempFilm);


            Act tempAct(tempYear, tempAward, tempWinner, tempName, tempFilm);

            a.insert(tempAct);
        }
    }
    input.close();
}

// WIll read with pictures same as act 
void fillMovie(TreeMovie &b, ifstream &input)
{
    input.open("pictures.csv");

    string tempName, tempYear, tempNomination, tempRating, tempDuration, tempGenre1, tempGenre2, tempRelease, tempMetacritic, tempSynopsis;
    if(input.good())
    {
        getline(input, tempName, ',');
        getline(input, tempYear, ',');
        getline(input, tempNomination, ',');
        getline(input, tempRating, ',');
        getline(input, tempDuration, ',');
        getline(input, tempGenre1, ',');
        getline(input, tempGenre2, ',');
        getline(input, tempRelease, ',');
        getline(input, tempMetacritic, ',');
        getline(input, tempSynopsis);

        while (!input.eof()) {
            getline(input, tempName, ',');
            if(tempName == ""){break;}
            getline(input, tempYear, ',');
            getline(input, tempNomination, ',');
            getline(input, tempRating, ',');
            getline(input, tempDuration, ',');
            getline(input, tempGenre1, ',');
            getline(input, tempGenre2, ',');
            getline(input, tempRelease, ',');
            getline(input, tempMetacritic, ',');
            getline(input, tempSynopsis);

            Movies tempMovie(tempName, tempYear, tempNomination, tempRating, tempDuration, tempGenre1, tempGenre2,
                             tempRelease, tempMetacritic, tempSynopsis);

            b.insert(tempMovie);
        }
    }
    input.close();
}
// main menu will give the users the actions that they can do 
int mainMenu()
{
    int choice = 0;

    cout<<endl<<endl;
    cout<<" Movie DataBase Operations "<<endl;
    cout<<" ----------------------------- "<<endl;
    cout<<" 0. Movie/Actors or Actress Read in             "<<endl;
    cout<<" 1. Movie/Actors or Actress Insertion/Creation "<<endl;
    cout<<" 2. Movie/Actors or Actress Search and Modify "<<endl;
    cout<<" 3. Movie/Actors or Actress Sort "<<endl;
    cout<<" 4. Movie/Actors or Actress Complete Search "<<endl;
    cout<<" 5. Movie/Actors or Actress Partial Search "<<endl;
    cout<<" 6. Movie/Actors or Actress Write out "<<endl;
    cout<<" 7. Exit "<<endl;
    cout<<" Enter your choice : ";
    cin >> choice;

    return choice;
}
// If the user selects a number a sub menu will appear for all actions 
int choice0()
{
    int choice = 0;
    cout << " Movie DataBase Operations " << endl;
    cout << " ----------------------------- " << endl;
    cout << "1. Read actor-actress data" << endl;
    cout << "2. Read movie data" << endl;
    cout << "3. Go back to main menu" << endl;
    cout<<" Enter your sub-choice : ";
    cin >> choice;

    return choice;
}

void action0(TreeAct &a, TreeMovie &b)
{
    int choice = 0;
    choice = choice0();
    ifstream infile;
    switch(choice)

    {
        case 1:
            cout << "- Read actor-actress data -" << endl;

            fillAct(a, infile);// these functions read in the files, this fillAct will read in the actors
            cout << "Successfully read actor-actredd data from input file!" << endl;
            break;

        case 2:
            cout << "- Read movie data -" << endl;
            fillMovie(b, infile);// this function will read in the movies
            cout << "Successfully read movie data from input file!" << endl;
            break;

        case 3:
            break;

        default:
            cout << "Wrong option number." << endl;
            action0(a, b);
    }
}

int choice1()
{
    int choice = 0;
    cout << " Movie DataBase Operations " << endl;
    cout << " ----------------------------- " << endl;
    cout << "1. Insert an actor-actress data" << endl;
    cout << "2. Insert a movie data" << endl;
    cout << "3. Go back to main menu" << endl;
    cout << "Enter your sub-choice: ";
    cin >> choice;

    return choice;
}

void action1(TreeAct &a, TreeMovie &b)
{
    int choice = 0;
    choice = choice1();

    switch(choice)
    {
        case 1:
        {
            string name, film, award, winner, year;
// Will ask the user the necessary input to create a new node in either pictures, or in 
// movies 
            cout << "- Insert an actor-actress data -" << endl;
            cin.ignore();
            cout << " Enter year to be inserted: " << endl;
            getline(cin, year);
            cout << "Enter Award to be inserted: " << endl;
            getline(cin, award);
            cout << "Enter if they won,(1 for win,0 for loss)" << endl;
            getline(cin, winner);
            cout << " Enter Name to be inserted: " << endl;
            getline(cin, name);
            cout << " Enter Film to be inserted: " << endl;
            getline(cin, film);

            Act tempAct(year, award, winner, name, film);
            a.insert(tempAct);
        }
        break;


        case 2:
        {
            string name, genre1, genre2, release, synopsis, year, nomination, duration, metacritic, rating;

            cout << "- Insert a movie data -" << endl;
            cin.ignore();
            cout << "Enter name to be inserted: " << endl;
            getline(cin, name);
            cout << "Enter year to be inserted: " << endl;
            getline(cin, year);
            cout << "Enter nomination to be inserted: " << endl;
            getline(cin, nomination);
            cout << "Enter rating to be inserted: " << endl;
            getline(cin, rating);
            cout << "Enter genre1 to be inserted: " << endl;
            getline(cin, genre1);
            cout << "Enter genre2 to be inserted: " << endl;
            getline(cin, genre2);
            cout << "Enter release month to be inserted: " << endl;
            getline(cin, release);
            cout << "Enter metacritic to be inserted: " << endl;
            getline(cin, metacritic);
            cout << "Enter synopsis to be inserted: " << endl;
            getline(cin, synopsis);

            Movies tempMovie(name, year, nomination, rating, duration, genre1, genre2,
                             release, metacritic, synopsis);
            b.insert(tempMovie);
        }
        break;

        case 3:
            break;

        default:
            cout << "Wrong option number." << endl;
            action1(a, b);
    }
}

int choice2()
{
    int choice=0;
    cout << " Movie DataBase Operations " << endl;
    cout << " ----------------------------- " << endl;
    cout << "1. Search and Modify on actor-actress data" << endl;
    cout << "2. Search and Modify  on movie data" << endl;
    cout << "Enter your sub-choice: ";

    cin >> choice;

    return choice;
}

void action2(TreeAct &a, TreeMovie &b)
{
    int choice = 0;
    int subchoice = 0;
    tree_node* ActRoot = a.getRoot();
    tree_node_movie* MovieRoot = b.getRoot();
    string str1 = "";
    string str2 = "";
    int counter1 = 0;
    int counter2 = 0;

    choice = choice2();

    switch(choice)
    {
        case 1:
        {
            string year = "", award = "", winner = "", film = "";

            cout << " Movie DataBase Operations " << endl;
            cout << " ----------------------------- " << endl;
            cout << "1. Search and Mod Year " << endl;
            cout << "2. Search and Mod Award " << endl;
            cout << "3. Search and Mod Winner " << endl;
            cout << "4. Search and Mod Film " << endl;
            cout << "Enter your sub-choice: ";
            cin >> subchoice;

            switch(subchoice)
            {
                case 1:
// Will search a name of the person using complete search, 
                    cout << " Enter the Name of the person to search for: ";
                    cin.ignore();
                    getline(cin, str1);
                    a.NameCompleteSearch(ActRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else if(counter1 > 1)
                    {
// If there is more than one result it will ask for another string to change 
// does this for all search and modify 
                        cout << "There are more than 1 result. Please enter the name of film to make sure exactly one actor-actress is chosen: ";
                        getline(cin, str2);
                        a.YearMod(ActRoot, str1, str2, counter2);
                        if(counter2 == 0){cout << "Wrong Film Name! Data not found." << endl;}
                    }
                    else
                    {
                        cout << " Enter the new year: " << endl;
                        getline(cin, year);
                        a.changeYear(str1, year);
                    }
                    break;

                case 2:
                    cout << " Enter the Name of the person to search for: ";
                    cin.ignore();
                    getline(cin, str1);
                    a.NameCompleteSearch(ActRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else if(counter1 > 1)
                    {
                        cout << "There are more than 1 result. Please enter the name of film to make sure exactly one actor-actress is chosen: ";
                        getline(cin, str2);
                        a.AwardMod(ActRoot, str1, str2, counter2);
                        if(counter2 == 0){cout << "Wrong Film Name! Data not found." << endl;}
                    }
                    else
                    {
                        cout << " Enter the new award: " << endl;
                        getline(cin, award);
                        a.changeAward(str1, award);
                    }
                    break;

                case 3:
                    cout << " Enter the Name of the person to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    a.NameCompleteSearch(ActRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else if(counter1 > 1)
                    {
                        cout << "There are more than 1 result. Please enter the name of film to make sure exactly one actor-actress is chosen: ";
                        getline(cin, str2);
                        a.WinnerMod(ActRoot, str1, str2, counter2);
                        if(counter2 == 0){cout << "Wrong Film Name! Data not found." << endl;}
                    }
                    else
                    {
                        cout << " Enter the new winner: " << endl;
                        getline(cin, winner);
                        a.changeWinner(str1, winner);
                    }
                    break;

                case 4:
                    cout << " Enter the Name of the person to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    a.NameCompleteSearch(ActRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else if(counter1 > 1)
                    {
                        cout << "There are more than 1 result. Please enter the name of film to make sure exactly one actor-actress is chosen: ";
                        getline(cin, str2);
                        a.FilmMod(ActRoot, str1, str2, counter2);
                        if(counter2 == 0){cout << "Wrong Film Name! Data not found." << endl;}
                    }
                    else
                    {
                        cout << " Enter the new film: " << endl;
                        getline(cin, film);
                        a.changeFilm(str1, film);
                    }
                    break;

                default:
                    break;
            }
        }
        break;

        case 2:
        {
            string year = "", nomination = "", rating = "", genre1 = "", genre2 = "", duration = "", release = "", metacritic = "", synopsis = "";

            cout << " Movie DataBase Operations " << endl;
            cout << " ----------------------------- " << endl;
            cout << "1. Search and Mod Year " << endl;
            cout << "2. Search and Mod Nomination " << endl;
            cout << "3. Search and Mod Rating " << endl;
            cout << "4. Search and Mod Genre1" << endl;
            cout << "5. Search and Mod Genre2" << endl;
            cout << "6. Search and Mod Duration" << endl;
            cout << "7. Search and Mod Release" << endl;
            cout << "8. Search and Mod Metacritic" << endl;
            cout << "9. Search and Mod Synopsis" << endl;
            cout << "Enter your sub-choice: ";
            cin >> subchoice;

            switch(subchoice)
            {
                case 1:
                    cout << " Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << " Enter the new year: " << endl;
                        getline(cin, year);
                        b.changeYear(str1, year);
                    }
                    break;

                case 2:
                    cout << " Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << " Enter the new nomination: " << endl;
                        getline(cin, nomination);
                        b.changeNomination(str1, nomination);
                    }
                    break;

                case 3:
                    cout << " Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << " Enter the new rating: " << endl;
                        getline(cin, rating);
                        b.changeRating(str1, rating);
                    }
                    break;

                case 4:
                    cout << " Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << " Enter the new genre1: " << endl;
                        getline(cin, genre1);
                        b.changeGenre1(str1, genre1);
                    }
                    break;

                case 5:
                    cout << "Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << "Enter the new genre2: " << endl;
                        getline(cin, genre2);
                        b.changeGenre2(str1, genre2);
                    }
                    break;

                case 6:
                    cout << "Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << "Enter the new duration: " << endl;
                        getline(cin, duration);
                        b.changeDuration(str1, duration);
                    }
                    break;

                case 7:
                    cout << " Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << "Enter the new release: " << endl;
                        getline(cin, release);
                        b.changeRelease(str1, release);
                    }
                    break;

                case 8:
                    cout << "Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << " Enter the new metacritic: " << endl;
                        getline(cin, metacritic);
                        b.changeMetacritic(str1, metacritic);
                    }
                    break;

                case 9:
                    cout << "Enter the Name of the movie to search for: " << endl;
                    cin.ignore();
                    getline(cin, str1);
                    b.NameCompleteSearch(MovieRoot, str1, counter1);
                    if(counter1 == 0){cout << "Wrong Name! Data not found." << endl;}
                    else
                    {
                        cout << " Enter the new synopsis: " << endl;
                        getline(cin, synopsis);
                        b.changeSynopsis(str1, synopsis);
                    }
                    break;

                default:
                    break;
            }

            break;
        }



        default:
            cout << "Wrong option number." << endl;
            action2(a, b);
            break;
    }

}
// Will come as a sub menu when the user inputs 3 then will go to action 3
int choice3()
{
    int choice = 0;
    cout << " Movie DataBase Operations " << endl;
    cout << " ----------------------------- " << endl;
    cout << "1. Sort on actor-actress data" << endl;
    cout << "2. Sort on movie data" << endl;
    cout << "Enter your sub-choice: ";

    cin >> choice;

    return choice;
}
// Will sort the information with vector of nodes 
void action3(TreeAct &a, TreeMovie &b, vector<Act> &A, vector<Movies> &B)
{
    int choice = 0;
    int subchoice = 0;
    char option = ' ';
    tree_node* ActRoot = a.getRoot();
    tree_node_movie* MovieRoot = b.getRoot();
    choice = choice3();

    A.clear();
    B.clear();

    switch(choice)
    {
        case 1:
        {
            cout << " Movie DataBase Operations " << endl;
            cout << " ----------------------------- " << endl;
            cout << "1. Sort with actor-actress name" << endl;
            cout << "2. Sort with actor-actress film" << endl;
            cout << "3. Sort with actor-actress year" << endl;
            cout << "Enter your sub-choice: ";
            cin >> subchoice;

            switch (subchoice) {
                case 1:
// calls the sort function 
                    a.NameSort(ActRoot, A);
                    break;

                case 2:
                    a.FilmSort(ActRoot, A);
                    break;

                case 3:
                    a.YearSort(ActRoot, A);
                    break;

                default:
                    break;
            }
        }
        break;

        case 2:
        {
            cout << " Movie DataBase Operations " << endl;
            cout << " ----------------------------- " << endl;
            cout << "1. Sort with movie name" << endl;
            cout << "2. Sort with movie year" << endl;
            cout << "3. Sort with movie nomination" << endl;
            cout << "4. Sort with movie rating" << endl;
            cout << "5. Sort with movie duration" << endl;
            cout << "6. Sort with movie metacritic" << endl;
            cout << "Enter your sub-choice: ";
            cin >> subchoice;

            switch (subchoice) {
                case 1:
                    b.NameSort(MovieRoot, B);
                    break;

                case 2:
                    b.YearSort(MovieRoot, B);
                    break;

                case 3:
                    b.NominationSort(MovieRoot, B);
                    break;

                case 4:
                    b.RatingSort(MovieRoot, B);
                    break;

                case 5:
                    b.DurationSort(MovieRoot, B);
                    break;

                case 6:
                    b.MetacriticSort(MovieRoot, B);
                    break;

                default:
                    break;


            }
        }
        break;

        default:
        {
            cout << "Wrong option number." << endl;
            action3(a, b, A, B);
            break;
        }
    }
}
// Complete searches using the search function 
int choice4()
{
    int choice = 0;
    cout << " Movie DataBase Operations " << endl;
    cout << " ----------------------------- " << endl;
    cout << "1. Complete search on actor-actress data" << endl;
    cout << "2. Complete search on movie data" << endl;
    cout << "Enter your sub-choice: ";

    cin >> choice;

    return choice;
}

void action4(TreeAct &a, TreeMovie &b)
{
    int choice = 0;
    int subchoice = 0;
    tree_node* ActRoot = a.getRoot();
    tree_node_movie* MovieRoot = b.getRoot();
    string str = "";
    int counter = 0;

    choice = choice4();

    switch(choice)
    {
        case 1:
            cout << " Movie DataBase Operations " << endl;
            cout << " ----------------------------- " << endl;
            cout << "1. Complete search with actor-actress name" << endl;
            cout << "2. Complete search with actor-actress film" << endl;
            cout << "3. Complete search with actor-actress year" << endl;
            cout << "4. Complete search with actor-actress winner" << endl;
            cout << "Enter your sub-choice: ";

            cin >> subchoice;

            switch(subchoice)
            {
                case 1:
// Will ask the user to enter the full name to search 
                    cout << "Enter the name of the actor or actress: ";
                    cin.ignore();
                    getline(cin, str);
                    cout << endl << "Complete search result: " << endl;
                    a.NameCompleteSearch(ActRoot, str, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 2:
                    cout << "Enter the name of the film: ";
                    cin.ignore();
                    getline(cin, str);
                    cout << endl << "Complete search result: " << endl;
                    a.FilmCompleteSearch(ActRoot, str, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 3:
                    cout << "Enter the year: ";
                    cin.ignore();
                    getline(cin, str);
                    cout << endl << "Complete search result: " << endl;
                    a.YearCompleteSearch(ActRoot, str, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 4:
                    cout << "Enter the number 1 or 0 (1 means won on an award, and 0 means did not win on any award): ";
                    cin.ignore();
                    getline(cin, str);
                    cout << endl << "Complete search result: " << endl;
                    a.WinnerCompleteSearch(ActRoot, str, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                default:
                    cout << "Wrong option number." << endl;
                    action4(a, b);
                    break;

            }
            break;

        case 2:
            cout << " Movie DataBase Operations " << endl;
            cout << " ----------------------------- " << endl;
            cout << "1. Complete search with movie name" << endl;
            cout << "2. Complete search with movie year" << endl;
            cout << "3. Complete search with movie genre" << endl;
            cout << "4. Complete search with movie released month" << endl;
            cout << "Enter your sub-choice: ";

            cin >> subchoice;

            switch(subchoice)
            {
                case 1:
                    cout << "Enter the name of the movie: ";
                    cin.ignore();
                    getline(cin, str);
                    cout << endl << "Complete search result: " << endl;
                    b.NameCompleteSearch(MovieRoot, str, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 2:
                    cout << "Enter the year when the movie was released: ";
                    cin.ignore();
                    getline(cin, str);
                    cout << endl << "Complete search result: " << endl;
                    b.YearCompleteSearch(MovieRoot, str, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 3:
                    cout << "Enter the genre of the movie (ex. Drama, Comedy, History and so on): ";
                    cin.ignore();
                    getline(cin, str);
                    cout << endl << "Complete search result: " << endl;
                    b.GenreCompleteSearch(MovieRoot, str, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 4:
                    cout << "Enter the released month of the movie (ex. January, May and so on): ";
                    cin.ignore();
                    getline(cin, str);
                    cout << endl << "Complete search result: " << endl;
                    b.ReleaseCompleteSearch(MovieRoot, str, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                default:
                    cout << "Wrong option number." << endl;
                    action4(a, b);
                    break;

            }
            break;

        default:
            cout << "Wrong option number." << endl;
            action4(a, b);
            break;
    }
}

int choice5()
{
    int choice = 0;
    cout << " Movie DataBase Operations " << endl;
    cout << " ----------------------------- " << endl;
    cout << "1. Partial search on actor-actress data" << endl;
    cout << "2. Partial search on movie data" << endl;
    cout << "Enter your sub-choice: ";

    cin >> choice;

    return choice;
}

void action5(TreeAct &a, TreeMovie &b)
{
    int choice = 0;
    int subchoice = 0;
    tree_node* ActRoot = a.getRoot();
    tree_node_movie* MovieRoot = b.getRoot();
    string Partial = "";
    int range1 = 0;
    int range2 = 0;
    int counter = 0;

    choice = choice5();

    switch(choice)
    {
        case 1:
            cout << " Movie DataBase Operations " << endl;
            cout << " ----------------------------- " << endl;
            cout << "1. Partial search with actor-actress name" << endl;
            cout << "2. Partial search with actor-actress film" << endl;
            cout << "3. Partial search with actor-actress award (Leading role or Supporting role)" << endl;
            cout << "Enter your sub-choice: ";

            cin >> subchoice;

            switch(subchoice)
            {
                case 1:
// asks a part of the name before listing all the options and then calling the 
// partial search 
                    cout << "Enter the partial string for the name: ";
                    cin.ignore();
                    getline(cin, Partial);
                    cout << endl << "Partial search result: " << endl;
                    a.NamePartialSearch(ActRoot, Partial, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 2:
                    cout << "Enter the partial string for the film: ";
                    cin.ignore();
                    getline(cin, Partial);
                    cout << endl << "Partial search result: " << endl;
                    a.FilmPartialSearch(ActRoot, Partial, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 3:
                    cout << "Enter the partial string for the award (Leading or Supporting): ";
                    cin.ignore();
                    getline(cin, Partial);
                    cout << endl << "Partial search result: " << endl;
                    a.AwardPartialSearch(ActRoot, Partial, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                default:
                    cout << "Wrong option number." << endl;
                    action5(a, b);
                    break;

            }
            break;

        case 2:
            cout << " Movie DataBase Operations " << endl;
            cout << " ----------------------------- " << endl;
            cout << "1. Partial search with movie name" << endl;
            cout << "2. Partial search with movie synopsis" << endl;
            cout << "3. Partial search with movie nomination" << endl;
            cout << "4. Partial search with movie rating" << endl;
            cout << "5. Partial search with movie duration" << endl;
            cout << "6. Partial search with movie metacritic" << endl;
            cout << "For nomination, rating, Ddration, metacritic search, user will enter two integers to make a range." << endl;
            cout << "Then the result will show the data that has a number between that range." << endl;
            cout << "Enter your sub-choice: ";

            cin >> subchoice;

            switch(subchoice)
            {
                case 1:
                    cout << "Enter the partial string for the name: ";
                    cin.ignore();
                    getline(cin, Partial);
                    cout << endl << "Partial search result: " << endl;
                    b.NamePartialSearch(MovieRoot, Partial, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 2:
                    cout << "Enter the partial string for the synopsis: ";
                    cin.ignore();
                    getline(cin, Partial);
                    cout << endl << "Partial search result: " << endl;
                    b.SynopsisPartialSearch(MovieRoot, Partial, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 3:
                    cout << "Enter two integers that will make a search range for the nomination: ";
                    cin.ignore();
                    cin >> range1 >> range2;
                    cout << endl << "Partial search result: " << endl;
                    b.NominationPartialSearch(MovieRoot, range1, range2, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 4:
                    cout << "Enter two integers that will make a search range for the rating: ";
                    cin.ignore();
                    cin >> range1 >> range2;
                    cout << endl << "Partial search result: " << endl;
                    b.RatingPartialSearch(MovieRoot, range1, range2, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 5:
                    cout << "Enter two integers that will make a search range for the duration: ";
                    cin.ignore();
                    cin >> range1 >> range2;
                    cout << endl << "Partial search result: " << endl;
                    b.DurationPartialSearch(MovieRoot, range1, range2, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                case 6:
                    cout << "Enter two integers that will make a search range for the meatcritic: ";
                    cin.ignore();
                    cin >> range1 >> range2;
                    cout << endl << "Partial search result: " << endl;
                    b.MetacriticPartialSearch(MovieRoot, range1, range2, counter);
                    if(counter==0){cout << "Data not found!" << endl;}
                    break;

                default:
                    cout << "Wrong option number." << endl;
                    action5(a, b);
                    break;

            }
            break;

        default:
            cout << "Wrong option number." << endl;
            action5(a, b);
            break;
    }
}

int choice6()
{
    int choice=0;
    cout << " Movie DataBase Operations " << endl;
    cout << " ----------------------------- " << endl;
    cout << "1. Write actor-actress data into csv file" << endl;
    cout << "2. Write movie data into csv file" << endl;
    cout << "Enter your sub-choice: ";

    cin >> choice;

    return choice;
}

// Will write the function node by node 
void action6(TreeAct &a, TreeMovie &b)
{
    int choice = choice6();

    tree_node* ActRoot = a.getRoot();
    tree_node_movie* MovieRoot = b.getRoot();

    switch(choice)
    {
        case 1:
        {
            ofstream output;
            output.open("NewAct.csv");

            if (output.good()) {
                output << "Year" << ',' << "Award" << ',' << "Winner" << ',' << "Name" << ',' << "Film" << endl;
                a.ActOut(ActRoot, output);
            }
            output.close();
        }
        break;

        case 2:
        {
            ofstream output;
            output.open("NewMovie.csv");

            if (output.good()) {
                output << "Name" << ',' << "Year" << ',' << "Nomination" << ',' << "Rating" << ',' << "Duration" << ',' << "Genre1" << ',' << "Genre2" << ',' << "Release" << ',' << "Metacritic" << ',' << "Synopsis" << ',' << endl;
                b.MovieOut(MovieRoot, output);
            }
            output.close();
        }

            break;

        default:
            break;
    }


}


int main()
{
    TreeAct a;
    TreeMovie b;
    int ch = 0;
    bool done = false;
    string _name;
    char key;
    vector<Act> sortedAct;
    vector<Movies> sortedMovies;

    while(1)
    {
        ch = mainMenu();

        switch (ch) {
            case 0 :// Read in
                action0(a, b);
                break;

            case 1 : // Insertion, Creation
                action1(a, b);
                break;

            case 2 :// Search and Modify
                action2(a, b);
                break;

            case 3 : //Sort
                action3(a, b, sortedAct, sortedMovies);
                break;

            case 4 ://  Search
                action4(a, b);
                break;

            case 5 : // Partial Search
                action5(a, b);
                break;

            case 6 : // Write out
                action6(a, b);
                break;

            case 7 : // End Program
                return 0;
                break;

            default:
                cout << "Wrong option number." << endl;
                break;
        }
    }
}

