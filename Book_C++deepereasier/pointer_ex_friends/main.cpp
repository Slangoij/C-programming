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
    int fricount = 0; //ģ�� �迭 ��ġ
    int frisize = 10; //ģ�� ��� �Ҵ� size
    int Daytemp;      //��ȭ�ð� ����� ���߱� ���� ����
    int stac;
    friInfo *friArray = new friInfo[frisize];

    //���� ����
    srand(time(NULL));

    //����ü �迭 �Ҵ�
    friDaycount = randRange(0,100);
    cout << "ģ���� �߰��Ͻðڽ��ϱ�?(Y/N)" << endl
         << "�߰��Ͻ÷��� ģ�� ����� ��Ȯ�ϰ� �Է��ϰ�, �׸� �Է��ϰ� ģ���е� ����� ���÷��� 0�� �Է��ϼ���: " << endl;

    while(1)
    {
        // key in �ޱ�
        friArray[fricount].friNum = fricount+1;
        friArray[fricount].friDay = friDaycount;
        cin >> stac;

        //�޸𸮺��� ģ�� ���� �� ������ ��� ģ����ܱ��� �߰�
        if(frisize == fricount+1)
        {
           friArray = growfriArray(friArray,&frisize);
        }

        //0�̳� ���� �ȸ°� ���� key �Է��ϸ� ģ������ ��ȭ�ð� ������ ��� ���
        if(stac != fricount+1 || stac == 0)
        {
            //��ȭ�� �ð������� �������
            sorting(friArray,fricount);
            //ģ����� ���
            cout << "================================================================";
            cout << endl <<"�� �׷� ���� ģ���� �̾߱��� ������ ģ������ ������ ���ô� "  << endl << endl;
            for(int i=0;i<fricount;i++)
            {
                cout << "ģ�� ��ȣ! : "       << friArray[i].friNum << endl
                     << "ģ���� �̾߱��� ��! : " << friArray[i].friDay << endl << endl;
            }
            cout << "================================================================" << endl;
            cout << "�̻� ��ȣ ��!" << endl << endl;
            break;
        }

        //���� ���� �߰����˿� ���
        cout << "���� ģ�� ��ȣ   : " << friArray[fricount].friNum << endl;
        cout << "ģ������ ��ȭ�ð� : " << friArray[fricount].friDay << endl << endl;

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






