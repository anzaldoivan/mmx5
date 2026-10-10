#include "types.h"

typedef struct {
    s8 active;
    u8 pad1[0x4F];
    s32 unk50;
    s32 unk54;
    u8 pad58[0x10];
    s32 unk68;
    u8 pad6C[0x30];
} Obj8002CC08;

extern Obj8002CC08 D_80098120[];
extern Obj8002CC08 D_80099404[];
extern Obj8002CC08 D_800994A0[];

Obj8002CC08* func_8002CC08(Obj8002CC08* p, s32 backward) {
    u8* q;
    s32 i;

    if (backward == 0) {
        if (p == 0) {
            p = D_80098120;
        } else {
            p++;
        }
        for (; p < D_800994A0; p++) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Obj8002CC08) - 1; i != -1; i--) {
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
            p = D_80099404;
        } else {
            if (p == D_80098120) {
                return 0;
            }
            p--;
        }
        for (; p >= D_80098120; p--) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Obj8002CC08) - 1; i != -1; i--) {
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
