// 3222.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp> 

using json = nlohmann::json;
using namespace std;

int main() {

    ifstream file("movies.json");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    json movieData;
    file >> movieData;
    file.close();


    cout << "Enter actor's name: ";
    string actorName;
    getline(cin, actorName);

    bool found = false;


    for (auto& [movie, details] : movieData.items()) {
        for (const auto& actor : details["actors"]) {
            if (actor["name"] == actorName) {
                cout << "Movie: " << movie << ", Role: " << actor["role"] << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Actor not found." << endl;
    }

    return 0;
}