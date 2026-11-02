#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];
extern s8 D_8009A0FC;

void func_800F1630_ovl06(u8* arg0) {
    s32 flag;
    u16 m;
    s32 hit;
    u8 t;
    s32 st;
    s32 c;

    if (*(s8*)(arg0 + 6) == 0) {
        arg0[6] = 1;
        arg0[0x7D] = 1;
        *(s16*)(arg0 + 0x98) = 0x420;
        if (arg0[0x15] != 0) {
            *(s32*)(arg0 + 0x20) = 0x42000;
        } else {
            *(s32*)(arg0 + 0x20) = -0x42000;
        }
        arg0[0x90] = 0x1E;
        *(s32*)(arg0 + 0x2C) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        func_800171E8(arg0, 0xC);
        if (arg0[0x8D] == 0) {
            D_8009A0A0[0xD8] = 0x2F;
            D_8009A0A0[6] = 0;
        }
        func_80016490(5, 2, 0);
    }
    if ((*(u16*)(arg0 + 0x88) & 7) == 4) {
        flag = 1;
        if (*(u16*)(arg0 + 0x8A) & 0x80) {
        } else {
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
        st = 0xB;
        goto out; // !FAKE: goto kept for the matching branch layout
    }
    if (arg0[0x97] & 2) {
        goto call2; // !FAKE: goto kept for the matching branch layout
    }
    hit = 0;
    if (*(u16*)(arg0 + 0x8A) & 0x30) {
        hit = 1;
        if (*(s8*)(arg0 + 2) != 0) {
            hit = arg0[0x7E] == 0;
        }
    }
    if (hit != 0) {
        arg0[5] = 0x10;
        arg0[6] = 0;
        goto call; // !FAKE: goto kept for the matching branch layout
    }
    if (arg0[0xA8] & 3) {
        st = 0xC;
        goto out; // !FAKE: goto kept for the matching branch layout
    }
    if (!(arg0[0x97] & 8)) {
        m = 2;
        if (arg0[0x15] != 0) {
            m = 1;
        }
        c = *(u16*)(arg0 + 0x88) & m;
    } else {
        m = 2;
        if (arg0[0x15] != 0) {
            m = 1;
        }
        if (*(u16*)(arg0 + 0x88) & m) {
            goto move; // !FAKE: goto kept for the matching branch layout
        }
        c = *(u16*)(arg0 + 0x88) & 0x100;
    }
    if (c == 0) {
        st = 0xC;
        goto out; // !FAKE: goto kept for the matching branch layout
    }
move:
    t = arg0[0x90];
    *(s32*)(arg0 + 8) += *(s32*)(arg0 + 0x20);
    arg0[0x90] = t - 1;
    if ((s8)t >= 0) {
        goto call; // !FAKE: goto kept for the matching branch layout
    }
    st = 0xC;
out:
    arg0[5] = st;
    arg0[6] = 0;
    return;
call:
    func_80017248(arg0);
    return;
call2:
    func_80017248(arg0);
}
