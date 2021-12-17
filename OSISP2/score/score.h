#ifndef SCORE_H
#define SCORE_H


class score
{
private:
    int pScore;
public:
    score();
    score(int sc);
    ~score();
    score(const score &obj);

    int getScore();
    void setScore(int sc);

    int plusScore();
};



#endif // SCORE_H
