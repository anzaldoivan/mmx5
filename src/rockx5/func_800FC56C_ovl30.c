/* rockx5 func_800FC56C_ovl30: twin of func_800FA934_ovl01 (dup1007). */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80016490(s32, s32, void*);
extern u8 D_800FD7B8_ovl30[];
extern u8 D_800FD7BC_ovl30[];

void func_800FC56C_ovl30(u8* o) {
    s8 state;

    if (*(s16*)(o + 0x7C) < 30) {
        *(s16*)(o + 0x7C) += 1;
        return;
    }
    o[0x94] = 0;
    func_80017248(o);
    state = o[0x45] - 1;
    switch (state) {
    case 0:
        o[6] = 5;
        *(s16*)(o + 0x7E) = 0x6C;
        break;
    case 1:
    case 2:
    case 3:
        *(u8**)(o + 0x50) = D_800FD7B8_ovl30;
        break;
    case 4:
    case 5:
    case 6:
        *(u8**)(o + 0x50) = 0;
        *(u8**)(o + 0x54) = D_800FD7BC_ovl30;
        break;
    case 15:
        func_80016490(2, 9, o);
        *(u8**)(o + 0x50) = D_800FD7B8_ovl30;
        break;
    }
}
