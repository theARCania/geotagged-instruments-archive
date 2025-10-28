#ifndef REGISTRY_H
#define REGISTRY_H

#include <string>
#include <vector>
#include "song.h"

using namespace std;
string add_song_reg(const Song &s);
bool has_fp(const string &fp);
Song get_song_by_id(const string &id);
vector<Song> get_all_songs();
vector<Song> find_by_title(const string &title);

#endif
