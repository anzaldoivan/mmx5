#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_8002002C(s32);
extern void func_80013288(s32);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A427;
extern u8 D_80070F5C[];

void func_800F0980_ovl24(Obj800F0980* arg0) {
    func_8001E668();
    D_8009A427 = 1;
    func_8002002C(0);
    arg0->unk1F = 0;
    arg0->unk24 = 0;
    func_80013288(8);
    arg0->unk8 = func_8001FF18(D_80070F5C, 1);
    arg0->unk2++;
}

extern void func_800211C4(void*, s32);
extern void func_800132F8(s8 arg);

void func_800F09E8_ovl24(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        func_800211C4(p + 7, *(s16*)(arg0 + 8));
        if (D_800C9320.h & 0x40) {
            play_sound(0, 0x22, 0);
            func_800132F8(8);
            arg0[2]++;
        }
    }
}

void func_8001E6AC(void);
void func_80012EAC(void);
void func_8002002C(s32);

void func_800F0A64_ovl24(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        if (p[7] == 0) {
            func_8001E6AC();
            func_80012EAC();
        } else {
            arg0[1] = 5;
            arg0[2] = 2;
            func_8002002C(1);
        }
    }
}
