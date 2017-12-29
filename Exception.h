#ifndef EXCEPTIONS_FROM_SCRATCH_EXCEPTION_H
#define EXCEPTIONS_FROM_SCRATCH_EXCEPTION_H

typedef enum ExceptionCode {
    EXCEPTION_NONE,
    // place new codes here
} ExceptionCode;

typedef struct Exception {
    const ExceptionCode code;
    const char* const   file;
    const char* const   message;
    const unsigned int  line;
} Exception;

#define Try jmp_buf ctx; if(setjmp(ctx) == 0)

#define Catch(x) else


#define Throw(code, msg) Exception es =  {code, __FILE__, msg, __LINE__}; \
                         e = es;                                          \
                         longjmp(ctx, code)                               \

#endif
