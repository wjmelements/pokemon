#include "stats.h"

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class pokemon {
private:
    stats base_stats;   
public:
    pokemon(string name);
    void setStats(stats&);
    const stats& getStats() const;
    const string name;

    bool operator<(const pokemon&) const;
};
ostream& operator<<(ostream&, const pokemon&);
