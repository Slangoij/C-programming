#include <iostream>

using namespace std;

namespace cprogramming
{
//�Ҵ��ϴ� �޸𸮴� ���� ���� ���� �����Ǿ���Ѵ�.
class vectorOflnt
{
public:
    //������
    vectorOflnt ();  //32���� ��� ���͸� �Ҵ��ϴ� ���μ� ������
    vectorOflnt (int vecsize);  //�ʱ� ũ�⸦ �μ��� �޴� ������
    //�ı� ������
    ~vectorOflnt ();
    int get (int index);//�ε����� �޾� �ش� �ε����� ���� �����ϴ� get �޼ҵ�
    void set ();  //�ε����� ���� �޾� ���� �ε����� �����ϴ� set �޼ҵ�
    void pushback (int x);  //�迭�� ���� ��Ҹ� �߰��ϴ� pushback �޼ҵ�(��, �ʿ��ϴٸ� �迭�� ũ�⸦ ������ �� ����)
    void pushfront (int x);  //�迭�� ó���� ��Ҹ� �߰��ϴ� pushfront �޼ҵ�
    //���� ������
    vectorOflnt (const vectorOflnt& other);
    //���� ������
    vectorOflnt& operator= (const vectorOflnt& other);
    //��� ���
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
        cout << "���ڸ� ã�� ��ġ�� ���� ũ�� ������ �Է��Ͻÿ�(ù��° �ڸ� 1���� ����)" << endl;
        cin >> index;
        if ( index > 0 && index <= _size )
        {
            //cout << "�ش� �ε����� ���� " << _vec[ index - 1 ] << "�Դϴ�.\n";
            break;
        }
        else
        {
            cout << "���� �ùٸ��� �ʽ��ϴ�.\n";
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
        cout << "���ڸ� ���� ������ ���� ũ�� ������ �Է��Ͻÿ�(ù��° �ڸ� 1���� ����)" << endl;
        cin >> index;
        cout << "���Ϳ� ���� ���� �Է��Ͻÿ�(1�̻��� ��)"<< endl;
        cin >> x;
        cout << endl;
        if ( index > 0 && index <= _size && x >= 0 )
        {
            _vec[ index - 1 ] = x;
            break;
        }
        else
        {
            cout << "���� �ùٸ��� �ʽ��ϴ�.\n";
        }
    }
}
void vectorOflnt::pushback(int x)
{
    int *new_vec = new int[ _size + 1 ];
    //new_vec �� ���� _vec�� �� �� x�� �ֱ����� ���纻�Դϴ�.
    for ( int i = 0; i < _size; i++ )
    {
        new_vec [ i ] = 0;
    }
    //new_vec�� ���� �迭�� �����մϴ�.
    for ( int i = 0; i < _size; i++ )
    {
        new_vec[ i ] = _vec[ i ];
    }
    //x�� ���� �Ҵ��� �迭 �������� �߰��մϴ�.
    new_vec[ _size ] = x;

    delete[] _vec;
    _size += 1;
    _vec = new int[ _size ];
    //�ܼ����縸 �ϸ� �ΰ��� ���� �ּҰ��� ����Ű�Ƿ� �ϳ��� ������ ���� ����.
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
    cout << "��, ������� ��� Ȯ��" << "\n==================================\n";
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
    //�ʱ�ȭ �� ���
    int vecsize = 0;

    cout << "���� ����� �Է��Ͻÿ�\n";
    cin >> vecsize;

    int p[vecsize] = {0};
    vectorOflnt vec(vecsize);
    vec.printclass();

    //���� �� Ǫ�ù�,����Ʈ�۾�
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

    //���� �� ���˿� ���
    vec.pushback( 100 );
    cout << "vec.pushback( 100 )\n";
    vec.printclass();
    vec.pushfront( 200 );
    cout << "vec.pushfront( 200 )\n";
    vec.printclass();
    vec.~vectorOflnt();
}
















