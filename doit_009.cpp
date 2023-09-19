#include <iostream>
#include <string>
using namespace std;

// 1000000 크기를 부분문자열로 하나하나 분리해서 비교하면
//  이거 그냥 계산하면 시간복잡도가 얼마일까

int s, p;
char dna[1000002];
int limits[4];

int checker[4] = {0, 0, 0, 0};

void deleteStartIndex(char c)
{
  if (c == 'A')
    checker[0]--;
  if (c == 'C')
    checker[1]--;
  if (c == 'G')
    checker[2]--;
  if (c == 'T')
    checker[3]--;
}

void addEndIndex(char c)
{
  if (c == 'A')
    checker[0]++;
  if (c == 'C')
    checker[1]++;
  if (c == 'G')
    checker[2]++;
  if (c == 'T')
    checker[3]++;
}

bool checkValid()
{
  for (int i = 0; i <4; i++)
  {
    if (limits[i] > checker[i])
      return false;
  }
  return true;
}

int main()
{
  cin >> s >> p;
  string str;
  cin >> str;
  for (int i = 0; i < 4; i++)
    cin >> limits[i];

  int start = 0;
  int end = p - 1;

  for (int i = 0; i < p; i++)
  {
    if (str[i] == 'A')
      checker[0]++;
    else if (str[i] == 'C')
      checker[1]++;
    else if (str[i] == 'G')
      checker[2]++;
    else if (str[i] == 'T')
      checker[3]++;
  }   //초기 acgt 개수를 담은 배열 생성

  int cnt = 0;

  while(end != s) //슬라이딩 윈도우 종료조건 : end 가 배열 끝에 다다름
  {
    if (checkValid() == true)
      cnt++;
    deleteStartIndex(str[start]); //start 인덱스의 알파벳 배열 감소
    start++;
    end++;
    addEndIndex(str[end]); //end 인덱스의 알파벳 배열 증가
  }

  cout<<cnt<<"\n";
  return 0;
}