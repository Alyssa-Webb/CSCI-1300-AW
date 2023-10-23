#include <iostream>

using namespace std;


int main ()
{

//declare variables
int genre;
int author;
int book_titles;

//user input for genre
cout << "Select the genre: (1) Mystery (2) Science" << endl;
cin >> genre;
       
 if ((genre < 0) || (genre > 2))
 {
    cout << "Please enter a valid input" << endl;
    return 0;
 }


switch (genre) 
{
    case 1: // user input Mystery
        cout << "Select the Author: (1) Agatha Christie (2) Arthur Conan Doyle (3) Stephen King" << endl;
        cin >> author;

        switch (author) 
        { 
            case 1: // Christie
                cout << "Select the Book Title: (1) Hercule Poirot (2) Miss Marple Detective" << endl;
                cin >> book_titles;
                
                switch (book_titles) 
                {
                    case 1:
                        cout << "You have ordered Hercule Poirot" << endl;
                        break;                        
                    case 2:
                        cout << "You have ordered Miss Marple Detective" << endl;
                        break;
                    default: // Invalid Book Title Input
                        cout << "Please enter a valid input" << endl;
                        break;
                }

            break;

            case 2: // Doyle
                cout << "Select the Book Title: (1) The Memoirs of Sherlock Holmes (2) Tales of Terror and Mystery" << endl;
                cin >> book_titles;
                
                switch (book_titles) 
                {
                    case 1:
                        cout << "You have ordered The Memoirs of Sherlock Holmes" << endl;
                        break;

                    case 2:
                        cout << "You have ordered Tales of Terror and Mystery" << endl;
                        break;
                    default: // Invalid Book Title Input
                        cout << "Please enter a valid input" << endl;
                        break;

                }



            break;

            case 3: // King
                cout << "Select the Book Title: (1) The Institute (2) Misery" << endl;
                cin >> book_titles;
                
                switch (book_titles) 
                {
                    case 1:
                        cout << "You have ordered The Institute" << endl;
                        break;

                    case 2:
                        cout << "You have ordered Misery" << endl;
                        break;

                    default: // Invalid Book Title Input
                        cout << "Please enter a valid input" << endl;
                        break;                       
                }

            break;

            default: // Invalid Author Input
                cout << "Please enter a valid input" << endl;
                
            break;
        }

        break;

    case 2: // user input Science
        cout << "Select the Author: (1) Stephen Hawking (2) Carl Sagan (3) Mary Roach" << endl;
        cin >> author;

        switch (author) 
        { 
            case 1: //Hawking
                cout << "Select the Book Title: (1) A Brief History of Time (2) The Universe in a Nutshell" << endl;
                cin >> book_titles;
                
                switch (book_titles) 
                {
                    case 1:
                        cout << "You have ordered A Brief History of Time" << endl;
                        break;

                    case 2:
                        cout << "You have ordered The Universe in a Nutshell" << endl;
                        break;

                    default: // Invalid Book Title Input
                        cout << "Please enter a valid input" << endl;
                        break;                       
                }

            break;

            case 2: // Sagan
                cout << "Select the Book Title: (1) Cosmos (2) Pale Blue Dot" << endl;
                cin >> book_titles;

                switch (book_titles) 
                {
                    case 1:
                        cout << "You have ordered Cosmos" << endl;
                        break;

                    case 2:
                        cout << "You have ordered Pale Blue Dot" << endl;
                        break;

                    default: // Invalid Book Title Input
                        cout << "Please enter a valid input" << endl;
                        break;                       
                }

            break;

            case 3: // Roach
                cout << "Select the Book Title: (1) Stiff: The Curious Lives of Human Cadavers (2) Gulp: Adventures on the Alimentary Canal" << endl;
                cin >> book_titles;

                switch (book_titles) 
                {
                    case 1:
                        cout << "You have ordered Stiff: The Curious Lives of Human Cadavers" << endl;
                        break;

                    case 2:
                        cout << "You have ordered Gulp: Adventures on the Alimentary Canal" << endl;
                        break;

                    default: // Invalid Book Title Input
                        cout << "Please enter a valid input" << endl;
                        break;                       
                }                

            break;

            default: // Invalid Author Input
                cout << "Please enter a valid input" << endl;
                
             break;

        }
    break;
        
    default: //invalid Genre Input 
        cout << "Please enter a valid input" << endl;
                
    break;
        
}

}


