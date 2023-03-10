/***
*excpt.h - defines exception values, types and routines
*
*	Copyright (c) 1990-1994, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file contains the definitions and prototypes for the compiler-
*	dependent intrinsics, support functions and keywords which implement
*	the structured exception handling extensions.
*
****/

#ifndef _INC_EXCPT

#ifdef __cplusplus
extern "C" {
#endif


/*
 * Conditional macro definition for function calling type and variable type
 * qualifiers.
 */
#if   ( (_MSC_VER >= 800) && (_M_IX86 >= 300) )

/*
 * Definitions for MS C8-32 (386/486) compiler
 */
#define _CRTAPI1 __cdecl
#define _CRTAPI2 __cdecl

#else

/*
 * Other compilers (e.g., MIPS)
 */
#define _CRTAPI1
#define _CRTAPI2

#endif


/*
 * Exception disposition return values.
 */
typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;


/*
 * Prototype for SEH support function.
 */

#ifdef	_M_IX86

/*
 * Declarations to keep MS C 8 (386/486) compiler happy
 */
struct _EXCEPTION_RECORD;
struct _CONTEXT;

EXCEPTION_DISPOSITION _CRTAPI2 _except_handler (
	struct _EXCEPTION_RECORD *ExceptionRecord,
	void * EstablisherFrame,
	struct _CONTEXT *ContextRecord,
	void * DispatcherContext
	);

#elif defined(_M_MRX000) || defined(_MIPS_) || defined(_ALPHA_)

/*
 * Declarations to keep MIPS and ALPHA compiler happy
 */
typedef struct _EXCEPTION_POINTERS *Exception_info_ptr;
struct _EXCEPTION_RECORD;
struct _CONTEXT;
struct _DISPATCHER_CONTEXT;


EXCEPTION_DISPOSITION __C_specific_handler (
	struct _EXCEPTION_RECORD *ExceptionRecord,
	void *EstablisherFrame,
	struct _CONTEXT *ContextRecord,
	struct _DISPATCHER_CONTEXT *DispatcherContext
	);

#endif


/*
 * Keywords and intrinsics for SEH
 */

#if	( _MSC_VER >= 800 )
/*
 * MS C8-32 (386/486)
 */
#define try				_try
#define except				_except
#define finally 			_finally
#define leave				_leave
#define GetExceptionCode		_exception_code
#define exception_code			_exception_code
#define GetExceptionInformation 	(struct _EXCEPTION_POINTERS *)_exception_info
#define exception_info			(struct _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination		_abnormal_termination
#define abnormal_termination		_abnormal_termination

unsigned long _CRTAPI1 _exception_code(void);
void *	      _CRTAPI1 _exception_info(void);
int	      _CRTAPI1 _abnormal_termination(void);

#elif defined(_M_MRX000) || defined(_MIPS_) || defined(_ALPHA_)
/*
 * MIPS or ALPHA compiler
 */
#define try				__builtin_try
#define except				__builtin_except
#define finally 			__builtin_finally
#define leave				__builtin_leave
#define GetExceptionCode()		__exception_code
#define exception_code()		__exception_code
#define GetExceptionInformation()	(struct _EXCEPTION_POINTERS *)__exception_info
#define exception_info()		(struct _EXCEPTION_POINTERS *)__exception_info
#define AbnormalTermination()		__abnormal_termination
#define abnormal_termination()		__abnormal_termination

extern unsigned long __exception_code;
extern int	     __exception_info;
extern int	     __abnormal_termination;

#endif


/*
 * Legal values for expression in except().
 */

#define EXCEPTION_EXECUTE_HANDLER	 1
#define EXCEPTION_CONTINUE_SEARCH	 0
#define EXCEPTION_CONTINUE_EXECUTION	-1



#ifdef __cplusplus
}
#endif

#define _INC_EXCPT
#endif	/* _INC_EXCPT */
