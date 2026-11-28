#include "types.h"

extern void CdControlF(s32, s32);
extern int CdPosToInt(void* p);
extern void func_80017D88(void);
extern s32 func_80066CD8(void);
extern s32 func_80066D58(s32, u8*);
extern s32 D_800E8060;
extern s32 D_800E806C;
extern s32 D_800E8074;
extern u8 D_800E8088[];
extern s16 D_800E8090;
extern u8 D_800E8098;
extern s32 D_800E80A4;

void func_80017C94(void) {
    s32 state;
    s32 cmd;
    u32 pos;
    u8* buf;

    if (D_800E80A4 == 2) {
        state = D_800E8060;
        if (state == D_800E80A4) {
            D_800E8090 = 1;
            cmd = func_80066CD8();
            if (cmd == 0x1B || cmd == 0x11) {
                buf = D_800E8088;
                if (func_80066D58(1, buf) == state) {
                    if (cmd == 0x11) {
                        pos = CdPosToInt(buf + 5);
                        D_800E806C = pos;
                        if ((u32)(D_800E8074 - 8) < pos) {
                            if (D_800E8098 != 0) {
                                D_800E8060 = 5;
                            } else {
                                func_80017D88();
                            }
                        }
                    }
                    CdControlF(0x11, 0);
                }
            }
        }
    }
}
