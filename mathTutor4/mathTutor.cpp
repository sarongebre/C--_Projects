
#include <cstdlib>//Adding the C standard utilities general to the library, to use the rand fun
#include <iostream>// Preprocessor directive adds the input output stream into the library
#include <limits>
#include <vector>//Adds the limits function to the library for checking if answer is a number or not
#include <ctime>

#include <fstream>
#include <ios>
#include <iomanip>

using namespace std; // used so that we don't use std:: for sin and cout statements

void DisplayWelcomeMsg() {


    cout << " Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math"  << endl << endl; //User friendly title
    cout << "*   ##     ##    ###    ######## ##     ##    ######## ##     ## ########  #######  ########      #######     *" << endl;
    cout << "*   ###   ###   ## ##      ##    ##     ##       ##    ##     ##    ##    ##     ## ##     ##    ##     ##    *" << endl;
    cout << "*   #### ####  ##   ##     ##    ##     ##       ##    ##     ##    ##    ##     ## ##     ##           ##    *" << endl;
    cout << "*   ## ### ## ##     ##    ##    #########       ##    ##     ##    ##    ##     ## ########      #######     *" << endl;
    cout << "*   ##     ## #########    ##    ##     ##       ##    ##     ##    ##    ##     ## ##   ##      ##           *" << endl;
    cout << "*   ##     ## ##     ##    ##    ##     ##       ##    ##     ##    ##    ##     ## ##    ##     ##           *" << endl;
    cout << "*   ##     ## ##     ##    ##    ##     ##       ##     #######     ##     #######  ##     ##    #########    *" << endl << endl;
    cout << " Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math_Math"  << endl << endl;

    cout << "\t \t \t \t \t Welcome to the MATH TUTOR GAME 2!!" << endl << endl; //user friendly title
    cout << "\t \t \t Are you ready to answer even more challenging mathematics questions!?" << endl << endl; //user friendly introduction
    cout << ".........................................................................................................." << endl << endl;
    cout << "These are the rules and description of the game:" << endl << endl;//Outputting the description of the game.
    cout << "1) Get ready to answer as many Mathematic questions you may want to try. You can stop the game when ever you like to." << endl;
    cout << "2) The mathematics questions include addition, subtraction, multiplication, or division." << endl;
    cout << "3) You get 3 attempts to answer each question correctly." << endl;
    cout << "4) If you don't get to answer the question with your 3 chances, that question will be considered wrong and will result";
    cout << "in a decrease in your overall score" << endl;
    cout << "5) You will see the total percentage score after each question you answered right or wrong." << endl;
    cout << "6) you will also see the total number of questions you have answered so far, and the total number of correct answers you got." << endl << endl;
    cout << "..........................................................................................................." << endl << endl;
    // cout << "Are you ready to do this!? Input \"Ready\" if you want to start the game" << endl ;
    //cout << "-->"; //user friendly arrow that shows only what the user is inputing.
//    cin  >> start;
    //cout << endl;


}

