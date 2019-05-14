//according to MSDN, if we use _beginthread to create a thread,
//MSVCRT will close the thread handle automatically when the thread is end,
//so the thread handle returned by _beginthread is unsafe to wait
//if the handle is reused by another running thread, deadlock can be caused
//so instead, we use _beginthreadex, we will have full control over the returned thread handle!


//  __cdecl
    the parameters are pushed from right to left(so that the first parameter is nearest to top-of-stack)
    caller cleans the parameters
    function names are decorates by a leading underscore
    
//  __stdcall
    this is the calling convention used for Win32, with exceptions for variadic functions(which necessarily use __cdecl) and a very few functions that use __fastcall
    parameters are pushed from right to left
    the callee cleans the stack
    function names are decorated by a leading underscore and a training @-sign followed by the number of bytes of parameters taken by the function
    
//  __fastcall
    the first two parameters are passed in ECX and EDX, with the remainder passed on the stack as in __stdcall
    callee cleans the stack
    function names are decorated by a leading @-sign and a trailing @-sign followed by the number of bytes of parameters taken by the function
    
//  thiscall
    the first parameter is passed in ECX(this), with the remainder passed on the stack as in __stdcall
    callee cleans the stack
    function names decorated by the C++ compiler in an extraordinarily complicated mechanism that encodes the types of each of the parameters, among the other things
    

struct ThreadParms
{
    void *(*start)(void*);
    void *arg;
};
typedef void* (*FUNC_POINTER) (void*);
static unsigned int __stdcall __cdecl2stdcall_thunk(void *p)
{
    ThreadParms *pc = (ThreadParms*)p;
    pc->start(pc->arg);
    delete pc;
    return 0;
}


int createThread(HANDLE &threadId, FUNC_POINTER cbFunc, void userDefined)
{
    ThreadParms *p = new ThreadParms();
    p->start = cbFunc;
    p->arg = userDefined;
    threadId = (HANDLE)_beginthreadex(NULL, 0, __cdecl2stdcall_thunk, p, 0, NULL);
    return 0;
}

