/**
 * Movie Ticket Booking System
 *
 * This program is a simple console-based movie ticket booking system designed to help manage
 * the booking of movie tickets for a cinema. It allows users to select movies, choose showtimes,
 * and book tickets.
 *
 * Key Features:
 * 1. Add Movies: Allows the user to add new movies to the system along with their showtimes.
 * 2. Book Tickets: Enables the user to book tickets for a specific movie and showtime.
 * 3. Display Movies: Shows all movies currently available along with their respective showtimes.
 * 4. Exit: Exits the program.
 *
 * Usage:
 * The system prompts the user with a menu of actions corresponding to the features listed above.
 * The user can select an action by entering the number associated with each feature. The program
 * will then ask for the necessary information to perform the selected action, such as the movie name
 * or showtime.
 *
 * This application is ideal for small to medium-sized cinemas looking to provide a straightforward
 * method for customers to book tickets.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Movie {
    string title;
    vector<string> showtimes;

    Movie(string t, vector<string> s) : title(move(t)), showtimes(move(s)) {}
};

class Cinema {
private:
    vector<Movie> movies;

public:
    void addMovie(const string& title, const vector<string>& showtimes) {
        movies.emplace_back(title, showtimes);
        cout << "Movie added successfully." << endl;
    }

    void bookTicket(const string& title, const string& showtime) {
        for (auto& movie : movies) {
            if (movie.title == title) {
                for (const auto& st : movie.showtimes) {
                    if (st == showtime) {
                        cout << "Ticket booked successfully for " << title << " at " << showtime << "." << endl;
                        return;
                    }
                }
            }
        }
        cout << "Showtime not found or movie does not exist." << endl;
    }

    void displayMovies() const {
        if (movies.empty()) {
            cout << "No movies currently available." << endl;
            return;
        }
        cout << "Available Movies and Showtimes:" << endl;
        for (const auto& movie : movies) {
            cout << "Movie: " << movie.title << endl;
            for (const auto& showtime : movie.showtimes) {
                cout << "  Showtime: " << showtime << endl;
            }
        }
    }
};

int main() {
    Cinema cinema;
    string title, showtime;
    vector<string> showtimes;
    int choice;

    cout << "Movie Ticket Booking System" << endl;

    while (true) {
        cout << "1. Add Movie" << endl;
        cout << "2. Book Tickets" << endl;
        cout << "3. Display Movies" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter movie title: ";
                cin >> ws; getline(cin, title);
                cout << "Enter showtimes (separated by newline, end with an empty line): ";
                showtimes.clear();
                while (getline(cin, showtime) && !showtime.empty()) {
                    showtimes.push_back(showtime);
                }
                cinema.addMovie(title, showtimes);
                break;
            case 2:
                cout << "Enter movie title to book tickets for: ";
                cin >> ws; getline(cin, title);
                cout << "Enter showtime: ";
                getline(cin, showtime);
                cinema.bookTicket(title, showtime);
                break;
            case 3:
                cinema.displayMovies();
                break;
            case 4:
                cout << "Exiting application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
