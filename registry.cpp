#include "registry.h"

using namespace std;
static vector<Song> reg;
string add_song_reg(const Song &s)
{
    for (const Song &x : reg)
    {
        if (x.title == s.title && x.uploader == s.uploader && x.duration == s.duration)
        {
            return "";
        }
    }
    reg.push_back(s);
    return s.id;
}
bool has_fp(const string &dummy)
{
    return false;
}
Song get_song_by_id(const string &id)
{
    for (const Song &x : reg)
    {
        if (x.id == id)
            return x;
    }
    return Song();
}
vector<Song> get_all_songs()
{
    return reg;
}
vector<Song> find_by_title(const string &title)
{
    vector<Song> out;
    for (const Song &x : reg)
    {
        if (x.title == title)
            out.push_back(x);
    }
    return out;
}
