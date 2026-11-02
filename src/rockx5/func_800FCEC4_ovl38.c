#include "types.h"

extern void func_800317B8(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void* D_800FD99C_ovl38[];

void func_800FCEC4_ovl38(u8* a0) {
    if (*(s8*)(*(u8**)(a0 + 0x7C) + 4) == 2) {
        a0[3] = 0;
        a0[4]++;
        return;
    }
    ((void (*)(u8*))D_800FD99C_ovl38[*(s8*)(a0 + 5)])(a0);
    func_800317B8(a0);
    if (a0[0x70] == 0) {
        func_8002F8FC(a0);
        if (a0[0x70] != 0) {
            if (*(s8*)(a0 + 2) == 2) {
                (*(u8**)(a0 + 0x7C))[0x92] = 0;
            }
            func_8004FC64(a0);
            a0[3] = 0;
            a0[4]++;
            return;
        }
    }
    if (func_8002D938(a0, 0xA0, 0x40) == 1) {
        if (*(s8*)(a0 + 2) == 2) {
            (*(u8**)(a0 + 0x7C))[0x92] = 0;
        }
        a0[4]++;
    }
}
