#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int randRange (int low, int high)

{
    return rand() % ( high - low + 1 ) + low;
}

class Comparable
{
public:
    Comparable();
    ~Comparable();
    void compare(Comparable& other);
private:
    int *_data;
    int *_result;
};


//데이터 생성 및 난수 벡터로 초기화
Comparable::Comparable()
{
    _data = new int;
    *_data = randRange( 0, 100 );
    _result = new int;
    *_result = 0;
}
Comparable::~Comparable()
{
    delete _data;
}
void Comparable::compare(Comparable& other)
{
    if ( *(this->_data) == *(other._data) )
    {
        *_result = 0;
    }
    else if ( *(this->_data) > *(other._data) )
    {
        *_result = 1;
    }
    else
    {
        *_result = -1;
    }
}
void sort(int size)
{
    vector<Comparable*> Comparables;
    size = 3;
    for ( int i = 0; i < size; i++ )
    {
        Comparables.push_back( new Comparable() );
    }
    for ( vector<Comparable*>::iterator itr = Comparables.begin(), end = Comparables.end();
          itr != end; ++itr )
    {
        if ( itr+1 != end )
        {
            (**itr)->compare(itr+1);
        }
        else
        {
            (**itr)->compare(Comparables.begin());
        }
    }
}



int main()
{
    srand( time( NULL ) );
    sort(3);
}
