#include<process.h>
#include<Windows.h>

CRITICAL_SECTION mutex;
unsigned __stdcall START_FUNCTION(void *para)
{
    EnterCriticalSection(&mutex);


    LeaveCriticalSection(&mutex);
}


InitializeCriticalSection(&mutex);
HANDLE hThread = (HANDLE)_beginthreadex(SECURITY_ARRTIBUTE, STACK_SIZE, newThread, INPUT_PARA,CREATE_SUSPENDED, THREAD_ID);
HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, START_FUNCTION, (void*)PARAMS, 0, 0);


WaitForSingleObject(hThread, TIMEOUT);
WaitForMultipleObjects(NUMBER, pThread, true(waitAll), TIMEOUT);

ClostHandle(hThread);
DeleteCriticalSection(&mutex);



