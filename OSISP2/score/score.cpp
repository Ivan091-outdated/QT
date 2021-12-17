#include "score.h"
score::score()
{
    pScore = 0;
}

score::score(int sc)
{
    pScore = sc;
}

score::~score()
{

}

score::score(const score &obj)
{
    pScore = obj.pScore;
}

int score::getScore()
{
    return pScore;
}

void score::setScore(int sc)
{
    pScore = sc;
}

int score::plusScore()
{
    return pScore++;
}
