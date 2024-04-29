#ifndef DOUBLESCORE_H
#define DOUBLESCORE_H

#include "PowerUp.h"

class DoubleScore : public PowerUp {
private:
    bool active;

public:
    DoubleScore();
    virtual void applyPower(int score) override;
    virtual bool isActive() const override;
    virtual void reset() override;
};

#endif // DOUBLESCORE_H
