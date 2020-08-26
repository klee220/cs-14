#include <iostream>
#include "Playlist.h"
using namespace std;

Playlist list;

void PrintMenu(string playlist){
    string ch;
    string id;
    string song;
    string artist;
    int length;
    int newPos;
    int curPos;
    
    cout << playlist << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl; 
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;
    
    getline(cin, ch);
    if (ch == "a"){
        cout << "ADD SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        getline(cin, id);
        cout << "Enter song's name:" << endl;
        getline(cin, song);
        cout << "Enter artist's name:" << endl;
        getline(cin, artist);
        cout << "Enter song's length (in seconds):" << endl << endl;
        cin >> length;
        cin.ignore();

        PlaylistNode* a = new PlaylistNode(id, song, artist, length);
        list.addSong(a);
        
        PrintMenu(playlist);
    }
    else if (ch == "d"){
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        getline(cin, id);
        list.delSong(id);
        PrintMenu(playlist);
    }
    else if (ch == "c"){
        cout << "CHANGE POSITION OF SONG" << endl;
        cout << "Enter song's current position:" << endl;
        cin >> curPos;
        cout << "Enter new position for song:" << endl;
        cin >> newPos;
        cin.ignore();
        list.changePos(curPos, newPos);
        PrintMenu(playlist);
    }
    else if (ch == "s"){
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl << endl;
        getline(cin, artist);
        list.artistSongs(artist);
        PrintMenu(playlist);
    }
    else if (ch == "t"){
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
        cout << "Total time: " << list.totTime() << " seconds" << endl << endl;
        PrintMenu(playlist);
    }
    else if (ch == "o"){
        list.outputList(playlist);
        PrintMenu(playlist);
    }
    else if (ch == "q"){
      
    }
    else {
        PrintMenu(playlist);
    }
}

int main(){
    string playlistName;
    cout << "Enter playlist's title:" << endl << endl;
    getline(cin, playlistName);

    PrintMenu(playlistName);
    return 0;
}