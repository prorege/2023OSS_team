#include "Ledger.h"

int main(void)
{

    int budget = 0; // 월간 정산 할 때 입력받는 기능. 한 달에 배정된 총 예산.
    Day *d[31];
    Day *m[31];
    DailyLoad *cd;
    int index, count = 0;
    int menu;

    while (1)
    {
        int ischeck = 0;
        menu = selectMenu();
        if (menu == 0)
        {
            printf("프로그램을 종료합니다. 안녕히 가세요.\n\n");
            break;
        }
        if (menu == 1 || menu == 3 || menu == 4 || menu == 5 || menu == 6)
            if (count == 0)
                continue;
        if (menu == 1)
        {
            listLedger(d, index);
        }
        else if (menu == 2)
        {
            count += addLedger(d, index);
            index++;
        }
        else if (menu == 3)
        {
            int no = selectLedger(d, index);
            if (no == 0)
            {
                printf("=> 취소되었습니다.\n");
                continue;
            }
            printf("정말로 수정하시겠습니까?(삭제 :1)");
            scanf("%d", &ischeck);
            updateLedger(d, no - 1);
        }
        else if (menu == 4)
        {
            int no = selectLedger(d, index);
            if (no == 0)
            {
                printf("=> 취소되었습니다.\n");
                continue;
            }
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &ischeck);
            if (ischeck == 1)
            {
                if (deleteLedger(d, no - 1) == 1)
                {
                    free(d[no - 1]);
                    count--;
                }
            }
            printf("\n=> 삭제되었습니다.\n");
        }
        else if (menu == 5)
        {
            saveLedger(d, index);
        }
        else if (menu == 6)
        {
            searchLedger(d, index);
        }
        else if (menu == 7)
        {
            printf("예산을 입력해 주세요: ");
            scanf("%d", &budget);
            calLedger(m, budget);
        }
        else if (menu == 8)
        {
            loadDay(cd);
        }
    }

    return 0;
}
