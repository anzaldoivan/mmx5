#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

#include "shared/func_800FD504_ovl39.c"

extern u8 D_800FEC1C_ovl39[];
extern u8 D_800FEC20_ovl39[];

void func_800FD558_ovl39(u8* a0) {
    s32 t;
    u8* p;
    u8* q;
    u8 v;
    s32 c;

    move_object(a0);
    t = ((s8*)a0)[2];
    if ((t == 0 && *(s16*)(a0 + 0xA) >= 0x12F0) ||
        (t == 1 && *(s16*)(a0 + 0xA) < 0x1131)) {
        if (((s8*)a0)[2] == 0) {
            q = D_800FEC20_ovl39;
            *(u8**)(a0 + 0x54) = q;
            q = D_800FEC1C_ovl39;
            *(u8**)(a0 + 0x68) = q;
            *(s32*)(a0 + 0x50) = 0;
            a0[0x8A] = 1;
            c = a0[6];
            c++;
            a0[6] = c;
        } else {
            *(u8**)(a0 + 0x54) = 0;
            *(s32*)(a0 + 0x50) = 0;
            *(u8**)(a0 + 0x68) = 0;
            a0[6] = 0xC;
        }
        p = *(u8**)(a0 + 0x7C);
        v = p[0x89];
        if (v) {
            v = 2;
        } else {
            v = 1;
        }
        p[0x89] = v;
        *(s16*)(a0 + 0x82) = 0x1E;
        a0[0x47] = 0;
    }
}

extern s32 D_8009A0A8;

void func_800FD63C_ovl39(u8* obj) {
    if (*(s8*)(*(u8**)(obj + 0x7C) + 7) != 0x11) {
        obj[0x84] = 0;
        obj[4] = 2;
    }
    if ((*(u8**)(obj + 0x7C))[0x89] == 2) {
        if (--*(s16*)(obj + 0x82) == 0) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = -0x18000;
            *(s32*)(obj + 0x8) = D_8009A0A8 + 0x140000;
            *(s16*)(obj + 0xE) = 0x710;
            set_animation(obj, 0xB);
            obj[6]++;
        }
    }
}

extern s32 D_8009A0A8;

void func_800FD6F4_ovl39(u8* obj) {
    *(s32*)(obj + 0x8) = D_8009A0A8 + 0x140000;
    move_object(obj);
    if (*(s16*)(obj + 0xE) >= 0x770) {
        *(s16*)(obj + 0x82) = 0x5A;
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
    }
}

extern s32 D_8009A0A8;

void func_800FD758_ovl39(u8* obj) {
    *(s32*)(obj + 0x8) = D_8009A0A8 + 0x140000;
    if (--*(s16*)(obj + 0x82) == 0) {
        obj[6]++;
    }
}

extern u8* find_free_visual_obj(void);

void func_800FD79C_ovl39(u8* arg0) {
    u8* p;
    s32 i;

    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x61;
        p[1] = 0x28;
        p[2] = 1;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        p[0x15] = arg0[0x15];
        *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
        *(u8**)(p + 0x7C) = arg0;
    }
    for (i = 0; i < 3; i++) {
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0x15;
            p[2] = i + 3;
            *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            p[0x15] = arg0[0x15];
            *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
            *(u8**)(p + 0x50) = arg0;
        }
    }
    *(u16*)(arg0 + 0x82) = 0x78;
    arg0[6]++;
}

void func_800FD8F4_ovl39(Obj800FD9BC* self) {
    if (--self->unk82 == 0) {
        if (self->unkA < 0x1210) {
            self->unk20 = 0x8000;
        } else {
            self->unk20 = -0x8000;
        }
        self->unk6++;
    }
}

void func_800FD944_ovl39(u8* a0) {
    move_object(a0);
    if ((*(s32*)(a0 + 0x20) > 0 && *(s16*)(a0 + 0xA) >= 0x1278) ||
        (*(s32*)(a0 + 0x20) < 0 && *(s16*)(a0 + 0xA) < 0x11A9)) {
        *(s16*)(a0 + 0x82) = 0x3C;
        a0[6]++;
    }
}

