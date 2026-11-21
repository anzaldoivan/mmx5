#include "types.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl03.h"

extern s16 D_800FA250_ovl03;
extern s16 D_800FA252_ovl03;

void func_800F5940_ovl03(u8* obj) {
    s32 i;
    u8* p;
    u8* d;

    if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA250_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA250_ovl03;
            *(s32*)(obj + 0x20) = 0;
        }
    } else if (*(s32*)(obj + 0x20) > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA250_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA250_ovl03;
            *(s32*)(obj + 0x20) = 0;
        }
    }
    if (*(s32*)(obj + 0x24) < 0) {
        if (*(s16*)(obj + 0xE) >= D_800FA252_ovl03) {
            *(s16*)(obj + 0xE) = D_800FA252_ovl03;
            *(s32*)(obj + 0x24) = 0;
        }
    } else if (*(s32*)(obj + 0x24) > 0) {
        if (*(s16*)(obj + 0xE) <= D_800FA252_ovl03) {
            *(s16*)(obj + 0xE) = D_800FA252_ovl03;
            *(s32*)(obj + 0x24) = 0;
        }
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        if (random_byte() & 1) {
            *(s16*)(obj + 0x7C) = 0;
            obj[6] += 1;
        } else {
            set_animation(obj, 8);
            for (i = 0; i < 3; i++) {
                p = func_8002D1A4();
                if (p != 0) {
                    p[0] = 0x61;
                    p[1] = 0x15;
                    p[2] = i;
                    *(u8**)(p + 0x7C) = obj;
                }
            }
            *(s16*)(obj + 0x7C) = 0;
            obj[6] += 2;
        }
    }
    d = g_Player;
    if (*(s16*)(d + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern u8* func_8002C938();
extern u8 D_8009A197;
extern u8 D_800D1C10;
extern u8 D_800F9E6C_ovl03[];

void func_800F5B0C_ovl03(u8* obj) {
    s32 i;
    s16 t;
    u8* p;

    t = ++*(u16*)(obj + 0x7C);
    if (t == 1) {
        *(u8**)(obj + 0x54) = D_800F9E6C_ovl03;
        D_8009A197 = 0;
        D_800D1C10 = 0;
    } else if (t == 0x1E) {
        set_animation(obj, 5);
        obj[7] = 0;
        for (i = 0; i < 3; i++) {
            p = func_8002C938();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 0x39;
                p[2] = 3;
                *(u8**)(p + 0x80) = obj;
            }
        }
    } else if (t == 0x6E) {
        set_animation(obj, 1);
        obj[5] = D_800FA0BC_ovl03[0][obj[0x93]++ + obj[0x92] * 6];
        obj[6] = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA248_ovl03;

void func_800F5C44_ovl03(Obj3DD4* obj) {
    s16 x;
    s16 a;
    s32 e;

    if (++obj->unk7C == 20) {
        set_animation(obj, 1);
        if (obj->unkA < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 16;
        } else {
            x = D_800FA242_ovl03 + 16;
        }
        e = obj->unkE + 1;
        a = ratan2(D_800FA244_ovl03 - e, x - obj->unkA);
        obj->unk20 = rcos(a) * 48;
        obj->unk24 = -rsin(a) * 48;
        obj->unk6++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F5D4C_ovl03(Obj5D4C* o) {
    if (D_8009A0AA > o->unkA) {
        o->unk15 = 0x40;
    } else {
        o->unk15 = 0;
    }
    if (o->unk20 < 0) {
        if (o->unkA <= D_800FA240_ovl03) {
            o->unkA = D_800FA240_ovl03;
            o->unk20 = 0;
        }
    } else if (o->unk20 > 0) {
        if (o->unkA >= D_800FA242_ovl03) {
            o->unkA = D_800FA242_ovl03;
            o->unk20 = 0;
        }
    }
    if (o->unkE <= D_800FA244_ovl03) {
        o->unkE = D_800FA244_ovl03;
        o->unk24 = 0;
    }
    if (o->unk20 == 0 && o->unk24 == 0) {
        o->unk90 = 0x3C;
        o->unk5 = 4;
        o->unk6 = 0;
    }
    animate_object(o);
    apply_object_motion(o);
}
