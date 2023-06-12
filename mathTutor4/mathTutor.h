#ifndef mathTutor_H
#define mathTutor_H

using namespace std;

void DisplayWelcomeMsg();
void DisplayPreviousResults();

int GenerateQuestion(vector<int>& rowVector);
int GetUserAnswer(int realAnswer, int& totalCorrect );
void displayPercentCorrect(int totalQuestions, int& totalCorrect);
vector<int> AskMathQuestion (int& totalQuestions, int& totalCorrect);
string DoYouWantToContinue();
void DisplayResultsReport(const vector<vector<int>>& resultsVector);
void DisplayClosingMsg (int totalQuestions, int totalCorrect);
void SaveResults(const vector<vector<int>>& resultsVector);

#endif // mathTutor_H
