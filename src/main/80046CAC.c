#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u32* D_800730AC[];
extern u8 D_8009A197;
extern s32 D_800E9550;

void func_80046CAC(u8* arg0) {
    u8* obj;
    u8* dst;
    u32* p;
    s8 sel;
    s32 v;
    s32 cur;

    obj = *(u8**)(arg0 + 0x7C);
    dst = arg0 + 0x8C;
    if (*(s8*)(obj + 0x45) != 0) {
        if ((s8)g_playthrough_state.u[0xC] == 0xC &&
            (s8)g_playthrough_state.u[0x1D] == 3) {
            arg0[4] = 4;
            arg0[5] = 0;
            return;
        }
        sel = arg0[1];
        if (sel == 2) {
            *dst = 8;
        } else if (sel == 0xB) {
            *dst = 0xA;
        } else {
            *dst = 9;
        }
        p = D_800730AC[(s8)g_playthrough_state.u[0xC] * 2 +
                       (s8)g_playthrough_state.u[0xD]];
        D_800E9550 = 0;
        if (p != 0) {
            *p &= ~0x19FFFF;
        }
        D_8009A197 = 1;
        arg0[4]++;
    }
    v = *(s8*)(obj + 2);
    if (v == 0) {
        cur = *(s8*)(obj + 5);
        v = 0x26;
    } else {
        cur = *(s8*)(obj + 5);
        v = 0x3F;
    }
    if (cur != v) {
        arg0[4] = 3;
    }
}

extern s32 func_8003E6FC(void*, s8);

void func_80046DBC(u8* arg0) {
    s8 arg;
    u8* obj;
    u8* timer;
    u8* tbl;
    s16* p;
    s16* q;
    s8 kind;
    s32 r;

    obj = *(u8**)(arg0 + 0x7C);
    timer = arg0 + 0x8C;
    if (obj[0xF7] == 0) {
        arg0[4] = 3;
        return;
    }
    arg0[0x8C]--;
    if ((s8)arg0[0x8C] > 0) {
        return;
    }
    arg = (((s8*)obj)[2] != 0) ? 1 : ((s8*)arg0)[1];
    tbl = obj + 0xA8;
    p = (s16*)(tbl + ((s8*)obj)[0x93] * 2);
    if (func_8003E6FC(obj, arg) > *p) {
        arg0[4] = 3;
        return;
    }
    r = func_8003E6FC(obj, arg);
    q = (s16*)(tbl + ((s8*)obj)[0x93] * 2);
    *q -= r;
    kind = ((s8*)arg0)[1];
    if (kind == 2) {
        *timer = 8;
    } else if (kind == 0xB) {
        *timer = 0xA;
    } else {
        *timer = 9;
    }
}

void func_80046ED8(u8* obj) {
    s8 c;

    c = obj[5];
    if (c == 0) {
        func_8002C218();
    } else if ((s8)(c % 3) == 0) {
        switch ((s8)(c / 3)) {
        case 1:
        case 3:
        case 5:
            D_800D50DE = 0;
            D_8009A42E = 0;
            D_80093E68 = 0;
            D_800C9310.b = 1;
            if ((s8)((s8)obj[5] / 3) == 5) {
                g_Player[0x98]--;
                g_Player[0x99]--;
                clear_object_slot(obj);
                return;
            }
            goto inc; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    D_800D50DE = 0x1F;
    D_8009A42E = 0x3E0;
    D_80093E68 = 0x7C00;
    D_800C9310.b = 1;
inc:
    obj[5]++;
}
