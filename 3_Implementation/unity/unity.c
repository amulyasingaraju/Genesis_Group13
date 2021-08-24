/* =========================================================================
    Unity Project - A Test Framework for C
    Copyright (c) 2007-19 Mike Karlesky, Mark VanderVoord, Greg Williams
    [Released under MIT License. Please refer to license.txt for details]
============================================================================ */

#include "unity.h"
#include <stddef.h>

#ifdef AVR
#include <avr/pgmspace.h>
#else
#define PROGMEM
#endif

/* If omitted from header, declare overrideable prototypes here so they're ready for use */
#ifdef UNITY_OMIT_OUTPUT_CHAR_HEADER_DECLARATION
void UNITY_OUTPUT_CHAR(int);
#endif

/* Helpful macros for us to use here in Assert functions */
#define UNITY_FAIL_AND_BAIL   { Unity.CurrentTestFailed  = 1; UNITY_OUTPUT_FLUSH(); TEST_ABORT(); }
#define UNITY_IGNORE_AND_BAIL { Unity.CurrentTestIgnored = 1; UNITY_OUTPUT_FLUSH(); TEST_ABORT(); }
#define RETURN_IF_FAIL_OR_IGNORE if (Unity.CurrentTestFailed || Unity.CurrentTestIgnored) TEST_ABORT()

struct UNITY_STORAGE_T Unity;

#ifdef UNITY_OUTPUT_COLOR
const char PROGMEM UnityStrOk[]                            = "\033[42mOK\033[00m";
const char PROGMEM UnityStrPass[]                          = "\033[42mPASS\033[00m";
const char PROGMEM UnityStrFail[]                          = "\033[41mFAIL\033[00m";
const char PROGMEM UnityStrIgnore[]                        = "\033[43mIGNORE\033[00m";
#else
const char PROGMEM UnityStrOk[]                            = "OK";
const char PROGMEM UnityStrPass[]                          = "PASS";
const char PROGMEM UnityStrFail[]                          = "FAIL";
const char PROGMEM UnityStrIgnore[]                        = "IGNORE";
#endif
static const char PROGMEM UnityStrNull[]                   = "NULL";
static const char PROGMEM UnityStrSpacer[]                 = ". ";
static const char PROGMEM UnityStrExpected[]               = " Expected ";
static const char PROGMEM UnityStrWas[]                    = " Was ";
static const char PROGMEM UnityStrGt[]                     = " to be greater than ";
static const char PROGMEM UnityStrLt[]                     = " to be less than ";
static const char PROGMEM UnityStrOrEqual[]                = "or equal to ";
static const char PROGMEM UnityStrNotEqual[]               = " to be not equal to ";
static const char PROGMEM UnityStrElement[]                = " Element ";
static const char PROGMEM UnityStrByte[]                   = " Byte ";
static const char PROGMEM UnityStrMemory[]                 = " Memory Mismatch.";
static const char PROGMEM UnityStrDelta[]                  = " Values Not Within Delta ";
static const char PROGMEM UnityStrPointless[]              = " You Asked Me To Compare Nothing, Which Was Pointless.";
static const char PROGMEM UnityStrNullPointerForExpected[] = " Expected pointer to be NULL";
static const char PROGMEM UnityStrNullPointerForActual[]   = " Actual pointer was NULL";
#ifndef UNITY_EXCLUDE_FLOAT
static const char PROGMEM UnityStrNot[]                    = "Not ";
static const char PROGMEM UnityStrInf[]                    = "Infinity";
static const char PROGMEM UnityStrNegInf[]                 = "Negative Infinity";
static const char PROGMEM UnityStrNaN[]                    = "NaN";
static const char PROGMEM UnityStrDet[]                    = "Determinate";
static const char PROGMEM UnityStrInvalidFloatTrait[]      = "Invalid Float Trait";
#endif
const char PROGMEM UnityStrErrShorthand[]                  = "Unity Shorthand Support Disabled";
const char PROGMEM UnityStrErrFloat[]                      = "Unity Floating Point Disabled";
const char PROGMEM UnityStrErrDouble[]                     = "Unity Double Precision Disabled";
const char PROGMEM UnityStrErr64[]                         = "Unity 64-bit Support Disabled";
static const char PROGMEM UnityStrBreaker[]                = "-----------------------";
static const char PROGMEM UnityStrResultsTests[]           = " Tests ";
static const char PROGMEM UnityStrResultsFailures[]        = " Failures ";
static const char PROGMEM UnityStrResultsIgnored[]         = " Ignored ";
static const char PROGMEM UnityStrDetail1Name[]            = UNITY_DETAIL1_NAME " ";
static const char PROGMEM UnityStrDetail2Name[]            = " " UNITY_DETAIL2_NAME " ";

