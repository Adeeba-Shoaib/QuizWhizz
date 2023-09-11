#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void CoutCentered(string);
void CoutCentered(int);
void CoutCentered(string, int);

enum color
{
    NONE,
    DARK_BLUE,
    GREEN,
    DARK_CYAN,
    DARK_RED,
    PURPLE,
    DARK_YELLOW,
    NORMAL,
    GRAY,
    BLUE,
    LIME,
    CYAN,
    RED,
    PINK,
    YELLOW,
    WHITE
};
void setcolor(color c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (c));
    /*SetConsoleTextAttribute function is used to change the text attributes (such as text color and background color) in a console window.
    GetStdHandle(STD_OUTPUT_HANDLE) retrieves the handle (a unique identifier,typically a pointer) of the standard output console.
    It's a way of saying "we want to change the attributes (here colour) of the console's text.*/
}

class Student
{
public:
    string name;
    int rollno;

    Student();
    void welcome();
    void putScore(int);
    void showDetails();
    int readFile();
};
Student::Student()
{
    system("CLS");
    setcolor(BLUE);
    cout << "Enter your name:";
    cin >> name;
    system("CLS");
    setcolor(YELLOW);
    cout << "enter roll no:";
    cin >> rollno;
    system("CLS");
}
void Student::welcome()
{
    system("CLS");
    setcolor(GREEN);
    cout << "\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  " << endl;
    cout << "\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ " << endl;
    cout << "\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ " << endl;
    cout << "\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| " << endl;
    _getch();
    system("CLS");
}
void Student::putScore(int score)
{
    fstream f("history.csv", ios::in | ios::out | ios::app);
    for (int i = 0; i < name.length(); i++)
        f << name[i];
    f << ',' << rollno << ',' << score << ',' << '\n';
    f.close();
}
void Student::showDetails()
{
    /*this function reads a CSV file line by line, separates the values by commas
    and displays them in a tabular format with columns for "NAME," "ROLL NUMBER," and "SCORE."
    It also waits for a key press and clears the screen after displaying the data.*/
    fstream f;
    f.open("history.csv", ios::in);
    cout << "NAME                "
         << "ROLL NO   "
         << "SCORE" << '\n';
    while (!f.eof())
    {
        string s;
        getline(f, s);
        vector<string> record;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ',')
            {
                record.push_back(s.substr(j, i - j));
                j = i + 1;
            }
        }
        cout << record[0];
        for (int i = 0; i < 20 - record[0].size(); i++)
            cout << " ";
        cout << record[1];
        for (int i = 0; i < 10 - record[1].size(); i++)
            cout << " ";
        cout << record[2];
        cout << '\n';
    }
    getch();
    system("CLS");
}
int Student::readFile()
{
    int score = 0;
    fstream f("data-1.csv", ios::in);
    f.seekg(std::ios::beg); // move the cursor to the beginning of the file
    f.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // skip over all characters until the first newline character is encountered, effectively "jumping over" the first line of the file

    Beep(450, 650); // it will produce a short beep sound with a frequency of 450 Hz and a duration of 650 milliseconds.
    while (!f.eof())
    {
        string s="";
        getline(f, s);
        vector<string> record;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '$'){
                record.push_back(s.substr(j, i - j));
                j = i + 1;
            }
        }

        int maxtime = stoi(record[7]); // it takes the string from record[7], converts it into an integer, and assigns that integer value to the variable maxtime

        while (maxtime != 0)
        {
            system("CLS");
            setcolor(RED);
            CoutCentered(maxtime);
            setcolor(NORMAL);
            cout << "Question " << record[0] << ")" << record[1] << "\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            cout << "1)" << record[2] << endl
                 << endl;
            cout << "2)" << record[3] << endl
                 << endl;
            cout << "3)" << record[4] << endl
                 << endl;
            cout << "4)" << record[5] << endl
                 << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL);
            if (kbhit())
            {
                char ch = getch();
                if (record[ch - '0' + 1] == record[6])
                {
                    score += stoi(record[8]);
                    setcolor(GREEN);
                    CoutCentered("CORRECT ANSWER :)");
                }
                else
                {
                    setcolor(RED);
                    CoutCentered("WRONG ANSWER :(");
                }
                setcolor(NORMAL);
                getch();
                system("CLS");
                break;
            }
            setcolor(PINK);
            CoutCentered("Your current score is:", score);
            setcolor(NORMAL);
            Sleep(1000);
            maxtime--;
        }
    }
    system("CLS");
    CoutCentered("YOUR SCORE IS");
    CoutCentered(score);
    if (score < 25)
    {
        setcolor(RED);
        CoutCentered("Work Hard!!!");
    }
    else if (score >= 25 && score <= 39)
    {
        setcolor(YELLOW);
        CoutCentered("Good, keep working hard!!");
    }
    else if (score > 39 && score < 49)
    {
        setcolor(DARK_CYAN);
        CoutCentered("Great, keep it up!!");
    }
    else
    {
        setcolor(LIME);
        CoutCentered("Excellent!!");
    }
    setcolor(NORMAL);
    getch();
    system("CLS");
    return score;
}

/**************************************************************************************************************************************/

void CoutCentered(string text)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.
    PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
    GetConsoleScreenBufferInfo(hConsole, lpScreenInfo); // Saves the console screen info into the lpScreenInfo pointer.
    COORD NewSBSize = lpScreenInfo->dwSize; // Gets the size of the screen
    if (NewSBSize.X > text.size()) {
        int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
        for (int i = 0; i < newpos; i++) cout << " "; // Prints the spaces
    }
    cout << text << endl; // Prints the text centered :]
}
// Overloading
void CoutCentered(int n)
{
    // This function will only center the text if it is less than the length of the console!
    // Otherwise it will just display it on the console without centering it.

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                           // Get the console handle.
    PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
    GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);                          // Saves the console screen info into the lpScreenInfo pointer.
    COORD NewSBSize = lpScreenInfo->dwSize;                                      // Gets the size of the screen

    int size = ceil(log10(n));

    if (NewSBSize.X > size)
    {
        int newpos = ((NewSBSize.X - size) / 2); // Calculate the number of spaces to center the specific text.
        for (int i = 0; i < newpos; i++)
            std::cout << " "; // Prints the spaces
    }
    std::cout << n << std::endl; // Prints the text centered :]
}

// Overloading
void CoutCentered(string s, int n)
{
    // This function will only center the text if it is less than the length of the console!
    // Otherwise it will just display it on the console without centering it.

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                           // Get the console handle.
    PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
    GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);                          // Saves the console screen info into the lpScreenInfo pointer.
    COORD NewSBSize = lpScreenInfo->dwSize;                                      // Gets the size of the screen

    int size = s.size() + 2 + ceil(log10(n));

    if (NewSBSize.X > size)
    {
        int newpos = ((NewSBSize.X - size) / 2); // Calculate the number of spaces to center the specific text.
        for (int i = 0; i < newpos; i++)
            std::cout << " "; // Prints the spaces
    }
    std::cout << s << " : " << n << '\n'; // Prints the text centered :]
}

/**********************************************************************************************************************************/

int main()
{
    Student s;
    s.welcome();
    int score=s.readFile();
    s.putScore(score);
    s.showDetails();
    return 0;
}


