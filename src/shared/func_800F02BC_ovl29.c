#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern void (*D_800F9388_ovl29[])(u8*);
extern u8 D_800F9374_ovl29[];
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);

void func_800F02BC_ovl29(u8* obj) {
    u8 state;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_800F9388_ovl29[*(signed char*)(obj + 5)](obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(3, D_800F9374_ovl29, obj);
        func_80054440(obj, 0);
        state = 2;
    } else {
        if (is_off_screen(obj, 0x40, 0x40) == 0) {
            func_8002D9EC(obj, 0x20, 0x20);
            return;
        }
        state = 3;
    }
    obj[4] = state;
}

extern int func_8002D7A0();

void func_800F0394_ovl29(signed char* arg0) {
    ((int*)arg0)[32] = 0;
    ((int*)arg0)[33] = 0;
    ((int*)arg0)[34] = 0;
    ((int*)arg0)[35] = 0;
    ((int*)arg0)[36] = 0;
    ((int*)arg0)[37] = 0;
    if (arg0[4] == 2) {
        func_8002D760(arg0);
    } else {
        func_8002D7A0(arg0);
    }
}
