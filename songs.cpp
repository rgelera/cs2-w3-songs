#include <iostream>
#include <sstream>

using namespace std;

struct song {
  string title;
  string artist;
  int year;
};

song** songsFromYear(song **songs, int size, int year, int* resultSize) {
  song ** filteredSongs = new song *[size];
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (songs[i]->year == year) {
      filteredSongs[count] = songs[i];
      count++;
    }
  }

  *resultSize = count;
  return filteredSongs;
}

string songToString(song *s) {
  stringstream ss;
  ss << s->artist << " - " << s->title << " (" << s->year << ")";
  return ss.str();
}

int main() {
  const int ARRAY_SIZE = 5;
  song ** songArray = new song*[ARRAY_SIZE];

  songArray[0] = new song;
  songArray[0]->title = "Song A";
  songArray[0]->artist = "Artist A";
  songArray[0]->year = 2010;

  songArray[1] = new song;
  songArray[1]->title = "Song B";
  songArray[1]->artist = "Artist A";
  songArray[1]->year = 2012;

  songArray[2] = new song;
  songArray[2]->title = "Song C";
  songArray[2]->artist = "Artist B";
  songArray[2]->year = 2012;

  songArray[3] = new song;
  songArray[3]->title = "Song D";
  songArray[3]->artist = "Artist C";
  songArray[3]->year = 2012;

  songArray[4] = new song;
  songArray[4]->title = "Song E";
  songArray[4]->artist = "Artist C";
  songArray[4]->year = 2012;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << songToString(songArray[i]) << endl;
  }

  const int YEAR = 2012;
  int resultSize;
  song ** filteredSongs = songsFromYear(songArray, ARRAY_SIZE, YEAR, &resultSize);

  cout << "Printing filtered songs from year " << YEAR << "..." << endl;
  for (int i = 0; i < resultSize; i++) {
    cout << songToString(filteredSongs[i]) << endl;
    delete songArray[i];
  }
  delete [] songArray;
}