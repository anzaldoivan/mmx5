#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* func_8002D078();
extern s8 D_8009A0FC;

void func_800F0C8C_ovl06(u8* obj) {
    u8* p;
    u8* q;
    s32 flag;
    u16 f;

    p = obj;
    if ((*(u16*)(p + 0x88) & 7) == 4) {
        flag = 1;
        if (!(*(u16*)(p + 0x8A) & 0x80)) {
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        flag = 1;
        if (D_8009A0FC != -0x80) {
        clear:
            flag = 0;
        }
    }
    if (flag != 0) {
        p[5] = 0xB;
        p[6] = 0;
        return;
    }
    if (!(p[0x97] & 2)) {
        if (!(p[0xA8] & 8)) {
            p[5] = 0xC;
            p[6] = 0;
        } else {
            f = *(u16*)(p + 0x88);
            if (f & 2) {
                p[0x15] = 0;
            } else if (f & 1) {
                p[0x15] = 0x40;
            }
            if (!(p[0x97] & 0x10) && p[0x94] == 0) {
                p[6] = 2;
                *(s16*)(p + 0x98) = 0x420;
                if (p[0x15] == 0) {
                    *(s32*)(p + 0x20) = 0xFFFBE000;
                } else {
                    *(s32*)(p + 0x20) = 0x42000;
                }
                p[0x90] = 0x1E;
                q = func_8002D078();
                if (q != 0) {
                    q[0] = 0x41;
                    q[1] = 0x3E;
                    q[2] = 4;
                    *(u16*)(q + 0xA) = *(u16*)(p + 0xA);
                    *(u16*)(q + 0xE) = *(u16*)(p + 0xE);
                    *(s32*)(q + 0x30) = *(s32*)(p + 0x30);
                    *(u16*)(q + 0x40) = *(u16*)(p + 0x40);
                    *(s32*)(q + 0x3C) = *(s32*)(p + 0x3C);
                    *(u16*)(q + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
                    q[0x16] = p[0x16];
                    *(u8**)(q + 0x7C) = p;
                    q[0x15] = p[0x15];
                }
                set_animation(p, 0xF);
                if (p[0x8D] == 0) {
                    g_Player[0xD8] = 0x36;
                    g_Player[6] = 0;
                }
                if (*(s8*)(p + 2) == 0) {
                    play_sound(5, 0x10, 0);
                } else {
                    play_sound(5, 6, 0);
                }
            }
        }
        animate_object(p);
        return;
    }
    animate_object(p);
}
