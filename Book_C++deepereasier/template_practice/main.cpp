#include <iostream>
#include <vector>

using namespace std;

template <typename T> class vecal
{
public:
    vecal();
    T value;
    vector<T> vec;
    void vecAdd(T value);
    void vecsum();
};

template <typename T> vecal<T>::vecal()
{}

template <typename T> vecal<T>::void vecAdd(T value)
{
    vec.push_back(value);
}

template <typename T> vecal<T>::void vecsum
{
    T sum;
    for ( vector<T>::iterator itr = vec.begin();
            itr != vec.end(); ++itr )
    {
        sum += *itr;
    }
    cout << sum;
}


int main()
{
    vecal<int> a();
    a.value = 0;
    //���� ����
    while ( a.value >= 0 )
    {
        cout << "���� ���� ���� �Է��Ͻÿ�: ";
        cin >> a.value;

        a.vecAdd(vecal.value);
    }

    //���� �� ���ϱ�
