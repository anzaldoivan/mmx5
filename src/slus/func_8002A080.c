/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80028EBC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define M2C_UNK s32

extern M2C_UNK D_8009A0A0;
#define D_8009A0A0 (*(X4_Obj*)&D_8009A0A0)

void func_8002A080(X4_BackgroundObj* arg0) {
    s32 spd1;
    s32 pos1;
    s32 spd2;
    s32 pos2;
    s32 spd3;
    s32 pos3;
    s32 pos4;
    s32 d;
    s16 t;
    s16 x;

    if (M2C_FIELD(arg0, s16*, 0x26) != M2C_FIELD(arg0, s16*, 0x1E)) {
        d = M2C_FIELD(arg0, s16*, 0x26) - M2C_FIELD(arg0, s16*, 0x1E);
        if (d < 0) {
            d = M2C_FIELD(arg0, s16*, 0x1E) - M2C_FIELD(arg0, s16*, 0x26);
        }
        spd1 = M2C_FIELD(arg0, s8*, 0x47);
        if (spd1 < d) {
            x = arg0->x_pos.i.hi;
            pos1 = (u16)arg0->x_pos.i.hi;
            if (M2C_FIELD(arg0, s16*, 0x26) >= x) {
                t = x + spd1;
                if (t >= M2C_FIELD(arg0, s16*, 0x26)) {
                    M2C_FIELD(arg0, s16*, 0x1E) = M2C_FIELD(arg0, s16*, 0x26);
                    goto block2; // !FAKE: control flow kept from the mmx6 twin
                }
                M2C_FIELD(arg0, s16*, 0x1E) = t;
                goto block2; // !FAKE: control flow kept from the mmx6 twin
            } else {
                t = D_8009A0A0.x_pos.i.hi;
                t = t - pos1;
                if ((s16)(t - M2C_FIELD(arg0, s16*, 0x30)) >= 0) {
                    t = D_8009A0A0.x_pos.i.hi - D_8009A0A0.unk18.i.hi;
                    if (t >= 0) {
                        t = 0;
                    }
                    t = t + pos1;
                    t = t - spd1;
                    if (t < M2C_FIELD(arg0, s16*, 0x26)) {
                        M2C_FIELD(arg0, s16*, 0x1E) = t;
                    } else {
                        M2C_FIELD(arg0, s16*, 0x1E) =
                            M2C_FIELD(arg0, s16*, 0x26);
                    }
                    goto block2; // !FAKE: control flow kept from the mmx6 twin
                } else {
                    M2C_FIELD(arg0, s16*, 0x1E) = M2C_FIELD(arg0, s16*, 0x26);
                    goto block2; // !FAKE: control flow kept from the mmx6 twin
                }
            }
        }
        M2C_FIELD(arg0, s16*, 0x1E) = M2C_FIELD(arg0, s16*, 0x26);
    }
block2:
    if (M2C_FIELD(arg0, s16*, 0x24) != M2C_FIELD(arg0, s16*, 0x1C)) {
        d = M2C_FIELD(arg0, s16*, 0x24) - M2C_FIELD(arg0, s16*, 0x1C);
        if (d < 0) {
            d = M2C_FIELD(arg0, s16*, 0x1C) - M2C_FIELD(arg0, s16*, 0x24);
        }
        spd2 = M2C_FIELD(arg0, s8*, 0x47);
        if (spd2 < d) {
            x = arg0->x_pos.i.hi;
            pos2 = (u16)arg0->x_pos.i.hi;
            if (M2C_FIELD(arg0, s16*, 0x24) < x) {
                t = x - spd2;
                if (t < M2C_FIELD(arg0, s16*, 0x24)) {
                    M2C_FIELD(arg0, s16*, 0x1C) = M2C_FIELD(arg0, s16*, 0x24);
                    goto block3; // !FAKE: control flow kept from the mmx6 twin
                }
                goto store2; // !FAKE: control flow kept from the mmx6 twin
            }
            t = D_8009A0A0.x_pos.i.hi;
            t = t - pos2;
            t = t - M2C_FIELD(arg0, s16*, 0x32);
            t = t + 2;
            if (t < 4) {
                t = D_8009A0A0.x_pos.i.hi - D_8009A0A0.unk18.i.hi;
                if (t < 0) {
                    t = 0;
                }
                t = t + pos2;
                t = t + spd2;
                if (M2C_FIELD(arg0, s16*, 0x24) < t) {
                store2:
                    M2C_FIELD(arg0, s16*, 0x1C) = t;
                    goto block3; // !FAKE: control flow kept from the mmx6 twin
                }
                M2C_FIELD(arg0, s16*, 0x1C) = M2C_FIELD(arg0, s16*, 0x24);
                goto block3; // !FAKE: control flow kept from the mmx6 twin
            }
        }

        M2C_FIELD(arg0, s16*, 0x1C) = M2C_FIELD(arg0, s16*, 0x24);
    }
block3:
    if (M2C_FIELD(arg0, s16*, 0x2A) != M2C_FIELD(arg0, s16*, 0x22)) {
        d = M2C_FIELD(arg0, s16*, 0x2A) - M2C_FIELD(arg0, s16*, 0x22);
        if (d < 0) {
            d = M2C_FIELD(arg0, s16*, 0x22) - M2C_FIELD(arg0, s16*, 0x2A);
        }
        spd3 = M2C_FIELD(arg0, s8*, 0x47);
        if (spd3 >= d) {
            M2C_FIELD(arg0, s16*, 0x22) = M2C_FIELD(arg0, s16*, 0x2A);
            goto block4; // !FAKE: control flow kept from the mmx6 twin
        }
        x = arg0->y_pos.i.hi;
        pos3 = (u16)arg0->y_pos.i.hi;
        if (M2C_FIELD(arg0, s16*, 0x2A) >= x) {
            t = x + spd3;
            if (t < M2C_FIELD(arg0, s16*, 0x2A)) {
                M2C_FIELD(arg0, s16*, 0x22) = t;
            } else {
                M2C_FIELD(arg0, s16*, 0x22) = M2C_FIELD(arg0, s16*, 0x2A);
            }
            goto block4; // !FAKE: control flow kept from the mmx6 twin
        }
        t = D_8009A0A0.y_pos.i.hi;
        t = t - pos3;
        t = t - M2C_FIELD(arg0, s16*, 0x2C);
        if (t < 0) {
            t = D_8009A0A0.y_pos.i.hi - D_8009A0A0.unk1C.i.hi;
            if (t >= 0) {
                t = 0;
            }
            t = t + pos3;
            t = t - spd3;
            if (t < M2C_FIELD(arg0, s16*, 0x2A)) {
                t = M2C_FIELD(arg0, s16*, 0x2A);
            }
        }
        M2C_FIELD(arg0, s16*, 0x22) = t;
    }
block4:
    if (M2C_FIELD(arg0, s16*, 0x28) != M2C_FIELD(arg0, s16*, 0x20)) {
        x = arg0->y_pos.i.hi;
        pos4 = (u16)arg0->y_pos.i.hi;
        if (M2C_FIELD(arg0, s16*, 0x28) < x) {
            t = x - M2C_FIELD(arg0, s8*, 0x47);
            if (t < M2C_FIELD(arg0, s16*, 0x28)) {
                t = M2C_FIELD(arg0, s16*, 0x28);
            }
            M2C_FIELD(arg0, s16*, 0x20) = t;
            return;
        }
        t = D_8009A0A0.y_pos.i.hi;
        t = t - pos4;
        t = t - M2C_FIELD(arg0, s16*, 0x2E);
        t = t + 2;
        if (t < 4) {
            t = D_8009A0A0.y_pos.i.hi - D_8009A0A0.unk1C.i.hi;
            if (t < 0) {
                t = 0;
            }
            t = t + pos4;
            t = t + M2C_FIELD(arg0, s8*, 0x47);
            if (t >= M2C_FIELD(arg0, s16*, 0x28)) {
                t = M2C_FIELD(arg0, s16*, 0x28);
            }
            M2C_FIELD(arg0, s16*, 0x20) = t;
            return;
        }
        M2C_FIELD(arg0, s16*, 0x20) = M2C_FIELD(arg0, s16*, 0x28);
    }
}
#undef D_8009A0A0
