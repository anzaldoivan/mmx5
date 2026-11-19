#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void func_8004B49C(u8* obj, u8* g);
extern void func_8004B8E4(u8* obj, u8* g);

void func_8004C7A4(u8* obj) {
    u8* g = g_Player;
    s32 f;

    f = FX(g, s8, 0x5C) == 0;
    if (FX(g, s8, 0xD3)) {
        f = 1;
    }
    if (FX(g, s8, 0xCF)) {
        f = 1;
    }
    if (FX(g, s8, 0x5) != 0x37) {
        f = 1;
    }
    if (f) {
        goto kill; // !FAKE: goto kept for the matching branch layout
    }
    if (FX(obj, s8, 0x4) == 0) {
        func_8004B49C(obj, g);
    } else if (FX(obj, s8, 0x4) == 1) {
        animate_object(obj);
        if (FX(g, s8, 0x6) != 3) {
            goto keep; // !FAKE: goto kept for the matching branch layout
        }
        goto kill; // !FAKE: goto kept for the matching branch layout
    } else {
        animate_object(obj);
        if (FX(obj, s8, 0x46) == 0) {
        kill: // !FAKE: label kept for the matching branch layout
            clear_object_slot(obj);
            return;
        }
    }
keep: // !FAKE: label kept for the matching branch layout
    func_8004B8E4(obj, g);
}
