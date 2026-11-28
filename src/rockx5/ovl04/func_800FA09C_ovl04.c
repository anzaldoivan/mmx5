#include "types.h"
#include "mmx5/globals.h"

void func_800FA09C_ovl04(u8* obj) {
    u8* parent;
    s32 r;

    parent = *(u8**)(obj + 0x80);
    r = func_80031DD0(obj);
    if (r < 0) {
        g_playthrough_state.u[0x2A] |= obj[0x92];
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        ((s32(*)())func_8004FD24)(obj);
        obj[5]++;
        return;
    }
    if (r > 0) {
        g_playthrough_state.u[0x27] |= 1;
    } else if (*(u16*)(parent + 0x42) & 0x8000) {
        *(u16*)(obj + 0x42) |= 0x8000;
    }
    func_800317B8(obj);
    func_8002D9EC(obj, 0x40, 0x20);
    if (g_playthrough_state.u[0x2A] & 4) {
        g_playthrough_state.u[0x2A] |= obj[0x92];
        ((s32(*)())func_8004FD24)(obj);
        obj[5]++;
    }
}
