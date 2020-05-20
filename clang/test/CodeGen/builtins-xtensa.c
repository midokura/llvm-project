// RUN: %clang_cc1 -Wall -Werror -triple xtensa -target-cpu esp32 -emit-llvm -o - %s | FileCheck %s

void test_xtensa_umul(unsigned a, unsigned b)
{
  // CHECK-LABEL: define void @test_xtensa_umul
  __builtin_xtensa_umul_aa_ll(a, b);
  // CHECK:   call void @llvm.xtensa.umul.aa.ll(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_umul_aa_lh(a, b);
  // CHECK:   call void @llvm.xtensa.umul.aa.lh(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_umul_aa_hl(a, b);
  // CHECK:   call void @llvm.xtensa.umul.aa.hl(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_umul_aa_hh(a, b);
  // CHECK:   call void @llvm.xtensa.umul.aa.hh(i32 %{{.*}}, i32 %{{.*}})
}

void test_xtensa_mul(unsigned a, unsigned b)
{
  // CHECK-LABEL: define void @test_xtensa_mul
  __builtin_xtensa_mul_aa_ll(a, b);
  // CHECK:   call void @llvm.xtensa.mul.aa.ll(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_mul_aa_lh(a, b);
  // CHECK:   call void @llvm.xtensa.mul.aa.lh(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_mul_aa_hl(a, b);
  // CHECK:   call void @llvm.xtensa.mul.aa.hl(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_mul_aa_hh(a, b);
  // CHECK:   call void @llvm.xtensa.mul.aa.hh(i32 %{{.*}}, i32 %{{.*}})

  __builtin_xtensa_mul_ad_ll(a, 2);
  // CHECK:   call void @llvm.xtensa.mul.ad.ll(i32 %{{.*}}, i32 2)
  __builtin_xtensa_mul_ad_lh(a, 2);
  // CHECK:   call void @llvm.xtensa.mul.ad.lh(i32 %{{.*}}, i32 2)
  __builtin_xtensa_mul_ad_hl(a, 2);
  // CHECK:   call void @llvm.xtensa.mul.ad.hl(i32 %{{.*}}, i32 2)
  __builtin_xtensa_mul_ad_hh(a, 2);
  // CHECK:   call void @llvm.xtensa.mul.ad.hh(i32 %{{.*}}, i32 2)

  __builtin_xtensa_mul_da_ll(1, b);
  // CHECK:   call void @llvm.xtensa.mul.da.ll(i32 1, i32 %{{.*}})
  __builtin_xtensa_mul_da_lh(1, b);
  // CHECK:   call void @llvm.xtensa.mul.da.lh(i32 1, i32 %{{.*}})
  __builtin_xtensa_mul_da_hl(1, b);
  // CHECK:   call void @llvm.xtensa.mul.da.hl(i32 1, i32 %{{.*}})
  __builtin_xtensa_mul_da_hh(1, b);
  // CHECK:   call void @llvm.xtensa.mul.da.hh(i32 1, i32 %{{.*}})

  __builtin_xtensa_mul_dd_ll(1, 2);
  // CHECK:   call void @llvm.xtensa.mul.dd.ll(i32 1, i32 2)
  __builtin_xtensa_mul_dd_lh(1, 2);
  // CHECK:   call void @llvm.xtensa.mul.dd.lh(i32 1, i32 2)
  __builtin_xtensa_mul_dd_hl(1, 2);
  // CHECK:   call void @llvm.xtensa.mul.dd.hl(i32 1, i32 2)
  __builtin_xtensa_mul_dd_hh(1, 2);
  // CHECK:   call void @llvm.xtensa.mul.dd.hh(i32 1, i32 2)
}

