#include "stats.h"
#include <stdlib.h>
int stats::total()  const {
    return hp + attack + defense + special_attack + special_defense + speed;
}
int stats::value() const {
    return total() + abs(attack - defense);
}
