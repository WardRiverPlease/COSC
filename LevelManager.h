    #ifndef LEVELMANAGER_H
    #define LEVELMANAGER_H

    class LevelManager {
        private:
            int currentLevel;
            int score;

        public:
            LevelManager();
            int getScore() const;
            int getCurrentLevel() const;
            int resetScore();
            void increaseLevel();
            void increaseScore(int amount);






    };

    #endif