/*-----------------------------------------------
 * Pretty Printers & Test Result Output Handlers
 -----------------------------------------------/

/-----------------------------------------------/
/* Local helper function to print characters. */
static void UnityPrintChar(const char* pch)
{
    /* printable characters plus CR & LF are printed */
    if ((*pch <= 126) && (*pch >= 32))
    {
        UNITY_OUTPUT_CHAR(*pch);
    }
    /* write escaped carriage returns */
    else if (*pch == 13)
    {
        UNITY_OUTPUT_CHAR('\\');
        UNITY_OUTPUT_CHAR('r');
    }
    /* write escaped line feeds */
    else if (*pch == 10)
    {
        UNITY_OUTPUT_CHAR('\\');
        UNITY_OUTPUT_CHAR('n');
    }
    /* unprintable characters are shown as codes */
    else
    {
        UNITY_OUTPUT_CHAR('\\');
        UNITY_OUTPUT_CHAR('x');
        UnityPrintNumberHex((UNITY_UINT)*pch, 2);
    }
}

/-----------------------------------------------/
/* Local helper function to print ANSI escape strings e.g. "\033[42m". */
#ifdef UNITY_OUTPUT_COLOR
static UNITY_UINT UnityPrintAnsiEscapeString(const char* string)
{
    const char* pch = string;
    UNITY_UINT count = 0;

    while (*pch && (*pch != 'm'))
    {
        UNITY_OUTPUT_CHAR(*pch);
        pch++;
        count++;
    }
    UNITY_OUTPUT_CHAR('m');
    count++;

    return count;
}
#endif

/-----------------------------------------------/
void UnityPrint(const char* string)
{
    const char* pch = string;

    if (pch != NULL)
    {
        while (*pch)
        {
#ifdef UNITY_OUTPUT_COLOR
            /* print ANSI escape code */
            if ((pch == 27) && ((pch + 1) == '['))
            {
                pch += UnityPrintAnsiEscapeString(pch);
                continue;
            }
#endif
            UnityPrintChar(pch);
            pch++;
        }
    }
}
/-----------------------------------------------/
void UnityPrintLen(const char* string, const UNITY_UINT32 length)
{
    const char* pch = string;

    if (pch != NULL)
    {
        while (*pch && ((UNITY_UINT32)(pch - string) < length))
        {
            /* printable characters plus CR & LF are printed */
            if ((*pch <= 126) && (*pch >= 32))
            {
                UNITY_OUTPUT_CHAR(*pch);
            }
            /* write escaped carriage returns */
            else if (*pch == 13)
            {
                UNITY_OUTPUT_CHAR('\\');
                UNITY_OUTPUT_CHAR('r');
            }
            /* write escaped line feeds */
            else if (*pch == 10)
            {
                UNITY_OUTPUT_CHAR('\\');
                UNITY_OUTPUT_CHAR('n');
            }
            /* unprintable characters are shown as codes */
            else
            {
                UNITY_OUTPUT_CHAR('\\');
                UNITY_OUTPUT_CHAR('x');
                UnityPrintNumberHex((UNITY_UINT)*pch, 2);
            }
            pch++;
        }
    }
}
/-----------------------------------------------/
void UnityPrintNumberByStyle(const UNITY_INT number, const UNITY_DISPLAY_STYLE_T style)
{
    if ((style & UNITY_DISPLAY_RANGE_INT) == UNITY_DISPLAY_RANGE_INT)
    {
        if (style == UNITY_DISPLAY_STYLE_CHAR)
        {
            /* printable characters plus CR & LF are printed */
            UNITY_OUTPUT_CHAR('\'');
            if ((number <= 126) && (number >= 32))
            {
                UNITY_OUTPUT_CHAR((int)number);
            }
            /* write escaped carriage returns */
            else if (number == 13)
            {
                UNITY_OUTPUT_CHAR('\\');
                UNITY_OUTPUT_CHAR('r');
            }
            /* write escaped line feeds */
            else if (number == 10)
            {
                UNITY_OUTPUT_CHAR('\\');
                UNITY_OUTPUT_CHAR('n');
            }
            /* unprintable characters are shown as codes */
            else
            {
                UNITY_OUTPUT_CHAR('\\');
                UNITY_OUTPUT_CHAR('x');
                UnityPrintNumberHex((UNITY_UINT)number, 2);
            }
            UNITY_OUTPUT_CHAR('\'');
        }
        else
        {
            UnityPrintNumber(number);
        }
    }
    else if ((style & UNITY_DISPLAY_RANGE_UINT) == UNITY_DISPLAY_RANGE_UINT)
    {
        UnityPrintNumberUnsigned((UNITY_UINT)number);
    }
    else
    {
        UNITY_OUTPUT_CHAR('0');
        UNITY_OUTPUT_CHAR('x');
        UnityPrintNumberHex((UNITY_UINT)number, (char)((style & 0xF) * 2));
    }
}

