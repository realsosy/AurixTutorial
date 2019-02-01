/**
 * \file IfxCpu_IntrinsicsGhs.h
 *
 * \version iLLD_1_0_1_8_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Cpu_Intrinsics_Ghs Intrinsics for GNU compiler
 * \ingroup IfxLld_Cpu_Intrinsics
 *
 */

#ifndef IFXCPU_INTRINSICSGHS_H
#define IFXCPU_INTRINSICSGHS_H

/******************************************************************************/
#include "Ifx_Types.h"
#include <intrinsics.h>

/******************************************************************************/
/* *INDENT-OFF* */
#define STRINGIFY(x)    #x

typedef void (*voidfunc)();

/** Function call without return
 */
#define __non_return_call(fun)	__asm__ volatile ("ji %0"::"a"(fun))

/** Jump and link
 */
IFX_INLINE void __jump_and_link(void (*fun)(void))
{
	__asm__ volatile ("jli %0"::"a"(fun));
}

IFX_INLINE void __moveToDataParam0(unsigned int var)
{
	__asm__ volatile ("mov\t d4, %0"::"d"(var));
}

IFX_INLINE void __moveToDataParamRet(unsigned int var)
{
	__asm__ volatile ("mov\t d2, %0"::"d"(var));
}

IFX_INLINE unsigned int __getDataParamRet(void)
{
	unsigned int var;
	__asm__ volatile (" mov\t %0, d2":"=d"(var));
	return var;
}

IFX_INLINE void __moveToAddrParam0(const void *var)
{
	__asm__ volatile ("mov.aa\t a4, %0"::"a"(var));
}

IFX_INLINE void __jumpToFunction(void (*fun)(void))
{
	__non_return_call(fun);
}

IFX_INLINE void __jumpToFunctionWithLink(void (*fun)(void))
{
	__jump_and_link(fun);
}

IFX_INLINE void __jumpBackToLink(void)
{
	__asm__ volatile ("ji a11");
}
/** \defgroup IfxLld_Cpu_Intrinsics_Ghs_any_type Cross type arithmetic operation
 *
 * Macro compatible with float, fix point, signed integer and unsigned integer
 *
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */
#define __minX(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define __maxX(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define __saturateX(X,Min,Max)          ( __minX(__maxX(X, Min), Max) )
#define __checkrangeX(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Ghs_singed_integer Signed integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */
#define __saturate(X,Min,Max)           ( __min(__max(X, Min), Max) )
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Ghs_unsinged_integer Unsigned integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */
#define __saturateu(X,Min,Max)           ( __minu(__maxu(X, Min), Max) )
/** \} */

/** \defgroup intrinsicsghs_float Floating point operation
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */

#define __sqrf(X)                       ((X) * (X))
#define __sqrtf(X)                      sqrtf(X)
#define __checkrange(X,Min,Max)         (((X) >= (Min)) && ((X) <= (Max)))

#define __roundf(X)                     ((((X) - (sint32)(X)) > 0.5) ? (1 + (sint32)(X)) : ((sint32)(X)))
#define __absf(X)                       ( ((X) < 0.0) ? -(X) : (X) )
#define __minf(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define __maxf(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define __saturatef(X,Min,Max)          ( __minf(__maxf(X, Min), Max) )
#define __checkrangef(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))

#define __abs_stdreal(X)                ( ((X) > 0.0) ? (X) : -(X) )
#define __min_stdreal(X,Y)              ( ((X) < (Y)) ? (X) : (Y) )
#define __max_stdreal(X,Y)              ( ((X) > (Y)) ? (X) : (Y) )
#define __saturate_stdreal(X,Min,Max)   ( __min_stdreal(__max_stdreal(X, Min), Max) )