int GenerateQuestion (vector<int>& rowVector) {

    int random1 = 0;
    int random2 = 0;
    int randomOperator = 0;
    char questionOperator;
    int realAnswer = 0 ;
    int temp = 0;

    srand(time(0));

//while (x < )

    random1  = (rand() % 10) + 1;// Assign random1 to rand() % 10: restrict the random1 value from 1 to 10 numbers
    random2  = (rand() % 10) + 1;// Assign random2 to rand() % 10: restrict the random1 value from 1 to 10 numbers
    randomOperator = rand() % 4;

    switch (randomOperator) { //switch statement that randomly chooses a case based on randomOp value expression

    case 0://for addition
        questionOperator = '+';// Assigns the question operator to variable qOperator
        realAnswer = random1 + random2; //assigning real correct answer to variable realOpAns
        break; //stops going into other cases and gets out of the switch statement

    case 1://for subtraction
        questionOperator = '-';

        if (random1 < random2) { //Using the if statement and assigning variables so that random2 will take random1's value if random 1 is greater that random2
            temp = random1;
            random1 = random2;
            random2 = temp;
        }

        realAnswer = random1 - random2;
        break;

    case 2: //multiplication
        questionOperator = '*';
        realAnswer = random1 * random2;//assigning the real correct answer to the variable realOpAns
        break;

    case 3: //division
        questionOperator = '/';
        realAnswer = random1;
        random1 = random1 * random2;//Making sure that there won't be decimal quotients. Only integers.
        break;

    default : //for safety purpose incase there happens to be a bug with in the switch statement or cases that doesn't meet the input
        cout << "error, invalid question type" <<endl;
        //if invalid question type
        break;

    }

//        vector<int> row;
    rowVector.push_back(random1);
    rowVector.push_back(random2);
    rowVector.push_back(randomOperator);
    //row.push_back(userAnswer);
    //totalQuestions = totalQuestions + 1;
    cout << "(Q" << ") " << random1 << " " << questionOperator <<" " << random2 <<" =" << "______" << endl;//Outputing the mathematic question for the uses

    return realAnswer;
}


int GetUserAnswer(int realAnswer, int& totalCorrect) {

    int userAnswer;


    for (int i = 2; i >= 0; --i ) { //For loop so that user can only have 3 attempts per question

        while (!(cin >> userAnswer)) {
            cin.clear(); //this clears the input error
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "You have entered an invalid input like a character, please enter a number " << endl;
        }

        if (userAnswer == realAnswer) {
            //totalCorrectAns++;
            totalCorrect = totalCorrect + 1;
            cout << "____________________________________________" << endl;
            cout << "Bravo! You have answered the question right!" << endl;
            break;
        } else { //if user answer is not equal to real answer, the statements below will execute

            if (i > 0) { //As I in the for loop decrements, as long as i is greater than 0, this else statement will continue to execute every time the for loops loops.
                cout << "_________________________________________________________________________________________" << endl;
                cout << "Sorry your answer is not correct. Please try again." << endl;
                cout << "Don't forget that you have >> " << i << " << attempts left. Take your time, don't rush:-)" << endl;
                cout << "_________________________________________________________________________________________" << endl << "-->";
            }
        }

        if (i == 0) { // if i equals to zero, this means that the user have used all 3 of his/her attempts so the output statements below will execute
            cout << "______________________________________________________________________" << endl;
            cout << "Sorry,you have used all attempts for this question, the answer was " << realAnswer << endl; //output the question's answer and having no attempts
        }
    }

    return userAnswer;
}


void displayPercentCorrect(int& totalQuestions, int& totalCorrect) {

    int percentage = 0;
//totalQuestions = totalQuestions + 1;

    percentage = totalCorrect * 100 / totalQuestions;
    cout << "this is the total correct answer you got  " << totalCorrect << endl;
    cout << "this is the total number of questions you have attempted " << totalQuestions <<endl;

    cout << "This is the percentage  " <<percentage;
}

vector<int> AskMathQuestion(int& totalQuestions, int& totalCorrect) {

    vector<int> rowVector;

    int realAnswer = GenerateQuestion(rowVector);

    rowVector.push_back(GetUserAnswer(realAnswer, totalCorrect));

    displayPercentCorrect(totalQuestions, totalCorrect);

    return rowVector;
}

string DoYouWantToContinue() {
    string userCont = "y";



    cout << endl <<"____________________________________________"  << endl;//use friendly line
    cout << "Do you want to keep on playing? \"Yes\" or \"No\"" << endl; //prompting the user if he/she wants to continue the game or not
    cout << "-->";
    cin  >> userCont; //where the user enters either y to go loop the while loop again or enter n to get out of the while loop and stop the game
    cout << endl;

    while ((tolower(userCont.at(0)) != 'y') & (tolower(userCont.at(0) != 'n'))) {
        cout << "invalid input. Please enter a word that starts with either y or n";
        cin  >> userCont; //where the user answer is stored
    }

    return userCont;
}


