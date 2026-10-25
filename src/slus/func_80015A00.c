#include "types.h"

s32 CdInit(void);
s32 CdControl(s32, u8*, u8*);
int VSync(int mode);
void func_80017A7C(void);

extern u8 D_800E5A3C;
extern u8 D_8009811C;
extern u8 D_80091D50;
extern u8 D_800E5209;
extern u8 D_800E5208;
extern s16 D_800E5A44;
extern s16 D_800E5A46;

void func_80015A00(void) {
    u8 param[4];

    param[0] = 0xA0;
    while (CdInit() == 0) {
    }
    while (CdControl(0xE, param, 0) == 0) {
    }
    VSync(3);
    D_800E5A3C = 0;
    D_8009811C = 0;
    D_80091D50 = 0;
    D_800E5209 = 0;
    D_800E5208 = 0;
    D_800E5A44 = 0;
    D_800E5A46 = 0;
    func_80017A7C();
}
