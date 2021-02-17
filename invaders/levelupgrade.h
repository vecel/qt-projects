#ifndef LEVELUPGRADE_H
#define LEVELUPGRADE_H

#include "upgradeitem.h"

class LevelUpgrade: UpgradeItem
{
public:
    LevelUpgrade();
    void onPlayerCollision(); // inherited from UpgradeItem
};

#endif // LEVELUPGRADE_H
