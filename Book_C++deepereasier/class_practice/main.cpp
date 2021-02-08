#include <iostream>

using namespace std;

//할당하는 메모리는 누수 없이 전부 삭제되어야한다.
class vectorOflnt
{
public:
    vectorOflnt();  //32개의 요소 벡터를 할당하는 무인수 생성자
    vectorOflnt (int vecsize);  //초기 크기를 인수로 받는 생성자
    void get (int index);//인덱스를 받아 해당 인덱스의 값을 리턴하는 get 메소드
    void set (int index, int x);  //인덱스와 값을 받아 값을 인덱스에 설정하는 set 메소드
    void pushback (int x);  //배열의 끝에 요소를 추가하는 pushback 메소드(단, 필요하다면 배열의 크기를 조절할 수 있음)
    void pushfront (int x);  //배열의 처음에 요소를 추가하는 pushfront 메소드
    //복사 생성자
    vectorOflnt (const vectorOflnt& other);
    //대입 연산자
    vectorOflnt& operator= (const vectorOflnt& other);
    void printclass();

private:
    int _size;
    int *_vec;
};

vectorOflnt::vectorOflnt()
{
    new int _vec[32];
    for ( int i = 0; i < 32; i++ )
    {
        _vec[ i ] = 0;
    }
}
vectorOflnt::vectorOflnt( int vecsize )
{
    _size = vecsize;
    new int _vec[ _size ];
    for ( int i = 0; i < _size; i++ )
    {
        _vec[ i ] = 0;
    }
}
void vectorOflnt::get(int index)
{
    while ( 1 )
    {
        cout << "숫자를 넣을 위치를 벡터 크기 내에서 입력하시오" << endl;
        cin >> index;
        if ( index > 0 || index < _size )
        {
            cout << _vec[ index ];
            break;
        }
        else
        {
            cout << "인덱스 내의 숫자를 입력하시오\n";
        }
    }
}
void vectorOflnt::set(int index, int x)
{
    while( 1 )
    {
        cout << "숫자를 넣을 위치를 벡터 크기 내에서 입력하시오" << endl;
        cin >> index;
        cout << "\n입력할 숫자를 입력하시오\n(만일 이 함수를 끝내시려면 음수를 입력하십시오)" << endl;
        cin >> x;
        if ( index > 0 || x >= 0 )
        {
            _vec[ index ] = x;
            break;
        }
        else
        {
            cout << "올바른 인덱스와 값을 입력하시오\n";
        }
    }
}
void vectorOflnt::pushback(int x)
{
    int *new_vec = new int[ _size + 1 ];
    for ( int i = 0; i < _size; ++ i )
    {
        new_vec[ i ] = _vec[ i ];
    }
    new_vec[ _size + 1 ] = x;

    delete _vec;
}
void vectorOflnt::pushfront(int x)
{
    int *new_vec = new int[ _size + 1 ];
    for ( int i = 0; i < _size; ++ i )
    {
        new_vec[ i + 1 ] = _vec[ i ];
    }
    new_vec[ 0 ] = x;

    delete _vec;
}
vectorOflnt::vectorOflnt (const vectorOflnt& other)
{
    if( this == &other )
    {
        return *this;
    }
    delete _vec;
    _vec = NULL;


}
vectorOflnt& operator= (const vectorOflnt& other)
{
}
void vectorOflnt::printclass()
{
    for ( int i = 0; i < _size; i++ )
    {
        cout << "현재까지의 벡터 출력" << endl;
        cout << "[ " << _vec[ i ] << " ]  ";
    }
}



int main()
{
    vectorOflnt vec;
    vec(3);
    vec.printclass();

    for ( int i = 0; i < _size; i++ )
    {
        vec.set()
    }
}


















