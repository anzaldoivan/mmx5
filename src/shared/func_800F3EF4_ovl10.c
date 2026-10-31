/* Shared body (DK-5), from the banked draft of func_800F3EF4_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);

void DEDUP_NAME(u8* o) {
    s32 v;

    v = 2;
    if (((s8*)o)[7] == v) {
        if (((s8*)o)[0x45] != v) {
            func_80017248(o);
        }
        return;
    }
    func_80017248(o);
    if (o[0x8A] == v) {
        if (((s8*)o)[2] != 0) {
            if (((s8*)o)[7] != 1) {
                return;
            }
            v = ((s8*)*(u8**)(o + 0x80))[7];
            if (v != ((s8*)o)[7]) {
                return;
            }
            if (((s8*)o)[0x45] != 3) {
                return;
            }
            if (o[0x8B] != 2) {
                func_800171E8(o, 10);
                o[0x90] = v;
            } else {
            nine:
                func_800171E8(o, 9);
                o[0x90] = 0;
            }
        } else {
            if (((s8*)o)[0x98] == 0) {
                v = ((s8*)o)[7];
                if (v != 1) {
                    return;
                }
            } else {
                if (((s8*)o)[7] != 1) {
                    return;
                }
                v = ((s8*)*(u8**)(o + 0x80))[7];
                if (v != ((s8*)o)[7]) {
                    return;
                }
            }
            if (((s8*)o)[0x45] != 3) {
                return;
            }
            if (o[0x8B] == 0) {
                goto nine; // !FAKE: goto kept for the matching branch layout
            }
            func_800171E8(o, 10);
            o[0x90] = v;
        }
    } else {
        v = ((s8*)o)[7];
        if (v != 1) {
            return;
        }
        if (((s8*)o)[0x45] != 3) {
            return;
        }
        if ((u32)(func_8002DF78() & 0xF) >= 6) {
            o[0x90] = v;
            func_800171E8(o, 10);
        } else {
            o[0x90] = 0;
            func_800171E8(o, 9);
        }
    }
    o[6] = 5;
}
