#include "types.h"
#include "addr.h"

extern void func_800FCB74_ovl38(u8* arg0, s32 arg1);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FD558_ovl38[];

void func_800FAABC_ovl38(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        switch (D_800FD558_ovl38[*(s16*)(D_1F80004C.bytes + 0x86) +
                                 *(s16*)(obj + 0x7E) * 7]) {
        case 0:
            func_800FCB74_ovl38(obj, 3);
            func_80016490(2, 0xA0, obj);
            break;
        case 1:
            func_800FCB74_ovl38(obj, 4);
            func_80016490(2, 0xA0, obj);
            break;
        case 2:
            func_800FCB74_ovl38(obj, 5);
            func_800FCB74_ovl38(obj, 6);
            func_80016490(2, 0xA0, obj);
            break;
        case 4:
            func_800171E8(obj, 0x18);
            *(s16*)(obj + 0x7C) = 0x32;
            obj[6]++;
            return;
        }
        (*(s16*)(D_1F80004C.bytes + 0x86))++;
    }
    if (*(s8*)(obj + 0x45) == 2) {
        func_800171E8(obj, 0x18);
        if (D_800FD558_ovl38[*(s16*)(D_1F80004C.bytes + 0x86) +
                             *(s16*)(obj + 0x7E) * 7] == 4) {
            *(s16*)(obj + 0x7C) = 0x32;
            obj[6]++;
        } else {
            obj[6]--;
        }
    }
}
