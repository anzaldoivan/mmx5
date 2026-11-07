#include "types.h"

extern s32 SsVabClose(s32);
extern void SsSepClose(s32);
extern void func_8005E408(void);
extern void SsUtSetReverbType(s32 type);
extern void SsUtSetReverbDepth(s32 l, s32 r);
extern void SsEnd(void);
extern void func_8005A908(void);
extern s8 D_80093E60[];
extern s8 D_80093E6C[];

void func_80016294(void) {
    s8 i;

    for (i = 0; i < 6; i++) {
        if (D_80093E60[i] != -1) {
            SsVabClose(D_80093E60[i]);
            D_80093E60[i] = -1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_80093E6C[i] != -1) {
            SsSepClose(D_80093E6C[i]);
            D_80093E6C[i] = -1;
        }
    }
    func_8005E408();
    SsUtSetReverbType(0);
    SsUtSetReverbDepth(0, 0);
    SsEnd();
    func_8005A908();
}
