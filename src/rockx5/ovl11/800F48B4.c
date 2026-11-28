#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800F48B4_ovl11(u8* arg0) {
    if (D_8009A0AA >= 0x798) {
        ((s32(*)())func_8003D29C)(0x1D, 0x40);
        arg0[5] = 5;
    }
}

extern void silence_sound(s32, s32);
extern void start_pad_vibration(s32);

void func_800F48F8_ovl11(u8* a0) {
    if (D_800D1C28[1] < 3) {
        silence_sound(5, 0x1C);
    }
    if (a0[0x72] & 0xB) {
        start_pad_vibration(6);
        play_sound(5, 0x1C, a0);
        a0[5] = 6;
    }
}

extern void start_pad_vibration(s32);

void func_800F4968_ovl11(u8* arg0) {
    u8* p = g_Player;
    u8* r;

    if (*(s16*)(p + 0xA) >= 0xE21) {
        u8* q = D_8009A1F8.u;
        arg0[0x83] = 0x1E;
        arg0[0x87] = 1;
        *(s16*)(q + 0x26) = 0xDC0;
        *(s16*)(q + 0x28) = 0x4B0;
        *(s16*)(q + 0x2A) = 0x4B0;
        arg0[5] = 7;
        start_pad_vibration(6);
        play_sound(5, 0x1A, arg0);
    }
    r = D_8009A1F8.u;
    if (*(s16*)(p + 0xE) < *(s16*)(r + 0xE) - 4) {
        *(s16*)(p + 0xE) = *(s16*)(r + 0xE) - 4;
    }
}

#define D_8007BD4C D_800F9C8C_ovl11

#define func_800532E0 func_800F4A20_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

extern void* D_800F9C9C_ovl11[];

void func_800F4A5C_ovl11(u8* arg0) {
    u8* p;

    ((void (*)(u8*))D_800F9C9C_ovl11[(s8)arg0[6]])(arg0);
    p = g_Player;
    if (*(s16*)(p + 0xE) < D_8009A206.s + 4) {
        *(s16*)(p + 0xE) = D_8009A206.s + 4;
    }
}

#define D_800EEC60_ovl00 func_800F4AC4_ovl11
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800F4ACC_ovl11
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
