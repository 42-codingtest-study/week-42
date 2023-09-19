#include <iostream>
#include <string>
using namespace std;

int checkarr[4]; // 비밀번호 체크
int arr[4];      // 현재 상태
int check = 0;   // 문자 몇 개의 조건을 확인했는지

void remove(char c)
{
    switch (c)
    {
    case 'A':
        if (arr[0] == checkarr[0])
            check--;
        arr[0]--;
        break;
    case 'C':
        if (arr[1] == checkarr[1])
            check--;
        arr[1]--;
        break;
    case 'G':
        if (arr[2] == checkarr[2])
            check--;
        arr[2]--;
        break;
    case 'T':
        if (arr[3] == checkarr[3])
            check--;
        arr[3]--;
        break;
    }
}

void add(char c)
{
    switch (c)
    {
    case 'A':
        arr[0]++;
        if (arr[0] == checkarr[0])
            check++;
        break;
    case 'C':
        arr[1]++;
        if (arr[1] == checkarr[1])
            check++;
        break;
    case 'G':
        arr[2]++;
        if (arr[2] == checkarr[2])
            check++;
        break;
    case 'T':
        arr[3]++;
        if (arr[3] == checkarr[3])
            check++;
        break;
    }
}
int main()
{
    int s, p;
    int res = 0;
    cin >> s >> p;
    string dna;
    cin >> dna;
    for (int i = 0; i < 4; i++)
    {
        cin >> checkarr[i];
        if (checkarr[i] == 0)
            check++;
    }

    for (int i = 0; i < p; i++)
    {
        add(dna[i]);
    }

    if (check == 4)
        res++;
    int start = 0;
    int end = p - 1;

    for (int i = p; i < s; i++)
    {
        int end = i - p;
        add(dna[i]);
        remove(dna[end]);
        if (check == 4)
            res++; // 유효
    }
    cout << res << endl;
}