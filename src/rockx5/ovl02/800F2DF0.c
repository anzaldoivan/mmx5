#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F2DF0_ovl02(u8* p) {
    s32 t;
    s32 c;

    c = 0xF0;
    *(s16*)(p + 0x2A) = c;
    *(s16*)(p + 0x32) = c;
    c = p[4];
    t = -1;
    *(s8*)(p + 0x37) = t;
    t = 0x140;
    *(s16*)(p + 0x1E) = t;
    *(s16*)(p + 0x26) = t;
    t = 0x7FFF;
    *(s16*)(p + 0x34) = t;
    t = 0x20;
    *(s16*)(p + 0x0A) = 0;
    *(s16*)(p + 0x0E) = 0;
    *(s16*)(p + 0x16) = 0;
    *(s16*)(p + 0x1A) = 0;
    *(s16*)(p + 0x22) = 0;
    *(s16*)(p + 0x2E) = 0;
    p[0x36] = t;
    c++;
    p[4] = c;
}

extern u8 D_8009A197;
extern X4_BackgroundObj D_8009A24C[3];
extern u8 D_800D1C27;
void func_80032CEC();

void func_800F2E48_ovl02(u8* a0) {
    u16 c;

    if (D_8009A197 != 0 || D_8009A24C[0].unk3 == 0 ||
        (c = (s8)D_800D1C27) == 0) {
        a0[3] = 0;
    } else {
        *(u16*)(a0 + 0x34) = c | (c << 5) | (c << 10);
        func_80032CEC();
    }
}

#define D_800EEBA0_ovl00 func_800F2EB8_ovl02
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
