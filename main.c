#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
    stat("text1", &stat1); //text1 size,blocks 크기 저장
    //printf("text1 size: %d\n", (int)stat1.st_size); //text1 size 출력하는 함수
    //printf("text1 blocks : %d\n", (int)stat1.st_blocks); //text1 block 출력하는 함수
    return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
    stat("text2", &stat2); //text2 size,blocks 크기 저장
    //printf("text2 size: %d\n", (int)stat2.st_size); //text1 size 출력하는 함수
    //printf("text2 blocks : %d\n", (int)stat2.st_blocks); //text1 block 출력하는 함수
    return;
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
   static struct tm temp1; 
    localtime_r(&stat1.st_mtime, &temp1);
    time1 = &temp1; 
}



//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
    static struct tm temp2; 
    localtime_r(&stat2.st_mtime, &temp2);
    time2 = &temp2; 

}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    int size1 = (int)stat1.st_size;
    int size2 = (int)stat2.st_size;

    printf("size compare\n");

    if (size1 > size2)
        printf("text1 is bigger\n");
    else if (size1 < size2)
        printf("text2 is bigger\n");
    else
        printf("sizes are equal\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    int blk1 = (int)stat1.st_blocks;
    int blk2 = (int)stat2.st_blocks;

    printf("block compare\n");

    if (blk1 > blk2)
        printf("text1 is bigger\n\n");
    else if (blk1 < blk2)
        printf("text2 is bigger\n\n");
    else
        printf("size are equal\n\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    printf("date compare\n");
    if (time1->tm_year > time2->tm_year) {
        printf("text1 is later\n");
    } else if (time1->tm_year < time2->tm_year) {
        printf("text2 is later\n");
    } else if (time1->tm_mon > time2->tm_mon) {
        printf("text1 is later\n");
    } else if (time1->tm_mon < time2->tm_mon) {
        printf("text2 is later\n");
    } else if (time1->tm_mday > time2->tm_mday) {
        printf("text1 is later\n");
    } else if (time1->tm_mday < time2->tm_mday) {
        printf("text2 is later\n");
    } else {
        printf("same date\n");
    }   
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    printf("time compare\n");
    if (time1->tm_hour > time2->tm_hour) {
        printf("text1 is later\n");
    } else if (time1->tm_hour < time2->tm_hour) {
        printf("text2 is later\n");
    } else if (time1->tm_min > time2->tm_min) {
        printf("text1 is later\n");
    } else if (time1->tm_min < time2->tm_min) {
        printf("text2 is later\n");
    } else {
        printf("same time\n");
    }
}
