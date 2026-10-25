/* Shared body (DK-5), from the banked draft of func_800F5CA0_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(ObjF5CA0*, s32);
extern u8 D_800FD460_ovl27[];
extern u8 D_800FD464_ovl27[];
extern u8 D_800FD468_ovl27[];
extern u8 D_800FD46C_ovl27[];

void DEDUP_NAME(ObjF5CA0* arg0) {
    arg0->unk60 = 8;
    arg0->unk5C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk16 = 4;
    arg0->unk67 = 1;
    arg0->unk54 = 0;
    switch (arg0->unk2) {
    case 0:
        DEDUP_CALLEE(arg0, 5);
        if (arg0->unk15 == 0) {
            arg0->unk20 = -0x40000;
        } else {
            arg0->unk20 = 0x40000;
        }
        arg0->unk24 = 0;
        arg0->unk50 = D_800FD460_ovl27;
        arg0->unk68 = D_800FD464_ovl27;
        break;
    case 1:
        DEDUP_CALLEE(arg0, 6);
        if (arg0->unk15 == 0) {
            arg0->unk20 = -0x40000;
        } else {
            arg0->unk20 = 0x40000;
        }
        arg0->unk24 = -0x40000;
        arg0->unk50 = D_800FD468_ovl27;
        arg0->unk68 = D_800FD46C_ovl27;
        break;
    }
    arg0->unk4 = 1;
    arg0->unk6 = 0;
    arg0->unk7 = 0;
    arg0->unk3 = 0;
}
