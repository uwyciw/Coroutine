#include "coroutine.h"
#include <stdio.h>
#include <string.h>

void CoroutineTask(const char * cmd)
{
    __COROUTINE_BEGIN();

    printf("start coroutine\n");

    __COROUTINE_WAIT_UNTIL(strcmp("one", cmd) == 0);
    printf("cmd is one\n");
    __COROUTINE_WAIT_UNTIL(strcmp("two", cmd) == 0);
    printf("cmd is two\n");

    __COROUTINE_END();
}

void main()
{
    char cmd[10];

    while (1) {
        scanf("%s", cmd);
        CoroutineTask(cmd);
    }
}
