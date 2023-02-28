#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iomanip>

class Song
{
private:
    friend std::ostream& operator<<(std::ostream& os, const Song& obj)
    {
        os << std::setw(20) << std::left <<obj.songName << std::setw(30) << std::left <<obj.artist << std::setw(2) << std::left << obj.rating;
        return os;
    }
    std::string songName;
    std::string artist;
    int rating;

public:
    Song(std::string songName = "None", std::string artist = "None", int rating = 0)
    {
        this->songName = songName;
        this->artist = artist;
        this->rating = rating;
    }
    std::string getName() const
    {
        return songName;
    }
    std::string getArtist() const
    {
        return artist;
    }
    int getRating() const
    {
        return rating;
    }
    bool operator<(const Song& rhs) const
    {
        if (this->getName() < rhs.getName())
        {
            return true;
        }
        return false;
    }
    bool operator==(const Song& rhs) const
    {
        if ((songName == rhs.songName) && (artist == rhs.artist) && (rating == rhs.rating))
        {
            return true;
        }
        return false;
    }
};

void displayMenu();
void displayPlaylist(const std::list<Song>& songs, const Song& currentSong);
void currentSong(const Song& currentSong);

int main()
{
    char selection{};
    std::list<Song> songs = { {"God's Plan", "Drake", 5},
                              {"Never Be The Same", "Camilla Cabello", 5},
                              {"Pray For Me", "The Weekend/K.Lamar", 4},
                              {"The Middle", "Zedd & Maren Morris & Grey", 5},
                              {"Wait", "Maroone5", 4},
                              {"Whatever It Takes", "Imagine Dragons", 3} };

    std::list<Song>::iterator playingSong = songs.begin();
    displayPlaylist(songs, *playingSong);

    while (selection != 'Q')
    {
        displayMenu();
        std::cin >> selection;
        selection = toupper(selection);
        if (selection == 'F')
        {
            std::cout << "Playing First Song" << std::endl;
            playingSong = songs.begin();
            currentSong(*playingSong);
        }
        else if (selection == 'N')
        {
            std::cout << "Playing Next Song" << std::endl;
            if (playingSong == songs.end())
            {
                playingSong = songs.begin();
            }
            else
            {
                playingSong++;
            }
            currentSong(*playingSong);
        }
        else if (selection == 'P')
        {
            std::cout << "Playing Previous Song" << std::endl;
            if (playingSong == songs.begin())
            {
                playingSong = songs.end();
            }
            else
            {
                playingSong--;
            }
            currentSong(*playingSong);
        }
        else if (selection == 'A')
        {
            std::string songName;
            std::string artist;
            int rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter the name of the new song : ";
            getline(std::cin, songName);
            std::cout << "Enter the song artist : ";
            getline(std::cin, artist);
            std::cout << "Enter rating of the song : ";
            std::cin >> rating;
            songs.insert(playingSong, Song{ songName, artist, rating });
            playingSong--;
            currentSong(*playingSong);
        }
        else if (selection == 'L')
        {
            std::cout << std::endl;
            displayPlaylist(songs, *playingSong);
        }
        else if (selection == 'Q')
        {
            std::cout << "Quitting" << std::endl;
            std::cout << "Thanks for listening" << std::endl;
        }
        else
        {
            std::cout << "Invalid choice, try again" << std::endl;
        }

    }

    return 0;
}

void displayMenu()
{
    std::cout << std::endl;
    std::cout << "F - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "=============================================================" << std::endl;
    std::cout << "Enter a selection (Q for quit) : ";
}

void displayPlaylist(const std::list<Song>& songs, const Song &currentSong)
{
    for (const auto it : songs)
    {
        std::cout << it << std::endl;
    }
    std::cout << "Current Song : " << currentSong.getName() << " || " << currentSong.getArtist() << std::endl;
}

void currentSong(const Song& currentSong)
{
    std::cout << "Playing : " << currentSong.getName() << " || " << currentSong.getArtist() << std::endl;
}
