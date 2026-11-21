#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"

void func_800F2CE4_ovl00(Ent08D8* e) {
    if (!(e->unk70 & 8)) {
        e->unk5 = 8;
        e->unk6 = 0;
        e->unk2C = 0x4200;
        e->unk24 = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 1;
    }
}

void func_800F2D24_ovl00(u8* arg0) {
    u8 v = (*(u8**)(D_1F80004C.bytes + 0x80))[0x8A];

    if (v == 1) {
        arg0[5] = 3;
    } else if (v == 2) {
        arg0[5] = 4;
    }
}

extern u8* func_8002C938();

void func_800F2D68_ovl00(u8* arg0, u8 arg1) {
    u8* p;

    p = func_8002C938();
    if (p != 0) {
        D_1F80004C.bytes[0x88] = 0;
        p[0] = 0x41;
        p[1] = arg0[1];
        p[2] = arg1;
        *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
        *(s32*)(p + 0x10) = 0;
        p[0x15] = arg0[0x15];
        *(u8**)(p + 0x80) = arg0;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
    }
}

extern s32 D_800FAC44_ovl00;

void func_800F2E10_ovl00(u8* arg0) {
    u8* obj = func_8002D1A4();

    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 1;
        obj[2] = 2;
        *(u8**)(obj + 0x7C) = arg0;
        *(u16*)(obj + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32**)(obj + 0x30) = &D_800FAC44_ovl00;
        *(s32*)(obj + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(obj + 0x40) = *(u16*)(arg0 + 0x40);
        obj[0x15] = arg0[0x15];
        obj[0x14] = arg0[0x14];
        obj[0x16] = 4;
    }
}

extern s32 D_800FAC44_ovl00;

void func_800F2EA4_ovl00(u8* arg0, s32 a1) {
    u8 arg1 = a1;
    u8* obj = func_8002D1A4();

    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 1;
        obj[2] = arg1;
        *(u8**)(obj + 0x7C) = arg0;
        *(u16*)(obj + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32**)(obj + 0x30) = &D_800FAC44_ovl00;
        *(s32*)(obj + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(obj + 0x40) = *(u16*)(arg0 + 0x40);
        obj[0x15] = arg0[0x15];
        obj[0x14] = arg0[0x14];
        obj[0x16] = 4;
    }
}

void func_800F2F40_ovl00(u8* obj) {
    u8* g = D_1F80004C.bytes;

    if (g[0x85] != 0 && (*(u8**)(g + 0x80))[0x87] == 0) {
        g[0x85] = 0;
        if ((*(u8**)(D_1F80004C.bytes + 0x80))[0x86] == 0) {
            func_8004FD24(obj);
        }
        obj[4] = 5;
    }
}

void func_800F2038_ovl00(void);

void func_800F2FC8_ovl00(u8* arg0) {
    if (D_1F80004C.bytes[0x88] != 0) {
        arg0[2] = 0;
        func_800F2038_ovl00();
        D_1F80004C.bytes[0x88] = 0;
    }
}

extern u8 D_80074DA0[];
extern u8 D_800FADA0_ovl00[];
extern u8 D_800FADA8_ovl00[];
extern u8 D_800FADAC_ovl00[];
extern u8 D_800FADB0_ovl00[];
extern u8 D_800FADB4_ovl00[];

void func_800F3014_ovl00(u8* obj) {
    u8* p;
    s16 e;

    obj[3] = 1;
    p = *(u8**)(obj + 0x7C);
    obj[0x8C] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(u8**)(obj + 0x58) = D_80074DA0;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    obj[0x8D] = p[1];
    switch (*(s8*)(obj + 2)) {
    case 0:
        obj[0x5C] = 2;
        obj[0x60] = 3;
        *(u8**)(obj + 0x50) = D_800FADAC_ovl00;
        *(u8**)(obj + 0x54) = D_800FADB0_ovl00;
        *(u8**)(obj + 0x68) = D_800FADB4_ovl00;
        set_animation(obj, 0xB);
        if (obj[0x15] == 0) {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) + 0x12;
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) - 0x12;
        }
        e = *(s16*)(p + 0xE) - 0x17;
        obj[5] = 0;
        *(s16*)(obj + 0xE) = e;
        break;
    case 1:
        obj[0x5C] = 2;
        obj[0x60] = 3;
        *(u8**)(obj + 0x50) = D_800FADAC_ovl00;
        *(u8**)(obj + 0x54) = D_800FADB0_ovl00;
        *(u8**)(obj + 0x68) = D_800FADB4_ovl00;
        set_animation(obj, 0xB);
        if (obj[0x15] == 0) {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) + 0x10;
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) - 0x10;
        }
        e = *(s16*)(p + 0xE) - 7;
        obj[5] = 0;
        *(s16*)(obj + 0xE) = e;
        break;
    case 2:
        obj[0x5C] = 1;
        obj[0x60] = 3;
        *(u8**)(obj + 0x50) = D_800FADA0_ovl00;
        *(u8**)(obj + 0x54) = 0;
        *(u8**)(obj + 0x68) = D_800FADA8_ovl00;
        set_animation(obj, 7);
        if (obj[0x15] == 0) {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) + 0x10;
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) - 0x10;
        }
        e = *(s16*)(p + 0xE) - 0x18;
        obj[5] = 2;
        *(s16*)(obj + 0xE) = e;
        break;
    }
    obj[4]++;
}

