/* addr.h — named absolute addresses (scratchpad 0x1F800000..). One `D_<ADDR>` per address; raw
 * constant-address casts live only here (readability scan exempts this file). An address read
 * through several pointee types is a union of views, member = lowercased pointee type. */
#ifndef ADDR_H
#define ADDR_H

#include "types.h"

typedef union {
    u8* bytes;
    s8* s8s;
    Scr4C* scr4c;
    Scr80* scr80;
    Scr82* scr82;
    Scr85* scr85;
    Scr84* scr84;
    Scr01A8* scr01a8;
    Scr0418* scr0418;
    Scr092C* scr092c;
    Scr0B1C* scr0b1c;
    Scr780* scr780;
    Scr1090* scr1090;
    Scr10C8* scr10c8;
    Scr1344* scr1344;
    Scr3594* scr3594;
    Scr36AC* scr36ac;
    Ctx0F18* ctx0f18;
    Ctx1040* ctx1040;
    Obj0470* obj0470;
    Scr5308* scr5308;
    Scr1334* scr1334;
    Scr24D4* scr24d4;
    Scr2074* scr2074;
    Scr* scr;
    Scr09F4* scr09f4;
    Ctx800EFCD8* ctx800efcd8;
} D_1F80004C_t;

typedef union {
    u32* u32s;
    s32* s32s;
} D_1F800020_t;

typedef union {
    u8* bytes;
    s32* s32s;
} D_1F80001C_t;

#define D_1F800000 (*(s32*)0x1F800000)
#define D_1F800004 (*(u8**)0x1F800004)
#define D_1F800008 (*(u8**)0x1F800008)
#define D_1F80000C (*(u8**)0x1F80000C)
#define D_1F800014 (*(u8**)0x1F800014)
#define D_1F80001C (*(D_1F80001C_t*)0x1F80001C)
#define D_1F800020 (*(D_1F800020_t*)0x1F800020)
#define D_1F800024 (*(u8**)0x1F800024)
#define D_1F800028 (*(u8**)0x1F800028)
#define D_1F800030 (*(u8**)0x1F800030)
#define D_1F800038 (*(void**)0x1F800038)
#define D_1F800044 (*(void**)0x1F800044)
#define D_1F80004C (*(D_1F80004C_t*)0x1F80004C)
#define D_1F800050 (*(u8**)0x1F800050)
#define D_1F800054 (*(s8**)0x1F800054)
#define D_1F80005C (*(s8**)0x1F80005C)
#define D_1F800060 (*(u8**)0x1F800060)
#define D_1F800064 (*(s8**)0x1F800064)
#define D_1F800068 (*(s8**)0x1F800068)
#define D_1F800080 (*(void (***)(u8*))0x1F800080)
#define D_1F800084 (*(void (***)(u8*))0x1F800084)
#define D_1F800088 (*(void (***)(s8*))0x1F800088)
#define D_1F80008C (*(void (***)())0x1F80008C)
#define D_1F800090 (*(void (***)(s8*))0x1F800090)
#define D_1F800094 (*(void (***)(u8*))0x1F800094)
#define D_1F800098 (*(void (***)())0x1F800098)
#define D_1F80009C (*(u8**)0x1F80009C)
#define D_1F800100 (*(u8**)0x1F800100)
#define D_1F800104 (*(u8**)0x1F800104)
#define D_1F800124 (*(s32*)0x1F800124)
#define D_801F3000 ((u8*)0x801F3000)
#define D_801F6000 (*(s32*)0x801F6000)
#define D_801F6384 ((u16*)0x801F6384)
#define D_801F3004 (*(s32*)0x801F3004)
#define D_801F300C (*(s32*)0x801F300C)
#define D_801F8100 ((u8*)0x801F8100)
#define D_801F8300 (*(u8**)0x801F8300)

#endif
