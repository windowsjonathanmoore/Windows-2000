// swprintf_fast.cpp
//

#include "stdafx.h"
#include <stdio.h>
#include "string_fast.h"


static const WCHAR char_table[4000] = {
    L'0',L'0',L'0',L'\0', L'0',L'0',L'1',L'\0', L'0',L'0',L'2',L'\0', L'0',L'0',L'3',L'\0', L'0',L'0',L'4',L'\0',
    L'0',L'0',L'5',L'\0', L'0',L'0',L'6',L'\0', L'0',L'0',L'7',L'\0', L'0',L'0',L'8',L'\0', L'0',L'0',L'9',L'\0',
    L'0',L'1',L'0',L'\0', L'0',L'1',L'1',L'\0', L'0',L'1',L'2',L'\0', L'0',L'1',L'3',L'\0', L'0',L'1',L'4',L'\0',
    L'0',L'1',L'5',L'\0', L'0',L'1',L'6',L'\0', L'0',L'1',L'7',L'\0', L'0',L'1',L'8',L'\0', L'0',L'1',L'9',L'\0',
    L'0',L'2',L'0',L'\0', L'0',L'2',L'1',L'\0', L'0',L'2',L'2',L'\0', L'0',L'2',L'3',L'\0', L'0',L'2',L'4',L'\0',
    L'0',L'2',L'5',L'\0', L'0',L'2',L'6',L'\0', L'0',L'2',L'7',L'\0', L'0',L'2',L'8',L'\0', L'0',L'2',L'9',L'\0',
    L'0',L'3',L'0',L'\0', L'0',L'3',L'1',L'\0', L'0',L'3',L'2',L'\0', L'0',L'3',L'3',L'\0', L'0',L'3',L'4',L'\0',
    L'0',L'3',L'5',L'\0', L'0',L'3',L'6',L'\0', L'0',L'3',L'7',L'\0', L'0',L'3',L'8',L'\0', L'0',L'3',L'9',L'\0',
    L'0',L'4',L'0',L'\0', L'0',L'4',L'1',L'\0', L'0',L'4',L'2',L'\0', L'0',L'4',L'3',L'\0', L'0',L'4',L'4',L'\0',
    L'0',L'4',L'5',L'\0', L'0',L'4',L'6',L'\0', L'0',L'4',L'7',L'\0', L'0',L'4',L'8',L'\0', L'0',L'4',L'9',L'\0',
    L'0',L'5',L'0',L'\0', L'0',L'5',L'1',L'\0', L'0',L'5',L'2',L'\0', L'0',L'5',L'3',L'\0', L'0',L'5',L'4',L'\0',
    L'0',L'5',L'5',L'\0', L'0',L'5',L'6',L'\0', L'0',L'5',L'7',L'\0', L'0',L'5',L'8',L'\0', L'0',L'5',L'9',L'\0',
    L'0',L'6',L'0',L'\0', L'0',L'6',L'1',L'\0', L'0',L'6',L'2',L'\0', L'0',L'6',L'3',L'\0', L'0',L'6',L'4',L'\0',
    L'0',L'6',L'5',L'\0', L'0',L'6',L'6',L'\0', L'0',L'6',L'7',L'\0', L'0',L'6',L'8',L'\0', L'0',L'6',L'9',L'\0',
    L'0',L'7',L'0',L'\0', L'0',L'7',L'1',L'\0', L'0',L'7',L'2',L'\0', L'0',L'7',L'3',L'\0', L'0',L'7',L'4',L'\0',
    L'0',L'7',L'5',L'\0', L'0',L'7',L'6',L'\0', L'0',L'7',L'7',L'\0', L'0',L'7',L'8',L'\0', L'0',L'7',L'9',L'\0',
    L'0',L'8',L'0',L'\0', L'0',L'8',L'1',L'\0', L'0',L'8',L'2',L'\0', L'0',L'8',L'3',L'\0', L'0',L'8',L'4',L'\0',
    L'0',L'8',L'5',L'\0', L'0',L'8',L'6',L'\0', L'0',L'8',L'7',L'\0', L'0',L'8',L'8',L'\0', L'0',L'8',L'9',L'\0',
    L'0',L'9',L'0',L'\0', L'0',L'9',L'1',L'\0', L'0',L'9',L'2',L'\0', L'0',L'9',L'3',L'\0', L'0',L'9',L'4',L'\0',
    L'0',L'9',L'5',L'\0', L'0',L'9',L'6',L'\0', L'0',L'9',L'7',L'\0', L'0',L'9',L'8',L'\0', L'0',L'9',L'9',L'\0',
    L'1',L'0',L'0',L'\0', L'1',L'0',L'1',L'\0', L'1',L'0',L'2',L'\0', L'1',L'0',L'3',L'\0', L'1',L'0',L'4',L'\0',
    L'1',L'0',L'5',L'\0', L'1',L'0',L'6',L'\0', L'1',L'0',L'7',L'\0', L'1',L'0',L'8',L'\0', L'1',L'0',L'9',L'\0',
    L'1',L'1',L'0',L'\0', L'1',L'1',L'1',L'\0', L'1',L'1',L'2',L'\0', L'1',L'1',L'3',L'\0', L'1',L'1',L'4',L'\0',
    L'1',L'1',L'5',L'\0', L'1',L'1',L'6',L'\0', L'1',L'1',L'7',L'\0', L'1',L'1',L'8',L'\0', L'1',L'1',L'9',L'\0',
    L'1',L'2',L'0',L'\0', L'1',L'2',L'1',L'\0', L'1',L'2',L'2',L'\0', L'1',L'2',L'3',L'\0', L'1',L'2',L'4',L'\0',
    L'1',L'2',L'5',L'\0', L'1',L'2',L'6',L'\0', L'1',L'2',L'7',L'\0', L'1',L'2',L'8',L'\0', L'1',L'2',L'9',L'\0',
    L'1',L'3',L'0',L'\0', L'1',L'3',L'1',L'\0', L'1',L'3',L'2',L'\0', L'1',L'3',L'3',L'\0', L'1',L'3',L'4',L'\0',
    L'1',L'3',L'5',L'\0', L'1',L'3',L'6',L'\0', L'1',L'3',L'7',L'\0', L'1',L'3',L'8',L'\0', L'1',L'3',L'9',L'\0',
    L'1',L'4',L'0',L'\0', L'1',L'4',L'1',L'\0', L'1',L'4',L'2',L'\0', L'1',L'4',L'3',L'\0', L'1',L'4',L'4',L'\0',
    L'1',L'4',L'5',L'\0', L'1',L'4',L'6',L'\0', L'1',L'4',L'7',L'\0', L'1',L'4',L'8',L'\0', L'1',L'4',L'9',L'\0',
    L'1',L'5',L'0',L'\0', L'1',L'5',L'1',L'\0', L'1',L'5',L'2',L'\0', L'1',L'5',L'3',L'\0', L'1',L'5',L'4',L'\0',
    L'1',L'5',L'5',L'\0', L'1',L'5',L'6',L'\0', L'1',L'5',L'7',L'\0', L'1',L'5',L'8',L'\0', L'1',L'5',L'9',L'\0',
    L'1',L'6',L'0',L'\0', L'1',L'6',L'1',L'\0', L'1',L'6',L'2',L'\0', L'1',L'6',L'3',L'\0', L'1',L'6',L'4',L'\0',
    L'1',L'6',L'5',L'\0', L'1',L'6',L'6',L'\0', L'1',L'6',L'7',L'\0', L'1',L'6',L'8',L'\0', L'1',L'6',L'9',L'\0',
    L'1',L'7',L'0',L'\0', L'1',L'7',L'1',L'\0', L'1',L'7',L'2',L'\0', L'1',L'7',L'3',L'\0', L'1',L'7',L'4',L'\0',
    L'1',L'7',L'5',L'\0', L'1',L'7',L'6',L'\0', L'1',L'7',L'7',L'\0', L'1',L'7',L'8',L'\0', L'1',L'7',L'9',L'\0',
    L'1',L'8',L'0',L'\0', L'1',L'8',L'1',L'\0', L'1',L'8',L'2',L'\0', L'1',L'8',L'3',L'\0', L'1',L'8',L'4',L'\0',
    L'1',L'8',L'5',L'\0', L'1',L'8',L'6',L'\0', L'1',L'8',L'7',L'\0', L'1',L'8',L'8',L'\0', L'1',L'8',L'9',L'\0',
    L'1',L'9',L'0',L'\0', L'1',L'9',L'1',L'\0', L'1',L'9',L'2',L'\0', L'1',L'9',L'3',L'\0', L'1',L'9',L'4',L'\0',
    L'1',L'9',L'5',L'\0', L'1',L'9',L'6',L'\0', L'1',L'9',L'7',L'\0', L'1',L'9',L'8',L'\0', L'1',L'9',L'9',L'\0',
    L'2',L'0',L'0',L'\0', L'2',L'0',L'1',L'\0', L'2',L'0',L'2',L'\0', L'2',L'0',L'3',L'\0', L'2',L'0',L'4',L'\0',
    L'2',L'0',L'5',L'\0', L'2',L'0',L'6',L'\0', L'2',L'0',L'7',L'\0', L'2',L'0',L'8',L'\0', L'2',L'0',L'9',L'\0',
    L'2',L'1',L'0',L'\0', L'2',L'1',L'1',L'\0', L'2',L'1',L'2',L'\0', L'2',L'1',L'3',L'\0', L'2',L'1',L'4',L'\0',
    L'2',L'1',L'5',L'\0', L'2',L'1',L'6',L'\0', L'2',L'1',L'7',L'\0', L'2',L'1',L'8',L'\0', L'2',L'1',L'9',L'\0',
    L'2',L'2',L'0',L'\0', L'2',L'2',L'1',L'\0', L'2',L'2',L'2',L'\0', L'2',L'2',L'3',L'\0', L'2',L'2',L'4',L'\0',
    L'2',L'2',L'5',L'\0', L'2',L'2',L'6',L'\0', L'2',L'2',L'7',L'\0', L'2',L'2',L'8',L'\0', L'2',L'2',L'9',L'\0',
    L'2',L'3',L'0',L'\0', L'2',L'3',L'1',L'\0', L'2',L'3',L'2',L'\0', L'2',L'3',L'3',L'\0', L'2',L'3',L'4',L'\0',
    L'2',L'3',L'5',L'\0', L'2',L'3',L'6',L'\0', L'2',L'3',L'7',L'\0', L'2',L'3',L'8',L'\0', L'2',L'3',L'9',L'\0',
    L'2',L'4',L'0',L'\0', L'2',L'4',L'1',L'\0', L'2',L'4',L'2',L'\0', L'2',L'4',L'3',L'\0', L'2',L'4',L'4',L'\0',
    L'2',L'4',L'5',L'\0', L'2',L'4',L'6',L'\0', L'2',L'4',L'7',L'\0', L'2',L'4',L'8',L'\0', L'2',L'4',L'9',L'\0',
    L'2',L'5',L'0',L'\0', L'2',L'5',L'1',L'\0', L'2',L'5',L'2',L'\0', L'2',L'5',L'3',L'\0', L'2',L'5',L'4',L'\0',
    L'2',L'5',L'5',L'\0', L'2',L'5',L'6',L'\0', L'2',L'5',L'7',L'\0', L'2',L'5',L'8',L'\0', L'2',L'5',L'9',L'\0',
    L'2',L'6',L'0',L'\0', L'2',L'6',L'1',L'\0', L'2',L'6',L'2',L'\0', L'2',L'6',L'3',L'\0', L'2',L'6',L'4',L'\0',
    L'2',L'6',L'5',L'\0', L'2',L'6',L'6',L'\0', L'2',L'6',L'7',L'\0', L'2',L'6',L'8',L'\0', L'2',L'6',L'9',L'\0',
    L'2',L'7',L'0',L'\0', L'2',L'7',L'1',L'\0', L'2',L'7',L'2',L'\0', L'2',L'7',L'3',L'\0', L'2',L'7',L'4',L'\0',
    L'2',L'7',L'5',L'\0', L'2',L'7',L'6',L'\0', L'2',L'7',L'7',L'\0', L'2',L'7',L'8',L'\0', L'2',L'7',L'9',L'\0',
    L'2',L'8',L'0',L'\0', L'2',L'8',L'1',L'\0', L'2',L'8',L'2',L'\0', L'2',L'8',L'3',L'\0', L'2',L'8',L'4',L'\0',
    L'2',L'8',L'5',L'\0', L'2',L'8',L'6',L'\0', L'2',L'8',L'7',L'\0', L'2',L'8',L'8',L'\0', L'2',L'8',L'9',L'\0',
    L'2',L'9',L'0',L'\0', L'2',L'9',L'1',L'\0', L'2',L'9',L'2',L'\0', L'2',L'9',L'3',L'\0', L'2',L'9',L'4',L'\0',
    L'2',L'9',L'5',L'\0', L'2',L'9',L'6',L'\0', L'2',L'9',L'7',L'\0', L'2',L'9',L'8',L'\0', L'2',L'9',L'9',L'\0',
    L'3',L'0',L'0',L'\0', L'3',L'0',L'1',L'\0', L'3',L'0',L'2',L'\0', L'3',L'0',L'3',L'\0', L'3',L'0',L'4',L'\0',
    L'3',L'0',L'5',L'\0', L'3',L'0',L'6',L'\0', L'3',L'0',L'7',L'\0', L'3',L'0',L'8',L'\0', L'3',L'0',L'9',L'\0',
    L'3',L'1',L'0',L'\0', L'3',L'1',L'1',L'\0', L'3',L'1',L'2',L'\0', L'3',L'1',L'3',L'\0', L'3',L'1',L'4',L'\0',
    L'3',L'1',L'5',L'\0', L'3',L'1',L'6',L'\0', L'3',L'1',L'7',L'\0', L'3',L'1',L'8',L'\0', L'3',L'1',L'9',L'\0',
    L'3',L'2',L'0',L'\0', L'3',L'2',L'1',L'\0', L'3',L'2',L'2',L'\0', L'3',L'2',L'3',L'\0', L'3',L'2',L'4',L'\0',
    L'3',L'2',L'5',L'\0', L'3',L'2',L'6',L'\0', L'3',L'2',L'7',L'\0', L'3',L'2',L'8',L'\0', L'3',L'2',L'9',L'\0',
    L'3',L'3',L'0',L'\0', L'3',L'3',L'1',L'\0', L'3',L'3',L'2',L'\0', L'3',L'3',L'3',L'\0', L'3',L'3',L'4',L'\0',
    L'3',L'3',L'5',L'\0', L'3',L'3',L'6',L'\0', L'3',L'3',L'7',L'\0', L'3',L'3',L'8',L'\0', L'3',L'3',L'9',L'\0',
    L'3',L'4',L'0',L'\0', L'3',L'4',L'1',L'\0', L'3',L'4',L'2',L'\0', L'3',L'4',L'3',L'\0', L'3',L'4',L'4',L'\0',
    L'3',L'4',L'5',L'\0', L'3',L'4',L'6',L'\0', L'3',L'4',L'7',L'\0', L'3',L'4',L'8',L'\0', L'3',L'4',L'9',L'\0',
    L'3',L'5',L'0',L'\0', L'3',L'5',L'1',L'\0', L'3',L'5',L'2',L'\0', L'3',L'5',L'3',L'\0', L'3',L'5',L'4',L'\0',
    L'3',L'5',L'5',L'\0', L'3',L'5',L'6',L'\0', L'3',L'5',L'7',L'\0', L'3',L'5',L'8',L'\0', L'3',L'5',L'9',L'\0',
    L'3',L'6',L'0',L'\0', L'3',L'6',L'1',L'\0', L'3',L'6',L'2',L'\0', L'3',L'6',L'3',L'\0', L'3',L'6',L'4',L'\0',
    L'3',L'6',L'5',L'\0', L'3',L'6',L'6',L'\0', L'3',L'6',L'7',L'\0', L'3',L'6',L'8',L'\0', L'3',L'6',L'9',L'\0',
    L'3',L'7',L'0',L'\0', L'3',L'7',L'1',L'\0', L'3',L'7',L'2',L'\0', L'3',L'7',L'3',L'\0', L'3',L'7',L'4',L'\0',
    L'3',L'7',L'5',L'\0', L'3',L'7',L'6',L'\0', L'3',L'7',L'7',L'\0', L'3',L'7',L'8',L'\0', L'3',L'7',L'9',L'\0',
    L'3',L'8',L'0',L'\0', L'3',L'8',L'1',L'\0', L'3',L'8',L'2',L'\0', L'3',L'8',L'3',L'\0', L'3',L'8',L'4',L'\0',
    L'3',L'8',L'5',L'\0', L'3',L'8',L'6',L'\0', L'3',L'8',L'7',L'\0', L'3',L'8',L'8',L'\0', L'3',L'8',L'9',L'\0',
    L'3',L'9',L'0',L'\0', L'3',L'9',L'1',L'\0', L'3',L'9',L'2',L'\0', L'3',L'9',L'3',L'\0', L'3',L'9',L'4',L'\0',
    L'3',L'9',L'5',L'\0', L'3',L'9',L'6',L'\0', L'3',L'9',L'7',L'\0', L'3',L'9',L'8',L'\0', L'3',L'9',L'9',L'\0',
    L'4',L'0',L'0',L'\0', L'4',L'0',L'1',L'\0', L'4',L'0',L'2',L'\0', L'4',L'0',L'3',L'\0', L'4',L'0',L'4',L'\0',
    L'4',L'0',L'5',L'\0', L'4',L'0',L'6',L'\0', L'4',L'0',L'7',L'\0', L'4',L'0',L'8',L'\0', L'4',L'0',L'9',L'\0',
    L'4',L'1',L'0',L'\0', L'4',L'1',L'1',L'\0', L'4',L'1',L'2',L'\0', L'4',L'1',L'3',L'\0', L'4',L'1',L'4',L'\0',
    L'4',L'1',L'5',L'\0', L'4',L'1',L'6',L'\0', L'4',L'1',L'7',L'\0', L'4',L'1',L'8',L'\0', L'4',L'1',L'9',L'\0',
    L'4',L'2',L'0',L'\0', L'4',L'2',L'1',L'\0', L'4',L'2',L'2',L'\0', L'4',L'2',L'3',L'\0', L'4',L'2',L'4',L'\0',
    L'4',L'2',L'5',L'\0', L'4',L'2',L'6',L'\0', L'4',L'2',L'7',L'\0', L'4',L'2',L'8',L'\0', L'4',L'2',L'9',L'\0',
    L'4',L'3',L'0',L'\0', L'4',L'3',L'1',L'\0', L'4',L'3',L'2',L'\0', L'4',L'3',L'3',L'\0', L'4',L'3',L'4',L'\0',
    L'4',L'3',L'5',L'\0', L'4',L'3',L'6',L'\0', L'4',L'3',L'7',L'\0', L'4',L'3',L'8',L'\0', L'4',L'3',L'9',L'\0',
    L'4',L'4',L'0',L'\0', L'4',L'4',L'1',L'\0', L'4',L'4',L'2',L'\0', L'4',L'4',L'3',L'\0', L'4',L'4',L'4',L'\0',
    L'4',L'4',L'5',L'\0', L'4',L'4',L'6',L'\0', L'4',L'4',L'7',L'\0', L'4',L'4',L'8',L'\0', L'4',L'4',L'9',L'\0',
    L'4',L'5',L'0',L'\0', L'4',L'5',L'1',L'\0', L'4',L'5',L'2',L'\0', L'4',L'5',L'3',L'\0', L'4',L'5',L'4',L'\0',
    L'4',L'5',L'5',L'\0', L'4',L'5',L'6',L'\0', L'4',L'5',L'7',L'\0', L'4',L'5',L'8',L'\0', L'4',L'5',L'9',L'\0',
    L'4',L'6',L'0',L'\0', L'4',L'6',L'1',L'\0', L'4',L'6',L'2',L'\0', L'4',L'6',L'3',L'\0', L'4',L'6',L'4',L'\0',
    L'4',L'6',L'5',L'\0', L'4',L'6',L'6',L'\0', L'4',L'6',L'7',L'\0', L'4',L'6',L'8',L'\0', L'4',L'6',L'9',L'\0',
    L'4',L'7',L'0',L'\0', L'4',L'7',L'1',L'\0', L'4',L'7',L'2',L'\0', L'4',L'7',L'3',L'\0', L'4',L'7',L'4',L'\0',
    L'4',L'7',L'5',L'\0', L'4',L'7',L'6',L'\0', L'4',L'7',L'7',L'\0', L'4',L'7',L'8',L'\0', L'4',L'7',L'9',L'\0',
    L'4',L'8',L'0',L'\0', L'4',L'8',L'1',L'\0', L'4',L'8',L'2',L'\0', L'4',L'8',L'3',L'\0', L'4',L'8',L'4',L'\0',
    L'4',L'8',L'5',L'\0', L'4',L'8',L'6',L'\0', L'4',L'8',L'7',L'\0', L'4',L'8',L'8',L'\0', L'4',L'8',L'9',L'\0',
    L'4',L'9',L'0',L'\0', L'4',L'9',L'1',L'\0', L'4',L'9',L'2',L'\0', L'4',L'9',L'3',L'\0', L'4',L'9',L'4',L'\0',
    L'4',L'9',L'5',L'\0', L'4',L'9',L'6',L'\0', L'4',L'9',L'7',L'\0', L'4',L'9',L'8',L'\0', L'4',L'9',L'9',L'\0',
    L'5',L'0',L'0',L'\0', L'5',L'0',L'1',L'\0', L'5',L'0',L'2',L'\0', L'5',L'0',L'3',L'\0', L'5',L'0',L'4',L'\0',
    L'5',L'0',L'5',L'\0', L'5',L'0',L'6',L'\0', L'5',L'0',L'7',L'\0', L'5',L'0',L'8',L'\0', L'5',L'0',L'9',L'\0',
    L'5',L'1',L'0',L'\0', L'5',L'1',L'1',L'\0', L'5',L'1',L'2',L'\0', L'5',L'1',L'3',L'\0', L'5',L'1',L'4',L'\0',
    L'5',L'1',L'5',L'\0', L'5',L'1',L'6',L'\0', L'5',L'1',L'7',L'\0', L'5',L'1',L'8',L'\0', L'5',L'1',L'9',L'\0',
    L'5',L'2',L'0',L'\0', L'5',L'2',L'1',L'\0', L'5',L'2',L'2',L'\0', L'5',L'2',L'3',L'\0', L'5',L'2',L'4',L'\0',
    L'5',L'2',L'5',L'\0', L'5',L'2',L'6',L'\0', L'5',L'2',L'7',L'\0', L'5',L'2',L'8',L'\0', L'5',L'2',L'9',L'\0',
    L'5',L'3',L'0',L'\0', L'5',L'3',L'1',L'\0', L'5',L'3',L'2',L'\0', L'5',L'3',L'3',L'\0', L'5',L'3',L'4',L'\0',
    L'5',L'3',L'5',L'\0', L'5',L'3',L'6',L'\0', L'5',L'3',L'7',L'\0', L'5',L'3',L'8',L'\0', L'5',L'3',L'9',L'\0',
    L'5',L'4',L'0',L'\0', L'5',L'4',L'1',L'\0', L'5',L'4',L'2',L'\0', L'5',L'4',L'3',L'\0', L'5',L'4',L'4',L'\0',
    L'5',L'4',L'5',L'\0', L'5',L'4',L'6',L'\0', L'5',L'4',L'7',L'\0', L'5',L'4',L'8',L'\0', L'5',L'4',L'9',L'\0',
    L'5',L'5',L'0',L'\0', L'5',L'5',L'1',L'\0', L'5',L'5',L'2',L'\0', L'5',L'5',L'3',L'\0', L'5',L'5',L'4',L'\0',
    L'5',L'5',L'5',L'\0', L'5',L'5',L'6',L'\0', L'5',L'5',L'7',L'\0', L'5',L'5',L'8',L'\0', L'5',L'5',L'9',L'\0',
    L'5',L'6',L'0',L'\0', L'5',L'6',L'1',L'\0', L'5',L'6',L'2',L'\0', L'5',L'6',L'3',L'\0', L'5',L'6',L'4',L'\0',
    L'5',L'6',L'5',L'\0', L'5',L'6',L'6',L'\0', L'5',L'6',L'7',L'\0', L'5',L'6',L'8',L'\0', L'5',L'6',L'9',L'\0',
    L'5',L'7',L'0',L'\0', L'5',L'7',L'1',L'\0', L'5',L'7',L'2',L'\0', L'5',L'7',L'3',L'\0', L'5',L'7',L'4',L'\0',
    L'5',L'7',L'5',L'\0', L'5',L'7',L'6',L'\0', L'5',L'7',L'7',L'\0', L'5',L'7',L'8',L'\0', L'5',L'7',L'9',L'\0',
    L'5',L'8',L'0',L'\0', L'5',L'8',L'1',L'\0', L'5',L'8',L'2',L'\0', L'5',L'8',L'3',L'\0', L'5',L'8',L'4',L'\0',
    L'5',L'8',L'5',L'\0', L'5',L'8',L'6',L'\0', L'5',L'8',L'7',L'\0', L'5',L'8',L'8',L'\0', L'5',L'8',L'9',L'\0',
    L'5',L'9',L'0',L'\0', L'5',L'9',L'1',L'\0', L'5',L'9',L'2',L'\0', L'5',L'9',L'3',L'\0', L'5',L'9',L'4',L'\0',
    L'5',L'9',L'5',L'\0', L'5',L'9',L'6',L'\0', L'5',L'9',L'7',L'\0', L'5',L'9',L'8',L'\0', L'5',L'9',L'9',L'\0',
    L'6',L'0',L'0',L'\0', L'6',L'0',L'1',L'\0', L'6',L'0',L'2',L'\0', L'6',L'0',L'3',L'\0', L'6',L'0',L'4',L'\0',
    L'6',L'0',L'5',L'\0', L'6',L'0',L'6',L'\0', L'6',L'0',L'7',L'\0', L'6',L'0',L'8',L'\0', L'6',L'0',L'9',L'\0',
    L'6',L'1',L'0',L'\0', L'6',L'1',L'1',L'\0', L'6',L'1',L'2',L'\0', L'6',L'1',L'3',L'\0', L'6',L'1',L'4',L'\0',
    L'6',L'1',L'5',L'\0', L'6',L'1',L'6',L'\0', L'6',L'1',L'7',L'\0', L'6',L'1',L'8',L'\0', L'6',L'1',L'9',L'\0',
    L'6',L'2',L'0',L'\0', L'6',L'2',L'1',L'\0', L'6',L'2',L'2',L'\0', L'6',L'2',L'3',L'\0', L'6',L'2',L'4',L'\0',
    L'6',L'2',L'5',L'\0', L'6',L'2',L'6',L'\0', L'6',L'2',L'7',L'\0', L'6',L'2',L'8',L'\0', L'6',L'2',L'9',L'\0',
    L'6',L'3',L'0',L'\0', L'6',L'3',L'1',L'\0', L'6',L'3',L'2',L'\0', L'6',L'3',L'3',L'\0', L'6',L'3',L'4',L'\0',
    L'6',L'3',L'5',L'\0', L'6',L'3',L'6',L'\0', L'6',L'3',L'7',L'\0', L'6',L'3',L'8',L'\0', L'6',L'3',L'9',L'\0',
    L'6',L'4',L'0',L'\0', L'6',L'4',L'1',L'\0', L'6',L'4',L'2',L'\0', L'6',L'4',L'3',L'\0', L'6',L'4',L'4',L'\0',
    L'6',L'4',L'5',L'\0', L'6',L'4',L'6',L'\0', L'6',L'4',L'7',L'\0', L'6',L'4',L'8',L'\0', L'6',L'4',L'9',L'\0',
    L'6',L'5',L'0',L'\0', L'6',L'5',L'1',L'\0', L'6',L'5',L'2',L'\0', L'6',L'5',L'3',L'\0', L'6',L'5',L'4',L'\0',
    L'6',L'5',L'5',L'\0', L'6',L'5',L'6',L'\0', L'6',L'5',L'7',L'\0', L'6',L'5',L'8',L'\0', L'6',L'5',L'9',L'\0',
    L'6',L'6',L'0',L'\0', L'6',L'6',L'1',L'\0', L'6',L'6',L'2',L'\0', L'6',L'6',L'3',L'\0', L'6',L'6',L'4',L'\0',
    L'6',L'6',L'5',L'\0', L'6',L'6',L'6',L'\0', L'6',L'6',L'7',L'\0', L'6',L'6',L'8',L'\0', L'6',L'6',L'9',L'\0',
    L'6',L'7',L'0',L'\0', L'6',L'7',L'1',L'\0', L'6',L'7',L'2',L'\0', L'6',L'7',L'3',L'\0', L'6',L'7',L'4',L'\0',
    L'6',L'7',L'5',L'\0', L'6',L'7',L'6',L'\0', L'6',L'7',L'7',L'\0', L'6',L'7',L'8',L'\0', L'6',L'7',L'9',L'\0',
    L'6',L'8',L'0',L'\0', L'6',L'8',L'1',L'\0', L'6',L'8',L'2',L'\0', L'6',L'8',L'3',L'\0', L'6',L'8',L'4',L'\0',
    L'6',L'8',L'5',L'\0', L'6',L'8',L'6',L'\0', L'6',L'8',L'7',L'\0', L'6',L'8',L'8',L'\0', L'6',L'8',L'9',L'\0',
    L'6',L'9',L'0',L'\0', L'6',L'9',L'1',L'\0', L'6',L'9',L'2',L'\0', L'6',L'9',L'3',L'\0', L'6',L'9',L'4',L'\0',
    L'6',L'9',L'5',L'\0', L'6',L'9',L'6',L'\0', L'6',L'9',L'7',L'\0', L'6',L'9',L'8',L'\0', L'6',L'9',L'9',L'\0',
    L'7',L'0',L'0',L'\0', L'7',L'0',L'1',L'\0', L'7',L'0',L'2',L'\0', L'7',L'0',L'3',L'\0', L'7',L'0',L'4',L'\0',
    L'7',L'0',L'5',L'\0', L'7',L'0',L'6',L'\0', L'7',L'0',L'7',L'\0', L'7',L'0',L'8',L'\0', L'7',L'0',L'9',L'\0',
    L'7',L'1',L'0',L'\0', L'7',L'1',L'1',L'\0', L'7',L'1',L'2',L'\0', L'7',L'1',L'3',L'\0', L'7',L'1',L'4',L'\0',
    L'7',L'1',L'5',L'\0', L'7',L'1',L'6',L'\0', L'7',L'1',L'7',L'\0', L'7',L'1',L'8',L'\0', L'7',L'1',L'9',L'\0',
    L'7',L'2',L'0',L'\0', L'7',L'2',L'1',L'\0', L'7',L'2',L'2',L'\0', L'7',L'2',L'3',L'\0', L'7',L'2',L'4',L'\0',
    L'7',L'2',L'5',L'\0', L'7',L'2',L'6',L'\0', L'7',L'2',L'7',L'\0', L'7',L'2',L'8',L'\0', L'7',L'2',L'9',L'\0',
    L'7',L'3',L'0',L'\0', L'7',L'3',L'1',L'\0', L'7',L'3',L'2',L'\0', L'7',L'3',L'3',L'\0', L'7',L'3',L'4',L'\0',
    L'7',L'3',L'5',L'\0', L'7',L'3',L'6',L'\0', L'7',L'3',L'7',L'\0', L'7',L'3',L'8',L'\0', L'7',L'3',L'9',L'\0',
    L'7',L'4',L'0',L'\0', L'7',L'4',L'1',L'\0', L'7',L'4',L'2',L'\0', L'7',L'4',L'3',L'\0', L'7',L'4',L'4',L'\0',
    L'7',L'4',L'5',L'\0', L'7',L'4',L'6',L'\0', L'7',L'4',L'7',L'\0', L'7',L'4',L'8',L'\0', L'7',L'4',L'9',L'\0',
    L'7',L'5',L'0',L'\0', L'7',L'5',L'1',L'\0', L'7',L'5',L'2',L'\0', L'7',L'5',L'3',L'\0', L'7',L'5',L'4',L'\0',
    L'7',L'5',L'5',L'\0', L'7',L'5',L'6',L'\0', L'7',L'5',L'7',L'\0', L'7',L'5',L'8',L'\0', L'7',L'5',L'9',L'\0',
    L'7',L'6',L'0',L'\0', L'7',L'6',L'1',L'\0', L'7',L'6',L'2',L'\0', L'7',L'6',L'3',L'\0', L'7',L'6',L'4',L'\0',
    L'7',L'6',L'5',L'\0', L'7',L'6',L'6',L'\0', L'7',L'6',L'7',L'\0', L'7',L'6',L'8',L'\0', L'7',L'6',L'9',L'\0',
    L'7',L'7',L'0',L'\0', L'7',L'7',L'1',L'\0', L'7',L'7',L'2',L'\0', L'7',L'7',L'3',L'\0', L'7',L'7',L'4',L'\0',
    L'7',L'7',L'5',L'\0', L'7',L'7',L'6',L'\0', L'7',L'7',L'7',L'\0', L'7',L'7',L'8',L'\0', L'7',L'7',L'9',L'\0',
    L'7',L'8',L'0',L'\0', L'7',L'8',L'1',L'\0', L'7',L'8',L'2',L'\0', L'7',L'8',L'3',L'\0', L'7',L'8',L'4',L'\0',
    L'7',L'8',L'5',L'\0', L'7',L'8',L'6',L'\0', L'7',L'8',L'7',L'\0', L'7',L'8',L'8',L'\0', L'7',L'8',L'9',L'\0',
    L'7',L'9',L'0',L'\0', L'7',L'9',L'1',L'\0', L'7',L'9',L'2',L'\0', L'7',L'9',L'3',L'\0', L'7',L'9',L'4',L'\0',
    L'7',L'9',L'5',L'\0', L'7',L'9',L'6',L'\0', L'7',L'9',L'7',L'\0', L'7',L'9',L'8',L'\0', L'7',L'9',L'9',L'\0',
    L'8',L'0',L'0',L'\0', L'8',L'0',L'1',L'\0', L'8',L'0',L'2',L'\0', L'8',L'0',L'3',L'\0', L'8',L'0',L'4',L'\0',
    L'8',L'0',L'5',L'\0', L'8',L'0',L'6',L'\0', L'8',L'0',L'7',L'\0', L'8',L'0',L'8',L'\0', L'8',L'0',L'9',L'\0',
    L'8',L'1',L'0',L'\0', L'8',L'1',L'1',L'\0', L'8',L'1',L'2',L'\0', L'8',L'1',L'3',L'\0', L'8',L'1',L'4',L'\0',
    L'8',L'1',L'5',L'\0', L'8',L'1',L'6',L'\0', L'8',L'1',L'7',L'\0', L'8',L'1',L'8',L'\0', L'8',L'1',L'9',L'\0',
    L'8',L'2',L'0',L'\0', L'8',L'2',L'1',L'\0', L'8',L'2',L'2',L'\0', L'8',L'2',L'3',L'\0', L'8',L'2',L'4',L'\0',
    L'8',L'2',L'5',L'\0', L'8',L'2',L'6',L'\0', L'8',L'2',L'7',L'\0', L'8',L'2',L'8',L'\0', L'8',L'2',L'9',L'\0',
    L'8',L'3',L'0',L'\0', L'8',L'3',L'1',L'\0', L'8',L'3',L'2',L'\0', L'8',L'3',L'3',L'\0', L'8',L'3',L'4',L'\0',
    L'8',L'3',L'5',L'\0', L'8',L'3',L'6',L'\0', L'8',L'3',L'7',L'\0', L'8',L'3',L'8',L'\0', L'8',L'3',L'9',L'\0',
    L'8',L'4',L'0',L'\0', L'8',L'4',L'1',L'\0', L'8',L'4',L'2',L'\0', L'8',L'4',L'3',L'\0', L'8',L'4',L'4',L'\0',
    L'8',L'4',L'5',L'\0', L'8',L'4',L'6',L'\0', L'8',L'4',L'7',L'\0', L'8',L'4',L'8',L'\0', L'8',L'4',L'9',L'\0',
    L'8',L'5',L'0',L'\0', L'8',L'5',L'1',L'\0', L'8',L'5',L'2',L'\0', L'8',L'5',L'3',L'\0', L'8',L'5',L'4',L'\0',
    L'8',L'5',L'5',L'\0', L'8',L'5',L'6',L'\0', L'8',L'5',L'7',L'\0', L'8',L'5',L'8',L'\0', L'8',L'5',L'9',L'\0',
    L'8',L'6',L'0',L'\0', L'8',L'6',L'1',L'\0', L'8',L'6',L'2',L'\0', L'8',L'6',L'3',L'\0', L'8',L'6',L'4',L'\0',
    L'8',L'6',L'5',L'\0', L'8',L'6',L'6',L'\0', L'8',L'6',L'7',L'\0', L'8',L'6',L'8',L'\0', L'8',L'6',L'9',L'\0',
    L'8',L'7',L'0',L'\0', L'8',L'7',L'1',L'\0', L'8',L'7',L'2',L'\0', L'8',L'7',L'3',L'\0', L'8',L'7',L'4',L'\0',
    L'8',L'7',L'5',L'\0', L'8',L'7',L'6',L'\0', L'8',L'7',L'7',L'\0', L'8',L'7',L'8',L'\0', L'8',L'7',L'9',L'\0',
    L'8',L'8',L'0',L'\0', L'8',L'8',L'1',L'\0', L'8',L'8',L'2',L'\0', L'8',L'8',L'3',L'\0', L'8',L'8',L'4',L'\0',
    L'8',L'8',L'5',L'\0', L'8',L'8',L'6',L'\0', L'8',L'8',L'7',L'\0', L'8',L'8',L'8',L'\0', L'8',L'8',L'9',L'\0',
    L'8',L'9',L'0',L'\0', L'8',L'9',L'1',L'\0', L'8',L'9',L'2',L'\0', L'8',L'9',L'3',L'\0', L'8',L'9',L'4',L'\0',
    L'8',L'9',L'5',L'\0', L'8',L'9',L'6',L'\0', L'8',L'9',L'7',L'\0', L'8',L'9',L'8',L'\0', L'8',L'9',L'9',L'\0',
    L'9',L'0',L'0',L'\0', L'9',L'0',L'1',L'\0', L'9',L'0',L'2',L'\0', L'9',L'0',L'3',L'\0', L'9',L'0',L'4',L'\0',
    L'9',L'0',L'5',L'\0', L'9',L'0',L'6',L'\0', L'9',L'0',L'7',L'\0', L'9',L'0',L'8',L'\0', L'9',L'0',L'9',L'\0',
    L'9',L'1',L'0',L'\0', L'9',L'1',L'1',L'\0', L'9',L'1',L'2',L'\0', L'9',L'1',L'3',L'\0', L'9',L'1',L'4',L'\0',
    L'9',L'1',L'5',L'\0', L'9',L'1',L'6',L'\0', L'9',L'1',L'7',L'\0', L'9',L'1',L'8',L'\0', L'9',L'1',L'9',L'\0',
    L'9',L'2',L'0',L'\0', L'9',L'2',L'1',L'\0', L'9',L'2',L'2',L'\0', L'9',L'2',L'3',L'\0', L'9',L'2',L'4',L'\0',
    L'9',L'2',L'5',L'\0', L'9',L'2',L'6',L'\0', L'9',L'2',L'7',L'\0', L'9',L'2',L'8',L'\0', L'9',L'2',L'9',L'\0',
    L'9',L'3',L'0',L'\0', L'9',L'3',L'1',L'\0', L'9',L'3',L'2',L'\0', L'9',L'3',L'3',L'\0', L'9',L'3',L'4',L'\0',
    L'9',L'3',L'5',L'\0', L'9',L'3',L'6',L'\0', L'9',L'3',L'7',L'\0', L'9',L'3',L'8',L'\0', L'9',L'3',L'9',L'\0',
    L'9',L'4',L'0',L'\0', L'9',L'4',L'1',L'\0', L'9',L'4',L'2',L'\0', L'9',L'4',L'3',L'\0', L'9',L'4',L'4',L'\0',
    L'9',L'4',L'5',L'\0', L'9',L'4',L'6',L'\0', L'9',L'4',L'7',L'\0', L'9',L'4',L'8',L'\0', L'9',L'4',L'9',L'\0',
    L'9',L'5',L'0',L'\0', L'9',L'5',L'1',L'\0', L'9',L'5',L'2',L'\0', L'9',L'5',L'3',L'\0', L'9',L'5',L'4',L'\0',
    L'9',L'5',L'5',L'\0', L'9',L'5',L'6',L'\0', L'9',L'5',L'7',L'\0', L'9',L'5',L'8',L'\0', L'9',L'5',L'9',L'\0',
    L'9',L'6',L'0',L'\0', L'9',L'6',L'1',L'\0', L'9',L'6',L'2',L'\0', L'9',L'6',L'3',L'\0', L'9',L'6',L'4',L'\0',
    L'9',L'6',L'5',L'\0', L'9',L'6',L'6',L'\0', L'9',L'6',L'7',L'\0', L'9',L'6',L'8',L'\0', L'9',L'6',L'9',L'\0',
    L'9',L'7',L'0',L'\0', L'9',L'7',L'1',L'\0', L'9',L'7',L'2',L'\0', L'9',L'7',L'3',L'\0', L'9',L'7',L'4',L'\0',
    L'9',L'7',L'5',L'\0', L'9',L'7',L'6',L'\0', L'9',L'7',L'7',L'\0', L'9',L'7',L'8',L'\0', L'9',L'7',L'9',L'\0',
    L'9',L'8',L'0',L'\0', L'9',L'8',L'1',L'\0', L'9',L'8',L'2',L'\0', L'9',L'8',L'3',L'\0', L'9',L'8',L'4',L'\0',
    L'9',L'8',L'5',L'\0', L'9',L'8',L'6',L'\0', L'9',L'8',L'7',L'\0', L'9',L'8',L'8',L'\0', L'9',L'8',L'9',L'\0',
    L'9',L'9',L'0',L'\0', L'9',L'9',L'1',L'\0', L'9',L'9',L'2',L'\0', L'9',L'9',L'3',L'\0', L'9',L'9',L'4',L'\0',
    L'9',L'9',L'5',L'\0', L'9',L'9',L'6',L'\0', L'9',L'9',L'7',L'\0', L'9',L'9',L'8',L'\0', L'9',L'9',L'9',L'\0'};

