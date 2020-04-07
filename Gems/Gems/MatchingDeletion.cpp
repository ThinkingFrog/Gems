#include "Field.h"

//global vector of matching gems, refreshed each time for a new combination
std::vector <std::array <unsigned, 2>> matching;

//Major function that runs all deletion of 3+ matching gems
bool Field::CheckFieldForMatching(void) {
    matching.clear();
    bool found = false;

    for (unsigned i = 0; i < gemsInColumn; i++) {
        for (unsigned j = 0; j < gemsInRow; j++) {
            matching.push_back({ i, j });
            CheckMatch(i, j);
            if (matching.size() >= 3)
                found = true;
            else
                if (!matching.empty())
                    matching.clear();
            if (found == true)
                break;
        }
        if (found == true)
            break;
    }

    FieldDeletion(matching);
    return found;
}

//Deleting all gems in given vector
void Field::FieldDeletion(std::vector <std::array <unsigned, 2>> matching) {
    for (unsigned k = 0; k < matching.size(); k++) {
        gemsMatrix[matching[k][0]][matching[k][1]].SetEmpty();
    }
}

//Supporting function for CheckMatch function that ensures that given gem wasn't already flaged
bool AlreadyMatched(unsigned i, unsigned j) {
    for (unsigned k = 0; k < matching.size(); k++)
        if (matching[k][0] == i && matching[k][1] == j)
            return true;
    return false;
}

//recursive function to find all matching neighbours of a gem
void Field::CheckMatch(unsigned i, unsigned j) {

    //if gem already empty - skip it
    if (gemsMatrix[i][j].IsEmpty())
        return;

    //Checking upper element
    if (j != 0)
        if (gemsMatrix[i][j].GetColor() == gemsMatrix[i][j - 1].GetColor())
            if (!AlreadyMatched(i, j - 1)) {
                matching.push_back({ i, j - 1 });
                CheckMatch(i, j - 1);
            }

    //Checking right element
    if (i != gemsInRow - 1)
        if (gemsMatrix[i][j].GetColor() == gemsMatrix[i + 1][j].GetColor())
            if (!AlreadyMatched(i + 1, j)) {
                matching.push_back({ i + 1, j });
                CheckMatch(i + 1, j);
            }

    //Checking bottom element
    if (j != gemsInColumn - 1)
        if (gemsMatrix[i][j].GetColor() == gemsMatrix[i][j + 1].GetColor())
            if (!AlreadyMatched(i, j + 1)) {
                matching.push_back({ i, j + 1 });
                CheckMatch(i, j + 1);
            }

    //Checking left element
    if (i != 0)
        if (gemsMatrix[i][j].GetColor() == gemsMatrix[i - 1][j].GetColor())
            if (!AlreadyMatched(i - 1, j)) {
                matching.push_back({ i - 1, j });
                CheckMatch(i - 1, j);
            }
}

void Field::FieldDrop(void) {
    for (unsigned i = 0; i < gemsInColumn - 1; i++)
        for (unsigned j = 0; j < gemsInRow; j++)
            if (gemsMatrix[i + 1][j].IsEmpty()) {
                gemsMatrix[i + 1][j].SetColor(gemsMatrix[i][j].GetColor());
                gemsMatrix[i][j].SetEmpty();
            }
}