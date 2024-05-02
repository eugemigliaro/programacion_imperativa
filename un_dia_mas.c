#include <stdio.h>

int one_more_day(int *day, int *month, int *year){
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((*year - 2000) % 4 == 0) {
        days_in_month[1] = 29;
    }

    if (*day < 1 || *day > days_in_month[*month - 1]) {
        return 0;
    }

    if (*month < 1 || *month > 12) {
        return 0;
    }

    if (*day == days_in_month[*month - 1]) {
        *day = 1;
        if (*month == 12) {
            *month = 1;
            (*year)++;
        } else {
            (*month)++;
        }
    } else {
        (*day)++;
    }

    return 1;
}

int main(void){
//now let's try an invalid date

    int day = 31;
    int month = 12;
    int year = 2022;

    printf("before: %d/%d/%d\n", day, month, year);

    if (!one_more_day(&day, &month, &year)) {
        printf("Invalid date");
    } else {
        printf("after: %d/%d/%d\n", day, month, year);
    }

    return 0;
}