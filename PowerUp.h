#ifndef POWERUP_H
#define POWERUP_H


class PowerUp{
    public:
        virtual void applyPower(int score) = 0;
        virtual bool isActive()  const = 0;
        virtual void reset() = 0;
        virtual ~PowerUp() {}
};


#endif
