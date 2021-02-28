#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char *get_day (int day, bool is_leap) {
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(is_leap) months[1]++;
    int cnt = 0;
    int currentMonth = 0;
    char *monthName;
    int currentDay = 0;


//counts the month
    for(int i = 0; i < 12; ++i) {
        if(cnt + months[i] >= day) {
            currentMonth = i + 1;
            break;
        }
        currentDay += months[i];
        cnt += months[i];
    }

//counts the day

    currentDay = day - currentDay;


    switch (currentMonth){
        case 1: monthName = "January"; break;
        case 2: monthName = "February"; break;
        case 3: monthName = "March"; break;
        case 4: monthName = "April"; break;
        case 5: monthName = "May"; break;
        case 6: monthName = "June"; break;
        case 7: monthName = "July"; break;
        case 8: monthName = "August"; break;
        case 9: monthName = "September"; break;
        case 10: monthName = "October"; break;
        case 11: monthName = "November"; break;
        case 12: monthName = "December"; break;
        default: monthName = " "; break;
    }

    int monthCharCnt = (int) strlen(monthName);
    char *ret;

    if(currentDay > 9) ret = malloc(monthCharCnt + 4);
    if(currentDay < 10) ret = malloc(monthCharCnt + 3);

    strcpy(ret, monthName);
    *(ret + monthCharCnt) = ',';
    *(ret + monthCharCnt + 1) = ' ';
    //printf("%d", currentDay);

    if(currentDay > 9) {
        *(ret + monthCharCnt + 2) = '0' + (currentDay / 10);
        *(ret + monthCharCnt + 3) = '0' + (currentDay - (currentDay / 10) * 10);
        *(ret + monthCharCnt + 4) = '\0';
    } else {
        *(ret + monthCharCnt + 2) = '0' +  (currentDay - (currentDay / 10) * 10);
        *(ret + monthCharCnt + 3) = '\0';
    }


    return ret;

}

int main(void) {
   printf("%s", get_day(366, true));
}