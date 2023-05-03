#include "Ledger.h"

int addLedger(Day *d[], int index)
{
    d[index] = (Day *)malloc(sizeof(Day));
    printf("가계부 입력을 시작합니다.\n");
    printf("월, 일을 띄어서 입력해주세요(ex.01 05): ");
    scanf("%d %d", &d[index]->mon, &d[index]->day);
    printf("수입을 입력해주세요.(0 입력시 다음 단계로 넘어갑니다)\n");
    for (int i = 0; i < 10; i++)
    {
        printf(": ");
        scanf("%d", &d[index]->income);
        d[index]->sumin += d[index]->income;
        if (d[index]->income == 0)
            break;
    }
    printf("카드 지출을 입력해주세요.(0 입력시 다음 단계로 넘어갑니다)\n");
    for (int i = 0; i < 10; i++)
    {
        printf(": ");
        scanf("%d", &d[index]->card);
        d[index]->sumout += d[index]->card;
        if (d[index]->card == 0)
            break;
    }
    printf("현금 지출을 입력해주세요.(0 입력시 다음 단계로 넘어갑니다)\n");
    for (int i = 0; i < 10; i++)
    {
        printf(": ");
        scanf("%d", &d[index]->cash);
        d[index]->sumout += d[index]->cash;
        if (d[index]->cash == 0)
            break;
    }
    printf("=> 가계부 입력이 완료되었습니다.\n");
    return 1;
}

void readLedger(Day d)
{
    printf("%2d-%d     %2d    %2d", d.mon, d.day, d.sumin, d.sumout);
}

int deleteLedger(Day *d[], int index)
{
    d[index] = NULL;
    return 1;
}

int updateLedger(Day *d[], int index)
{
    printf("가계부 수정을 시작합니다.\n");
    printf("월, 일을 띄어서 입력해주세요(ex.01 05): ");
    scanf("%d %d", &d[index]->mon, &d[index]->day);
    printf("수입을 입력해주세요.(0 입력시 다음 단계로 넘어갑니다)\n");
    for (int i = 0; i < 10; i++)
    {
        printf(": ");
        scanf("%d", &d[index]->income);
        d[index]->sumin += d[index]->income;
        if (d[index]->income == 0)
            break;
    }
    printf("카드 지출을 입력해주세요.(0 입력시 다음 단계로 넘어갑니다)\n");
    for (int i = 0; i < 10; i++)
    {
        printf(": ");
        scanf("%d", &d[index]->card);
        d[index]->sumout += d[index]->card;
        if (d[index]->card == 0)
            break;
    }
    printf("현금 지출을 입력해주세요.(0 입력시 다음 단계로 넘어갑니다)\n");
    for (int i = 0; i < 10; i++)
    {
        printf(": ");
        scanf("%d", &d[index]->cash);
        d[index]->sumout += d[index]->cash;
        if (d[index]->cash == 0)
            break;
    }
    printf("=> 가계부 수정이 완료되었습니다.\n");
    return 1;
}

int selectMenu()
{
    int menu;
    printf("\n*** 가계부 작성 메뉴 ***\n");
    printf("1. 가계부 확인하기\n");
    printf("2. 가계부 추가하기\n");
    printf("3. 가계부 수정하기\n");
    printf("4. 가계부 삭제하기\n");
    printf("5. 가계부 저장하기\n");
    printf("6. 가계부 검색하기\n");
    printf("7. 가계부 월간정산\n");
    printf("8. 가계부 불러오기\n"); // 월간정산 불러올 지, 일간정산 불러올 지 입력 받고 하기.
    printf("0. 가계부 종료하기\n\n");
    printf(" >> 원하시는 메뉴를 선택하세요: ");
    scanf("%d", &menu);
    printf("\n");
    return menu;
}

void listLedger(Day *d[], int index)
{
    printf("번호   날짜   수입내역   지출내역\n");
    printf("===============================\n");
    for (int i = 0; i < index; i++)
    {
        if (d[i] == NULL)
            continue;
        printf("% 2d     ", i + 1);
        readLedger(*d[i]);
    }
    printf("\n");
}

int selectLedger(Day *d[], int index)
{
    int no;
    listLedger(d, index);
    printf("작업하기 원하는 가계부의 번호를 입력해주세요(취소: 0): ");
    scanf("%d", &no);
    return no;
}

void mkFolder(Day *d[], int index, char (*save_pth)[20])
{

    char mm[4];

    for (int i = 0; i < index; i++)
    {
        char *m_pth = (char *)malloc(20 * sizeof(char));
        m_pth[0] = '\0';
        m_pth[1] = '\0';
        strcat(m_pth, PATH);
        sprintf(mm, "%d", d[i]->mon);
        strcat(m_pth, mm);
        strcat(m_pth, "/");
        mkdir(m_pth, 0775);
        strcpy(save_pth[i], m_pth);
        free(m_pth);
    }
}

void saveLedger(Day *d[], int index)
{
    FILE *fp;
    char save_pth[40][20];
    mkFolder(d, index, save_pth);
    char *wd = getcwd(NULL, 0);

    /* for(int i = 0; i < index; i++){
        char mm[4];
        strcat(save_pth[i], PATH);
        sprintf(mm, "%d", d[i]->mon);
        strcat(save_pth[i], mm);
        strcat(save_pth[i], "/");
    } */

    for (int i = 0; i < index; i++)
    {
        char dd[4];
        chdir(wd);
        chdir(save_pth[i]);
        sprintf(dd, "%d", d[i]->day);
        strcat(dd, ".txt");
        fp = fopen(dd, "wt");
        if (d[i] == NULL)
            continue;
        fprintf(fp, "%d %d %d %d", d[i]->mon, d[i]->day, d[i]->sumin, d[i]->sumout);
        fclose(fp);
    }
    printf("=> 저장이 완료되었습니다.\n");
    chdir(wd);
} // 저장이 안되면 한 txt 안에 다 저장되게 해야하나?

