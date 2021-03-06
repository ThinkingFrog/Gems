#include <cstdlib>
#include "Field.h"
#include "Bonus.h"
#include "Main.h"

//Major function that runs all deletion of 3+ matching gems
bool Field::CheckFieldForMatching() {
    matching.clear();
    bool found = false;

    for (unsigned j = 0; j < gemsInColumn; j++) {
        for (unsigned i = 0; i < gemsInRow; i++) {
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
        gemsMatrix[matching[k][1]][matching[k][0]].SetEmpty();
    }
}

//Supporting function for CheckMatch function that ensures that given gem wasn't already flaged
bool Field::AlreadyMatched(unsigned i, unsigned j) {
    for (unsigned k = 0; k < matching.size(); k++)
        if (matching[k][0] == i && matching[k][1] == j)
            return true;
    return false;
}

//recursive function to find all matching neighbours of a gem
void Field::CheckMatch(unsigned i, unsigned j) {

    //if gem already empty - skip it
    if (gemsMatrix[j][i].IsEmpty())
        return;

    //Checking upper element
    if (j != 0)
        if (gemsMatrix[j][i].GetColor() == gemsMatrix[j - 1][i].GetColor())
            if (!AlreadyMatched(i, j - 1)) {
                matching.push_back({ i, j - 1 });
                CheckMatch(i, j - 1);
            }

    //Checking right element
    if (i != gemsInRow - 1)
        if (gemsMatrix[j][i].GetColor() == gemsMatrix[j][i + 1].GetColor())
            if (!AlreadyMatched(i + 1, j)) {
                matching.push_back({ i + 1, j });
                CheckMatch(i + 1, j);
            }

    //Checking bottom element
    if (j != gemsInColumn - 1)
        if (gemsMatrix[j][i].GetColor() == gemsMatrix[j + 1][i].GetColor())
            if (!AlreadyMatched(i, j + 1)) {
                matching.push_back({ i, j + 1 });
                CheckMatch(i, j + 1);
            }

    //Checking left element
    if (i != 0)
        if (gemsMatrix[j][i].GetColor() == gemsMatrix[j][i - 1].GetColor())
            if (!AlreadyMatched(i - 1, j)) {
                matching.push_back({ i - 1, j });
                CheckMatch(i - 1, j);
            }
}