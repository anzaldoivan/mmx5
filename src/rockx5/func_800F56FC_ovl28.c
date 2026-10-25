#include "types.h"
#include "addr.h"

extern D_8009A1F8_t D_8009A1F8;
extern signed char D_800D1CA2;
extern u8 D_800FEA5C_ovl28;
extern void func_80017248(Ent8EF0*);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_8003D2C4(void);

void func_800F56FC_ovl28(Ent8EF0* obj) {
    func_80017248(obj);
    if (--obj->unk7C == 0) {
        func_80016490(0, 0xE, 0);
        obj->unk7C = 2;
    }
    D_8009A1F8.unk26 = 0x18F0;
    *(u16*)((u8*)&D_8009A1F8 + 0x24) = 0x1920;
    if (++obj->unk5C == D_800D1CA2) {
        D_8009A1F8.unk48 = D_800FEA5C_ovl28;
        D_1F80004C.scr1090->unk87 = 1;
        func_8003D2C4();
        obj->unk5 = 7;
        obj->unk6 = 0;
        ((u8*)obj)[7] = 0;
    }
}
