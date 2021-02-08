#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
w


struct friInfo
{
    int friNum;
    int friDay;
};

friInfo *growfriArray(friInfo *friArray,int *frisize);
void sorting(friInfo *friArray, int frisize);
void swapping(friInfo *friArray, int first_index, int second_index);
int FSRE(friInfo *friArray, int size_of_friarray, int index);

int randRange(int low, int high)
{
    return rand() % (high-low+1)+low;
}




int main()
{
    int friDaycount;
    int fricount = 0; //친구 배열 위치
    int frisize = 10; //친구 명수 할당 size
    int Daytemp;      //대화시간 양수로 맞추기 위한 변수
    int stac;
    friInfo *friArray = new friInfo[frisize];

    //난수 생성
    srand(time(NULL));

    //구조체 배열 할당
    friDaycount = randRange(0,100);
    cout << "친구를 추가하시겠습니까?(Y/N)" << endl
         << "추가하시려면 친구 명수를 정확하게 입력하고, 그만 입력하고 친구분들 명단을 보시려면 0을 입력하세요: " << endl;

    while(1)
    {
        // key in 받기
        friArray[fricount].friNum = fricount+1;
        friArray[fricount].friDay = friDaycount;
        cin >> stac;

        //메모리보다 친구 수가 더 많이진 경우 친구명단길이 추가
        if(frisize == fricount+1)
        {
           friArray = growfriArray(friArray,&frisize);
        }

        //0이나 순서 안맞게 대충 key 입력하면 친구와의 대화시간 순으로 명단 출력
        if(stac != fricount+1 || stac == 0)
        {
            //대화한 시간순으로 명단정렬
            sorting(friArray,fricount);
            //친구명단 출력
            cout << "================================================================";
            cout << endl <<"자 그럼 이제 친구랑 이야기한 순으로 친구들을 나열해 봅시다 "  << endl << endl;
            for(int i=0;i<fricount;i++)
            {
                cout << "친구 번호! : "       << friArray[i].friNum << endl
                     << "친구랑 이야기한 날! : " << friArray[i].friDay << endl << endl;
            }
            cout << "================================================================" << endl;
            cout << "이상 번호 끝!" << endl << endl;
            break;
        }

        //현재 정보 중간점검용 출력
        cout << "현재 친구 번호   : " << friArray[fricount].friNum << endl;
        cout << "친구와의 대화시간 : " << friArray[fricount].friDay << endl << endl;

        fricount++;
        Daytemp = friDaycount;
        friDaycount += randRange(-Daytemp,100);


    }
    delete[] friArray;
}




friInfo *growfriArray(friInfo *friArray,int *frisize)
{
    *frisize *= 2;
    friInfo *new_friArray = new friInfo[*frisize];
    for(int i=0;i<*frisize;++i)
    {
        new_friArray[i] = friArray[i];
    }
    delete[] friArray;
    return new_friArray;
}

void sorting(friInfo *friArray,int frisize)
{
    for(int i=0;i<frisize;i++)
    {
        int index = FSRE(friArray, frisize, i);
        swapping(friArray,i,index);
    }
}

void swapping(friInfo *friArray, int first_index, int second_index)
{
    friInfo temp = friArray[first_index];
    friArray[first_index] = friArray[second_index];
    friArray[second_index] = temp;
}

int FSRE(friInfo *friArray, int size_of_friarray, int index)
{
    int index_of_smallest_value = index;
    for(int i = index +1; i<size_of_friarray;i++)
    {
        if(friArray[i].friDay<friArray[index_of_smallest_value].friDay)
        {
            index_of_smallest_value = i;
        }
    }
    return index_of_smallest_value;
}






