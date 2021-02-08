#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


int main()
{
    fstream file ( "highscores.txt", ios::in | ios::out );
    if ( ! file.is_open() )
    {
        cout << "Could not open file!" << endl;
        return 0;
    }
    int new_high_score;
    cout << "Enter a new high score: ";
    cin >> new_high_score;

    streampos pre_score_pos = file.tellg();
    int cur_score;
    while ( file >> cur_score )
    {
        pre_score_pos = file.tellg();
        if ( cur_score < new_high_score )
        {
            break;
        }
    }

    if ( file.fail() && ! file.eof() )
    {
        cout << "Bad score/read--exiting";
        return 0;
    }
    file.clear();

    file.seekg( pre_score_pos );

    vector<int> scores;
    while ( file >> cur_score )
    {
        scores.push_back( cur_score );
    }
    if ( ! file.eof() )
    {
        cout << "Bad score/read--exiting";
        return 0;
    }
    file.clear();
    file.seekp( pre_score_pos );
    /*
    if ( pre_score_pos != streampos(0) )
    {
        file << endl;
    }
    */
    file << new_high_score << endl;

    for ( vector<int>::iterator itr = scores.begin(); itr != scores.end(); ++itr )
    {
        file << *itr << endl;
    }
}


















