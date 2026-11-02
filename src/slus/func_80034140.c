#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s32 D_8009A420;
extern u8 D_800D1C00[];
extern u8 D_8009A0A0[];

void func_80034140(u8* obj) {
    s32 frame;
    s32 idx;

    frame = D_8009A420;
    if (frame & 1) {
        return;
    }
    idx = ((s8*)obj)[0x14] != 10;
    if (*(s32*)(obj + 0x30) != 0) {
        u8* base = D_800D1C00;
        u8* q = base + 0x76;
        u8* p;
        s32 v;
        p = q + idx;
        v = *p & 0x7F;
        if (v != 0) {
            u8* x = D_8009A0A0;
            s32 t = x[0x5C];
            s32 lim;
            idx = v - 1;
            *p = idx | 0x80;
            idx = (s8)((t & 0x7F) + 1);
            lim = ((D1C00*)base)->unk47[((s8*)x)[2]];
            if (lim < idx) {
                idx = lim;
            }
            x[0x5C] = idx;
            if (!(frame & 3)) {
                func_80016490(0, 0x17, 0);
            }
        } else {
            u8* x = D_8009A0A0;
            s32 lim = ((D1C00*)base)->unk47[((s8*)x)[2]];
            if (((s8*)x)[0x5C] != lim) {
                idx = (s8)((x[0x5C] & 0x7F) + 1);
                if (lim < idx) {
                    idx = lim;
                }
                x[0x5C] = idx;
                if (!(frame & 3)) {
                    func_80016490(0, 0x17, 0);
                }
            } else {
                obj[5] = 1;
                *(s32*)(obj + 0x30) = 0;
                if (idx == 0) {
                    if (((s8*)base)[0x77] < 0) {
                        base[0x76] = base[0x77];
                        base[0x77] = base[0x77] & 0x80;
                    }
                }
            }
        }
    } else {
        u8* base2 = D_800D1C00;
        u8* q2 = base2 + 0x76;
        u8* p2;
        s32 m = -0x80;
        s32 v2;
        p2 = q2 + idx;
        v2 = *p2 & 0x7F;
        if (v2 != 0) {
            u8* x2 = D_8009A0A0;
            s32 t2 = x2[0x5C];
            s32 lim2;
            s32 hi;
            idx = v2 - 1;
            *p2 = idx | m;
            idx = (s8)((t2 & 0x7F) + 1);
            hi = (s8)(t2 & m);
            lim2 = ((D1C00*)base2)->unk47[((s8*)x2)[2]];
            if (lim2 < idx) {
                idx = lim2;
            }
            x2[0x5C] = idx | hi;
            if (!(frame & 3)) {
                func_80016490(0, 0x17, 0);
            }
        } else {
            obj[5] = 1;
            if (idx == 0) {
                if (((s8*)base2)[0x77] < 0) {
                    base2[0x76] = base2[0x77];
                    base2[0x77] = base2[0x77] & 0x80;
                }
            }
        }
    }
}
