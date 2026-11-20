#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void func_8002E0F8(s32* a0, s32* a1, s32 a2);
extern s32 func_8002E024(void*, void*);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002E274(u8* a0, u8* a1);

s32 func_800F777C_ovl00(u8* obj) {
    u16 k;
    s32 r;
    s32 y;
    s32 x;
    s32 v;

    v = ((s8*)obj)[5];
    if (v != 1) {
        if (v < 2) {
            if (v == 0) {
                *(u16*)(obj + 0x8E) -= *(u16*)(obj + 0x90);
                k = *(u16*)(obj + 0x8E) >> 8;
                func_8002E0F8((s32*)(obj + 0x20), (s32*)(obj + 0x24),
                              obj[0x8C]);
                *(s32*)(obj + 0x20) *= k;
                *(s32*)(obj + 0x24) *= k;
                if (k == 0) {
                    *(u16*)(obj + 0x92) = 0x3C;
                    obj[5]++;
                }
            }
        }
    } else {
        if (--*(u16*)(obj + 0x92) == 0) {
            func_8002E0F8((s32*)(obj + 0x20), (s32*)(obj + 0x24),
                          func_8002E024(obj, g_Player));
            x = *(s32*)(obj + 0x20);
            y = *(s32*)(obj + 0x24);
            x <<= 2;
            do {
                *(s32*)(obj + 0x20) = x;
            } while (0); // !FAKE: fences the sched1 hoist of the state load
            x = obj[5];
            y <<= 2;
            do {
                *(s32*)(obj + 0x24) = y;
            } while (0); // !FAKE: keeps the state increment below the store
            x++;
            obj[5] = x;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        r = func_8004FC64(obj);
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    if (func_8002E274(obj, g_Player) == 0) {
        if (obj[0x70] != 0) {
            r = ((s32(*)())func_8004FD24)(obj);
        inc:
            obj[4]++;
            return r;
        }
        if (is_off_screen(obj, 0x20, 0x20) == 0) {
            func_8002D9EC(obj, 0x10, 0x10);
            return;
        }
    }
    obj[4]++;
}
