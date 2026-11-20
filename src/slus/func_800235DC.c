#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void func_80017348(u8* a0, s32 a1, s32 a2);
extern void func_80021F64(void);
extern void func_80022084(void);
extern void func_800221B0(void);
extern void func_800222D0(void);
extern void func_800223E4(void);
extern void func_800224F8(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void update_layer_objects(void);
extern void func_80022960(void);
extern void func_80022EDC(void);
extern void func_80022F3C(void);
extern void func_80022F90(void);
extern void func_8002A440(void);
extern void func_8002A4E4(void);
extern void func_8002A554(void);
extern void func_8002AE50(void);
extern void func_8002BD8C(void);
extern void func_8002C2C0(void);
extern void func_8002F338(u16 v, u8* p, s32 n);
extern void func_80035040(void);

void func_800235DC(void) {
    u8* p = g_Player;
    u16 v = 0xE10;
    s32 n;

    {
        // !FAKE: pin keeps the old value out of v0, as the target allocates it
        register u16 old asm("$3") = *(u16*)(p + 0x7C);
        *(u16*)(p + 0x7E) = old;
    }
    n = D_801F6000;
    if (n != 0xE10) {
        // !FAKE: pin keeps the table base in v1, as the target allocates it
        register u16* tbl asm("$3") = D_801F6384;
        v = tbl[n];
        *(u16*)(p + 0x7C) = v;
        D_801F6000++;
    } else {
        *(u16*)(p + 0x7C) = 0;
    }
    do {
        *(u16*)(p + 0x80) =
            *(u16*)(p + 0x7C) & (*(u16*)(p + 0x7C) ^ *(u16*)(p + 0x7E));
    } while (0); // !FAKE: fence keeps the a1 copy after the store
    func_8002F338(v, p, n);
    func_80022960();
    func_80035040();
    func_80022084();
    update_layer_objects();
    func_80021F64();
    func_800221B0();
    func_800222D0();
    func_800224F8();
    func_80022618();
    func_8002272C();
    func_8002AE50();
    func_800223E4();
    func_8002FB58(g_Player);
    func_8002A440();
    func_8002A4E4();
    func_8002A554();
    func_8002C2C0();
    func_8002BD8C();
    func_80022EDC();
    func_80022F3C();
    func_80022F90();
    func_80017348(g_Player, 0x140, 0);
}