#define __neqf(X,Y)                     ( ((X) > (Y)) ||  ((X) < (Y)) )     /**< X != Y */
#define __leqf(X,Y)                     ( !((X) > (Y)) )     /**< X <= Y */
#define __geqf(X,Y)                     ( !((X) < (Y)) )     /**< X >= Y */
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Ghsfractional Fractional Arithmetic Support
 The next table provides an overview of intrinsic functions to convert fractional values. Note that the
 TASKING VX-toolset C compiler for TriCore fully supports the fractional type so normally you should not
 need these intrinsic functions (except for __mulfractlong). For compatibility reasons the TASKING C
 compiler does support these functions.
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */

/** Count the consecutive number of bits that have the same value as bit 15 of an sfract
 */
IFX_INLINE sint16 __clssf(sfract a)
{
    sint16 res;
    __asm__ volatile ("sh  %1,%1,16    \n\
                      cls  %0,%1":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert fract to float
 */
IFX_INLINE float __fract_to_float(fract a)
{
    float res;
    __asm__ volatile ("q31tof  %0,%1,%2":"=d"(res):"d"(a), "d"(0):"memory");
    return res;
}

/** Convert float to fract
 */
IFX_INLINE fract __float_to_fract(float a)
{
    fract res;
    __asm__ volatile ("ftoq31  %0,%1,%2":"=d"(res):"d"(a), "d"(0):"memory");
    return res;
}

/** Convert laccum to fract
 */
IFX_INLINE fract __getfract(laccum a)
{
    fract res;
    __asm__ volatile ("dextr  %0,%H1,%L1,0x11":"=&d" (res):"d" (a):"memory");
    return res;
}

/** Multiply-add with rounding. Returns the rounded result of ( a + b * c )
 */
IFX_INLINE sfract __mac_r_sf(sfract a, sfract b, sfract c)
{
    sfract res;
    __asm__ volatile ("sh  %1,%1,16        \n\
                       maddrs.q  %0,%1,%2L,%3L,1        \n\
                       sh %0,%0,-16":"=d"(res):"d"(a), "d"(b), "d"(c):"memory");
    return res;
}

/** Multiply-add sfract. Returns ( a + b * c )
 */
IFX_INLINE sfract __mac_sf(sfract a, sfract b, sfract c)
{
    sfract res;
    __asm__ volatile ("sh  %1,%1,16        \n\
                      madds.q  %0,%1,%2L,%3L,1        \n\
                      sh %0,%0,-16":"=d"(res):"d"(a), "d"(b), "d"(c):"memory");
    return res;
}

/** Integer part of the multiplication of a fract and a fract
 */
IFX_INLINE long __mulfractfract(fract a, fract b)
{
    long res;
    __asm__ volatile ("mul.q %0,%1,%2,1":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Integer part of the multiplication of a fract and a long
 */
IFX_INLINE long __mulfractlong(fract a, long b)
{
    long res;
    __asm__ volatile ("mul.q %0,%1,%2,1":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Convert fract to sfract
 */
IFX_INLINE sfract __round16(fract a)
{
    sfract res;
    __asm__ volatile ("mov.u  %0,0x8000        \n\
                    adds  %0,%1              \n\
                    extr  %0,%0,0x10,0x10 "
                      :"=&d"(res):"d"(a):"memory");
    return res;
}

#define __fract_to_sfract __round16

/** Convert float to sfract
 */
IFX_INLINE sfract __float_to_sfract(float a)
{
    fract tmp = __float_to_fract(a);
    return __fract_to_sfract(tmp);
}

/** Convert signed sint16 to sfract
 */
IFX_INLINE sfract __s16_to_sfract(sint16 a)
{
    sfract res;
    __asm__ volatile ("sh  %0,%1,16    \n\
                       sh  %0,%0,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert sfract to sint16
 */
IFX_INLINE sint16 __sfract_to_s16(sfract a)
{
    sint16 res;
    __asm__ volatile ("sh  %1,%1,16    \n\
                       sh  %0,%1,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert sfract to uint16
 */
IFX_INLINE uint16 __sfract_to_u16(sfract a)
{
    uint16 res;
    __asm__ volatile ("sh  %1,%1,16    \n\
                       sh  %0,%1,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Left/right shift of an __laccum
 */
__asm__ laccum __shaaccum(laccum a, sint32 b)
{
% lab L0, L1; reg a, b
! "%d2", "%d3"
    jge   b, 0, L0
    sha   %d3, a!L, b
    rsub  b, b, 0
    dextr %d2, a!H, a!L, b
    j L1
L0:
    dextr %d2, a!H, a!L, b
    sha   %d2, a!L, b
L1:
}

/** Left/right shift of an fract
 */
IFX_INLINE fract __shafracts(fract a, sint32 b)
{
    fract res;
    __asm__ volatile ("shas  %0,%1,%2":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Left/right shift of an sfract
 */
IFX_INLINE sfract __shasfracts(sfract a, sint32 b)
{
    sfract res;
    __asm__ volatile ("sh  %1,%1,16    \n\
                       shas  %0,%1,%2  \n\
                       sh  %0,%0,-16":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Convert uint16 to sfract
 */
IFX_INLINE sfract __u16_to_sfract(uint16 a)
{
    sfract res;
    __asm__ volatile ("sh  %0,%1,16    \n\
                       sh  %0,%0,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Ghsinsert Insert / Extract Bit-fields and Bits
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */

/** Extract a bit-field (bit pos to bit pos+width) from value
 */
IFX_INLINE sint32 __extr(sint32 a, uint32 p, uint32 w)
{
    sint32 res;
    __asm__ volatile ("mov d14,%2  \n\
                     mov d15,%3  \n\
                     extr %0,%1,e14"
                      : "=d" (res) : "d" (a), "d" (p), "d" (w):"d14", "d15");
    return res;
}

/** Same as __extr() but return bit-field as unsigned integer
 */
IFX_INLINE uint32 __extru(uint32 a, uint32 p, uint32 w)
{
	uint32 res;
    __asm__ volatile ("mov d14,%2  \n\
                     mov d15,%3  \n\
                     extr.u %0,%1,e14"\
                      : "=d" (res) : "d" (a), "d" (p), "d" (w):"d14", "d15");
    return res;
}

/** Load a single bit.
 */
//#define __getbit(address,bitoffset ) __extru( *(address), bitoffset, 1 )
#define __getbit(address, bitoffset) ((*(address) & (1U << (bitoffset))) != 0)

/** Atomic load-modify-store.
 */
#define __imaskldmst(address, value, bitoffset, bits) __imaskldmst((int *)address, value, bitoffset, bits)

/** Extract bit-field (width bits starting at bit 0) from src and insert it in trg at pos.
 */
IFX_INLINE sint32 __insert(sint32 a, sint32 b, sint32 p, const sint32 w)
{
    sint32 res;
    __asm__ volatile ("mov d14,%3  \n\
                     mov d15,%4  \n\
                     insert %0,%1,%2,e14"
                      :"=d"(res):"d"(a), "d"(b), "d"(p), "d"(w):"d14", "d15");
    return res;
}

/** Store a single bit.
 */
#define __putbit(value,address,bitoffset ) __imaskldmst(address, value, bitoffset,1)

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Ghsinterrupt_handling Interrupt Handling
 The next table provides an overview of the intrinsic functions to read or set interrupt handling.
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Ghsmiscellaneous Miscellaneous Intrinsic Functions
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */

/**  Write back and invalidate cache address "p". Generates CACHEA.WI [Ab].
 */
IFX_INLINE void __cacheawi(uint8* p)
{
    __asm__ volatile("cachea.wi [%0]0"::"a"(p));
}
/**  Write back and invalidate cache index "p". Generates CACHEI.WI [Ab].
 */
IFX_INLINE void __cacheiwi(uint8* p)
{
    __asm__ volatile("cachei.wi [%0]0"::"a"(p));
}

/**  Write back and invalidate cache address \"p\" and return post incremented
 * value of \"p\". Generates CACHEA.WI [Ab+].
 */
IFX_INLINE uint8* __cacheawi_bo_post_inc(uint8* p)
{
    __asm__ volatile("cachea.wi  [%0+]0"::"a"(p));
    return p;
}

/** Multiply two 32-bit numbers to an intermediate 64-bit result, and scale
 * back the result to 32 bits. To scale back the result, 32 bits are extracted
 * from the intermediate 64-bit result: bit 63-offset to bit 31-offset.
 */
IFX_INLINE sint32 __mulsc(sint32 a, sint32 b, sint32 offset)
{
    sint32 res;
    __asm__ volatile("mul  e12,%1,%2      \n\
                    dextr  %0,d13,d12,%3"
                     :"=d"(res):"d"(a), "d"(b), "d"(offset):"d12", "d13");
    return res;
}

/**  Rotate operand left count times. The bits that are shifted out are inserted at the right side (bit 31 is shifted to bit 0).
 */
IFX_INLINE uint32 __rol(uint32 operand, uint32 count)
{
    uint32 res;
    __asm__ volatile("dextr  %0,%1,%1,%2":"=d"(res):"d"(operand), "d"(count):"memory");
    return res;
}

/**  Rotate operand right count times. The bits that are shifted out are inserted at the left side (bit 0 is shifted to bit 31).
 */
IFX_INLINE uint32 __ror(uint32 operand, uint32 count)
{
    uint32 res;
    __asm__ volatile("rsub %2,%2,0 \n\
                    dextr  %0,%1,%1,%2"
                     :"=d"(res):"d"(operand), "d"(count):"memory");
    return res;
}
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Ghspacked Packed Data Type Support
 The next table provides an overview of the intrinsic functions for initialization of packed data type.
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */

/** Extract first byte from a __packb
 */
IFX_INLINE sint8 __extractbyte1(__packb a)
{
    sint8 res;
    __asm__ volatile ("extr  %0,%1,0,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second byte from a __packb
 */
IFX_INLINE sint8 __extractbyte2(__packb a)
{
    sint8 res;
    __asm__ volatile ("extr  %0,%1,8,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract third byte from a __packb
 */
IFX_INLINE sint8 __extractbyte3(__packb a)
{
    sint8 res;
    __asm__ volatile ("extr  %0,%1,16,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Extract fourth byte from a __packb
 */
IFX_INLINE sint8 __extractbyte4(__packb a)
{
    sint8 res;
    __asm__ volatile ("extr  %0,%1,24,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first sint16 from a __packhw
 */
IFX_INLINE sint16 __extracthw1(__packhw a)
{
    sint16 res;
    __asm__ volatile ("extr  %0,%1,0,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second sint16 from a __packhw
 */
IFX_INLINE sint16 __extracthw2(__packhw a)
{
    sint16 res;
    __asm__ volatile ("extr  %0,%1,16,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first uint8 from a __packb
 */
IFX_INLINE uint8 __extractubyte1(__upackb a)
{
    uint8 res;
    __asm__ volatile ("extr  %0,%1,0,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second uint8 from a __packb
 */
IFX_INLINE uint8 __extractubyte2(__upackb a)
{
    uint8 res;
    __asm__ volatile ("extr  %0,%1,8,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract third uint8 from a __packb
 */
IFX_INLINE uint8 __extractubyte3(__upackb a)
{
    uint8 res;
    __asm__ volatile ("extr  %0,%1,16,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract fourth uint8 from a __packb
 */
IFX_INLINE uint8 __extractubyte4(__upackb a)
{
    uint8 res;
    __asm__ volatile ("extr  %0,%1,24,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first uint16 from a __packhw
 */
IFX_INLINE uint16 __extractuhw1(__upackhw a)
{
    uint16 res;
    __asm__ volatile ("extr  %0,%1,0,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second uint16 from a __packhw
 */
IFX_INLINE uint16 __extractuhw2(__upackhw a)
{
    uint16 res;
    __asm__ volatile ("extr  %0,%1,16,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Extract first byte from a __packb
 */
IFX_INLINE sint8 __getbyte1(__packb* a)
{
    sint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract second byte from a __packb
 */
IFX_INLINE sint8 __getbyte2(__packb* a)
{
    sint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,8,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract third byte from a __packb
 */
IFX_INLINE sint8 __getbyte3(__packb* a)
{
    sint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract fourth byte from a __packb
 */
IFX_INLINE sint8 __getbyte4(__packb* a)
{
    sint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,24,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract first sint16 from a __packhw
 */
IFX_INLINE sint16 __gethw1(__packhw* a)
{
    sint16 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}
/**  Extract second sint16 from a __packhw
 */
IFX_INLINE sint16 __gethw2(__packhw* a)
{
    sint16 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract first uint8 from a __packb
 */
IFX_INLINE uint8 __getubyte1(__upackb* a)
{
    uint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract second uint8 from a __packb
 */
IFX_INLINE uint8 __getubyte2(__upackb* a)
{
    uint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,8,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract third uint8 from a __packb
 */
IFX_INLINE uint8 __getubyte3(__upackb* a)
{
    uint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract fourth uint8 from a __packb
 */
IFX_INLINE uint8 __getubyte4(__upackb* a)
{
    uint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,24,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract first uint16 from a __packhw
 */
IFX_INLINE uint16 __getuhw1(__upackhw* a)
{
    uint16 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract second uint16 from a __packhw
 */
IFX_INLINE uint16 __getuhw2(__upackhw* a)
{
    uint16 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Initialize  __packb with four integers
 */
IFX_INLINE __packb __initpackb(sint32 a, sint32 b, sint32 c, sint32 d)
{
    __packb res;
    __asm__ volatile ("insert  %3,%3,%4,8,8   \n\
                    insert  %4,%1,%2,8,8   \n\
                    insert  %0,%4,%3,16,16 "
                      :"=d"(res):"d"(a), "d"(b), "d"(c), "d"(d):"memory");
    return res;
}

/** Initialize  __packb with a long integer
 */
IFX_INLINE __packb __initpackbl(long a)
{
    return (__packb) a;
}

/** Initialize  __packhw with two integers
 */
IFX_INLINE __packhw __initpackhw(sint16 a, sint16 b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Initialize  __packhw with a long integer
 */
IFX_INLINE __packhw __initpackhwl(long a)
{
    return a;
}

/** Initialize  __packb with four unsigned integers
 */
IFX_INLINE __upackb    __initupackb( uint32 a, uint32 b, uint32 c, uint32 d)
{
    __upackb res;
    __asm__ volatile ("insert  %3,%3,%4,8,8   \n\
                    insert  %1,%1,%2,8,8   \n\
                    insert  %0,%1,%3,16,16"
                      :"=d"(res):"d"(a), "d"(b), "d"(c), "d"(d):"memory");
    return res;
}

/**  Initialize  __packhw with two unsigned integers
 */
IFX_INLINE __upackhw    __initupackhw( uint16 a, uint16 b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into first byte of a __packb
 */
IFX_INLINE __packb __insertbyte1(__packb a, sint8 b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,0,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into second byte of a __packb
 */
IFX_INLINE __packb __insertbyte2(__packb a, sint8 b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,8,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into third byte of a __packb
 */
IFX_INLINE __packb __insertbyte3(__packb a, sint8 b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,16,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into fourth byte of a __packb
 */
IFX_INLINE __packb __insertbyte4(__packb a, sint8 b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,24,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into first uint8 of a __packb
 */
IFX_INLINE __upackb    __insertubyte1( __upackb a, uint8 b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,0,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into second uint8 of a __packb
 */
IFX_INLINE __upackb    __insertubyte2( __upackb a, uint8 b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,8,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into third uint8 of a __packb
 */
IFX_INLINE __upackb     __insertubyte3( __upackb a, uint8 b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,16,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into fourth uint8 of a __packb
 */
IFX_INLINE __upackb     __insertubyte4( __upackb a, uint8 b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,24,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert sint16 into first halfword of a __packhw
 */
IFX_INLINE __packhw __inserthw1(__packhw a, sint16 b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,0,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert sint16 into second halfword of a __packhw
 */
IFX_INLINE __packhw __inserthw2(__packhw a, sint16 b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert uint16 into first halfword of a __upackhw
 */
IFX_INLINE __upackhw    __insertuhw1( __upackhw a, uint16 b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,0,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert uint16 into second halfword of a __upackhw
 */
IFX_INLINE __upackhw    __insertuhw2( __upackhw a, uint16 b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert sint8 into first byte of a __packb
 */
IFX_INLINE void __setbyte1(__packb* a, sint8 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,0,8 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint8 into second byte of a __packb
 */
IFX_INLINE void __setbyte2(__packb* a, sint8 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,8,8 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint8 into third byte of a __packb
 */
IFX_INLINE void __setbyte3(__packb* a, sint8 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,16,8 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint8 into fourth byte of a __packb
 */
IFX_INLINE void __setbyte4(__packb* a, sint8 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,24,8 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint16 into first halfword of a __packhw
 */
IFX_INLINE void __sethw1(__packhw* a, sint16 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,0,16 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint16 into second halfword of a __packhw
 */
IFX_INLINE void __sethw2(__packhw* a, sint16 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,16,16 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint8 into first byte of a __upackb
 */
IFX_INLINE void __setubyte1(__upackb* a, uint8 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,0,8 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint8 into second byte of a __upackb
 */
IFX_INLINE void __setubyte2(__upackb* a, uint8 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,8,8 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint8 into third byte of a __upackb
 */
IFX_INLINE void __setubyte3(__upackb* a, uint8 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,16,8 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint8 into fourth byte of a __upackb
 */
IFX_INLINE void __setubyte4(__upackb* a, uint8 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,24,8 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint16 into first halfword of a __upackhw
 */
IFX_INLINE void __setuhw1(__upackhw* a, uint16 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,0,16 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint16 into second halfword of a __upackhw
 */
IFX_INLINE void __setuhw2(__upackhw* a, uint16 b)
{
    __asm__ volatile ("ld.w  d15,[%0] \n\
                    insert  d15,d15,%1,16,16 \n\
                    st.w [%0],d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Ghssingle_assembly Insert Single Assembly Instruction
 The next table provides an overview of the intrinsic functions that you can use to insert a single assembly
 instruction.You can also use inline assembly but these intrinsics provide a shorthand for frequently used
 assembly instructions.
 * \ingroup IfxLld_Cpu_Intrinsics_Ghs
 * \{
 */

/** Insert LDMST instruction. Note that all operands must be word-aligned.
 */
IFX_INLINE void __ldmst(volatile void* address, uint32 mask, uint32 value)
{
    __asm__ volatile("ldmst [%0]0,%1"
                     ::"a"(address), "e"((long long)mask<<32 | value));
}

/** Insert a loop over cnt NOP instruction
 */
IFX_INLINE void __nops(void* cnt)
{
    __asm__ volatile ("0: nop \n\
        loop %0,0b"
                      ::"a"(((sint8*)cnt)-1));
}

/** Insert SWAP instruction. Note that all operands must be word-aligned.
 */
IFX_INLINE uint32 __swap(void* place, uint32 value)
{
    uint32 res;
    __asm__ volatile("swap.w [%1]0,%2":"=d"(res):"a"(place), "0"(value));
    return res;
}

/** Insert n NOP instruction
 */
#define NOP(n)   __asm(".rept " #n "\n\tnop\n\t.endr\n")

/** \} */

/* FIXME use inline instead of #define */
/*#define __extru(src,start,size) \
    ({ sint32 res; asm volatile (" extr.u\t %0,%1,%2,%3" : "=d" (res) : \
        "d" (src),"i" (start),"i" (size) : "memory"); res; })*/

/* FIXME use inline instead of #define */
#define __setareg(areg,val) \
    { uint32 reg_val= (uint32)val; \
        asm volatile (" mov.a\t %"#areg",%0"::"d"(reg_val)); }

/**__mtcr (CPU_CCTRL, 0);
*/
IFX_INLINE void __stopPerfCounters(void)
{
    __asm__ volatile("mov d0,0\n\
                  mtcr 0xFC00,d0\n\
                  isync\n"
            : : :"d0"); /* FIXME check that the parameter d0 is understood by the compiler as a register used by the inline */
}

/** \brief This function is a implementation of a binary semaphore using compare and swap instruction
 * \param address address of resource.
 * \param value This variable is updated with status of address
 * \param condition if the value of address matches with the value of condition, then swap of value & address occurs.
 *
 */
IFX_INLINE unsigned int __cmpAndSwap (unsigned int volatile *address,
           unsigned int value, unsigned int condition)
{
  unsigned long long reg64
    = value | (unsigned long long) condition << 32;

  __asm__ __volatile__ ("cmpswap.w [%[addr]]0, %A[reg]"
                        : [reg] "+d" (reg64)
                        : [addr] "a" (address)
                        : "memory");
    return reg64;
}

/** \brief Convert a fixpoint value to float32
 *
 * This function converts a value from a fixpoint format to a float32 format.
 *
 *
 * \param value value to be converted.
 * \param shift position of the fix point. Range = [-256, 255] => (Qx.y format where x = shift+1).
 *
 * \return Returns the converted value in the float32 format.
 *
 */
IFX_INLINE float32 __fixpoint_to_float32(fract value, sint32 shift)
{
    float32 result;

    __asm__ volatile("q31tof %0, %1, %2": "=d" (result) : "d" (value), "d" (shift));
    return result;
}

IFX_INLINE void* __getA11(void)
{
    uint32 *res;
    __asm__ volatile ("mov.aa %0, a11": "=a" (res) : :"a11");
    return res;
}

IFX_INLINE void __setStackPointer(void *stackAddr)
{
    __asm__ volatile ("mov.aa a10, %0": : "a" (stackAddr));
}

IFX_INLINE uint32 IfxCpu_calculateCrc32(uint32 *startaddress, uint8 length) 
{
    uint32 returnvalue = 0; /* set seed value to 0 */
    for (;length > 0; length--) 
    { 
    	  /* calculate the CRC over all data */
        __asm__ ("CRC32 %0,%0,%1" : "+d" (returnvalue) : "d" (*startaddress)); 
        startaddress++; 
    } 
    return returnvalue;
}

IFX_INLINE uint32 IfxCpu_getRandomVal(uint32 a, uint32 x, uint32 m)
{
	uint32 result;
    __asm("      mul.u     %%e14,%1,%2       # d15 = Eh; d14 = El    \n"
        "        mov       %%d12,%%d14       #   e12 = El            \n"
        "        mov       %%d13, 0          #                       \n"
        "        madd.u    %%e14,%%e12,%%d15, 5 # e14 = El + 5 * d15    \n"
        " cmp_m_%=: jge.u     %%d14,%3,sub_m_%=    #                       \n"
        "        jz        %%d15,done_%=        #                       \n"
        " sub_m_%=: subx      %%d14,%%d14,%3    #  e12=e12-m            \n"
        "        subc      %%d15,%%d15,%%d13 # d13=d13-0             \n"
        "        loopu     cmp_m_%=             #                       \n"
        " done_%=:  mov       %0,%%d14          #                       \n"
        : "=d"(result) : "d"(a), "d"(x), "d"(m) : "d12","d13","d14","d15");
    return result;
}

/* compiler don't know this instruction
IFX_INLINE sint32 __popcnt(sint32 a)
{ 
	sint32 res; 
	__asm__ volatile ("popcnt %0,%1":"=d"(res):"d"(a)); 
		return res; 
}*/

/**  Invalidate cache address "p". Generates CACHEA.I [Ab].
*/
IFX_INLINE void __cacheai(uint8* p)
{
    __asm__ volatile("cachea.i [%0]0"::"a"(p));
}

/* *INDENT-ON* */

/******************************************************************************/
#endif /* IFXCPU_INTRINSICSGHS_H */
