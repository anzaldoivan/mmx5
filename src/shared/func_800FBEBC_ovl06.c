#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FF708_ovl06[];
extern u16 D_800FF714_ovl06[][2];

void func_800FBEBC_ovl06(u8* obj) {
    s32 c;
    s32 idx;
    u32 hi;

    ((s32(*)(u8*))animate_object)(obj);
    c = (*(s8**)(obj + 0x50))[0x45];
    hi = c & 0xF0;
    if (hi == 0) {
        return;
    }
    switch (hi) {
    case 0x80:
        obj[3] = 1;
        ((s32(*)(u8*, s32))set_animation)(obj, D_800FF708_ovl06[idx = c & 0xF]);
        if (idx == 1 || idx == 8) {
            obj[0x16] = 4;
        } else {
            obj[0x16] = 6;
        }
        break;
    case 0x40:
        obj[3] = 0;
        break;
    case 0x20:
        if (obj[0x15] == 0) {
            *(u16*)(obj + 0xA) += D_800FF714_ovl06[c & 0xF][0];
        } else {
            *(u16*)(obj + 0xA) -= D_800FF714_ovl06[c & 0xF][0];
        }
        *(u16*)(obj + 0xE) += D_800FF714_ovl06[c & 0xF][1];
        break;
    }
}