inline long wcscpy_count (WCHAR *d, WCHAR const *s)
{
	register int i = 0;
	while (d[i] = s[i])
		++i;
	return (i);
}

inline long WriteChars(WCHAR* str, const WCHAR *text)
{
	return wcscpy_count(str, text);
}

inline long WriteChars(WCHAR* str, const WCHAR *name, const WCHAR *data, int slen, bool bQuotes)
{
	long length = 0;
	
	length += wcscpy_count(&str[length], name);

	if (bQuotes)
		length += wcscpy_count(&str[length], L" = \"");
	else
		length += wcscpy_count(&str[length], L" = ");

	if (slen > 0)
	{
		wcsncpy_fast(&str[length], data, slen);

		length += slen;
	}
	else
	{
		length += wcscpy_count(&str[length], data);
	}

	if (bQuotes)
		length += wcscpy_count(&str[length], L"\", ");
	else
		length += wcscpy_count(&str[length], L", ");

	return length;
}

inline long WriteChars(WCHAR* str, const WCHAR *name, const WCHAR *month, short nDay, short nYear)
{
	long length = 0;
	
	length += wcscpy_count(&str[length], name);
	length += wcscpy_count(&str[length], L" = \"");
	length += wcscpy_count(&str[length], month);
	length += WriteChars(&str[length], nDay);
	str[length++] = L' ';
	length += WriteChars(&str[length], nYear);
	length += wcscpy_count(&str[length], L"\", ");
	return length;
}