void DisplayResultsReport(const vector<vector<int>>& resultsVector) {

    char questionOperator;
    int realAnswer;

    cout << "Question " << setw(10) <<"answer "<< setw(10) << " result"  << endl <<endl;


    for (int i = 0; i < resultsVector.size(); ++i) {

        switch (resultsVector.at(i).at(2)) {

        case 0:
            questionOperator = '+';
            realAnswer = resultsVector.at(i).at(0) + resultsVector.at(i).at(1);
            break;

        case 1:
            questionOperator = '-';
            realAnswer = resultsVector.at(i).at(0) - resultsVector.at(i).at(1);
            break;

        case 2:
            questionOperator = '*';
            realAnswer = resultsVector.at(i).at(0) * resultsVector.at(i).at(1);
            break;

        case 3:
            questionOperator = '/';
            realAnswer = resultsVector.at(i).at(0) / resultsVector.at(i).at(1);
            break;
        default:
            cout <<"error, invalid question type";
            break;
        }

        if (resultsVector.at(i).at(3) == realAnswer) {
            cout  << "Correct! Yeeppy! " << setw(5) <<resultsVector.at(i).at(0) <<" "<< questionOperator<< " " <<resultsVector.at(i).at(1)<< setw(5) << " = "<< setw(5) << resultsVector.at(i).at(3) << endl ;
        }

        else {
            cout << "Incorrect! Oh no! ";
            cout << setw(5) << resultsVector.at(i).at(0) <<" "<< questionOperator << " " <<resultsVector.at(i).at(1)<< setw(5) <<" = "<< setw(5) <<resultsVector.at(i).at(3) << setw(5) << " The correct answer is " << realAnswer << endl;
        }
    }

    cout << "  ";
}

void DisplayClosingMsg (int totalQuestions, int totalCorrect) {
    int percentage;
    percentage = (totalCorrect * 100 )/ totalQuestions;

    cout << endl;
    cout << "\t \t \t \t  Good practice! Your overall score is " << percentage << "%" << endl;
    cout << "\t \t Total questions attempted = " << totalQuestions << "     Correct questions";
    cout <<" answered = " << totalCorrect << endl;
    cout << "Thank you for playing! Please play again next time in order to beat your previous score! See you soon!" << endl << endl;
    cout << "........................................................................................................";


}

void SaveResults(const vector<vector<int>>& resultsVector) {

    ofstream outFS; // Output file stream

    outFS.open("userScoreResults.txt");

    if (!outFS.is_open()) {
        throw runtime_error("Could not open file userScoreResults.txt for writing");
    }

    for(int i = 0; i < resultsVector.size(); i++) {

        outFS << resultsVector.at(i).at(0) << " "
              << resultsVector.at(i).at(1) << " "
              << resultsVector.at(i).at(2) << " "
              << resultsVector.at(i).at(3) << endl;

    }
    // Done with file, so close it
    outFS.close();

    return;

}

void DisplayPreviousResults() {

    vector<vector<int> >(previousResults);
    int random1 = 0;
    int random2 = 0;
    int randomOperator = 0;
    int userAnswer = 0 ;
    ifstream inFS;

    inFS.open("userScoreResults.txt");

    if (!inFS.is_open()) {

        cout <<"you have not played before, good luck on your first try!" <<endl;
        //throw runtime_error("userScoreResults.txt");

        return;

        //else please better
    } else {

        cout << "looks like you have played before! Come on try to beat your previous scores. These are your previous scores" <<endl;
    }

    while (inFS >> random1 >> random2 >> randomOperator >> userAnswer) {

        vector<int> row;
        row.push_back(random1);
        row.push_back(random2);
        row.push_back(randomOperator);
        row.push_back(userAnswer);
        previousResults.push_back(row);

    }

    if (!inFS.eof()) {
        throw runtime_error("Something went wrong reading the results.txt file.");
    }

    // Done with file, so close it
    inFS.close();

    DisplayResultsReport(previousResults);
}









