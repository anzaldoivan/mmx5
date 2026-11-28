#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s32 func_8002E804(u8*, u8*);
extern void func_80053E3C(u8* obj, u8 arg1, u8 arg2);
extern void func_80053B68(s32 arg0, u8 arg1);
#define D_800D1C00_as_Gm1C00 (*(Gm1C00*)&g_playthrough_state)

void func_80054000(u8* obj) {
    u8* p;
    u8 hi;
    u8* b = g_Player;

    if (*(s8*)(b + 0xD5) != 0) {
        p = D_800D1DC0.u;
        if (*(s8*)(p + 5) == 0) {
            p += 0xB0;
        }
    } else {
        p = b;
    }
    if ((p[0x5C] & 0x7F) == 0) {
        return;
    }
    if (func_8002E804(obj, p) == 0) {
        return;
    }
    obj[5] = 0;
    switch (obj[0x82]) {
    case 0: {
        u8* q;
        u8* c = (u8*)&D_800D1C00_as_Gm1C00;
        s32 m;

        m = 1 << *(s8*)(obj + 2);
        if (*(s32*)(c + 0x80) & m) {
            break;
        }
        *(s32*)(c + 0x80) |= m;
        q = g_Player;
        ((Gm1C00*)c)->lim[*(s8*)(q + 2)] += 2;
        ((void (*)())play_sound)(0, 0x15, 0);
        break;
    }
    case 1: {
        u8* q;
        u8* c = (u8*)&D_800D1C00_as_Gm1C00;
        s32 m;

        m = 0x10000 << (*(s8*)(obj + 2) - 0x10);
        if (*(s32*)(c + 0x80) & m) {
            break;
        }
        *(s32*)(c + 0x80) |= m;
        q = g_Player;
        ((Gm1C00*)(c + 0xC))->lim[*(s8*)(q + 2)] += 2;
        play_sound(0, 0x15, 0);
        break;
    }
    case 2: {
        u8* q = g_Player;

        if (*(s32*)(q + 0xFC) & 0x40) {
            func_80053E3C(obj, 5, 2);
        } else {
            func_80053E3C(obj, 4, 1);
        }
        return;
    }
    case 3: {
        u8* q = g_Player;

        if (*(s32*)(q + 0xFC) & 0x40) {
            func_80053E3C(obj, 0x14, 3);
        } else {
            func_80053E3C(obj, 0x10, 2);
        }
        return;
    }
    case 4: {
        Gm1C00* c = &D_800D1C00_as_Gm1C00;
        u8* q = g_Player;

        func_80053E3C(obj, c->lim[*(s8*)(q + 2)], 4);
        return;
    }
    case 5:
    case 6:
    case 7:
        func_80053B68((s32)obj, obj[0x82]);
        break;
    case 8: {
        u8* c = (u8*)&D_800D1C00_as_Gm1C00;
        c[0x45]++;
        if (*(s8*)(c + 0x45) >= 10) {
            c[0x45] = 9;
            break;
        }
        ((void (*)())play_sound)(0, 0x15, 0);
        break;
    }
    case 9: {
        u8* c = (u8*)&D_800D1C00_as_Gm1C00;
        s32 m;
        u16 h;

        m = 0x1000 << (*(s8*)(obj + 2) - 0x27);
        h = *(u16*)(c + 0x7E);
        if (h & m) {
            return;
        }
        *(u16*)(c + 0x7E) = h | m;
        obj[4] = 3;
        if (*(s8*)(obj + 2) == 0x27) {
            *(s8*)(c + 0x76) = -0x80;
        } else {
            *(s8*)(c + 0x77) = -0x80;
        }
        ((void (*)())play_sound)(0, 0x15, 0);
        return;
    }
    case 10: {
        u8* c = (u8*)&D_800D1C00_as_Gm1C00;
        u16 h;
        h = *(u16*)(c + 0x7E);
        if (h & 0x4000) {
            return;
        }
        *(u16*)(c + 0x7E) = h | 0x4000;
        obj[4] = 3;
        ((void (*)())play_sound)(0, 0x15, 0);
        c[0x78] = 0;
        return;
    }
    case 11: {
        u8* c = (u8*)&D_800D1C00_as_Gm1C00;
        u16 h;
        h = *(u16*)(c + 0x7E);
        if (h & 0x8000) {
            return;
        }
        *(u16*)(c + 0x7E) = h | 0x8000;
        obj[4] = 3;
        ((void (*)())play_sound)(0, 0x15, 0);
        return;
    }
    case 12: {
        u32 n = 4;
        u8 t;

        p = g_Player;
        hi = p[0xFB];
        t = hi & 0x7F;
        hi &= 0x80;
        p[0xFB] = t;
        if (t > n) {
            p[0xFB] = t - n;
        } else {
            p[0xFB] = 0;
        }
        p[0xFB] |= hi;
        obj[4] = 3;
        return;
    }
    case 13: {
        u32 n = 0x10;
        u8 t;

        p = g_Player;
        hi = p[0xFB];
        t = hi & 0x7F;
        hi &= 0x80;
        p[0xFB] = t;
        if (t > n) {
            p[0xFB] = t - n;
        } else {
            p[0xFB] = 0;
        }
        p[0xFB] |= hi;
        obj[4] = 3;
        return;
    }
    }
    obj[4] = 3;
}
