#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_800132F8(s8 arg);
extern void func_800211C4(void*, s32);

void func_80020164(u8* arg0) {
    u8* p = D_8009A420;

    if (((s8*)p)[4] == 0) {
        if (D_800C9320.h & 0x40) {
            play_sound(0, 0x22, 0);
            if (p[7] != 1) {
                func_800132F8(8);
            }
            arg0[1]++;
            *(s16*)(arg0 + 0xA) = p[7];
        } else if (D_800C9320.h & 0x10) {
            func_800132F8(8);
            *(s16*)(arg0 + 0xA) = 2;
            arg0[1]++;
        } else {
            func_800211C4(p + 7, *(s16*)(arg0 + 8));
        }
    }
}

extern void func_800132F8(s8 arg);

void func_80020230(u8* arg0) {
    u8* p = D_8009A420;

    if (((s8*)p)[4] == 0) {
        if (D_800C9320.h & 0x40) {
            play_sound(0, 0x22, 0);
            if (p[7] != 0) {
                func_800132F8(8);
            }
            arg0[1]++;
            *(s16*)(arg0 + 0xA) = p[7];
        } else if (D_800C9320.h & 0x10) {
            func_800132F8(8);
            *(s16*)(arg0 + 0xA) = 2;
            arg0[1]++;
        }
    }
}

void func_800202EC(u8* arg0) {
    u8 pad[16]; // !FAKE: unused local keeps the 0x10 stack frame
    u8* p = D_8009A420;

    if (((s8*)p)[4] == 0) {
        if (p[7] != 0) {
            D_800C9310.b |= 1;
        }
        if (*(s16*)(arg0 + 0xA) == 0) {
            u8* g = g_playthrough_state.u;
            arg0[0] = 9;
            g[1] = 0;
            g[2] = 0;
            g[3] = 0;
        } else {
            u8* q = D_8009A1F8.u;
            *(s16*)(q + 0xA) = 0;
            *(s16*)(q + 0xE) = 0;
            q[0x4C] = 1;
            q[3] = 1;
            arg0[0] = 6;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
        }
    }
}
