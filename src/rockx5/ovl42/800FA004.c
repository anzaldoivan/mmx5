#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void (*D_800FA41C_ovl42[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA004_ovl42(u8* arg0) {
    D_800FA41C_ovl42[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}

#define func_800FA078_ovl40 func_800FA078_ovl42
#include "shared/func_800FA078_ovl40.c"
#undef func_800FA078_ovl40

extern void func_80013288(s32);
extern u8 D_8009A1F8[];

void func_800FA0E4_ovl42(u8* arg0) {
    u8* p;

    D_8009A1F8[3] = 0;
    D_8009A1F8[0x57] = 0;
    p = alloc_class6_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xA;
        p[0x36] = 0x22;
        p[2] = 0;
    }
    func_80013288(8);
    arg0[1]++;
}

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800FA150_ovl42(Ovl45State* s) {
    if (D_8009A424 == 0) {
        s->unk4 = 0;
        s->unk1++;
        func_800177B0(0xF, 0x7F);
    }
}

#include "shared/func_800FA190_ovl42.c"

extern u8 D_8009A1F8[];
extern s32 D_800FA43C_ovl42;

void func_800FA1C0_ovl42(u8* arg0) {
    u8* p = D_8009A1F8;

    *(s32*)(p + 0xB4) += 0x15555;
    if (++*(s16*)(arg0 + 4) >= 0x60) {
        *(s16*)(p + 0xB6) = 0x80;
        D_800FA43C_ovl42 = 0x700000;
        *(s16*)(arg0 + 4) = 0x3C;
        p[0x3] = 0;
        *(s16*)(p + 0x62) = 0;
        *(s16*)(p + 0x5E) = 0x200;
        *(s32*)(p + 0x5C) += 0x700000;
        p[0xA0] = 1;
        p[0x57] = 1;
        func_8002385C(0xC, 0xFF, 0);
        arg0[1]++;
    }
}
