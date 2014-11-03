#include "pokemon.h"
pokemon::pokemon(string _name): name(_name) {
}
void pokemon::setStats(stats& other) {
    base_stats = other;
}
const stats& pokemon::getStats() const {
    return base_stats;
}
bool pokemon::operator<(const pokemon& other) const {
    if (base_stats.value() < other.base_stats.value()) {
        return true;
    }
    if (base_stats.value() > other.base_stats.value()) {
        return false;
    }
    return name < other.name;
}
ostream& operator<<(ostream& out, const pokemon& pokemon) {
    out << pokemon.getStats().value();
    out << ' ';
    out << pokemon.name;
}