void test_xtensa_mula(unsigned a, unsigned b)
{
  // CHECK-LABEL: define void @test_xtensa_mula
  __builtin_xtensa_mula_aa_ll(a, b);
  // CHECK:   call void @llvm.xtensa.mula.aa.ll(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_mula_aa_lh(a, b);
  // CHECK:   call void @llvm.xtensa.mula.aa.lh(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_mula_aa_hl(a, b);
  // CHECK:   call void @llvm.xtensa.mula.aa.hl(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_mula_aa_hh(a, b);
  // CHECK:   call void @llvm.xtensa.mula.aa.hh(i32 %{{.*}}, i32 %{{.*}})

  __builtin_xtensa_mula_ad_ll(a, 2);
  // CHECK:   call void @llvm.xtensa.mula.ad.ll(i32 %{{.*}}, i32 2)
  __builtin_xtensa_mula_ad_lh(a, 2);
  // CHECK:   call void @llvm.xtensa.mula.ad.lh(i32 %{{.*}}, i32 2)
  __builtin_xtensa_mula_ad_hl(a, 2);
  // CHECK:   call void @llvm.xtensa.mula.ad.hl(i32 %{{.*}}, i32 2)
  __builtin_xtensa_mula_ad_hh(a, 2);
  // CHECK:   call void @llvm.xtensa.mula.ad.hh(i32 %{{.*}}, i32 2)

  __builtin_xtensa_mula_da_ll(1, b);
  // CHECK:   call void @llvm.xtensa.mula.da.ll(i32 1, i32 %{{.*}})
  __builtin_xtensa_mula_da_lh(1, b);
  // CHECK:   call void @llvm.xtensa.mula.da.lh(i32 1, i32 %{{.*}})
  __builtin_xtensa_mula_da_hl(1, b);
  // CHECK:   call void @llvm.xtensa.mula.da.hl(i32 1, i32 %{{.*}})
  __builtin_xtensa_mula_da_hh(1, b);
  // CHECK:   call void @llvm.xtensa.mula.da.hh(i32 1, i32 %{{.*}})

  __builtin_xtensa_mula_dd_ll(1, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.ll(i32 1, i32 2)
  __builtin_xtensa_mula_dd_lh(1, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.lh(i32 1, i32 2)
  __builtin_xtensa_mula_dd_hl(1, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.hl(i32 1, i32 2)
  __builtin_xtensa_mula_dd_hh(1, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.hh(i32 1, i32 2)
}

void test_xtensa_muls(unsigned a, unsigned b)
{
  // CHECK-LABEL: define void @test_xtensa_muls
  __builtin_xtensa_muls_aa_ll(a, b);
  // CHECK:   call void @llvm.xtensa.muls.aa.ll(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_muls_aa_lh(a, b);
  // CHECK:   call void @llvm.xtensa.muls.aa.lh(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_muls_aa_hl(a, b);
  // CHECK:   call void @llvm.xtensa.muls.aa.hl(i32 %{{.*}}, i32 %{{.*}})
  __builtin_xtensa_muls_aa_hh(a, b);
  // CHECK:   call void @llvm.xtensa.muls.aa.hh(i32 %{{.*}}, i32 %{{.*}})

  __builtin_xtensa_muls_ad_ll(a, 2);
  // CHECK:   call void @llvm.xtensa.muls.ad.ll(i32 %{{.*}}, i32 2)
  __builtin_xtensa_muls_ad_lh(a, 2);
  // CHECK:   call void @llvm.xtensa.muls.ad.lh(i32 %{{.*}}, i32 2)
  __builtin_xtensa_muls_ad_hl(a, 2);
  // CHECK:   call void @llvm.xtensa.muls.ad.hl(i32 %{{.*}}, i32 2)
  __builtin_xtensa_muls_ad_hh(a, 2);
  // CHECK:   call void @llvm.xtensa.muls.ad.hh(i32 %{{.*}}, i32 2)

  __builtin_xtensa_muls_da_ll(1, b);
  // CHECK:   call void @llvm.xtensa.muls.da.ll(i32 1, i32 %{{.*}})
  __builtin_xtensa_muls_da_lh(1, b);
  // CHECK:   call void @llvm.xtensa.muls.da.lh(i32 1, i32 %{{.*}})
  __builtin_xtensa_muls_da_hl(1, b);
  // CHECK:   call void @llvm.xtensa.muls.da.hl(i32 1, i32 %{{.*}})
  __builtin_xtensa_muls_da_hh(1, b);
  // CHECK:   call void @llvm.xtensa.muls.da.hh(i32 1, i32 %{{.*}})

  __builtin_xtensa_muls_dd_ll(1, 2);
  // CHECK:   call void @llvm.xtensa.muls.dd.ll(i32 1, i32 2)
  __builtin_xtensa_muls_dd_lh(1, 2);
  // CHECK:   call void @llvm.xtensa.muls.dd.lh(i32 1, i32 2)
  __builtin_xtensa_muls_dd_hl(1, 2);
  // CHECK:   call void @llvm.xtensa.muls.dd.hl(i32 1, i32 2)
  __builtin_xtensa_muls_dd_hh(1, 2);
  // CHECK:   call void @llvm.xtensa.muls.dd.hh(i32 1, i32 2)
}

void test_xtensa_mula_ld(int *pa, unsigned b)
{
  // CHECK-LABEL: define void @test_xtensa_mula_ld
  __builtin_xtensa_mula_da_ll_lddec(1, &pa, 0, b);
  // CHECK:   call void @llvm.xtensa.mula.da.ll.lddec(i32 1, i8* %{{.*}}, i32 0, i32 %{{.*}})
  __builtin_xtensa_mula_da_lh_lddec(1, &pa, 0, b);
  // CHECK:   call void @llvm.xtensa.mula.da.lh.lddec(i32 1, i8* %{{.*}}, i32 0, i32 %{{.*}})
  __builtin_xtensa_mula_da_hl_lddec(1, &pa, 0, b);
  // CHECK:   call void @llvm.xtensa.mula.da.hl.lddec(i32 1, i8* %{{.*}}, i32 0, i32 %{{.*}})
  __builtin_xtensa_mula_da_hh_lddec(1, &pa, 0, b);
  // CHECK:   call void @llvm.xtensa.mula.da.hh.lddec(i32 1, i8* %{{.*}}, i32 0, i32 %{{.*}})

  __builtin_xtensa_mula_dd_ll_lddec(1, &pa, 0, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.ll.lddec(i32 1, i8* %{{.*}}, i32 0, i32 2)
  __builtin_xtensa_mula_dd_lh_lddec(1, &pa, 0, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.lh.lddec(i32 1, i8* %{{.*}}, i32 0, i32 2)
  __builtin_xtensa_mula_dd_hl_lddec(1, &pa, 0, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.hl.lddec(i32 1, i8* %{{.*}}, i32 0, i32 2)
  __builtin_xtensa_mula_dd_hh_lddec(1, &pa, 0, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.hh.lddec(i32 1, i8* %{{.*}}, i32 0, i32 2)

  __builtin_xtensa_mula_da_ll_ldinc(1, &pa, 0, b);
  // CHECK:   call void @llvm.xtensa.mula.da.ll.ldinc(i32 1, i8* %{{.*}}, i32 0, i32 %{{.*}})
  __builtin_xtensa_mula_da_lh_ldinc(1, &pa, 0, b);
  // CHECK:   call void @llvm.xtensa.mula.da.lh.ldinc(i32 1, i8* %{{.*}}, i32 0, i32 %{{.*}})
  __builtin_xtensa_mula_da_hl_ldinc(1, &pa, 0, b);
  // CHECK:   call void @llvm.xtensa.mula.da.hl.ldinc(i32 1, i8* %{{.*}}, i32 0, i32 %{{.*}})
  __builtin_xtensa_mula_da_hh_ldinc(1, &pa, 0, b);
  // CHECK:   call void @llvm.xtensa.mula.da.hh.ldinc(i32 1, i8* %{{.*}}, i32 0, i32 %{{.*}})

  __builtin_xtensa_mula_dd_ll_ldinc(1, &pa, 0, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.ll.ldinc(i32 1, i8* %{{.*}}, i32 0, i32 2)
  __builtin_xtensa_mula_dd_lh_ldinc(1, &pa, 0, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.lh.ldinc(i32 1, i8* %{{.*}}, i32 0, i32 2)
  __builtin_xtensa_mula_dd_hl_ldinc(1, &pa, 0, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.hl.ldinc(i32 1, i8* %{{.*}}, i32 0, i32 2)
  __builtin_xtensa_mula_dd_hh_ldinc(1, &pa, 0, 2);
  // CHECK:   call void @llvm.xtensa.mula.dd.hh.ldinc(i32 1, i8* %{{.*}}, i32 0, i32 2)
}

void test_xtensa_ld(int *pa)
{
  // CHECK-LABEL: define void @test_xtensa_ld
  __builtin_xtensa_lddec(0, &pa);
  // CHECK:   call void @llvm.xtensa.lddec(i32 0, i8* %{{.*}})
  __builtin_xtensa_ldinc(0, &pa);
  // CHECK:   call void @llvm.xtensa.ldinc(i32 0, i8* %{{.*}})
}

void test_xtensa_xsr(unsigned *a)
{
  // CHECK-LABEL: define void @test_xtensa_xsr
  __builtin_xtensa_xsr_acclo(a);
  // CHECK:   call void @llvm.xtensa.xsr.acclo(i8* %{{.*}})
  __builtin_xtensa_xsr_acchi(a);
  // CHECK:   call void @llvm.xtensa.xsr.acchi(i8* %{{.*}})
  __builtin_xtensa_xsr_m0(a);
  // CHECK:   call void @llvm.xtensa.xsr.m0(i8* %{{.*}})
  __builtin_xtensa_xsr_m1(a);
  // CHECK:   call void @llvm.xtensa.xsr.m1(i8* %{{.*}})
  __builtin_xtensa_xsr_m2(a);
  // CHECK:   call void @llvm.xtensa.xsr.m2(i8* %{{.*}})
  __builtin_xtensa_xsr_m3(a);
  // CHECK:   call void @llvm.xtensa.xsr.m3(i8* %{{.*}})
}

void test_xtensa_rsr()
{
  // CHECK-LABEL: define void @test_xtensa_rsr
  unsigned a;
  a = __builtin_xtensa_rsr_acclo();
  // CHECK:   call i32 @llvm.xtensa.rsr.acclo()
  a = __builtin_xtensa_rsr_acchi();
  // CHECK:   call i32 @llvm.xtensa.rsr.acchi()
  a = __builtin_xtensa_rsr_m0();
  // CHECK:   call i32 @llvm.xtensa.rsr.m0()
  a = __builtin_xtensa_rsr_m1();
  // CHECK:   call i32 @llvm.xtensa.rsr.m1()
  a = __builtin_xtensa_rsr_m2();
  // CHECK:   call i32 @llvm.xtensa.rsr.m2()
  a = __builtin_xtensa_rsr_m3();
  // CHECK:   call i32 @llvm.xtensa.rsr.m3()
}

void test_xtensa_wsr(unsigned a)
{
  // CHECK-LABEL: define void @test_xtensa_wsr
  __builtin_xtensa_wsr_acclo(a);
  // CHECK:   call void @llvm.xtensa.wsr.acclo(i32 %{{.*}})
  __builtin_xtensa_wsr_acchi(a);
  // CHECK:   call void @llvm.xtensa.wsr.acchi(i32 %{{.*}})
  __builtin_xtensa_wsr_m0(a);
  // CHECK:   call void @llvm.xtensa.wsr.m0(i32 %{{.*}})
  __builtin_xtensa_wsr_m1(a);
  // CHECK:   call void @llvm.xtensa.wsr.m1(i32 %{{.*}})
  __builtin_xtensa_wsr_m2(a);
  // CHECK:   call void @llvm.xtensa.wsr.m2(i32 %{{.*}})
  __builtin_xtensa_wsr_m3(a);
  // CHECK:   call void @llvm.xtensa.wsr.m3(i32 %{{.*}})
}