void func_800FD9BC_ovl39(Obj800FD9BC* self) {
    if (--self->unk82 == 0) {
        if (self->unkA < 0x1210) {
            self->unk20 = 0x8000;
        } else {
            self->unk20 = -0x8000;
        }
        self->unk82 = 0;
        self->unk84 = 0;
        self->unk85 = 3;
        self->unk6++;
    }
}

void func_800FDA18_ovl39(u8* o) {
    if (*(s16*)(o + 0x82) != 0) {
        *(s16*)(o + 0x82) = *(u16*)(o + 0x82) - 1;
    } else if (*(s8*)(o + 0x85) != 0) {
        o[0x84] = 0x28;
        o[0x85] = o[0x85] - 1;
        *(s16*)(o + 0x82) = ((random_byte() & 7) << 5) + 0x80;
    }
    if ((u16)(*(u16*)(o + 0xA) - 0x11C1) < 0x9F && *(s8*)(o + 0x84) != 0) {
        o[0x84] = o[0x84] - 1;
        return;
    }
    move_object(o);
    if ((*(s32*)(o + 0x20) > 0 && *(s16*)(o + 0xA) >= 0x1268) ||
        (*(s32*)(o + 0x20) < 0 && *(s16*)(o + 0xA) < 0x11B9)) {
        o[6]++;
    }
}

#define func_800FDAE0_ovl07 func_800FDB00_ovl39
#include "shared/func_800FDAE0_ovl07.c"
#undef func_800FDAE0_ovl07

void func_800FDB20_ovl39(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xE) < 0x711) {
        (*(u8**)(a0 + 0x7C))[0x89] = 3;
        *(s32*)(a0 + 0x24) = 0;
        a0[6] += 2;
    }
}

void func_800FDB74_ovl39(u8* a0) {
    if (*(s8*)(*(u8**)(a0 + 0x7C) + 7) != 0x11) {
        a0[0x84] = 0;
        a0[4] = 2;
    }
    if ((*(u8**)(a0 + 0x7C))[0x89] == 3) {
        a0[6]++;
    }
}

extern u8 D_800FEC18_ovl39[];
extern u8 D_800FEC14_ovl39[];

void func_800FDBC8_ovl39(u8* obj) {
    s32 t;

    if (*(s8*)(obj + 0x2) == 0) {
        *(u8*)(obj + 0x15) = 0;
        *(s16*)(obj + 0xA) = 0x12E0;
        *(s32*)(obj + 0x20) = -0x18000;
    } else {
        *(u8*)(obj + 0x15) = 0x40;
        *(s16*)(obj + 0xA) = 0x1140;
        *(s32*)(obj + 0x20) = 0x18000;
    }
    t = 0x820;
    *(s16*)(obj + 0xE) = t;
    t = (s32)D_800FEC18_ovl39;
    *(s32*)(obj + 0x54) = t;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(u8**)(obj + 0x68) = D_800FEC14_ovl39;
    *(u8*)(obj + 0x8A) = 0;
    set_animation(obj, 0);
    *(u8*)(*(u8**)(obj + 0x7C) + 0x89) = 0;
    *(u8*)(obj + 0x6) += 1;
}

extern u8 D_800FEB3C_ovl39[][4];

void func_800FDC84_ovl39(u8* a0) {
    s8 t;

    move_object(a0);
    t = *(s8*)(a0 + 2);
    if ((t == 0 && *(s16*)(a0 + 0xA) < 0x1291) ||
        (t == 1 && *(s16*)(a0 + 0xA) >= 0x1190)) {
        if (*(s8*)(*(u8**)(a0 + 0x7C) + 7) != 0x11) {
            *(s8*)(a0 + 5) = 7;
        } else {
            a0[0x88]++;
            *(s8*)(a0 + 5) = D_800FEB3C_ovl39[a0[0x87]][a0[0x88]];
        }
        a0[6] = 0;
        if (*(s8*)(a0 + 5) == 2) {
            *(s16*)(a0 + 0x82) = 180;
        }
    }
}
