#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void* D_800FD544_ovl01[];
extern s32 func_8003240C(u8* a0);

void func_800F7EB0_ovl01(u8* obj) {
    u8* g;

    if ((((s8*)obj)[2] & 0xF0) && (*(u8**)(D_1F80004C.bytes + 0x80))[7] >= 2) {
        obj[4] = 2;
        func_8004FD24(obj);
        return;
    }
    g = g_Player;
    if (g[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        animate_object(obj);
        ((void (*)(u8*))D_800FD544_ovl01[((s8*)obj)[5]])(obj);
    }
    if (((s8*)obj)[5] != 3 && g[0xF8] == 0) {
        func_8003240C(obj);
    }
    func_80031DD0(obj);
    if (is_off_screen(obj, 0x50, 0x40) == 0) {
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    if (!(((s8*)obj)[2] & 0xF0)) {
        obj[4] = 3;
    }
}
