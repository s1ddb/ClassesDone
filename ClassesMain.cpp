//Classes by Siddhartha Bobba, it's a media database where you can add search and delete new media like videogames, music and movies 


#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>

#include "database.h"
#include "videogame.h"
#include "movie.h"
#include "music.h"

using namespace std;


void add(vector<database*>* StoreData, int mediatype);
void search(vector<database*>* StoreData);
void del(vector<database*>* StoreData);


int main() {

  // vector<database*> StoreData; //Vector to store all the data in the database

  vector<database*>* storeData = new vector<database*>();

  bool replay = true; //boolean to set program running true or false

  while (replay == true) {

    int inpt = 0;
    int mediatype = 0; //for choosing the type of media
    cout << "TYPE IN 1 TO ADD" << endl;
    cout << "TYPE IN 2 TO SEARCH" << endl;
    cout << "TYPE IN 3 TO DELETE" << endl;
    cout << "TYPE IN 4 TO QUIT" << endl;

    cin >> inpt; //stores user's input into inpt variable

    cin.ignore(100, '\n'); //clears the memory for next usage


    if (inpt == 1)  { //if is 1

      cout << "TYPE IN 1 FOR VIDEO GAMES" << endl;
      cout << "TYPE IN 2 TO MUSIC" << endl;
      cout << "TYPE IN 3 TO MOVIES" << endl;

      cin >> mediatype; //stores user's input into inpt variable

      cin.ignore(100, '\n');

      if (mediatype == 1) {

	add(storeData, 1); //add function for video games

      } 

      else if (mediatype == 2) { //add function for music

	add(storeData, 2); 
      } 

      else if (mediatype == 3) {

	add(storeData, 3); // add function for movies
	
      }


    } // end if input = 1
    else if (inpt == 2) { // if user wants search function

      search(storeData); // search
	}
    else if (inpt == 3)  {// if user wants delete function
      
      del(storeData); // delete
      
    }
    else if (inpt == 4) {


      replay = false;
      
    }


    
      
  } // end while
 

} // end main

//function for add function
void add(vector<database*>* storeData, int mediatype) {


  if (mediatype == 2) {

    music* newMusic = new music; //new music variable for music class inside the add function

    //TITLE
    
    cout << "What is the title of the track" << endl;
    cout << endl;
    cout << "SONG/ALBUM TITLE: " << endl;

    char title[40];
    cin.get(title, 40);
    newMusic->setTitle(title);
    
    //cin.get(newMusic->getTitle(), 40);
    cin.ignore(100, '\n'); //terminating character

    
    //artist
    cout << "Who is the artist?" << endl;
    cout << endl;
    cout << "NAME OF THE ARTIST: " << endl;


    char artist[40];
    cin.get(artist, 40);
    newMusic->setArtist(artist);
    //cin.get(newMusic->getArtist(), 40);
    cin.ignore(100, '\n'); //terminating character

    
    cout << "When was the music released?" << endl;
    cout << endl; //space
    cout << "YEAR OF RELEASE: " << endl;

    int year;
    cin >> year;
    (newMusic -> setYear(year));
    cin.ignore(100, '\n'); // clear memory | terminating char

    
    //DURATION
    
    
    cout << "What is the duration of the track/album?" << endl;
    cout << endl;
    cout << "DURATION: " << endl;
    
    float duration;
    cin >> duration;
    newMusic->setDuration(duration);
    
    //cin >> fixed >> setprecision(2) >> newMusic->setDuration(); //sets precision to 2 decimal points for the float and gets the duration entered into getDuration
    cin.ignore(100, '\n');


    //PUBLISHER
    
    cout << "Who is the publisher?" << endl;
    cout << endl;
    cout << "NAME OF THE PUBLISHER: " << endl;


    char publisher[40];
    cin >> publisher;
    newMusic->setPublisher(publisher);
    
    //cin.get(newMusic->getPublisher(), 40);
    cin.ignore(100, '\n'); //terminating character



    storeData->push_back(newMusic);
  }

  
  else if (mediatype == 3) {


    movie* newMovie = new movie; //object for movie




    // TITLE

    cout << "What is the name of the movie?" << endl;
    cout << endl;
    cout << "TITLE: " << endl;

    char title[40];
    cin.get(title, 40);
    newMovie->setTitle(title);
    
    // cin.get(*newMovie->setDuration(), 40);
    cin.ignore(100, '\n');

    
    //YEAR OF RELEASE
    
    cout << "When was the movie released?" << endl;
    cout << endl; //space
    cout << "YEAR OF RELEASE: " << endl;


    int year;
    cin >> year;
    newMovie->setYear(year);
    
    //cin >> *newMovie->getYear();
    cin.ignore(100, '\n');


    
    // DIRECTOR
    
    cout << "Who directed the movie?" << endl;
    cout << endl;
    cout << "DIRECTOR: " << endl;


    char director[40];
    cin.get(director, 40);
    newMovie->setDirector(director);
    
    //cin.get(newMovie->getDirector(), 40);
    cin.ignore(100, '\n');


    // DURATION

    cout << "How long is the movie?" << endl;
    cout << endl;
    cout << "DURATION: " << endl;

    float duration;
    cin >> duration;
    newMovie->setDuration(duration);
    
    //cin >> *newMovie->getDuration();
    cin.ignore(100, '\n');


    // RATING

    cout << "How was the movie recieved>" << endl;
    cout << endl;
    cout << "RATING: " << endl;

    float rating;
    cin >> rating;
    newMovie->setRating(rating);
    
    //cin >> fixed >> setPrecision(2) >> *newMovie-getRating();
    cin.ignore(100, '\n');


    storeData -> push_back(newMovie);
  }
  
else if (mediatype == 1) {
    
    
    videogame* newVideogame = new videogame(); //object
    
    //TITLE
    
    cout << "What is the title of the game" << endl;
    cout << endl;
    cout << "TITLE: " << endl;

    char title[40];
    cin.get(title, 40);
    newVideogame->setTitle(title);
    
    //cin.get(newVideogame->getTitle(), 40);
    cin.ignore(100, '\n'); //terminating character
    
    
    
    cout << "When was the videogame released?" << endl;
    cout << endl; //space
    cout << "YEAR OF RELEASE: " << endl;
    
    int year;
    cin >> year;
    newVideogame -> setYear(year);
    cin.ignore(100, '\n'); // clear memory | terminating char


    

    //PUBLISHER
    
    cout << "Who is the publisher?" << endl;
    cout << endl;
    cout << "NAME OF THE PUBLISHER: " << endl;


    char publisher[40];
    cin >> publisher;
    newVideogame->setPublisher(publisher);
    //cin.get(newMusic->getPublisher(), 40);
    cin.ignore(100, '\n'); //terminating character


// RATING

    cout << "How was the videogame recieved?" << endl;
    cout << endl;
    cout << "RATING: " << endl;

    float rating;
    cin >> rating;
    newVideogame->setRating(rating);
    
    //cin >> fixed >> setPrecision(2) >> *newMovie-getRating();
    cin.ignore(100, '\n');

    
    
    storeData->push_back(newVideogame);
 } 
  
}


