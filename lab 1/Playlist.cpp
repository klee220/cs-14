#include "Playlist.h"

PlaylistNode::PlaylistNode(string id, string name, string artist, int length){
    uniqueID = id;
    songName = name;
    artistName = artist;
    songLength = length;
    nextNodePtr = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* a){
    PlaylistNode* temp = nextNodePtr;
    nextNodePtr = a;
    a->SetNext(temp);
}

void PlaylistNode::SetNext(PlaylistNode* a){
    nextNodePtr = a;
}

string PlaylistNode::GetID(){
    return uniqueID;
}

string PlaylistNode::GetSongName(){
    return songName;
}

string PlaylistNode::GetArtistName(){
    return artistName;
}

int PlaylistNode::GetSongLength(){
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext(){
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

Playlist::Playlist(){
    head = 0;
    tail = 0;
}

void Playlist::addSong(PlaylistNode* a){
    if (head == 0){
        head = a;
        tail = a;
    }
    else {
        tail->SetNext(a);
        tail = a;
    }
}

void Playlist::delSong(string id){
    if (head == 0){
        cout << "Playlist is empty" << endl;
    }
    PlaylistNode* curNode = head;
    PlaylistNode* prev = 0;
    while (curNode != 0){
        if (curNode->GetID() == id){
            break;
        }
        prev = curNode;
        curNode = curNode->GetNext();
    }
    if (curNode == 0){
        cout << "\"" << curNode->GetSongName() << "\"is not found" << endl;
    }
    else {
        if (prev != 0){
            prev->SetNext(curNode->GetNext());
        }
        else{
            head = curNode->GetNext();
        }
        if (tail == curNode){
            tail = prev;
        }
        cout << "\"" << curNode->GetSongName() << "\" removed." << endl << endl;
        delete curNode;
    }
}

//COULD HAVE DONE IT ALL IN ONE FOR LOOP, NO NEED TO BREAK IT INTO CASES

void Playlist::changePos(int curPos, int newPos){
    int i = 1;
    PlaylistNode* prev = 0;
    PlaylistNode* curNode = head;

    while (i < curPos){
        if (curNode != 0){
            prev = curNode;
            curNode = curNode->GetNext();
            ++i;
        }
        else {
          return;
        }
    }
    
    if (prev != 0){
      prev->SetNext(curNode->GetNext());
    }
    else{
      head = curNode->GetNext();
    }

    if (curNode == tail){
      tail = prev;
    }

    if (newPos <= 1){
        if (head == 0){
          head = curNode;
          tail = curNode;
        }

        curNode->SetNext(head);
        head = curNode;
        cout << '"' << curNode->GetSongName() << '"' << " moved to position 1" << endl;
    }
    else{
        if (head == 0){
            addSong(curNode);
            cout << '"' << curNode->GetSongName() << '"' << " moved to position 1" << endl;
        }
        else{
            PlaylistNode* before = head;
            PlaylistNode* after = head->GetNext();
            int j = 2;

            while ((j < newPos) && (after != 0)){
                before = after;
                after = after->GetNext();
                ++j;
            }

            before->InsertAfter(curNode);

            if (after == 0){
                tail = curNode;
            }
            cout << '"' << curNode->GetSongName() << '"' << " moved to position " << j << endl << endl;
        }
    }
}

void Playlist::artistSongs(string artist){
    if (head == 0){
        cout << "Playlist is empty." << endl;
    }
    else{
        PlaylistNode* curr = head;
        int i = 1;
        while (curr != 0){
            if (curr->GetArtistName() == artist){
                cout << i << "." << endl;
                curr->PrintPlaylistNode();    
                cout << endl;          
            }
            curr = curr->GetNext();
            ++i;
        }
    }
}

int Playlist::totTime(){
    int length = 0;
    for (PlaylistNode* curNode = head; curNode != 0; curNode = curNode->GetNext()){
        length = length + curNode->GetSongLength();
    }
    return length;
}

void Playlist::outputList(string playlist){
    cout << playlist << " - OUTPUT FULL PLAYLIST" << endl;
    int i = 1;
    PlaylistNode* a = head;

    if (head == 0){
        cout << "Playlist is empty" << endl << endl;
    }
    else{
        while (a != 0){
            cout << i << "." << endl;
            a->PrintPlaylistNode();
            cout << endl;
            ++i;
            a = a->GetNext();
        }
    }
}