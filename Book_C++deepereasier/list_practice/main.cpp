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

    //원하는 리스트 크기 입력
    cout << "원하시는 리스트의 크기를 입력하세요: " << endl;
    cin >> listsize;
    cout << endl << endl;

    //연결 리스트 원하는 크기만큼 작성
    p_enemies = getNewEnemy();
    for(int i=0;i<listsize-1;i++)
    {
        p_enemies = addNewEnemyToList( p_enemies );
    }
    cout << "삭제되기 전의 현재 상태입니다: " << endl << endl;
    cout << "============================="<< endl;
    printlist(p_enemies);
    cout << "============================="<< endl << endl << endl;

    //삭제요소와 비삭제요소 구분을 위한 전체 업그레이드
    p_current = p_enemies;
    while( p_current != NULL)
    {
        upgradeWeapons( p_current );
        p_current = p_current ->p_next_enemy;
    }


    //삭제 전의 리스트 총 출동
    cout << "삭제되기 전의 현재 상태입니다: " << endl << endl;
    cout << "============================="<< endl;
    printlist(p_enemies);
    cout << "============================="<< endl << endl << endl;
    cout << endl << endl;

    //연결리스트에서 삭제를 원하는 요소의 순서 인덱스 입력
    cout << "삭제를 원하시는 리스트의 순서를 입력하세요: " << endl;
    cin >> deletetarget;
    cout << endl << endl;

    //원하는 요소 삭제         일단 중간 점검용 출력
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



    //삭제 후 최종 리스트 확인
    cout << "삭제된 후의 현재 상태입니다: " << endl << endl;
    cout << "============================="<< endl << endl;
    printlist(p_enemies);
    cout << "============================="<< endl << endl << endl;
    cout << endl << endl;

    delete[] p_enemies;
}


