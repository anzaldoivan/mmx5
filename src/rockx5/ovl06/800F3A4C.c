#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F3A4C_ovl06(u8* obj) {
    u8* p;
    u8* q;
    u8* r;
    u16 t;

    if (*(s8*)(obj + 0x45) == 7) {
        set_animation(obj, 0);
    }
    p = g_Player;
    if (((*(s16*)(obj + 0xE) - *(s16*)(p + 0xE)) < 0
             ? (*(s16*)(p + 0xE) - *(s16*)(obj + 0xE))
             : (*(s16*)(obj + 0xE) - *(s16*)(p + 0xE))) > 16) {
        q = g_Player;
        t = *(u16*)(obj + 0xE);
        if (*(s16*)(obj + 0xE) > *(s16*)(q + 0xE)) {
            *(s16*)(obj + 0xE) = t - 1;
        } else if (*(s16*)(obj + 0xE) < *(s16*)(q + 0xE)) {
            *(s16*)(obj + 0xE) = t + 1;
        }
        r = g_Player;
        if (((*(s16*)(obj + 0xE) - *(s16*)(r + 0xE)) < 0
                 ? (*(s16*)(r + 0xE) - *(s16*)(obj + 0xE))
                 : (*(s16*)(obj + 0xE) - *(s16*)(r + 0xE))) <= 16) {
            *(s32*)(obj + 0xC) = *(s32*)(obj + 0x1C);
        }
    }
    if (*(s16*)(obj + 0x7C) == 0) {
        if (*(s8*)(obj + 0x45) != 0) {
            set_animation(obj, 2);
            obj[6]++;
        }
    } else {
        *(s16*)(obj + 0x7C) = *(s16*)(obj + 0x7C) - 1;
    }
}

extern u32 func_8002DFB0(void);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_800F3B7C_ovl06(u8* obj) {
    u8* child;
    u8* pl;
    s32 ang;

    if (*(s8*)(obj + 0x45) == 2) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0xF;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            *(s32*)(child + 0x8) = *(s32*)(obj + 0x8) + 0x300000;
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC) - 0x200000;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(u8**)(child + 0x7C) = obj;
            child[2] = 0;
            pl = g_Player;
            ang = ratan2(*(s16*)(pl + 0xE) - *(s16*)(child + 0xE),
                         *(s16*)(pl + 0xA) - *(s16*)(child + 0xA));
            *(s32*)(child + 0x20) = rcos(ang);
            *(s32*)(child + 0x24) = -rsin(ang);
        }
    }
    if (*(s8*)(obj + 0x45) == 7) {
        set_animation(obj, 0);
        *(s16*)(obj + 0x7C) = (u8)(func_8002DFB0() % 50) + 40;
        if (*(s16*)(obj + 0x7E) == 0) {
            obj[6] = obj[6] + 1;
        } else {
            *(s16*)(obj + 0x7E) = *(s16*)(obj + 0x7E) - 1;
            obj[6] = obj[6] - 1;
        }
    }
}

#define OY (*(s16*)(o + 0xE))
#define PY(p) (*(s16*)((p) + 0xE))

void func_800F3D08_ovl06(u8* o) {
    u8* p = g_Player;

    if ((OY - PY(p)) >= 0 ? (OY - PY(p)) >= 9 : (PY(p) - OY) >= 9) {
        {
            u8* q = g_Player;
            if (OY > PY(q)) {
                OY--;
            } else if (OY < PY(q)) {
                OY++;
            }
        }
        {
            u8* r = g_Player;
            if ((OY - PY(r)) >= 0 ? (OY - PY(r)) < 9 : (PY(r) - OY) < 9) {
                *(s32*)(o + 0xC) = *(s32*)(o + 0x1C);
            }
        }
    }
    if (--*(s16*)(o + 0x7C) == 0) {
        o[6]++;
    }
}
