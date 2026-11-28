#include "types.h"

void func_8001AF60(void);
s32 CdControlB(s32, s32, u8*);
int VSync(int mode);
void func_800672B8(s32);
void* func_80066D98(void* func);
void DecDCToutCallback(void* func);
void func_80064788(void);
s32 CdReset(s32);
s32 CdControl(s32, u8*, u8*);

void func_8001B10C(void) {
    u8 param[4];

    param[0] = 0x80;
    func_8001AF60();
    while (CdControlB(9, 0, 0) == 0) {
    }
    VSync(0);
    func_800672B8(0);
    func_80066D98(0);
    DecDCToutCallback(0);
    func_80064788();
    while (CdReset(0) == 0) {
    }
    VSync(3);
    while (CdControl(0xE, param, 0) == 0) {
    }
    VSync(3);
}
