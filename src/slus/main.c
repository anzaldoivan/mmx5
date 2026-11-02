#include "types.h"
#include "addr.h"

extern void func_80012344(void);
extern int VSync(int mode);
extern void PutDispEnv(void* env);
extern void PutDrawEnv(void* env);
extern void DrawOTag(void* ot);
extern void ClearOTagR(void* ot, s32 n);
extern void func_800120F8(void);
extern void func_80017C94(void);
extern s32 func_800178C8(void);
extern void func_8001255C(void);
extern void func_8001728C(void);
extern void func_80012C34(void);
extern void func_80015B78(void);
extern s32 DrawSync(s32);
extern void func_800172CC(void);
extern void func_80017484(void);
extern void func_800289D8(void);
extern void func_80012824(void);
extern void func_80012A84(void);

extern s32 D_8009A420;
extern u8* D_8009E794;
extern u8 D_800C9328[];
extern u8 D_800D5188[];
extern u8 D_800D51C8[];

void main(void) {
    s32 idx;
    u8* e;
    u32* q;
    u32 t;

    func_80012344();
    while (1) {
        VSync(0);
        PutDispEnv(D_8009E794);
        PutDrawEnv(D_8009E794 + 0x14);
        DrawOTag(D_8009E794 + 0xAC);
        idx = D_1F800000 ^ 1;
        D_1F800000 = idx;
        D_8009E794 = D_800C9328 + idx * 0xB0;
        ClearOTagR(D_8009E794 + 0x70, 0x10);
        func_800120F8();
        e = D_8009E794;
        q = (u32*)(D_800D51C8 + D_1F800000 * 12);
        t = *(u32*)(e + 0xA4) & 0xFFFFFF;
        *q =
            (*q & 0xFF000000) |
            (t &
             0xFFFFFF); // !FAKE: second mask mirrors the addPrim bitfield insert order
        *(u32*)(e + 0xA4) = (*(u32*)(e + 0xA4) & 0xFF000000) |
                            ((u32)(D_800D51C8 + D_1F800000 * 12) & 0xFFFFFF);
        *(u32*)(D_800D5188 + D_1F800000 * 12) =
            (*(u32*)(D_800D5188 + D_1F800000 * 12) & 0xFF000000) |
            (*(u32*)(e + 0xA4) & 0xFFFFFF);
        *(u32*)(e + 0xA4) = (*(u32*)(e + 0xA4) & 0xFF000000) |
                            ((u32)(D_800D5188 + D_1F800000 * 12) & 0xFFFFFF);
        func_80017C94();
        func_800178C8();
        func_8001255C();
        func_8001728C();
        D_8009A420++;
        func_80012C34();
        func_80015B78();
        (&D_1F800000)[0x1C] = VSync(1);
        DrawSync(0);
        func_800172CC();
        func_80017484();
        func_800289D8();
        DrawSync(0);
        (&D_1F800000)[0x1F] = (&D_1F800000)[0x1D];
        func_80012824();
        func_80012A84();
    }
}
