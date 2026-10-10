#include "types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x5C - 7];
    signed char unk5C;
    u8 pad5D[0x7C - 0x5D];
    s16 unk7C;
} Ent57B4;

extern D_8009A1F8_t D_8009A1F8;
extern signed char D_800D1CA2;
extern u8 D_800FB65C_ovl09;
extern u16 D_800FB660_ovl09;
extern s32 func_80044DE0();
extern void func_8002D9EC(Ent57B4* obj, s32 a, s32 b);
extern s32 func_80016490(s32, s32, s32);
extern void func_8003D2C4(void);
extern void func_80017248(Ent57B4*);
extern void func_8002DED4(Ent57B4*);

void func_800F57B4_ovl09(Ent57B4* obj) {
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x40, 0x40);
        return;
    }
    D_8009A1F8.unk26 = D_800FB660_ovl09;
    if (obj->unk5C < D_800D1CA2) {
        if (--obj->unk7C == 0) {
            func_80016490(0, 0xE, 0);
            obj->unk7C = 3;
        }
        obj->unk5C++;
        func_8002D9EC(obj, 0x40, 0x40);
        return;
    }
    D_8009A1F8.unk48 = D_800FB65C_ovl09;
    func_8003D2C4();
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
    obj->unk5 = 4;
    obj->unk6 = 0;
}
