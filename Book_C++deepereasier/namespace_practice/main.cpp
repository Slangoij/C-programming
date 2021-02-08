#include <iostream>

using namespace std;

namespace cprogramming
{
//할당하는 메모리는 누수 없이 전부 삭제되어야한다.
class vectorOflnt
{
public:
    //생성자
    vectorOflnt ();  //32개의 요소 벡터를 할당하는 무인수 생성자
    vectorOflnt (int vecsize);  //초기 크기를 인수로 받는 생성자
    //파괴 연산자
    ~vectorOflnt ();
    int get (int index);//인덱스를 받아 해당 인덱스의 값을 리턴하는 get 메소드
    void set ();  //인덱스와 값을 받아 값을 인덱스에 설정하는 set 메소드
    void pushback (int x);  //배열의 끝에 요소를 추가하는 pushback 메소드(단, 필요하다면 배열의 크기를 조절할 수 있음)
    void pushfront (int x);  //배열의 처음에 요소를 추가하는 pushfront 메소드
    //복사 생성자
    vectorOflnt (const vectorOflnt& other);
    //대입 연산자
    vectorOflnt& operator= (const vectorOflnt& other);
    //결과 출력
    void printclass ();

private:
    int _size;
    int *_vec;
};

vectorOflnt::vectorOflnt()
{
    _size = 32;
    _vec = new int[_size];
    for ( int i = 0; i < _size; i++ )
    {
        _vec[ i ] = 0;
    }
}
vectorOflnt::vectorOflnt(int vecsize)
{
    _size = vecsize;
    _vec = new int[ _size ];
    for ( int i = 0; i < _size; i++ )
    {
        _vec[ i ] = 0;
    }
}
vectorOflnt::~vectorOflnt()
{
    delete[] _vec;
}
int vectorOflnt::get(int index)
{
    /*
    while ( 1 )
    {
        cout << "숫자를 찾을 위치를 벡터 크기 내에서 입력하시오(첫번째 자리 1부터 시작)" << endl;
        cin >> index;
        if ( index > 0 && index <= _size )
        {
            //cout << "해당 인덱스의 값은 " << _vec[ index - 1 ] << "입니다.\n";
            break;
        }
        else
        {
            cout << "값이 올바르지 않습니다.\n";
        }
    }
    */
    return _vec[ index - 1 ];
}
void vectorOflnt::set()
{
    while( 1 )
    {
        int index, x;
        cout << "숫자를 넣을 순서를 벡터 크기 내에서 입력하시오(첫번째 자리 1부터 시작)" << endl;
        cin >> index;
        cout << "벡터에 넣을 값을 입력하시오(1이상의 수)"<< endl;
        cin >> x;
        cout << endl;
        if ( index > 0 && index <= _size && x >= 0 )
        {
            _vec[ index - 1 ] = x;
            break;
        }
        else
        {
            cout << "값이 올바르지 않습니다.\n";
        }
    }
}
void vectorOflnt::pushback(int x)
{
    int *new_vec = new int[ _size + 1 ];
    //new_vec 은 기존 _vec에 새 값 x를 넣기위한 복사본입니다.
    for ( int i = 0; i < _size; i++ )
    {
        new_vec [ i ] = 0;
    }
    //new_vec에 기존 배열을 복사합니다.
    for ( int i = 0; i < _size; i++ )
    {
        new_vec[ i ] = _vec[ i ];
    }
    //x를 새로 할당한 배열 마지막에 추가합니다.
    new_vec[ _size ] = x;

    delete[] _vec;
    _size += 1;
    _vec = new int[ _size ];
    //단순복사만 하면 두개가 같은 주소값을 가리키므로 하나만 삭제할 수가 없다.
    //_vec = new_vec;
    for ( int i = 0; i < _size; i++ )
    {
        _vec[ i ] = new_vec[ i ];
    }
    delete[] new_vec;
}
void vectorOflnt::pushfront(int x)
{
    int *new_vec = new int[ _size + 1 ];
    for ( int i = 0; i < _size; i++ )
    {
        new_vec [ i ] = 0;
    }
    for ( int i = 0; i < _size; i++ )
    {
        new_vec[ i + 1 ] = _vec[ i ];
    }
    new_vec[ 0 ] = x;

    delete[] _vec;
    _size += 1;
    _vec = new int[ _size ];
    for ( int i = 0; i < _size; i++ )
    {
        _vec[ i ] = new_vec[ i ];
    }
    delete new_vec;
}
vectorOflnt::vectorOflnt (const vectorOflnt& other)
    : _vec( NULL )
{
    _vec = other._vec;
    for ( int i = 0; i < _size; i++ )
    {
        _vec[ i ] = other._vec[ i ];
    }
}
vectorOflnt& vectorOflnt::operator= (const vectorOflnt& other)
{
    if ( this == & other )
    {
        return *this;
    }
    delete _vec;
    _vec = NULL;

    for ( int i = 0; i < _size; i++ )
    {
        _vec[ i ] = other._vec[ i ];
    }
    return *this;
}
void vectorOflnt::printclass ()
{
    cout << "자, 현재까지 결과 확인" << "\n==================================\n";
    for ( int i = 0; i < _size; i++ )
    {
        cout << "[ " << _vec[ i ] << " ]  ";
    }
    cout << "\n==================================\n\n";
}

}

using cprogramming::vectorOflnt;

int main()
{
    //초기화 후 출력
    int vecsize = 0;

    cout << "벡터 사이즈를 입력하시오\n";
    cin >> vecsize;

    int p[vecsize] = {0};
    vectorOflnt vec(vecsize);
    vec.printclass();

    //세팅 및 푸시백,프론트작업
    while ( 1 )
    {
        vec.set();
        int j = 100000;
        for ( int i = 0; i < vecsize; i++ )
        {
            p[ i ] = vec.get(i+1);
        }
        for ( int i = 0; i < vecsize; i++ )
        {
            if ( j > p[ i ] )
            {
                j = p [ i ];
            }
        }
        if ( j != 0 )
        {
            break;
        }
    }

    //세팅 후 점검용 출력
    vec.pushback( 100 );
    cout << "vec.pushback( 100 )\n";
    vec.printclass();
    vec.pushfront( 200 );
    cout << "vec.pushfront( 200 )\n";
    vec.printclass();
    vec.~vectorOflnt();
}
















