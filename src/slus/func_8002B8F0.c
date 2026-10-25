#include "types.h"

extern Sel800218E0 D_8009A420;
extern Pad800218E0 D_800C931C;
extern u8 D_800E9300;
extern u16 D_80073020[];
extern u16 D_8006FAE4[];
extern u16 D_80073030[];
extern u8 D_8006FADB;
extern u8 D_8007301C[];
extern void func_80016490(s32, s32, void*);
extern void func_800132F8(s8 arg);

void func_8002B8F0(void) {
    u8 i;
    u8 j;
    u8 slot;
    u16 tmp;
    u16 btn;
    u16 val;

    if (D_8009A420.unk4 != 0) {
        return;
    }
    if ((D_800C931C.unk4 & 0x800) ||
        ((D_800C931C.unk4 & 0x40) && D_8009A420.unk7.u == 10)) {
        func_80016490(0, 0x22, 0);
        func_800132F8(8);
        D_800E9300++;
        return;
    }
    if (D_800C931C.unk4 & 0x1000) {
        func_80016490(0, 0xC, 0);
        if (D_8009A420.unk7.u == 0) {
            D_8009A420.unk7.u = 10;
        } else {
            D_8009A420.unk7.u--;
        }
    }
    if (D_800C931C.unk4 & 0x4000) {
        func_80016490(0, 0xC, 0);
        if (D_8009A420.unk7.u == 10) {
            D_8009A420.unk7.u = 0;
        } else {
            D_8009A420.unk7.u++;
        }
    }
    if (D_8009A420.unk7.u < 7) {
        slot = 0xFF;
        for (i = 4; i < 16; i++) {
            if ((1 << i) == D_80073020[D_8009A420.unk7.u]) {
                slot = i;
                break;
            }
        }
        if (slot != 0xFF) {
            btn = D_800C931C.unk4;
            for (i = 0; i < 8; i++) {
                if (btn == D_80073030[i]) {
                    func_80016490(0, 0x22, 0);
                    val = D_80073030[i];
                    tmp = D_8006FAE4[slot];
                    D_8006FAE4[slot] = val;
                    if (D_8006FAE4[0] != 0) {
                        j = 0;
                        do {
                            if (j != slot && D_8006FAE4[j] == D_80073030[i]) {
                                D_8006FAE4[j] = tmp;
                            }
                        } while (D_8006FAE4[++j] != 0);
                    }
                    return;
                }
            }
        }
    } else if (D_8009A420.unk7.u < 10) {
        if (D_800C931C.unk4 & 0x40) {
            func_80016490(0, 0x22, 0);
            D_8006FADB ^= D_8007301C[D_8009A420.unk7.u - 7];
        }
    }
}
