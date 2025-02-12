#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
private:
    string title;
    string genre;
    int releaseYear;

public:
    Movie(string movieTitle, string movieGenre, int year) : title(movieTitle), genre(movieGenre), releaseYear(year) {}

    void displayDetails() {
        cout << "Title: " << title << ", Genre: " << genre << ", Year: " << releaseYear << endl;
    }

    string getTitle() { return title; }
    int getReleaseYear() { return releaseYear; }
};

class MovieCollection {
private:
    vector<Movie> movies;

public:
    void addMovie(string title, string genre, int year) {
        movies.push_back(Movie(title, genre, year));
        cout << "Movie added successfully!\n";
    }

    void displayMovies() {
        if (movies.empty()) {
            cout << "No movies in the collection.\n";
            return;
        }
        cout << "Movies in the Collection:\n";
        for (size_t i = 0; i < movies.size(); ++i) {
            movies[i].displayDetails();
        }
    }

    void searchMovie(string title) {
        bool found = false;
        for (size_t i = 0; i < movies.size(); ++i) {
            if (movies[i].getTitle() == title) {
                cout << "Movie Found:\n";
                movies[i].displayDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Movie not found!\n";
        }
    }
};

int main() {
    MovieCollection collection;
    int choice, year;
    string title, genre;

    do {
        cout << "\nMovie Collection Menu:\n";
        cout << "1. Add Movie\n2. Display Movies\n3. Search Movie\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter Movie Title: ";
                getline(cin, title);
                cout << "Enter Genre: ";
                getline(cin, genre);
                cout << "Enter Release Year: ";
                cin >> year;
                collection.addMovie(title, genre, year);
                break;

            case 2:
                collection.displayMovies();
                break;

            case 3:
                cin.ignore();
                cout << "Enter Movie Title to Search: ";
                getline(cin, title);
                collection.searchMovie(title);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
