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
    time1 = localtime(&stat1.st_mtime);
    //printf("Time information of text1\n");
    //printf("month : %d\n", time1->tm_mon+1);
    //printf("date : %d\n", time1->tm_mday);
    //printf("hour : %d\n", time1->tm_hour);
    //printf("min : %d\n", time1->tm_min);
    //return;
}



//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
    time2 = localtime(&stat2.st_mtime);
    //printf("Time information of text2\n");
    //printf("month : %d\n", time2->tm_mon + 1  );
    //printf("date : %d\n", time2->tm_mday);
    //printf("hour : %d\n", time2->tm_hour);
    //printf("min : %d\n", time2->tm_min);
    //return;
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
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    
}