extern u8 D_8009A197;
extern void (*D_800FADCC_ovl00[])(u8* obj);
extern u8 D_800FADB8_ovl00[];

void func_800F3224_ovl00(u8* obj) {
    u8* base;
    s32 off;
    s32 r;

    if (D_8009A197 == 0) {
        D_800FADCC_ovl00[(s8)obj[5]](obj);
        animate_object(obj);
    }
    func_800317B8(obj);
    r = 2; /* r holds the 2: a literal is cse-reused across the calls (phantom $s1) */
    if ((s8)obj[2] != r && (r = func_80031DD0(obj)) < 0) {
        goto dead; // !FAKE: early exit joins the target's shared death block
    }
    if (obj[0x70] != 0 || (((s32(*)())func_8002F8FC)(obj), obj[0x70] != 0)) {
        if ((s8)obj[2] == 2) {
            obj[0] = 0x21;
            obj[0x15] = 0;
            *(s32*)(obj + 0x38) = 0;
            base = D_1F80001C.bytes;
            off = *(s32*)(base + 8);
            *(s16*)(obj + 0x40) = 0;
            *(s16*)(obj + 0x42) = 0x7804;
            *(u8**)(obj + 0x3C) = base + off;
            set_animation(obj, 0x11);
            if (random_byte() & 1) {
                play_sound(0, 2, obj);
            } else {
                play_sound(0, 3, obj);
            }
            obj[0x60] = 4;
            *(u8**)(obj + 0x50) = D_800FADB8_ovl00;
            obj[4] = 2;
            obj[7] = 0;
            return;
        }
    dead:
        ((s32(*)())func_8004FD24)(obj);
        obj[4] = 3;
        return;
    }
    if (is_off_screen(obj, 0x40, 0x20) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
        return;
    }
    obj[4] = 3;
}

void func_800F33B0_ovl00(u8* o) {
    u8* q0;
    u8* q1;
    u8* q2;
    u8* q3;
    s32 v;
    s32 t;
    s32 e;
    s32 a;

    if (o[0x15] != 0) {
        q0 = g_Player;
        if (((*(s16*)(q0 + 0xA) - *(s16*)(o + 0xA)) < 0
                 ? (*(s16*)(o + 0xA) - *(s16*)(q0 + 0xA))
                 : (*(s16*)(q0 + 0xA) - *(s16*)(o + 0xA))) >= 0x48) {
            q1 = g_Player;
            a = *(s16*)(q1 + 0xA);
            t = *(s16*)(o + 0xA) + 0x24;
            e = a - t;
            if (e >= 0) {
                v = ((e << 16) / 50);
            } else {
                v = (((t - a) << 16) / 50);
            }
            *(s32*)(o + 0x20) = v;
        } else {
            *(s32*)(o + 0x20) = 0x170A3;
        }
    } else {
        q2 = g_Player;
        if (((*(s16*)(q2 + 0xA) - *(s16*)(o + 0xA)) < 0
                 ? (*(s16*)(o + 0xA) - *(s16*)(q2 + 0xA))
                 : (*(s16*)(q2 + 0xA) - *(s16*)(o + 0xA))) >= 0x48) {
            q3 = g_Player;
            a = *(s16*)(q3 + 0xA);
            t = *(s16*)(o + 0xA) - 0x24;
            e = a - t;
            if (e >= 0) {
                v = -((e << 16) / 50);
            } else {
                v = -(((t - a) << 16) / 50);
            }
            *(s32*)(o + 0x20) = v;
        } else {
            *(s32*)(o + 0x20) = -0x170A3;
        }
    }
    *(s32*)(o + 0x24) = 0x30000;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0x2000;
    o[0x67] = 0;
    o[6]++;
}
