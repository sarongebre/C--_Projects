#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>



#include "mathTutor.h";

using namespace std;


int main() {
    int totalCorrect = 0;
    int totalQuestions = 0;

    vector<vector<int>> resultsVector;

    string userCont = "y";

    srand(time(0));

    try {

        DisplayWelcomeMsg();

        DisplayPreviousResults();
        cout << endl;


        while (tolower(userCont.at(0)) == 'y') {
            totalQuestions++;

            resultsVector.push_back(AskMathQuestion(totalQuestions, totalCorrect));

            userCont = DoYouWantToContinue();
        }

        DisplayResultsReport(resultsVector);

        SaveResults(resultsVector);

        DisplayClosingMsg (totalQuestions, totalCorrect);
    }

    catch (runtime_error &excpt) {
        cout << excpt.what()<< endl;
        cout <<"There is a runtime or a compiler error" << endl;

    }


    cout << "bye bye";
    return 0;
}
