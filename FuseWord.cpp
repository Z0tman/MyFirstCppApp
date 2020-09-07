#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string FuseWord(string word_1, string word_2) {
    int n = word_1.length();
    int m = word_2.length();
    int i = 0;
    int j = 0;

    string LettersToDeleteWord = "";
    for (int i_2 = 0; i_2 < n; i_2++) {
        for (int j_2 = 0; j_2 < m; j_2++) {
            if (word_1[i_2] == word_2[j_2]) {
                LettersToDeleteWord += word_1[i_2];
            }
        }
    }

    for (int k = 0; k < LettersToDeleteWord.size(); k++) {
        word_1.erase(remove(word_1.begin(), word_1.end(), LettersToDeleteWord[k]), word_1.end());
        word_2.erase(remove(word_2.begin(), word_2.end(), LettersToDeleteWord[k]), word_2.end());
    }

    string result = "";
    result.append(word_1);
    result.append(word_2);
    return result;
}

enum class Requests {
    noRequest,
    IntroRequest,
    Announcer01,
    confirm01,
    Announcer02,
    confirm02,
    resultAnnounceBegin,
    transitionResult,
    declarationResult,
    reverseQuestion,
    yesReverse,
    noReverse,
};


string DyDia(Requests quote, string UserLangEntry) {
    if (quote == Requests::noRequest) {
        return "";
    }
    if (UserLangEntry == "en") {
        switch (quote) {
        case(Requests::IntroRequest):
            return "Please, choose two words to fuse together: ";
        case(Requests::Announcer01):
            return "First Word: ";
        case(Requests::confirm01):
            return " entered";
        case(Requests::Announcer02):
            return " Second Word: ";
        case(Requests::confirm02):
            return " second Word entered ready for fusion";
        case(Requests::resultAnnounceBegin):
            return "The fusion result of the words ";
        case(Requests::transitionResult):
            return " and ";
        case(Requests::declarationResult):
            return " is ";
        case(Requests::reverseQuestion):
            return "Should revert the result ?(press y or n)";
        case(Requests::yesReverse):
            return "The reverse of the result is: ";
        case(Requests::noReverse):
            return "Good Bye !";
        default:
            return "Invalid quote";
        }
    }
    else if (UserLangEntry == "fr") {
        switch (quote) {
        case(Requests::IntroRequest):
            return "Veuillez entrer deux mots que le logiciel fera fusionner: ";
        case(Requests::Announcer01):
            return "Premier mot: ";
        case(Requests::confirm01):
            return " a ete enregistre";
        case(Requests::Announcer02):
            return " Deuxieme mot: ";
        case(Requests::confirm02):
            return "a ete enregistre pour le processus de fusion.";
        case(Requests::resultAnnounceBegin):
            return "La fusion des mots ";
        case(Requests::transitionResult):
            return " et ";
        case(Requests::declarationResult):
            return " est ";
        case(Requests::reverseQuestion):
            return "Souhaitez-vous inverser le sens de lecture ?(taper o ou n)";
        case(Requests::yesReverse):
            return "Le resultat inverse donne : ";
        case(Requests::noReverse):
            return "Au revoir !";
        default:
            return "citation invalid";
        }
    }
}

int main()
{
    string word_1, word_2;

    string UserLangEntry;
    cout << "lang option: (francais: fr - anglais: en): ";
    getline(cin, UserLangEntry);
    Requests quote = Requests::noRequest;
    DyDia(quote, UserLangEntry);
    cout << DyDia(Requests::IntroRequest, UserLangEntry) << endl;
    cout << DyDia(Requests::Announcer01, UserLangEntry);
    getline(cin, word_1);
    cout << word_1 << DyDia(Requests::confirm01, UserLangEntry) << endl;
    cout << DyDia(Requests::Announcer02, UserLangEntry);
    getline(cin, word_2);
    cout << word_2 << DyDia(Requests::confirm02, UserLangEntry) << endl;
    string fusedWords = FuseWord(word_1, word_2);
    cout << DyDia(Requests::resultAnnounceBegin, UserLangEntry) << word_1 << DyDia(Requests::transitionResult, UserLangEntry);
    cout << word_2 << DyDia(Requests::declarationResult, UserLangEntry) << fusedWords << endl;

    string UserEntry;

    cout << DyDia(Requests::reverseQuestion, UserLangEntry) << endl;
    getline(cin, UserEntry);
    if (UserLangEntry == "en") {
        if (UserEntry == "y" || UserEntry == "Y" | UserEntry == "Yes" || UserEntry == "yes" || UserEntry == "YES") {
            reverse(fusedWords.begin(), fusedWords.end());
            cout << DyDia(Requests::yesReverse, UserLangEntry) << fusedWords << endl;
        }
        else {
            cout << DyDia(Requests::noReverse, UserLangEntry);
        }
    }
    else if (UserLangEntry == "fr") {
        if (UserEntry == "o" || UserEntry == "O" || UserEntry == "oui" || UserEntry == "OUI" || UserEntry == "Oui") {
            reverse(fusedWords.begin(), fusedWords.end());
            cout << DyDia(Requests::yesReverse, UserLangEntry) << fusedWords << endl;
        }
        else {
            cout << DyDia(Requests::noReverse, UserLangEntry);
        }
    }

    return 0;
}
