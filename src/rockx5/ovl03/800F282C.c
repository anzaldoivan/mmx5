#include "types.h"
#include "mmx5/ovl03.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_8002B070(s16, s16, s16, s16, s32);
extern u8* alloc_class3_slot(void);
extern void func_8002DC44(void);
extern void func_8003A670(u8* arg0);
extern s16 D_800F9D0C_ovl03[][2];
extern s16 D_800F9E04_ovl03[][2];

void func_800F282C_ovl03(u8* arg0) {
    u8* p;
    s32 i;
    s32 v;

    {
        u8* a = g_Player;
        *(s16*)(a + 0xA) = D_800F9D0C_ovl03[arg0[0x7C]][0];
        if (arg0[0x7C] & 1) {
            *(s16*)(a + 0xE) = 0x18B;
        } else {
            *(s16*)(a + 0xE) = 0x36B;
        }
    }
    {
        u8* a = g_Player;
        if (*(s8*)(a + 2) != 0) {
            *(s16*)(a + 0xE) += 2;
        }
        *(s32*)(a + 0x18) = *(s32*)(a + 0x8);
        *(s32*)(a + 0x1C) = *(s32*)(a + 0xC);
    }
    {
        u8* b = D_8009A1F8.u;
        v = (u16)D_800F9D0C_ovl03[arg0[0x7C]][0] - 0x28;
        *(s16*)(b + 0x26) = v;
        *(s16*)(b + 0x1E) = v;
        if (arg0[0x7C] & 1) {
            *(s16*)(b + 0x22) = 0xE0;
            *(s16*)(b + 0x2A) = 0xE0;
            *(s16*)(b + 0x20) = 0xE0;
            *(s16*)(b + 0x28) = 0xE0;
            *(s16*)(b + 0x1C) = 0xF20;
            *(s16*)(b + 0x24) = 0xF20;
            *(s16*)(b + 0x62) = 0;
            *(s16*)(b + 0xB6) = 0;
            if (arg0[0x7C] == 0xD) {
                *(s16*)(b + 0x1E) = 0xEE0;
                *(s16*)(b + 0x26) = 0xEE0;
                for (i = 0; i < 4; i++) {
                    p = alloc_class3_slot();
                    if (p != 0) {
                        p[0] = 1;
                        p[1] = 0;
                        p[2] = i;
                        *(s16*)(p + 0xA) = D_800F9E04_ovl03[i][0];
                        *(s16*)(p + 0xE) = D_800F9E04_ovl03[i][1];
                    }
                }
                g_playthrough_state.u[0x1D] = 1;
            }
        } else {
            *(s16*)(b + 0x22) = 0x2C0;
            *(s16*)(b + 0x2A) = 0x2C0;
            *(s16*)(b + 0x20) = 0x2C0;
            *(s16*)(b + 0x28) = 0x2C0;
            *(s16*)(b + 0x1C) = 0xDE0;
            *(s16*)(b + 0x24) = 0xDE0;
            *(s16*)(b + 0x62) = 0x310;
            *(s16*)(b + 0xB6) = 0x310;
        }
    }
    {
        u8* a = g_Player;
        u8* b = D_8009A1F8.u;
        b[0x4C] = 1;
        b[0xA0] = 1;
        b[0xF4] = 1;
        *(s16*)(b + 0xA) = *(s16*)(a + 0xA) - 0xA0;
        *(s16*)(b + 0xE) = *(s16*)(b + 0x2A);
        func_8003A670(a);
        a[0x67] = 0;
        func_8002DC44();
        a[0xA4] = 0;
        a[0x61] = 0;
        if (*(s8*)(a + 0x14B) != -1 || *(s8*)(a + 2) == 0) {
            a[0x7A] = 0;
        }
    }
    {
        u8* a = g_Player;
        u8* b = D_8009A1F8.u;
        g_playthrough_state.u[0x1C] = 0;
        a[0xF3] = 0;
        a[0x15] = 0x40;
        func_8002B070(*(s16*)(b + 0xA) - 0x30, *(s16*)(b + 0xA) + 0x170,
                      *(s16*)(b + 0xE) - 0x30, *(s16*)(b + 0xE) + 0x120, 0);
    }
    arg0[0x7D] = 0;
    arg0[6]++;
}

extern void func_8002C1C8(void);
extern void func_800F2E3C_ovl03(s32);
extern s8 D_8009A0A2;

void func_800F2AE0_ovl03(u8* a0) {
    Obj8002CD14* p;
    s32 i;
    s32 mask;

    a0[0x7D]++;
    if (a0[0x7D] >= 10) {
        func_8002C1C8();
        (&D_8009A0A2)[1] = 1;
        func_800F2E3C_ovl03(0);
        mask = ~8;
        D_800FA238_ovl03.u = 0;
        p = g_class4_slots.cd14;
        for (i = 0x3F; i >= 0; i--, p++) {
            if (p->active != 0 && ((s8*)p)[1] == (s8)a0[1]) {
                p->active &= mask;
            }
        }
        a0[6]++;
    }
}