inline long WriteChars(WCHAR* str, const WCHAR *str1, const WCHAR *str2, const WCHAR *str3)
{
	long length = 0;
	
	length += wcscpy_count(&str[length], str1);
	str[length++] = L' ';
	length += wcscpy_count(&str[length], str2);
	str[length++] = L' ';
	length += wcscpy_count(&str[length], str3);
	return length;
}

inline long WriteChars(WCHAR* string, int nData)
{
	WCHAR *str = string;

	WCHAR buffer[32];

	register unsigned int v2;
	register const WCHAR *ap;
	register WCHAR *s = buffer + 30;
	if (nData <= 0)
	{
		if (nData == 0)
		{
			*str++ = L'0';
			return str - string;
		}
		else
		{
			*str++ = L'-';
			#pragma warning (disable:4146)
			nData = -nData;
			#pragma warning (default:4146)
		}
	}
	s[1] = L'\0';
	
	do
	{
		v2 = nData / 1000;
		ap = char_table + 2 + ((nData - 1000 * v2) << 2);
		*s-- = *ap--;
		*s-- = *ap--;
		*s-- = *ap;
	}
	while ((nData = v2) > 0);

	while (L'0' == *++s);
	*str = *s;
	while ((*++str = *++s));

	return str - string;
}

inline long WriteChars(WCHAR* string, const WCHAR *name, int nData)
{
	long length = 0;
	
	length += wcscpy_count(&string[length], name);
	length += wcscpy_count(&string[length], L" = ");

	WCHAR *str = &string[length];

	WCHAR buffer[32];

	register unsigned int v2;
	register const WCHAR *ap;
	register WCHAR *s = buffer + 30;
	if (nData <= 0)
	{
		if (nData == 0)
		{
			*str++ = L'0';
			length = str - string;

			length += wcscpy_count(&string[length], L", ");

			return length;
		}
		else
		{
			*str++ = L'-';
			#pragma warning (disable:4146)
			nData = -nData;
			#pragma warning (default:4146)
		}
	}
	s[1] = L'\0';
	
	do
	{
		v2 = nData / 1000;
		ap = char_table + 2 + ((nData - 1000 * v2) << 2);
		*s-- = *ap--;
		*s-- = *ap--;
		*s-- = *ap;
	}
	while ((nData = v2) > 0);

	while (L'0' == *++s);
	*str = *s;
	while ((*++str = *++s));

	length = str - string;

	length += wcscpy_count(&string[length], L", ");

	return length;
}

WCHAR *wcscpy_fast (WCHAR *d, WCHAR const *s)
{
	register int i = 0;
	while (d[i] = s[i])
		++i;
	return (d);
}

inline WCHAR *wcsncpy_fast (WCHAR * dest, const WCHAR * source, size_t count)
{
	dest[count] = L'\0';
	while ((count-- > 0) && (dest[count] = source[count]) != 0);    /* copy string */

	return dest;
}

int wcsncmp_fast (const WCHAR * first, const WCHAR * last, size_t count)
{
	if (!count)
		return(0);
	register int i = -1;

	do
	{
		i++;
	}
	while (--count && first[i] && first[i] == last[i]);
	return((int)(first[i] - last[i]));
}

int __cdecl wcscmp_fast (const WCHAR * src, const WCHAR * dst)
{
	register int i = -1;

	do
	{
		i++;
	}
	while (dst[i] && src[i] == dst[i]);

	return((int)(src[i] - dst[i]));
}