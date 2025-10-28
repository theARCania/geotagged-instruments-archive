#include "location.h"
#include "song.h"
#include <string>
#include <vector>

std::vector<Location> locations; // Definition of global variable

Location *find_location(const std::string &name)
{
    for (auto &loc : locations)
    {
        if (loc.name == name)
            return &loc;
    }
    return nullptr;
}

Location *add_or_get_location(const std::string &name)
{
    Location *loc = find_location(name);
    if (loc)
        return loc;
    Location newLoc;
    newLoc.name = name;
    locations.push_back(newLoc);
    return &locations.back();
}

void link_song_to_location(const std::string &song_id, const std::string &loc_name)
{
    Location *loc = add_or_get_location(loc_name);
    loc->song_ids.push_back(song_id);
}

std::vector<std::string> get_song_ids_in_location(const std::string &loc_name)
{
    Location *loc = find_location(loc_name);
    if (!loc)
        return {};
    return loc->song_ids;
}
