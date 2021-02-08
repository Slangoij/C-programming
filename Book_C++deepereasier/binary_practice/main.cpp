#include <iostream>

using namespace std;

struct node
{
    int key_value;
    node *p_left;
    node *p_right;
};

node *insert (node *p_tree, int key);
node *search (node *p_tree, int key);
void destroy_tree (node *p_tree);
node *remove (node *p_tree, int key);
node *find_max (node *p_tree);
node *remove_max_node (node *p_tree, node *p_max_node);
int **tree_to_array(node *p_tree, int **Array, int *q, int max_index_of_tree);
node *findnodeindex (node *p_tree, int key);
int returnindex_of_tree (node *p_tree, int key);
void printArray (int **Array, int max_index_of_tree);
int *growArray (int *p, int *size);








int main()
{
    int x = 0;                 //��尪 �����
    int next_element = 0;      //�迭 �ε���
    int size = 10;             //��尪 ������ �迭 �ӽ� ������
    int *p = new int[ size ];  //��尪 ���� �迭
    node *p_tree = NULL;      //��� ���� Ʈ��

    cout << "�Է��� ���Ͻô� ����� Ű�� �Է��Ͻÿ�, �� �Է��� �׸��Ͻ÷��� -1�� �Է��Ͻÿ� : " << endl;
    //��带 �߰� �� ��尪 �迭 �Ҵ��ϰų� ���
    while( 1 )
    {
        cout << "key in : " << endl;
        cin >> x;
        cout << endl;

        //-1 �־��� �� ���
        if(x == -1)
        {
            int k = 0;
            //check
            cout << "�迭�̶� ����" << endl;
            for(int i=0;i<next_element;i++)
            {
                cout << p[i] << "  ";
            }
            cout << endl;

            //�ִ� �ε��� ������ k�� �Է�
            cout << "�� ��� ������ : " << next_element << endl;


            for(int i=0; i < next_element; i++ )
            {
                if ( k < returnindex_of_tree( p_tree, p[i] ) )
                {
                    k = returnindex_of_tree( p_tree, p[i] );
                }
            }

            cout << "�ִ� �ε��� ������ : " << k << endl;

            //���ÿ� ������ �� ���� ũ�Ⱑ �ִ� �ε����� 2*2 �迭 �Ҵ��Ŀ� �Է��Ͽ� ��ü ��� �ľ�
            int **Array;
            Array = new int*[k];
            for (int i=0; i<k; i++)
            {
                Array[ i ] = new int[k];
            }
            //�ʱ�ȭ
            for (int i=0; i<k; i++)
            {
                for (int j=0; j<k; j++)
                {
                    Array[i][j] = 0;
                }
            }

            Array = tree_to_array( p_tree, Array, p, k );

            //�迭 ���
            printArray(Array, k);

            //2���� �迭 Array �޸� �ݳ�
            for ( int i = 0; i < k; i++ )
            {
                delete [] Array[ k ];
            }
            delete [] Array;

            break;
        }

        //Ʈ���� ��� �߰�
        p_tree = insert( p_tree, x );

        //���ÿ� ������ �迭�� �Է��Ͽ� ��ü ��� �ľ�
        if ( size == next_element +1 )
        {
            p = growArray( p, &size );
        }
        p[ next_element ] = x;
        next_element++;
    }

    delete [] p;
    destroy_tree( p_tree );
}











int *growArray (int *p, int *size)
{
    *size *= 2;
    int *p_new = new int[ *size ];
    for ( int i=0; i < *size; ++i )
    {
        p_new[ i ] = p[ i ];
    }
    delete [] p;
    return p_new;
}

//Ʈ���� �迭�� �Է�
int **tree_to_array(node *p_tree, int **Array, int *p, int max_index_of_tree)
{
    node *p_new_tree;
    int s;
    int j;

    for ( int i = 0; i < max_index_of_tree; i++ )
    {
        //���� Ʈ�� ������ Ʈ���̽̿� ���� Ʈ�� ���� �� �迭 �࿭���� ������ �ʱ�ȭ
        p_new_tree = p_tree;
        while ( 1 )
        {
            s = 0;
            j = 0;
            if( p_new_tree == NULL || p_new_tree == findnodeindex ( p_new_tree, p[i] ) )
            {
                break;
            }
            if( p_new_tree->p_left == findnodeindex( p_new_tree, p[i] ) )
            {
                p_new_tree = findnodeindex( p_new_tree, p[i] );
                s++;
            }
            if( p_new_tree->p_right == findnodeindex( p_new_tree, p[i] ) )
            {
                p_new_tree = findnodeindex( p_new_tree, p[i] );
                s++;
                j++;
            }
        }
        Array[s][j] = p[i];
    }
    return Array;
}

