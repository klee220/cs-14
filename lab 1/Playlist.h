#include <string>
#include <iostream>
using namespace std;

#ifndef PLAYLIST_H
#define PLAYLIST_H

class PlaylistNode {
    public:
        PlaylistNode(){
            uniqueID = "none";
            songName = "none";
            artistName = "none";
            songLength = 0;
            nextNodePtr = 0;
        }
        PlaylistNode(string id, string name, string artist, int length);
        void InsertAfter(PlaylistNode* a);
        void SetNext(PlaylistNode* a);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();
    private:
        string uniqueID; 
        string songName; 
        string artistName; 
        int songLength; 
        PlaylistNode* nextNodePtr;
};

class Playlist {
    public:
        Playlist();
        void addSong(PlaylistNode* a);
        void delSong(string id);
        void changePos(int curPos, int newPos);
        void artistSongs(string artist);
        int totTime();
        void outputList(string playlist);
    private:
        PlaylistNode* head;
        PlaylistNode* tail;
};

#endif