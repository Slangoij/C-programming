#include <cstddef>
#include <iostream>

using namespace std;

struct EnemySpaceShip
{
    int x_coordinate;
    int y_coordinate;
    int weapon_power;
    EnemySpaceShip *p_next_enemy;
};

EnemySpaceShip *p_enemies = NULL;

void upgradeWeapons (EnemySpaceShip *p_ship)
{
    p_ship->weapon_power += 10;
}

EnemySpaceShip *getNewEnemy()
{
    EnemySpaceShip *p_ship = new EnemySpaceShip;
    p_ship->x_coordinate = 000;
    p_ship->y_coordinate = 000;
    p_ship->weapon_power = 20;
    p_ship->p_next_enemy = p_enemies;
    p_enemies = p_ship;
    return p_ship;
}

EnemySpaceShip *addNewEnemyToList (EnemySpaceShip *p_list)
{
    EnemySpaceShip *p_ship = new EnemySpaceShip;
    p_ship->x_coordinate = 0;
    p_ship->y_coordinate = 0;
    p_ship->weapon_power = 20;
    p_ship->p_next_enemy = p_list;
    return p_ship;
}

void printlist(EnemySpaceShip *p_enemies)
{
    EnemySpaceShip *p_current = p_enemies;
    while(p_current != NULL)
    {
        cout << p_current->x_coordinate << "   ";
        cout << p_current->y_coordinate << "   ";
        cout << p_current->weapon_power << endl;
        p_current = p_current->p_next_enemy;
    }
}


int main()
{
    int listsize;
    int deletetarget;
    EnemySpaceShip *p_current = p_enemies;

    //���ϴ� ����Ʈ ũ�� �Է�
    cout << "���Ͻô� ����Ʈ�� ũ�⸦ �Է��ϼ���: " << endl;
    cin >> listsize;
    cout << endl << endl;

    //���� ����Ʈ ���ϴ� ũ�⸸ŭ �ۼ�
    p_enemies = getNewEnemy();
    for(int i=0;i<listsize-1;i++)
    {
        p_enemies = addNewEnemyToList( p_enemies );
    }
    cout << "�����Ǳ� ���� ���� �����Դϴ�: " << endl << endl;
    cout << "============================="<< endl;
    printlist(p_enemies);
    cout << "============================="<< endl << endl << endl;

    //������ҿ� �������� ������ ���� ��ü ���׷��̵�
    p_current = p_enemies;
    while( p_current != NULL)
    {
        upgradeWeapons( p_current );
        p_current = p_current ->p_next_enemy;
    }


    //���� ���� ����Ʈ �� �⵿
    cout << "�����Ǳ� ���� ���� �����Դϴ�: " << endl << endl;
    cout << "============================="<< endl;
    printlist(p_enemies);
    cout << "============================="<< endl << endl << endl;
    cout << endl << endl;

    //���Ḯ��Ʈ���� ������ ���ϴ� ����� ���� �ε��� �Է�
    cout << "������ ���Ͻô� ����Ʈ�� ������ �Է��ϼ���: " << endl;
    cin >> deletetarget;
    cout << endl << endl;

    //���ϴ� ��� ����         �ϴ� �߰� ���˿� ���
    EnemySpaceShip *temp;
    p_current = p_enemies;
    for(int i=0;i<deletetarget-1;i++)
    {
        p_current = p_current->p_next_enemy;
    }
    p_current->x_coordinate = 99;
    p_current->y_coordinate = 99;
    p_current->weapon_power = 0;
    temp = p_current->p_next_enemy;
    p_current = temp->p_next_enemy;

    cout << p_current->x_coordinate << "   ";
    cout << p_current->y_coordinate << "   ";
    cout << p_current->weapon_power << endl;



    //���� �� ���� ����Ʈ Ȯ��
    cout << "������ ���� ���� �����Դϴ�: " << endl << endl;
    cout << "============================="<< endl << endl;
    printlist(p_enemies);
    cout << "============================="<< endl << endl << endl;
    cout << endl << endl;

    delete[] p_enemies;
}


