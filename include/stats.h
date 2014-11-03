struct stats {
    int hp;
    int attack;
    int defense;
    int special_attack;
    int special_defense;
    int speed;

    int total() const;
    int value() const;
};
