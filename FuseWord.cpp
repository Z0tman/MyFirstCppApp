#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string FuseWord(string word_1, string word_2) {
    //set words length
    int n = word_1.length();
    int m = word_2.length();

    //set fusion condition as general operator list from which we will get the character to remove in the end
    string LettersToDeleteWord = "";
    for (int i_2 = 0; i_2 < n; i_2++) {
        for (int j_2 = 0; j_2 < m; j_2++) {
            if (word_1[i_2] == word_2[j_2]) {
                LettersToDeleteWord += word_1[i_2];
            }
        }
    }
    //treatment of the words before fusion.
    for (int k = 0; k < LettersToDeleteWord.size(); k++) {
        word_1.erase(remove(word_1.begin(), word_1.end(), LettersToDeleteWord[k]), word_1.end());
        word_2.erase(remove(word_2.begin(), word_2.end(), LettersToDeleteWord[k]), word_2.end());
    }
    //define result variable to return after processing his value
    string result = "";
    result.append(word_1);
    result.append(word_2);
    return result;
}

int main()
{
    //set local variable for the application

    string word_1, word_2;

    //set language application settings
    string UserLangEntry;
    cout << "lang option: (francais: fr - anglais: en): ";
    getline(cin, UserLangEntry);
    if (UserLangEntry == "en") {
        //set words request
        cout << "Please, choose two words to fuse together: " << endl;
        cout << "First Word: ";
        getline(cin, word_1);
        cout << "First word " << word_1 << " entered" << endl;
        cout << " Second Word: ";
        getline(cin, word_2);
        cout << "Second Word entered ready for fusion" << endl;
        //output the fusion result
        string fusedWords = FuseWord(word_1, word_2);
        cout << "The fusion result of the words " << word_1 << " and " << word_2 << " is " << fusedWords << endl;

        //set user reverse option request
        string UserEntry;

        cout << "Should revert the result ?(press y or n)" << endl;
        getline(cin, UserEntry);
        if (UserEntry == "y" || "Y" || "yes" || "YES" || "Yes") {
            reverse(fusedWords.begin(), fusedWords.end());
            cout << "The reverse of the result is: " << fusedWords << endl;
        }
        else {
            cout << "Good Bye !" << endl;
        }
    }
    //same process with french language instructions
    else if (UserLangEntry == "fr") {
        cout << "Veuillez entrer deux mots que le logiciel fera fusionner: " << endl;
        cout << "Premier mot: ";
        getline(cin, word_1);
        cout << "Le premier mot " << word_1 << "est enregistre pour le processus de fusion" << endl;
        cout << " Deuxieme mot: ";
        getline(cin, word_2);
        cout << "Le deuxieme mot" << word_2 << " est enregitre pour le processus de fusion" << endl;
        string fusedWords = FuseWord(word_1, word_2);
        cout << "La fusion des mots " << word_1 << " et " << word_2 << " est " << fusedWords << endl;

        string UserEntry;


        cout << "Souhaitez-vous inverser le sens de lecture ?(taper o ou n)" << endl;
        getline(cin, UserEntry);
        if (UserEntry == "o" || "O" || "oui" || "OUI" || "Oui") {
            reverse(fusedWords.begin(), fusedWords.end());
            cout << "Le resultat inverse donne : " << fusedWords << endl;
        }
        else {
            cout << "Au revoir !" << endl;
        }
    }
    return 0;
}
