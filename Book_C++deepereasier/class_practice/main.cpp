#include <iostream>

using namespace std;

//�Ҵ��ϴ� �޸𸮴� ���� ���� ���� �����Ǿ���Ѵ�.
class vectorOflnt
{
public:
    vectorOflnt();  //32���� ��� ���͸� �Ҵ��ϴ� ���μ� ������
    vectorOflnt (int vecsize);  //�ʱ� ũ�⸦ �μ��� �޴� ������
    void get (int index);//�ε����� �޾� �ش� �ε����� ���� �����ϴ� get �޼ҵ�
    void set (int index, int x);  //�ε����� ���� �޾� ���� �ε����� �����ϴ� set �޼ҵ�
    void pushback (int x);  //�迭�� ���� ��Ҹ� �߰��ϴ� pushback �޼ҵ�(��, �ʿ��ϴٸ� �迭�� ũ�⸦ ������ �� ����)
    void pushfront (int x);  //�迭�� ó���� ��Ҹ� �߰��ϴ� pushfront �޼ҵ�
    //���� ������
    vectorOflnt (const vectorOflnt& other);
    //���� ������
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
        cout << "���ڸ� ���� ��ġ�� ���� ũ�� ������ �Է��Ͻÿ�" << endl;
        cin >> index;
        if ( index > 0 || index < _size )
        {
            cout << _vec[ index ];
            break;
        }
        else
        {
            cout << "�ε��� ���� ���ڸ� �Է��Ͻÿ�\n";
        }
    }
}
void vectorOflnt::set(int index, int x)
{
    while( 1 )
    {
        cout << "���ڸ� ���� ��ġ�� ���� ũ�� ������ �Է��Ͻÿ�" << endl;
        cin >> index;
        cout << "\n�Է��� ���ڸ� �Է��Ͻÿ�\n(���� �� �Լ��� �����÷��� ������ �Է��Ͻʽÿ�)" << endl;
        cin >> x;
        if ( index > 0 || x >= 0 )
        {
            _vec[ index ] = x;
            break;
        }
        else
        {
            cout << "�ùٸ� �ε����� ���� �Է��Ͻÿ�\n";
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
        cout << "��������� ���� ���" << endl;
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


















