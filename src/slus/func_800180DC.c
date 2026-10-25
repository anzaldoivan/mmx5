#include "types.h"

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);                  /* extern */
s32 CdControlB(M2C_UNK, M2C_UNK, u8*);           /* extern */
void SsSetSerialAttr(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void func_80017E98(u8 vol);
extern u8 D_800E805C;
extern s32 D_800E8060;
extern s32 D_800E8094;

void func_800180DC(void) {
    s32 temp_v0;

    temp_v0 = func_80066D58(1, 0);
    if (temp_v0 == 2) {
        if (D_800E8094 == temp_v0) {
            if (CdControlB(9, 0, 0) == 0) {
                return;
            }
            SsSetSerialAttr(0, 0, 0);
            D_800E805C = 0;
            func_80017E98(0);
            D_800E8094 = 0;
            D_800E8060 = 0;
        } else {
            SsSetSerialAttr(0, 0, 0);
            D_800E805C = 0;
            func_80017E98(0);
            D_800E8060 = 0;
        }
    }
}
