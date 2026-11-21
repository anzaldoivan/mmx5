#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern s32 func_8003240C(u8* a0);
extern void func_80032F70(u8* a0);
extern s32 func_800326BC(u8* a0);
extern void func_8003258C(u8* a0);

extern void (*D_800FDBE4_ovl27[])(u8*);
extern u8 D_8009A198;

void func_800FB9F0_ovl27(u8* p) {
    *(s32*)(p + 0x18) = *(s32*)(p + 0x8);
    *(s32*)(p + 0x1C) = *(s32*)(p + 0xC);
    D_800FDBE4_ovl27[*(s8*)(p + 5)](p);
    if (D_8009A198 == 0) {
        func_8003240C(p);
    }
    func_80032F70(p);
    func_80033024(p);
    func_800326BC(p);
    func_8003258C(p);
}

#define D_800EEBA0_ovl00 func_800FBA80_ovl27
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
