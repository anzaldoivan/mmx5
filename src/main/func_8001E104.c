#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"

extern void func_80027288(void);
extern void func_80017D88(void);
extern void silence_sound(s32, s32);
extern void func_8002D004(void);
extern void setup_file_load(s32, s32, s32);
extern void pump_file_loads(void);
extern void func_800176B0(void);
extern void func_80013288(s32, u8*);
extern s8 D_80070EA0;

void func_8001E104(u8* a0) {
    u8* p;
    s32 w;
    s32 one;

    w = 0x80;
    a0[0xD] = 1;
    func_80027288();
    func_80017D88();
    silence_sound(0xFF, 0);
    func_8002C50C();
    func_8002D004();
    setup_file_load(0xAB, 0, 0);
    pump_file_loads();
    func_800176B0();
    p = (u8*)func_8002D27C();
    if (p != 0) {
        p[1] = 0x15;
        p[0] = 1;
        p[0x47] = 0;
        p[2] = 1;
        *(s16*)(p + 0xA) = w;
        *(s16*)(p + 0xE) = w;
        p[3] = 1;
        *(s8*)(p + 0x14) = -1;
        *(s32*)(p + 0x38) = 0;
        *(s32*)(p + 0x3C) = (s32)D_1F80001C.s32s;
        *(s32*)(p + 0x30) = 0;
        *(s16*)(p + 0x40) = 0x600;
        *(s16*)(p + 0x42) = 0x7807;
        p[0x15] = 0;
        p[0x16] = 0;
    }
    one = 1;
    p = (u8*)func_8002D27C();
    if (p != 0) {
        p[1] = 0x15;
        p[0] = one;
        p[0x47] = one;
        p[2] = one;
        *(s16*)(p + 0xE) = w;
        p[3] = one;
        *(s16*)(p + 0xA) = 0x180;
        *(s32*)(p + 0x38) = 0;
        *(s8*)(p + 0x14) = -1;
        *(s32*)(p + 0x3C) = (s32)D_1F80001C.s32s;
        *(s32*)(p + 0x30) = 0;
        *(s16*)(p + 0x40) = 0x600;
        *(s16*)(p + 0x42) = 0x7807;
        p[0x15] = 0;
        p[0x16] = 0;
    }
    p = (u8*)func_8002D27C();
    if (p != 0) {
        p[1] = 0x15;
        p[0x47] = 2;
        p[0] = one;
        p[2] = one;
        *(s16*)(p + 0xA) = 0xF0;
        *(s16*)(p + 0xE) = 0x60;
        p[3] = one;
        *(s8*)(p + 0x14) = -1;
        *(s32*)(p + 0x38) = 0;
        *(s32*)(p + 0x3C) = (s32)D_1F80001C.s32s;
        *(s32*)(p + 0x30) = 0;
        *(s16*)(p + 0x40) = 0x600;
        *(s16*)(p + 0x42) = 0x7807;
        p[0x15] = 0;
        p[0x16] = 0;
    }
    *(s16*)(a0 + 4) = 0x258;
    func_80013288(8, p);
    a0[1]++;
    D_80070EA0 = one;
}