void search(vector<database*>* storeData) {

  cout << "searching.." << endl;


  int searchType;
  char searchTitle[50];
  int searchYear;
  
  vector<database*>::iterator searchThrough;

  cout << "1 TO SEARCH BY TITLE" << endl;
  cout << "2 TO SEARCH BY YEAR" << endl;

  cin >> searchType;
  cin.ignore(100, '\n');
  
  if (searchType == 1) {

    cout << "Title to search for: " << endl;
    cin.get(searchTitle, 50);
    cin.ignore(100, '\n');


    for (searchThrough = storeData->begin(); searchThrough != storeData->end(); searchThrough++) {

      if (strcmp((*searchThrough)->getTitle(), searchTitle) == 0) {

	if ((*searchThrough)->getType() == 1) { //getting the media type 
	  //title, year, publisher, rating
	  
	  cout << "TITLE: " << (*searchThrough)->getTitle() <<endl;
	   
	  cout << "YEAR RELEASED:" << (*searchThrough)->getYear() << endl;
	  
	  cout << "PUBLISHER: " << dynamic_cast<videogame*>(*searchThrough)->getPublisher() << endl;
	  
	  cout << "RATING: " << dynamic_cast<videogame*>(*searchThrough)->getRating() << endl;
	  

	}
	else if ((*searchThrough)->getType() == 2) { //music

	  
	  cout << "MUSIC INFO: " << endl;

	  cout << endl;
	  
	  cout << "TITLE: " << (*searchThrough)->getTitle() <<endl;

	  cout << "ARTIST: " << dynamic_cast<music*>(*searchThrough)->getArtist() << endl;

	  cout << "YEAR RELEASED" << (*searchThrough)->getYear() << endl;

	  cout << "PUBLISHER: " << dynamic_cast<music*>(*searchThrough)->getPublisher() << endl;

	  cout << "DURATION OF MUSIC: " << dynamic_cast<music*>(*searchThrough)->getDuration() << endl;

	  cout << endl;
	  
	}
	else if ((*searchThrough)->getType() == 3) {
	  //title, director, year, duration, rating
	  
	  cout << "MOVIE INFO: " << endl;
	  
	  cout << endl;
	  
	  cout << "TITLE: " << (*searchThrough)->getTitle() <<endl;
	  
	  cout << "DIRECTOR: " << dynamic_cast<movie*>(*searchThrough)->getDirector() << endl;
	  
	  cout << "YEAR RELEASED" << (*searchThrough)->getYear() << endl;

	  cout << "RATING: " << dynamic_cast<movie*>(*searchThrough)->getRating() << endl;
	  
	  cout << "DURATION OF MOVIE: " << dynamic_cast<movie*>(*searchThrough)->getDuration() << endl;
	  
	  cout << endl;
	  
	}
	
	
      }
      
    }
  }
  else if (searchType == 2) {
    
    
    cout << "Year to search for: " << endl;
    cin >> searchYear;
    cin.ignore(100277645528.4, '\n');
    
    
    for (searchThrough = storeData->begin(); searchThrough != storeData->end(); searchThrough++) {
      
      if ((*searchThrough)->getYear() == searchYear) {
	
	if ((*searchThrough)->getType() == 1) { //getting the media type 
	  //title, year, publisher, rating
	  
	  cout << "TITLE: " << (*searchThrough)->getTitle() <<endl;
	  
	  cout << "YEAR RELEASED:" << (*searchThrough)->getYear() << endl;
	  
	  cout << "PUBLISHER: " << dynamic_cast<videogame*>(*searchThrough)->getPublisher() << endl;
	  
	  cout << "RATING: " << dynamic_cast<videogame*>(*searchThrough)->getRating() << endl;
	  
	  
	}
	else if ((*searchThrough)->getType() == 2) { //music
	  
	  
	  cout << "MUSIC INFO: " << endl;
	    
	  cout << endl;
	  
	  cout << "TITLE: " << (*searchThrough)->getTitle() <<endl;
	  
	  cout << "ARTIST: " << dynamic_cast<music*>(*searchThrough)->getArtist() << endl;
	  
	  cout << "YEAR RELEASED" << (*searchThrough)->getYear() << endl;
	  
	  cout << "PUBLISHER: " << dynamic_cast<music*>(*searchThrough)->getPublisher() << endl;
	    
	  cout << "DURATION OF MUSIC: " << dynamic_cast<music*>(*searchThrough)->getDuration() << endl;
	  
	  cout << endl;
	  
	}
	else if ((*searchThrough)->getType() == 3) {
	  //title, director, year, duration, rating
	  
	  cout << "MOVIE INFO: " << endl;
	  
	  cout << endl;
	  
	  cout << "TITLE: " << (*searchThrough)->getTitle() <<endl;
	  
	  cout << "DIRECTOR: " << dynamic_cast<movie*>(*searchThrough)->getDirector() << endl;
	    
	  cout << "YEAR RELEASED" << (*searchThrough)->getYear() << endl;
	  
	  cout << "RATING: " << dynamic_cast<movie*>(*searchThrough)->getRating() << endl;
	  
	  cout << "DURATION OF MOVIE: " << dynamic_cast<movie*>(*searchThrough)->getDuration() << endl;
	  
	  cout << endl;
	  
	}
	
	  
      }
      
    }
    
    
    
  }
  
  
  
}
  



