#include "types.h"
#include "addr.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern void func_8002C338(s32, void*, s32);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 D_8009A420;
extern u8 D_800FE310_ovl28[];

void func_800F42F8_ovl28(u8* obj) {
    u8* p;

    if (func_8002D938(obj, 0x20, 0x14) == 0) {
        func_80017248(obj);
        func_800317B8(obj);
        if (D_8009A420 & 1) {
            func_8002C338(
                0x13E,
                (void*)((s32)D_1F800024 + (D_800FE310_ovl28[obj[0x8F]] << 5)),
                1);
            func_8002C338(
                0x13F,
                (void*)((s32)D_1F800024 + (D_800FE310_ovl28[obj[0x8F]] << 5)),
                1);
            if (++obj[0x8F] == 6) {
                obj[0x8F] = 0;
            }
        }
        func_8002DF54(obj);
        func_8002D9EC(obj, 0x20, 0x14);
        return;
    }
    if ((obj[2] >> 4) == 1) {
        p = *(u8**)(obj + 0x7C);
        p[0x8C]++;
    }
    obj[4]++;
}