void searchLedger(Day *d[], int count)
{
    int scnt = 0;
    int mm, dd;
    printf("검색할 월, 일을 입력해주세요(ex.01 05): ");
    scanf("%d %d", &mm, &dd);

    for (int i = 0; i < count; i++)
    {
        if (d[i] == NULL)
            continue;
        if (d[i]->mon == mm && d[i]->day == dd)
        {
            printf("번호   날짜   수입내역   지출내역\n");
            printf("===============================\n");
            scnt++;
            break;
        }
    }
    if (scnt == 0)
        printf("=> 검색된 가계부가 없습니다.\n");
    else if (scnt != 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (d[i] == NULL)
                continue;
            if (d[i]->mon == mm && d[i]->day == dd)
            {
                printf("%2d     ", i + 1);
                readLedger(*d[i]);
            }
        }
    }
    printf("\n");
}

void loadDay(DailyLoad *cd)
{
    cd = (DailyLoad *)malloc(sizeof(DailyLoad));
    int mm, dd;
    FILE *fp;
    char mon[8], day[8];
    char save_pth[20];
    char *wd = getcwd(NULL, 0);
    day[0] = '\0';
    mon[0] = '\0';
    for (int i = 0; i < 20; i++)
        save_pth[i] = '\0';

    strcat(save_pth, PATH);
    printf("불러오고 싶은 월, 일을 띄어서 입력해주세요(ex.01 05): ");
    scanf("%d %d", &mm, &dd);

    sprintf(mon, "%d", mm);
    strcat(save_pth, mon);
    strcat(save_pth, "/");

    sprintf(day, "%d", dd);
    strcat(day, ".txt");

    if (access(save_pth, 0) == 0)
        chdir(save_pth);
    else
        printf("\n=> 찾으시는 가계부가 존재하지 않습니다.\n");

    fp = fopen(day, "r");
    if (fp == NULL)
        return;
    else
    {
        fscanf(fp, "%d", &cd->mon);
        if(feof(fp)) return;
        fscanf(fp, "%d", &cd->day);
        fscanf(fp, "%d", &cd->sumin);
        fscanf(fp, "%d", &cd->sumout);

        printf("번호 날짜 수입내역 지출내역 \n");
        printf("============================\n");
        printf("%2d   %d   %2d    %2d", cd->mon, cd->day, cd->sumin, cd->sumout);
    }
    chdir(wd);
    free(cd);
}
/* void loadMonth(MthLoad *cm)
{
    int yy, mm, dd;

} */

int loadLedger(Day *m[], int list[])
{   
    int mm;
    FILE *fp;
    char mon[8];
    char save_pth[20];
    char *wd = getcwd(NULL, 0);
    mon[0] = '\0';
    save_pth[0] = '\0';

    strcat(save_pth, PATH);
    printf("불러오고 싶은 월을 입력해주세요(ex.01): ");
    scanf("%d", &mm);
    sprintf(mon, "%d", mm);
    strcat(save_pth, mon);
    strcat(save_pth, "/");

    if (access(save_pth, 0) == 0)
        chdir(save_pth);
    else
        printf("\n=> 월간 정산할 가계부가 존재하지 않습니다.\n");

    for (int i = 0; i < 31; i++)
    {   
        char day[8];
        day[0] = '\0';
        sprintf(day, "%d", i+1);
        strcat(day, ".txt");
        fp = fopen(day, "r");
        m[i] = (Day *)malloc(sizeof(Day));
        if (fp == NULL){
            list[i] = 0;
            free(m[i]);
            continue;
        }
        list[i] = i+1;
        fscanf(fp, "%d", &m[i]->mon);
        if (feof(fp)) break;
        fscanf(fp, "%d", &m[i]->day);
        fscanf(fp, "%d", &m[i]->sumin);
        fscanf(fp, "%d", &m[i]->sumout);
        fclose(fp);
    }
    chdir(wd);
    return mm;
}

void calLedger(Day *m[], int budget)
{
    /*     int m_year, m_mon, m_day;
        int m_sumin, m_sumout; */
        int list[31];
    Month *cal = (Month*)malloc(sizeof(Month));    
    int mm = loadLedger(m, list);
    cal->m_sumin = 0;
    cal->m_sumout = 0;
    cal->eff = 0;
    float budeff = 0;

    for (int i = 0; i < 31; i++)
    {   
        if(list[i] != 0){
            cal->m_sumin += m[i]->sumin;
            cal->m_sumout += m[i]->sumout;
        }else continue;
    }
    if(budget == 0)
        cal->eff = 0;
    else
        cal->eff = (cal->m_sumout/(float)budget)*100;
    
    if(cal->m_sumin == 0)
        budeff = 0;
    else
        budeff = (cal->m_sumout / (float)cal->m_sumin)*100;

    printf("%d월 가계부 월간 정산 내역입니다.\n", mm);
    printf(" 월  예산   총수입   총지출   소비(예산%%)   소비(수입%%)\n");
    printf("==============================================\n");
    printf("%2d    %2d     %2d    %2d    %.2f    %.2f\n", mm, budget, cal->m_sumin, cal->m_sumout, cal->eff, budeff);
    free(cal);
}