//Ʈ�� �������� �迭�� ���
void printArray(int **Array, int max_index_of_tree)
{
    //�� ����� �ε����� �ݿ��Ͽ� ���� ����� ���� �ø�
    for(int i=0;i<max_index_of_tree;i++)
    {
        for(int j=0;j<max_index_of_tree;j++)
        {
            //check
            cout << Array[i][j] << "  ";
            /*
            for(int k=0;k<max_index_of_tree-i;k++)
            {
                cout << "   ";
            }
            if( Array[i][j] != 0 )
            {
                cout << Array[i][j];
            }
            //NULL ���� ��� ���
            else if ( Array[i][j] == NULL )
            {
                cout << "NULL";
            }
            */
        }
        cout << endl;
    }
}

//Ư�� ��尪�� �ܰ踦 �����ϴ� �ڵ�
int returnindex_of_tree(node *p_tree, int key)
{
    int i=0;
    while( 1 )
    {
        if ( p_tree == NULL || p_tree == findnodeindex ( p_tree, key ) )
        {
            break;
        }
        p_tree = findnodeindex(p_tree, key);
        i++;
    }
    return i;
}

//��� �迭 ��Ҹ� ���󰡴� �ڵ�
node *findnodeindex(node *p_tree, int key)
{
    if( p_tree == NULL )
    {
        return NULL;
    }
    else if ( key == p_tree->key_value )
    {
        return p_tree;
    }
    else if ( key < p_tree->key_value )
    {
        return p_tree->p_left;
    }
    else
    {
        return p_tree->p_right;
    }
}

node *insert (node *p_tree, int key)
{
    if( p_tree == NULL )
    {
        node *p_new_tree = new node;
        p_new_tree->p_left = NULL;
        p_new_tree->p_right = NULL;
        p_new_tree->key_value = key;
        return p_new_tree;
    }
    if( key < p_tree->key_value )
    {
        p_tree->p_left = insert( p_tree->p_left, key );
    }
    else
    {
        p_tree->p_right = insert( p_tree->p_right, key );
    }
    return p_tree;
}

node *search (node *p_tree, int key)
{
    if( p_tree == NULL )
    {
        return NULL;
    }
    else if ( key == p_tree->key_value )
    {
        return p_tree;
    }
    else if ( key < p_tree->key_value )
    {
        return search( p_tree->p_left, key );
    }
    else
    {
        return search( p_tree->p_right, key );
    }
}

void destroy_tree (node *p_tree)
{
    if ( p_tree != NULL)
    {

        destroy_tree( p_tree->p_left );
        destroy_tree( p_tree->p_right );
        delete p_tree;
    }
}

node *remove (node *p_tree, int key)
{
    if( p_tree == NULL )
    {
        return NULL;
    }
    if ( p_tree->key_value == key )
    {
        if ( p_tree->p_left == NULL )
        {
            node *p_right_subtree = p_tree->p_right;
            delete p_tree;
            return p_right_subtree;
        }
        if ( p_tree->p_right == NULL )
        {
            node *p_left_subtree = p_tree->p_left;
            delete p_tree;
            return p_left_subtree;
        }
        node *p_max_node = find_max( p_tree->p_left );
        p_max_node->p_left = remove_max_node( p_tree->p_left, p_max_node );
        p_max_node->p_right = p_tree->p_right;
        delete p_tree;
        return p_max_node;
    }
    else if ( key < p_tree->key_value )
    {
        p_tree->p_left = remove( p_tree->p_left, key );
    }
    else
    {
        p_tree->p_right - remove( p_tree->p_right, key );
    }
    return p_tree;
}

node *find_max (node *p_tree)
{
    if ( p_tree == NULL )
    {
        return NULL;
    }
    if ( p_tree->p_right == NULL )
    {
        return p_tree;
    }
    return find_max( p_tree->p_right );
}

node *remove_max_node (node *p_tree, node *p_max_node)
{
    if ( p_tree == NULL )
    {
        return NULL;
    }
    if ( p_tree == p_max_node )
    {
        return p_max_node->p_left;
    }
    p_tree->p_right = remove_max_node( p_tree->p_right, p_max_node );
    return p_tree;
}







