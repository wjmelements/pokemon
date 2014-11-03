#include "bulba.h"

#include <stdlib.h>

#include <fstream>
using std::ifstream;

set<pokemon> report(string source) {
    set<pokemon> ret;
    ifstream input(source);
    pokemon* current = NULL;
    char* buffer = (char*) malloc(2000);
    string prefix("<td align=\"left\">");
    string lead("(Pokémon)\">");
    string follow("</a>");
    string statlead("<td style=\"background:#");
    string hp("FF5959");
    string atk("F5AC78");
    string def("FAE078");
    string spa("9DB7F5");
    string spd("A7DB8D");
    string speed("FA92B2");
    stats base;
    while (input.good()) {
        input.getline(buffer, 2000);
        string line(buffer);
        if (line.substr(0, prefix.size()) == prefix) {
            // declares pokemon
            if (current) {
                delete current;
            }
            size_t name_start = line.find(lead) + lead.size();
            size_t name_end = line.find(follow, name_start);
            string name = line.substr(name_start, name_end);
            current = new pokemon(name);
        } else if (line.substr(0, statlead.size()) == statlead) {
            string type = line.substr(statlead.size(), 6);
            string val_str = line.substr(statlead.size() + type.size() + 3);
            int val = atoi(val_str.c_str());
            if (type == hp) {
                base.hp = val;
            } else if (type == atk) {
                base.attack = val;
            } else if (type == def) {
                base.defense = val;
            } else if (type == spa) {
                base.special_attack = val;
            } else if (type == spd) {
                base.special_defense = val;
            } else if (type == speed) {
                base.speed = val;
                // this is the last one
                current->setStats(base);
                ret.insert(*current);
            }
        }

    }
    return ret;
}
