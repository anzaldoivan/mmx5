#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

extern s32 func_8002E198(void);
extern void func_8003D010(s8 dmg);

void func_800F64E4_ovl10(u8* obj) {
    u8 t;
    s16 old;
    s32 cnt;
    s32 was;

    t = (*(u8**)(obj + 0x7C))[0x47];
    if (t == 0x76 || t == 0x7F) {
        set_animation(obj, 4);
    } else {
        set_animation(obj, 0x18);
    }
    set_animation(obj, 4);
    if (g_Player[0x5C] & 0x7F) {
        old = *(s16*)(obj + 0x90);
        *(s16*)(obj + 0x90) += func_8002E198();
        if (old != *(s16*)(obj + 0x90)) {
            *(u16*)(obj + 0x42) |= 0x8000;
        } else {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    cnt = *(s32*)(obj + 0x84);
    was = cnt;
    cnt--;
    *(s32*)(obj + 0x84) = cnt;
    if (was == 0) {
        func_8003D010(6);
        was = 0x3C;
        *(s32*)(obj + 0x84) = was;
    }
    if (*(s16*)(obj + 0x90) >= 30) {
        obj[0x62] = 0;
        g_Player[0xCA] = 0;
        obj[4] = 2;
    }
}

extern u8 D_80074DA0[];
extern u8 D_800FBF38_ovl10[];
extern signed char D_800D1C0C;

void func_800F660C_ovl10(u8* o) {
    s32 y;
    s32 v;

    o[4] = 5;
    o[3] = 1;
    o[0x16] = 6;
    *(s32*)(o + 0x68) = 0;
    *(u8**)(o + 0x58) = D_80074DA0;
    *(u8**)(o + 0x54) = D_800FBF38_ovl10;
    *(u8**)(o + 0x50) = D_800FBF38_ovl10;
    *(s16*)(o + 0x88) = 0xAA;
    o[0x5C] = 0x18;
    o[0x60] = 4;
    set_animation(o, 5);
    if (D_800D1C0C != 12) {
        y = *(s16*)(o + 0xA);
        if (y < 0x1F61) {
            *(s16*)(o + 0x88) = 0x32;
            *(s32*)(o + 0x68) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x50) = 0;
            set_animation(o, 0x1B);
            v = 0x1F70;
            *(s16*)(o + 0xA) = v;
        } else if (y >= 0x20A0) {
            *(s16*)(o + 0x88) = 0x32;
            *(s32*)(o + 0x68) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x50) = 0;
            set_animation(o, 0x1B);
            v = 0x2090;
            *(s16*)(o + 0xA) = v;
        }
    } else {
        y = *(s16*)(o + 0xA);
        if (y < 0xA61) {
            *(s16*)(o + 0x88) = 0x32;
            *(s32*)(o + 0x68) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x50) = 0;
            set_animation(o, 0x1B);
            v = 0xA70;
            *(s16*)(o + 0xA) = v;
        } else if (y >= 0xBA0) {
            *(s16*)(o + 0x88) = 0x32;
            *(s32*)(o + 0x68) = 0;
            *(s32*)(o + 0x54) = 0;
            *(s32*)(o + 0x50) = 0;
            set_animation(o, 0x1B);
            v = 0xB90;
            *(s16*)(o + 0xA) = v;
        }
    }
    play_sound(2, 0x2D, o);
}

extern signed char D_800D1C0C;

void func_800F6780_ovl10(u8* o) {
    s32 r;
    s16 x;
    u32 d;
    s16 c;

    *(u16*)(o + 0x42) &= 0x7FFF;
    func_800317B8(o);
    r = func_80031DD0(o);
    animate_object(o);
    x = *(s16*)(o + 0xA);
    if ((D_8009A0AA - 4 < x && x < D_8009A0AA + 4) ||
        *(s16*)(o + 0x88) != 0xAA) {
        *(u16*)(o + 0x88) -= 1;
    } else {
        move_object(o);
    }
    if (D_800D1C0C != 0xC) {
        d = *(u16*)(o + 0xA) - 0x1F71;
    } else {
        d = *(u16*)(o + 0xA) - 0xA71;
    }
    if (d >= 0x11F && *(s16*)(o + 0x88) > 0x32) {
        *(s16*)(o + 0x88) = 0x32;
    }
    if (r < 0) {
        o[4] = 6;
        func_8004FD24(o);
        return;
    }
    if (*(s8*)(*(u8**)(o + 0x7C) + 4) == 2) {
        o[3] = 0;
        clear_object_slot(o);
    } else if (is_off_screen(o, 0x40, 0x40) == 1) {
        o[4] = 6;
    } else {
        func_8002D9EC(o, 0x20, 0x20);
    }
    c = *(s16*)(o + 0x88);
    if (c == 50) {
        *(s32*)(o + 0x68) = 0;
        *(s32*)(o + 0x54) = 0;
        *(s32*)(o + 0x50) = 0;
        set_animation(o, 0x1B);
    } else if (c == 0) {
        o[4] = 6;
    }
}

