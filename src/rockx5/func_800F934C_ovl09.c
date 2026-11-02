#include "types.h"

extern void func_8004FD24(u8* a0);
extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);

void func_800F934C_ovl09(u8* obj) {
    s8 state;
    s8 sub;

    state = (*(u8**)(obj + 0x50))[4];
    if (state == 2) {
        *(u16*)(obj + 0xE) -= 0x40;
        func_8004FD24(obj);
        *(u16*)(obj + 0xE) += 0x20;
        func_8004FD24(obj);
        *(u16*)(obj + 0xE) += 0x20;
        func_8004FD24(obj);
        *(u16*)(obj + 0xE) += 0x20;
        func_8004FD24(obj);
        *(u16*)(obj + 0xE) += 0x20;
        func_8004FD24(obj);
        *(s16*)(obj + 0x54) = 0;
        obj[4] = state;
        obj[5] = 0;
        obj[3] = 0;
        *(u16*)(obj + 0xE) -= 0x40;
        return;
    }
    sub = obj[5];
    if (sub == 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0xFFFE0000;
        obj[5]++;
    } else if (sub == 1) {
        func_8002DF54(obj);
        if (*(s16*)(obj + 0xE) >= 0x8A8) {
            *(s16*)(obj + 0xE) = 0x8A8;
            obj[5]++;
        }
    }
    func_80017248(obj);
}