void del(vector<database*>* storeData) {

  
  int deleteType;
  char deleteTitle[40]; //delete by title
  int deleteYear; //delete by year
  int confirmprompt; //are you sure you want to del

  cout << "Press 1 to delete by title, press 2 to delete by year" << endl;
  cin >> deleteType;
  cin.ignore(100, '\n');
  
  vector<database*>::iterator delThru;

  if (deleteType == 1) {

    cout << "Title of the media you want to delete: " << endl;
    cin.get(deleteTitle, 40);
    cin.ignore(100, '\n');


    for (delThru = storeData->begin(); delThru != storeData->end(); delThru++) {
      if (strcmp((*delThru)->getTitle(), deleteTitle) == 0) {
	
	if ((*delThru)->getType() == 1) {
	  
	  cout << "VIDEO GAME title has been found: " << (*delThru)->getTitle() << endl;
	  cout << "Are you sure you want to delete? Use 1 for YES. 2 for NO." << endl;
	  cin >> confirmprompt; //takes in confirmation answer
	  cin.ignore(100, '\n');
	  
	    if (confirmprompt == 1) {
	      
	      delete* delThru;
	      delThru = storeData->erase(delThru); //deletes the data
	      
	      cout << "The video game data entered was deleted sucessfully." << endl;
	      
	      confirmprompt = 0; //sets confirmprompt var to 0 after deleting
	      
	      return;
	      
	    }
	    else if (confirmprompt == 2) {
	      
	      cout << "Videogame data was not deleted. Process terminated by user." << endl;
	      confirmprompt = 0;
	    }
	}
	  else if ((*delThru)->getType() == 2) {
	    
	    cout << "MUSIC title has been found: " << (*delThru)->getTitle() << endl;
	    cout << "Are you sure you want to delete? Use 1 for YES. 2 for NO." << endl;
	    cin >> confirmprompt; //takes in confirmation answer
	    cin.ignore(100, '\n');
	    
	    if (confirmprompt == 1) {
	      
	      delete* delThru;
	      delThru = storeData->erase(delThru); //deletes the data
	      
	      cout << "The music data entered was deleted sucessfully." << endl;
	      
	      confirmprompt = 0; //sets confirmprompt var to 0 after deleting
	      
	      return;
	      
	    }
	    else if (confirmprompt == 2) {
	      
	      cout << "Music data was not deleted. Process terminated by user." << endl;
	      confirmprompt = 0;
	    }
	    
	  }
	
	  else if ((*delThru)->getType() == 3) {
	    
	    cout << "MOVIE title has been found: " << (*delThru)->getTitle() << endl;
	    cout << "Are you sure you want to delete? Use 1 for YES. 2 for NO." << endl;
	    cin >> confirmprompt; //takes in confirmation answer
	    cin.ignore(100, '\n');
	    
	    if (confirmprompt == 1) {
	      
	      delete* delThru;
	      delThru = storeData->erase(delThru); //deletes the data
	      
	      cout << "The movie data entered was deleted sucessfully." << endl;
	      
	      confirmprompt = 0; //sets confirmprompt var to 0 after deleting
	      
	      return;
	      
	    }
	    else if (confirmprompt == 2) {
	      
	      cout << "Movie data was not deleted. Process terminated by user." << endl;
	      confirmprompt = 0;
	    }
	    
	  }
	
      }
      
    }
    
  }
  else if (deleteType == 2) {
    
    //delete by year
    
    cout << "Year of the media you want to delete: " << endl;
    cin >> deleteYear;
    cin.ignore(100, '\n');
    
    
    for (delThru = storeData->begin(); delThru != storeData->end(); delThru++) {
      if ((*delThru)->getYear() == deleteYear) {
	
	if ((*delThru)->getType() == 1) {
	  
	  cout << "VIDEO GAME year has been found: " << (*delThru)->getTitle() << endl;
	  cout << "Are you sure you want to delete? Use 1 for YES. 2 for NO." << endl;
	  cin >> confirmprompt; //takes in confirmation answer
	  cin.ignore(100, '\n');
	  
	  if (confirmprompt == 1) {
	    
	    delete* delThru;
	    delThru = storeData->erase(delThru); //deletes the data
	    
	    cout << "The video game data entered was deleted sucessfully." << endl;
	    
	    confirmprompt = 0; //sets confirmprompt var to 0 after deleting
	    
	    return;
	    
	  }
	  else if (confirmprompt == 2) {
	    
	    cout << "Videogame data was not deleted. Process terminated by user." << endl;
	    confirmprompt = 0;
	  }
	}
	else if ((*delThru)->getType() == 2) {
	  
	  cout << "MUSIC year has been found: " << (*delThru)->getTitle() << endl;
	  cout << "Are you sure you want to delete? Use 1 for YES. 2 for NO." << endl;
	  cin >> confirmprompt; //takes in confirmation answer
	  cin.ignore(100, '\n');
	  
	  if (confirmprompt == 1) {
	    
	    delete* delThru;
	    delThru = storeData->erase(delThru); //deletes the data
	    
	    cout << "The music data entered was deleted sucessfully." << endl;
	    
	    confirmprompt = 0; //sets confirmprompt var to 0 after deleting
	    
	    return;
	    
	  }
	  else if (confirmprompt == 2) {
	    
	    cout << "Music data was not deleted. Process terminated by user." << endl;
	    confirmprompt = 0;
	  }
	  
	}
	
	else if ((*delThru)->getType() == 3) {
	  
	  cout << "MOVIE year has been found: " << (*delThru)->getTitle() << endl;
	  cout << "Are you sure you want to delete? Use 1 for YES. 2 for NO." << endl;
	  cin >> confirmprompt; //takes in confirmation answer
	  cin.ignore(100, '\n');
	  
	  if (confirmprompt == 1) {
	    
	    delete* delThru;
	    delThru = storeData->erase(delThru); //deletes the data
	    
	    cout << "The movie data entered was deleted sucessfully." << endl;
	    
	    confirmprompt = 0; //sets confirmprompt var to 0 after deleting
	    
	    return;
	    
	  }
	  else if (confirmprompt == 2) {
	    
	    cout << "Movie data was not deleted. Process terminated by user." << endl;
	    confirmprompt = 0;
	  }
	  
	}
	
      }
      
    }
    
  }
  
}