void func_800F6924_ovl10(u8* o) {
    u8 f;
    s16 t;

    move_object(o);
    animate_object(o);
    ((s32(*)())func_8002FB58)(o);
    *(u16*)(o + 0x42) &= 0x7FFF;
    func_800317B8(o);
    f = o[0x70];
    if ((f & 2) || (f & 1)) {
        play_sound(2, 0x2E, o);
        *(s32*)(o + 0x20) = -*(s32*)(o + 0x20);
    }
    if (*(s32*)(o + 0x70) & 0xC) {
        play_sound(2, 0x2E, o);
        *(s32*)(o + 0x24) = -*(s32*)(o + 0x24);
    }
    if (func_80031DD0(o) < 0) {
        o[4] = 9;
        func_8004FD24(o);
        return;
    }
    if ((*(s8**)(o + 0x7C))[4] == 2) {
        o[3] = 0;
        clear_object_slot(o);
    } else if (is_off_screen(o, 0x60, 0x60) == 1) {
        o[4] = 9;
    } else {
        func_8002D9EC(o, 0x20, 0x20);
    }
    t = --*(u16*)(o + 0x88);
    if (t == 0) {
        o[4] = 9;
    } else if (t == 50) {
        *(s32*)(o + 0x68) = 0;
        *(s32*)(o + 0x54) = 0;
        *(s32*)(o + 0x50) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x24) = 0;
        set_animation(o, 0x22);
    }
}

extern s8 D_800D1C0C;
extern u8 D_800FBF34_ovl10[];

void func_800F6AAC_ovl10(u8* a0) {
    s32 lim;
    s32 x;
    s32 vx;
    s32 i;
    s32 n;
    u8* c;
    s8 m;

    if (D_800D1C0C != 0xC) {
        lim = 0x3C0;
        x = 0x2000;
        vx = 0x20900000;
    } else {
        lim = 0;
        x = 0xB00;
        vx = 0x0B900000;
    }
    move_object(a0);
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    func_800317B8(a0);
    animate_object(a0);
    if (func_80031DD0(a0) < 0) {
        a0[4] = 0xD;
        func_8004FD24(a0);
        return;
    }
    a0[0x15] = 0;
    if (*(s16*)(a0 + 0xE) < lim) {
        if (x < *(s16*)(a0 + 0xA)) {
            *(s32*)(a0 + 0x20) = 0;
            *(s32*)(a0 + 0x28) = 0x17D0;
            *(s32*)(a0 + 0x8) = vx;
        } else {
            *(s32*)(a0 + 0x20) = 0;
            *(s32*)(a0 + 0x28) = -0x17D0;
            *(s32*)(a0 + 0x8) = vx + 0xFEE00000;
        }
        *(s32*)(a0 + 0x24) = 0xFFFE0000;
        *(s32*)(a0 + 0x2C) = -0x770;
        *(u8**)(a0 + 0x68) = D_800FBF34_ovl10;
        a0[4] = 0xC;
        *(s16*)(a0 + 0x92) = 0x3C;
        *(s16*)(a0 + 0x88) = (*(s8*)(a0 + 2) * 0x3C) + 0x3C;
        set_animation(a0, 0xD);
        m = a0[2];
        if (m == 0) {
            i = 0;
            do {
                c = func_8002D1A4();
                n = i + 1;
                if (c != 0) {
                    c[0] = 0x41;
                    c[1] = 0x27;
                    c[2] = n;
                    c[4] = 0xA;
                    *(u16*)(c + 0x40) = *(u16*)(a0 + 0x40);
                    *(u16*)(c + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
                    *(s32*)(c + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(c + 0x3C) = *(s32*)(a0 + 0x3C);
                    c[0x14] = a0[0x14];
                    *(s32*)(c + 0x8) = *(s32*)(a0 + 0x8);
                    *(s16*)(c + 0xE) = lim - 1;
                    c[0x15] = a0[0x15];
                    *(s32*)(c + 0x7C) = *(s32*)(a0 + 0x7C);
                }
                i = n;
            } while (i < 4);
        } else if (m == 4) {
            a0[4] = 0xD;
        }
    }
}

extern u8 D_800FBF3C_ovl10[];
extern signed char D_800D1C0C;

void func_800F6CC8_ovl10(u8* o) {
    s32 lim;
    s32 mid;
    s32 v;
    s32 y;
    u8 f;

    *(u8**)(o + 0x54) = D_800FBF3C_ovl10;
    if (D_800D1C0C != 12) {
        lim = 0x3F0;
        mid = 0x2000;
    } else {
        lim = 0x30;
        mid = 0xB00;
    }
    if (*(s16*)(o + 0x88) != 0) {
        (*(s16*)(o + 0x88))--;
        return;
    }
    *(u16*)(o + 0x42) &= 0x7FFF;
    func_800317B8(o);
    animate_object(o);
    if (func_80031DD0(o) < 0) {
        o[4] = 0xD;
        func_8004FD24(o);
        return;
    }
    apply_object_motion(o);
    y = *(s16*)(o + 0xE);
    y = lim < y;
    if (y != 0) {
        func_8002FB58(o);
    }
    y = *(s16*)(o + 0xA);
    if (y > mid + 5 && (v = *(s32*)(o + 0x28)) < 0) {
        *(s32*)(o + 0x28) = -v;
    } else if (y < mid - 5 && (v = *(s32*)(o + 0x28)) > 0) {
        *(s32*)(o + 0x28) = -v;
    }
    f = o[0x70];
    if (f & 2) {
        *(s32*)(o + 0x28) = -0x17D0;
        *(s32*)(o + 0x24) = -0x20000;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x2C) = -0x770;
        (*(s16*)(o + 0xA))++;
    } else if (f & 1) {
        *(s32*)(o + 0x28) = 0x17D0;
        *(s32*)(o + 0x24) = -0x20000;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x2C) = -0x770;
        (*(s16*)(o + 0xA))--;
    }
    if (o[0x70] & 8) {
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
        if (*(s16*)(o + 0x92) == 0) {
            clear_object_slot(o);
            return;
        }
        if (!(--(*(s16*)(o + 0x92)) & 1)) {
            o[3] = 0;
            return;
        }
    }
    if ((*(s8**)(o + 0x7C))[4] == 2) {
        o[3] = 0;
        clear_object_slot(o);
        return;
    }
    if (is_off_screen(o, 0x60, 0x60) == 1) {
        o[4] = 0xD;
        return;
    }
    func_8002D9EC(o, 0x20, 0x20);
}

