#include <iostream>
#include <iomanip>

using namespace std;

class Movie {
     private:
          string title;
          int duration;
          string actors;
     public:
          Movie();
          Movie(string title, int duration, string actors);
          ~Movie();
          static const string DEFAULT_TITLE;
          static const int DEFAULT_DURATION;
          static const string DEFAULT_ACTORS;
     public:
          string get_title() const;
          void set_title(string title);
          int get_duration() const;
          void set_duration(int duration);
          string get_actor() const;
          void set_actor(string actors);
     public:
          void DisplayMovieInfo() const;
};

const string Movie::DEFAULT_TITLE = "Unknown Movie";
const int Movie::DEFAULT_DURATION = 120;
const string Movie::DEFAULT_ACTORS = ";;;";

Movie::Movie() : title(Movie::DEFAULT_TITLE),
                 duration(Movie::DEFAULT_DURATION),
                 actors(Movie::DEFAULT_ACTORS) {
     cout << "Movie " << title << " is showing now." << endl;
}
Movie::Movie(string title, int duration, string actors) : title(title), duration(duration), actors(actors) {}
Movie::~Movie() {
     cout << "Movie " << title << " is no longer showing." << endl;
}

string Movie::get_title() const {return title;}
void Movie::set_title(string title) {this->title = title;}
int Movie::get_duration() const {return duration;}
void Movie::set_duration(int duration) {this->duration = duration;}
string Movie::get_actor() const {return actors;}
void Movie::set_actor(string actors) {this->actors = actors;}


void Movie::DisplayMovieInfo() const {
     cout << "Movie data in the form: Movie " << title;
     cout << " lasts" << duration << " minutes, ";
     cout << "featuring " << actors;
     cout << endl;
} 