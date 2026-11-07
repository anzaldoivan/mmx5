#include "types.h"
#include "addr.h"

extern X4_BackgroundObj D_8009A1F8[3];
extern u8 D_800BE9B0[];
void func_800278E8(u8 idx);
void func_80028278(void);
void func_80027CD8(s32 arg0);
void func_80027F88(s32 arg0);
void func_80027D84(s32 arg0);

void func_80027BFC(void) {
    u32 i;
    X4_BackgroundObj* p;

    i = 0;
    D_1F80011C = 0;
    while (1) {
        p = &D_8009A1F8[i];
        if (((u8*)p)[0x4C] != 0 || ((s8*)p)[0x52] >= 0) {
            func_800278E8(i);
        }
        i++;
        if (i >= 3) {
            break;
        }
    }
    p = D_8009A1F8;
    func_80028278();
    i = 0;
    D_1F800108 = D_800BE9B0 + (D_1F800000 << 14);
    while (1) {
        if (p->unk3 != 0) {
            func_80027CD8(i);
            func_80027F88(i);
            func_80027D84(i);
        }
        i++;
        p++;
        if (i >= 3) {
            break;
        }
    }
}
