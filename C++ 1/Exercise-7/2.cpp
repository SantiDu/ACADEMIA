#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Movie {
    private:
        string title;
        string actors;
        int duration;
    public:
        static const string DEFAULT_TITLE;
        static const int DEFAULT_DURATION;
        static const string DEFAULT_ACTORS;
    public:
        Movie();
        Movie(string new_title, int new_duration, string new_actors);
        ~Movie();
        string get_title() const;
        void set_title(string new_title);
        int get_duration() const;
        void set_duration(int new_duration);
        string get_actors() const;
        void set_actors(string new_actors);
        void DisplayMovieInfo() const;
};

int main() {
    Movie movie;
    movie.set_title("The Inseparable");
    movie.set_duration(137);
    movie.set_actors("J.J Winson;Rachel West");
    movie.DisplayMovieInfo();

    cout << movie.get_duration() << endl;
    cout << Movie::DEFAULT_TITLE << endl;

    return 0;
}

const string Movie::DEFAULT_TITLE = "Unknown Movie";
const string Movie::DEFAULT_ACTORS = ";;;";
const int Movie::DEFAULT_DURATION = 120;

Movie::Movie() : title(Movie::DEFAULT_TITLE),
                 actors(Movie::DEFAULT_ACTORS),
                 duration(Movie::DEFAULT_DURATION) {
                    cout << "Movie " << title << " is showing now." << endl;
                 }

Movie::Movie(string new_title, int new_duration, string new_actors) : title(new_title),
                                                                      actors(new_actors),
                                                                      duration(new_duration) {}

Movie::~Movie() {
    cout << "Movie " << title << " is no longer showing." << endl;
}

string Movie::get_title() const {return title;}

void Movie::set_title(string new_title) {title = new_title;}

int Movie::get_duration() const {return duration;}

void Movie::set_duration(int new_duration) {duration = new_duration;}

string Movie::get_actors() const {return actors;}

void Movie::set_actors(string new_actors) {actors = new_actors;}

void Movie::DisplayMovieInfo() const {
    cout << "Movie <" << title;
    cout << "> lasts <" << duration << "> minutes,";
    cout << "featuring <" << actors << ">" << endl;
}