/-----------------------------------------------/
void UnityPrintNumber(const UNITY_INT number_to_print)
{
    UNITY_UINT number = (UNITY_UINT)number_to_print;

    if (number_to_print < 0)
    {
        /* A negative number, including MIN negative */
        UNITY_OUTPUT_CHAR('-');
        number = (~number) + 1;
    }
    UnityPrintNumberUnsigned(number);
}

/*-----------------------------------------------
 * basically do an itoa using as little ram as possible */
void UnityPrintNumberUnsigned(const UNITY_UINT number)
{
    UNITY_UINT divisor = 1;

    /* figure out initial divisor */
    while (number / divisor > 9)
    {
        divisor *= 10;
    }

    /* now mod and print, then divide divisor */
    do
    {
        UNITY_OUTPUT_CHAR((char)('0' + (number / divisor % 10)));
        divisor /= 10;
    } while (divisor > 0);
}

/-----------------------------------------------/
void UnityPrintNumberHex(const UNITY_UINT number, const char nibbles_to_print)
{
    int nibble;
    char nibbles = nibbles_to_print;

    if ((unsigned)nibbles > UNITY_MAX_NIBBLES)
    {
        nibbles = UNITY_MAX_NIBBLES;
    }

    while (nibbles > 0)
    {
        nibbles--;
        nibble = (int)(number >> (nibbles * 4)) & 0x0F;
        if (nibble <= 9)
        {
            UNITY_OUTPUT_CHAR((char)('0' + nibble));
        }
        else
        {
            UNITY_OUTPUT_CHAR((char)('A' - 10 + nibble));
        }
    }
}

/-----------------------------------------------/
void UnityPrintMask(const UNITY_UINT mask, const UNITY_UINT number)
{
    UNITY_UINT current_bit = (UNITY_UINT)1 << (UNITY_INT_WIDTH - 1);
    UNITY_INT32 i;

    for (i = 0; i < UNITY_INT_WIDTH; i++)
    {
        if (current_bit & mask)
        {
            if (current_bit & number)
            {
                UNITY_OUTPUT_CHAR('1');
            }
            else
            {
                UNITY_OUTPUT_CHAR('0');
            }
        }
        else
        {
            UNITY_OUTPUT_CHAR('X');
        }
        current_bit = current_bit >> 1;
    }
}

/-----------------------------------------------/
#ifndef UNITY_EXCLUDE_FLOAT_PRINT
/*
 * This function prints a floating-point value in a format similar to
 * printf("%.7g") on a single-precision machine or printf("%.9g") on a
 * double-precision machine.  The 7th digit won't always be totally correct
 * in single-precision operation (for that level of accuracy, a more
 * complicated algorithm would be needed).
 */
void UnityPrintFloat(const UNITY_DOUBLE input_number)
{
#ifdef UNITY_INCLUDE_DOUBLE
    static const int sig_digits = 9;
    static const UNITY_INT32 min_scaled = 100000000;
    static const UNITY_INT32 max_scaled = 1000000000;
#else
    static const int sig_digits = 7;
    static const UNITY_INT32 min_scaled = 1000000;
    static const UNITY_INT32 max_scaled = 10000000;
#endif

    UNITY_DOUBLE number = input_number;

    /* print minus sign (does not handle negative zero) */
    if (number < 0.0f)
    {
        UNITY_OUTPUT_CHAR('-');
        number = -number;
    }

    /* handle zero, NaN, and +/- infinity */
    if (number == 0.0f)
    {
        UnityPrint("0");
    }
    else if (isnan(number))
    {
        UnityPrint("nan");
    }
    else if (isinf(number))
    {
        UnityPrint("inf");
    }
    else
    {
        UNITY_INT32 n_int = 0, n;
        int exponent = 0;
        int decimals, digits;
        char buf[16] = {0};

        /*
         * Scale up or down by powers of 10.  To minimize rounding error,
         * start with a factor/divisor of 10^10, which is the largest
         * power of 10 that can be represented exactly.  Finally, compute
         * (exactly) the remaining power of 10 and perform one more
         * multiplication or division.
         */