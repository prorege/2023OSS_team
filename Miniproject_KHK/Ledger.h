#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <io.h>
#define PATH "./"

typedef struct
{

    int mon, day;           // 원하는 월, 일 입력 받음.
    int income, card, cash; // income = 당일 수입, card = 카드로 사용한 금액, cash = 현금으로 사용한 금액.
    int sumin, sumout; // 수입 총합, 지출 총합
    } Day;

typedef struct
{
    int m_sumin, m_sumout; // 수입 총합, 지출 총합 불러와서 저장.
    float eff;
} Month; // [31] 월간 정산 하기 기능시 이용. 월간 정산 하면 입력받은 달의 모든 가계부를 불러와 저장 후 계산.


typedef struct
{
    int mon, day;
    int sumin, sumout;
} DailyLoad; // 입력받은 특정 달의 특정 일 불러와서 보여줌.

int addLedger(Day *d[], int index); // 새로운 가계부를 배열에 추가하는 기능.
void readLedger(Day d); // 배열에 저장된 가계부를 읽어오는 기능.
int deleteLedger(Day *d[], int index); // 배열에 저장된 가계부를 삭제하는 기능.
int updateLedger(Day *d[], int index); // 배열에 저장된 가계부를 수정하는 기능.
int selectMenu(); // 메뉴를 선택하는 기능.
void listLedger(Day *d[], int index); // 배열에 저장된 가계부를 읽어오면서 기능과 순서를 표시하는 기능.
int selectLedger(Day *d[], int index); // 삭제, 수정할 때 원하는 가계부를 선택하는 기능.
void mkFolder(Day *d[], int index, char (*save_pth)[20]); // 배열에 저장된 가계부를 실제 Local에 저장하기 위한 폴더를 만드는 기능.
void saveLedger(Day *d[], int index); // 배열에 저장된 가계부를 '월'에 맞는 폴더에 '일'에 해당하는 이름으로 저장하는 기능. ex)1월 15일 가계부면 1 폴더에 15라는 이름으로 저장.
void searchLedger(Day *d[], int count); // 배열에 저장된 가계부 중 원하는 가계부를 검색하는 기능.
void loadDay(DailyLoad *cd); // 저장된 가계부 중 원하는 날의 가계부를 불러오는 기능.
int loadLedger(Day *m[], int list[]); // 저장된 가계부 중 원하는 달의 가계부를 모두 불러오는 기능.
void calLedger(Day *m[], int budget); // loadLedger()로 불러온 가계부를 월간정산하기 위해 계산하는 기능.
