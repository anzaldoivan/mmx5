#include "types.h"

extern void read_rock_bin_member(s32, s32);
extern D1C00_800F6A94 D_800D1C00;
extern s8 D_800D1C26[];

void func_800F6A94_ovl18(u8* arg0) {
    s32 i;

    for (i = 8; i < 16; i++) {
        if (D_800D1C00.f26[i] == 0) {
            break;
        }
    }
    if (i == 16) {
        for (i = 8; i < 16; i++) {
            D_800D1C26[i] = 0;
        }
    }
    if (D_800D1C00.f26[11] != 1) {
        D_800D1C00.f26[11] = 1;
        read_rock_bin_member(0x26, 0x800FA000);
        arg0[4]++;
    } else {
        arg0[4] += 2;
    }
}

s32 poll_rock_bin_read();

void func_800F6B64_ovl18(u8* arg0) {
    if (poll_rock_bin_read() != 0) {
        arg0[4]++;
    }
}

extern u8* func_8002CA10(s32, s32);

void func_800F6BA0_ovl18(Obj800F6C58* arg0) {
    u8* p;

    p = func_8002CA10(0, 0);
    if (p != 0) {
        p[0] = 'A';
        p[1] = 'B';
        p[2] = 0;
    }
    arg0->unk14 = p;
    arg0->unk4++;
}

extern void read_rock_bin_member(s32, s32);
extern u8 D_800D1C31;

void func_800F6BF8_ovl18(Obj800F6C58* arg0) {
    if (*(s8*)arg0->unk14 == 0) {
        D_800D1C31 = 2;
        read_rock_bin_member(0x27, 0x800FA000);
        arg0->unk4++;
    }
}

extern s32 poll_rock_bin_read(void);
extern u8* func_8002CA10(s32, s32);

void func_800F6C58_ovl18(Obj800F6C58* arg0) {
    u8* p;

    if (poll_rock_bin_read() != 0) {
        p = func_8002CA10(0, 0);
        if (p != 0) {
            p[0] = 'A';
            p[1] = 'C';
            p[2] = 0;
        }
        arg0->unk14 = p;
        arg0->unk4++;
    }
}

#define D_800EEC60_ovl00 func_800F6CB8_ovl18
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
