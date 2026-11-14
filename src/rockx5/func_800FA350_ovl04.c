#include "types.h"

extern s32 func_8002DF78(void);
extern u8* func_8002D27C(void);
extern s32 D_8009A420;
extern s32 D_80102C1C_ovl04[][4];
extern s32 D_80102C5C_ovl04[];
extern u16 D_80102BFC_ovl04[][4];
extern s32 D_80102C6C_ovl04[];
extern s32 D_80102C7C_ovl04[];

static inline u8* func_800FA350_ovl04_spawn(u8* o, s32 kind) {
    u8* q;

    q = func_8002D27C();
    if (q != 0) {
        q[0] = 0x41;
        q[1] = 0x18;
        q[2] = kind;
        *(u8**)(q + 0x50) = o;
    }
    return q;
}

static inline void func_800FA350_ovl04_place(u8* p, u8* o, s32 slot) {
    if (p != 0) {
        *(s16*)(p + 0xA) = *(u16*)(o + 0xA) + D_80102BFC_ovl04[slot][0];
        *(s16*)(p + 0xE) = *(u16*)(o + 0xE) + D_80102BFC_ovl04[slot][2];
        if (func_8002DF78() & 1) {
            *(s16*)(p + 0xA) -= func_8002DF78() & 3;
        } else {
            *(s16*)(p + 0xA) += func_8002DF78() & 3;
        }
    }
}

void func_800FA350_ovl04(u8* o) {
    if (*(s16*)(o + 0xA) > 0xA50) {
        return;
    }
    if (*(s16*)(o + 0x88) != 0) {
        if (--*(s16*)(o + 0x88) != 0) {
            return;
        }
    }
    if (*(s8*)(o + 0x8C) == 1 && !(D_8009A420 & 1)) {
        s8 kind;
        s32 slot;
        s32* sp;
        u8* tbl;
        u8* p;

        if (*(s8*)(o + 0x90) == 0) {
            *(s8*)(o + 0x91) = func_8002DF78() & 3;
        }
        tbl = (u8*)D_80102C1C_ovl04;
        sp = (s32*)(tbl + (*(s8*)(o + 0x90) * 4 + *(s8*)(o + 0x91) * 16));
        kind = D_80102C5C_ovl04[*(s8*)(o + 0x90)];
        slot = *sp;
        p = func_800FA350_ovl04_spawn(o, kind);
        func_800FA350_ovl04_place(p, o, slot);
        if (++*(s8*)(o + 0x90) >= 4) {
            u32 r = func_8002DF78();

            *(s8*)(o + 0x90) = 0;
            *(s16*)(o + 0x88) = (u8)(r % 3) + 8;
        }
    } else if (*(s8*)(o + 0x8C) == 0 && !(D_8009A420 & 7)) {
        s8 kind;
        s32 slot;
        s32* sp;
        u8* tbl;
        u8* p;

        if (*(s8*)(o + 0x90) == 0) {
            *(s8*)(o + 0x91) = func_8002DF78() & 3;
        }
        tbl = (u8*)D_80102C1C_ovl04;
        sp = (s32*)(tbl + (*(s8*)(o + 0x90) * 4 + *(s8*)(o + 0x91) * 16));
        kind = D_80102C6C_ovl04[*(s8*)(o + 0x90)];
        slot = *sp;
        p = func_800FA350_ovl04_spawn(o, kind);
        func_800FA350_ovl04_place(p, o, slot);
        if (++*(s8*)(o + 0x90) >= 4) {
            u32 r = func_8002DF78();

            *(s8*)(o + 0x90) = 0;
            *(s16*)(o + 0x88) = (u8)(r % 31) + 20;
        }
    } else if (*(s8*)(o + 0x8C) == -1 && !(D_8009A420 & 1)) {
        s8 kind;
        s32 slot;
        s32* sp;
        u8* tbl;
        u8* p;

        if (*(s8*)(o + 0x90) == 0) {
            *(s8*)(o + 0x91) = func_8002DF78() & 3;
        }
        tbl = (u8*)D_80102C1C_ovl04;
        sp = (s32*)(tbl + (*(s8*)(o + 0x90) * 4 + *(s8*)(o + 0x91) * 16));
        kind = D_80102C7C_ovl04[*(s8*)(o + 0x90)];
        slot = *sp;
        p = func_800FA350_ovl04_spawn(o, kind);
        func_800FA350_ovl04_place(p, o, slot);
        if (++*(s8*)(o + 0x90) >= 4) {
            u32 r = func_8002DF78();

            *(s8*)(o + 0x90) = 0;
            *(s16*)(o + 0x88) = (u8)(r % 51) + 40;
        }
    }
}
