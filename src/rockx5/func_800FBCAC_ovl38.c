#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800FCD04_ovl38(u8* obj, s32 arg1);
extern void func_80016490(s32, s32, void*);

void func_800FBCAC_ovl38(u8* obj) {
    u8* scr;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        *(s16*)(D_1F80004C.bytes + 0x84) = 0;
        func_800FCD04_ovl38(obj, 0);
        func_80016490(2, 0xA2, obj);
    } else {
        scr = D_1F80004C.bytes;
        if (*(s16*)(scr + 0x84) == 1) {
            *(s16*)(scr + 0x84) = 0;
            *(s16*)(obj + 0x7C) = 2;
            obj[6]++;
        }
    }
}
