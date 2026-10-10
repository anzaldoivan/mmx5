#include "types.h"

typedef struct {
    s8 active;
    u8 pad1[0x4F];
    s32 unk50;
    s32 unk54;
    u8 pad58[0x10];
    s32 unk68;
    u8 pad6C[0x38];
} Obj8002CD14;

extern Obj8002CD14 D_800C6A10[];
extern Obj8002CD14 D_800C926C[];
extern Obj8002CD14 D_800C9310[];

Obj8002CD14* func_8002CD14(Obj8002CD14* p, s32 backward) {
    u8* q;
    s32 i;

    if (backward == 0) {
        if (p == 0) {
            p = D_800C6A10;
        } else {
            p++;
        }
        for (; p < D_800C9310; p++) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Obj8002CD14) - 1; i != -1; i--) {
                    *q++ = 0;
                }
                p->unk50 = 0;
                p->unk54 = 0;
                p->unk68 = 0;
                return p;
            }
        }
    } else {
        if (p == 0) {
            p = D_800C926C;
        } else {
            if (p == D_800C6A10) {
                return 0;
            }
            p--;
        }
        for (; p >= D_800C6A10; p--) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Obj8002CD14) - 1; i != -1; i--) {
                    *q++ = 0;
                }
                p->unk50 = 0;
                p->unk54 = 0;
                p->unk68 = 0;
                return p;
            }
        }
    }
    return 0;
}
