#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/uio.h>
#define PATH "./"

typedef struct
{
    int mon, day;           // 날짜 입력 받기
    int income, card, cash; // income은 뜻하지 않은 수입, card는 카드 사용, cash는 현금 사용
    // sizeof(a) / sizeof(a[0])으로 크기 구함.
    int sumin, sumout; // 수입 총합, 지출 총합
    } Day;                 // [31] 자동으로 날짜를 받아 그 달의 모든 가계부를 로딩할 때 가져오기

typedef struct
{
    int m_sumin, m_sumout; // 수입 총합, 지출 총합 불러와서 저장.
    float eff;
} Month; // [31] 월간 정산 하기 기능시 이용. 월간 정산 하면 입력받은 달의 모든 가계부를 불러와 계산한 후 자동으로 저장
         // 만약 저장된 가계부가 하나도 없다면, 가계부를 저장 후 다시 이용해달라고 반려.

typedef struct
{
    int mon, day;
    int sumin, sumout;
} DailyLoad; // 입력받은 특정 달의 특정 일 불러와서 로딩

int addLedger(Day *d[], int index);
void readLedger(Day d);
int deleteLedger(Day *d[], int index);
int updateLedger(Day *d[], int index);
int selectMenu();
void listLedger(Day *d[], int index);
int selectLedger(Day *d[], int index);
void mkFolder(Day *d[], int index, char (*save_pth)[20]);
void saveLedger(Day *d[], int index);
void searchLedger(Day *d[], int count);
void loadDay(DailyLoad *cd);
int loadLedger(Day *m[], int list[]);
void calLedger(Day *m[], int budget);