extern void (*D_800FBF88_ovl10[])(Actor7C*);

void func_800F6EFC_ovl10(Actor7C* obj) {
    Actor7CLink* other;

    obj->unk18 = obj->unk8;
    obj->unk1C = obj->unkC;
    other = obj->unk7C;
    D_800FBF88_ovl10[obj->state](obj);
    if (other->state == 2) {
        obj->state = 3;
    }
}

void func_800F6F70_ovl10(Obj6F70* obj) {
    obj->unk16 = 3;
    obj->unk4 = 1;
    obj->unk5 = 0;
    obj->unk3 = 1;
    obj->unk58 = 0;
    obj->unk61 = 1;
    obj->unk90 = 0;
    obj->unk94 = 0;
    obj->unk20 = 0;
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk68 = 0;
    obj->unk54 = 0;
    obj->unk50 = 0;
    obj->unk5C = 0;
    obj->unk60 = 0;
    obj->unk84 = 0;
    set_animation(obj, 0x18);
}

extern s8 D_8009A16A;
extern void* D_800FBFCC_ovl10[];

void func_800F6FE0_ovl10(u8* arg0) {
    u8* obj;
    u8 kind;
    s8 st;

    arg0[0x62] = 3;
    obj = *(u8**)(arg0 + 0x7C);
    ((void (*)(u8*))D_800FBFCC_ovl10[(s8)arg0[5]])(arg0);
    kind = obj[0x47];
    if (kind == 0x76 || kind == 0x7F) {
        arg0[3] = 1;
    } else {
        arg0[3] = 0;
    }
    if (((s8*)obj)[4] == 2 || (st = ((s8*)obj)[5]) == 2 ||
        (st == 6 && ((s8*)obj)[6] < 3)) {
        if (((s8*)arg0)[5] != 0) {
            D_8009A16A = 0;
        }
        arg0[4] = 2;
    }
}

void func_800F70B8_ovl10(u8* arg0) {
    (*(u8**)(arg0 + 0x7C))[7] = 1;
    clear_object_slot(arg0);
}
