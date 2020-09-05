
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

enum Requests {
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
    if (quote == noRequest) {
        return "";
    }
    if (UserLangEntry == "en") {
        switch (quote) {
            case(IntroRequest):
                return "Please, choose two words to fuse together: ";
            case(Announcer01):
                return "First Word: ";
            case(confirm01):
                return " entered";
            case(Announcer02):
                return " Second Word: ";
            case(confirm02):
                return " second Word entered ready for fusion";
            case(resultAnnounceBegin):
                return "The fusion result of the words ";
            case(transitionResult):
                return " and ";
            case(declarationResult):
                return " is ";
            case(reverseQuestion):
                return "Should revert the result ?(press y or n)";
            case(yesReverse):
                return "The reverse of the result is: ";
            case(noReverse):
                return "Good Bye !";
            default:
                return "Invalid quote";
        }
    }
    else if (UserLangEntry == "fr") {
        switch (quote) {
        case(IntroRequest):
            return "Veuillez entrer deux mots que le logiciel fera fusionner: ";
        case(Announcer01):
            return "Premier mot: ";
        case(confirm01):
            return " a ete enregistre";
        case(Announcer02):
            return " Deuxieme mot: ";
        case(confirm02):
            return "a ete enregistre pour le processus de fusion.";
        case(resultAnnounceBegin):
            return "La fusion des mots ";
        case(transitionResult):
            return " et ";
        case(declarationResult):
            return " est ";
        case(reverseQuestion):
            return "Souhaitez-vous inverser le sens de lecture ?(taper o ou n)";
        case(yesReverse):
            return "Le resultat inverse donne : ";
        case(noReverse):
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
    Requests quote = noRequest;
    DyDia(quote, UserLangEntry);
        cout << DyDia(IntroRequest,UserLangEntry) << endl;
        cout << DyDia(Announcer01, UserLangEntry);
        getline(cin, word_1);
        cout << word_1 << DyDia(confirm01, UserLangEntry) << endl;
        cout << DyDia(Announcer02, UserLangEntry);
        getline(cin, word_2);
        cout << word_2 << DyDia(confirm02,UserLangEntry) << endl;
        string fusedWords = FuseWord(word_1, word_2);
        cout << DyDia(resultAnnounceBegin, UserLangEntry) << word_1 << DyDia(transitionResult, UserLangEntry);
        cout<< word_2 << DyDia(declarationResult,UserLangEntry) << fusedWords << endl;

        string UserEntry;

        cout << DyDia(reverseQuestion,UserLangEntry) << endl;
        getline(cin, UserEntry);
        if (UserLangEntry == "en") {
            if (UserEntry == "y" || UserEntry == "Y" | UserEntry == "Yes" || UserEntry == "yes" || UserEntry == "YES") {
                reverse(fusedWords.begin(), fusedWords.end());
                cout << DyDia(yesReverse, UserLangEntry) << fusedWords << endl;
            }
            else {
                cout << DyDia(noReverse, UserLangEntry);
            }
        }
        else if (UserLangEntry == "fr") {
            if (UserEntry == "o" || "O" || "oui" || "OUI" || "Oui") {
                reverse(fusedWords.begin(), fusedWords.end());
                cout << DyDia(yesReverse, UserLangEntry) << fusedWords << endl;
            }
            else {
                cout << DyDia(noReverse, UserLangEntry);
            }
        }
        
    return 0;
}
