class Takim{
    public:
        Takim();
        Takim(char player1, char player2);
        Takim(const Takim& t1);
        char getter(int i); //i == player number
        void setter(char p1, char p2);
        const Takim& operator =(const Takim& t1);
        friend bool operator ==(const Takim& t1, const Takim& t2);
        friend bool operator !=(const Takim& t1, const Takim& t2);
    private:
        char player1, player2;
};