/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN xorsign

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/xorsign.h>

static int
test_simde_x_mm512_xorsign_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   171.14), SIMDE_FLOAT32_C(  -720.88), SIMDE_FLOAT32_C(    91.20), SIMDE_FLOAT32_C(  -603.00),
        SIMDE_FLOAT32_C(   989.54), SIMDE_FLOAT32_C(  -571.77), SIMDE_FLOAT32_C(    86.22), SIMDE_FLOAT32_C(  -501.69),
        SIMDE_FLOAT32_C(   265.51), SIMDE_FLOAT32_C(   768.92), SIMDE_FLOAT32_C(  -453.43), SIMDE_FLOAT32_C(  -713.07),
        SIMDE_FLOAT32_C(   899.54), SIMDE_FLOAT32_C(   -39.26), SIMDE_FLOAT32_C(  -227.05), SIMDE_FLOAT32_C(   101.70) },
      { SIMDE_FLOAT32_C(   235.94), SIMDE_FLOAT32_C(   354.55), SIMDE_FLOAT32_C(   653.88), SIMDE_FLOAT32_C(   954.61),
        SIMDE_FLOAT32_C(   287.59), SIMDE_FLOAT32_C(  -584.93), SIMDE_FLOAT32_C(   648.35), SIMDE_FLOAT32_C(  -109.54),
        SIMDE_FLOAT32_C(   674.70), SIMDE_FLOAT32_C(   116.20), SIMDE_FLOAT32_C(   333.77), SIMDE_FLOAT32_C(  -680.08),
        SIMDE_FLOAT32_C(   -22.25), SIMDE_FLOAT32_C(  -768.22), SIMDE_FLOAT32_C(   768.15), SIMDE_FLOAT32_C(  -851.11) },
      { SIMDE_FLOAT32_C(   171.14), SIMDE_FLOAT32_C(  -720.88), SIMDE_FLOAT32_C(    91.20), SIMDE_FLOAT32_C(  -603.00),
        SIMDE_FLOAT32_C(   989.54), SIMDE_FLOAT32_C(   571.77), SIMDE_FLOAT32_C(    86.22), SIMDE_FLOAT32_C(   501.69),
        SIMDE_FLOAT32_C(   265.51), SIMDE_FLOAT32_C(   768.92), SIMDE_FLOAT32_C(  -453.43), SIMDE_FLOAT32_C(   713.07),
        SIMDE_FLOAT32_C(  -899.54), SIMDE_FLOAT32_C(    39.26), SIMDE_FLOAT32_C(  -227.05), SIMDE_FLOAT32_C(  -101.70) } },
    { { SIMDE_FLOAT32_C(  -489.10), SIMDE_FLOAT32_C(  -140.65), SIMDE_FLOAT32_C(  -454.11), SIMDE_FLOAT32_C(  -499.56),
        SIMDE_FLOAT32_C(   287.59), SIMDE_FLOAT32_C(   632.11), SIMDE_FLOAT32_C(    -1.25), SIMDE_FLOAT32_C(  -446.90),
        SIMDE_FLOAT32_C(   401.02), SIMDE_FLOAT32_C(   545.32), SIMDE_FLOAT32_C(  -159.97), SIMDE_FLOAT32_C(   300.56),
        SIMDE_FLOAT32_C(  -493.93), SIMDE_FLOAT32_C(   612.97), SIMDE_FLOAT32_C(  -597.74), SIMDE_FLOAT32_C(   742.01) },
      { SIMDE_FLOAT32_C(   -32.48), SIMDE_FLOAT32_C(  -943.85), SIMDE_FLOAT32_C(   696.62), SIMDE_FLOAT32_C(  -744.89),
        SIMDE_FLOAT32_C(  -528.78), SIMDE_FLOAT32_C(   344.97), SIMDE_FLOAT32_C(   145.58), SIMDE_FLOAT32_C(  -854.08),
        SIMDE_FLOAT32_C(  -538.83), SIMDE_FLOAT32_C(  -520.66), SIMDE_FLOAT32_C(  -534.16), SIMDE_FLOAT32_C(   438.92),
        SIMDE_FLOAT32_C(  -288.87), SIMDE_FLOAT32_C(  -766.01), SIMDE_FLOAT32_C(   587.81), SIMDE_FLOAT32_C(   222.03) },
      { SIMDE_FLOAT32_C(   489.10), SIMDE_FLOAT32_C(   140.65), SIMDE_FLOAT32_C(  -454.11), SIMDE_FLOAT32_C(   499.56),
        SIMDE_FLOAT32_C(  -287.59), SIMDE_FLOAT32_C(   632.11), SIMDE_FLOAT32_C(    -1.25), SIMDE_FLOAT32_C(   446.90),
        SIMDE_FLOAT32_C(  -401.02), SIMDE_FLOAT32_C(  -545.32), SIMDE_FLOAT32_C(   159.97), SIMDE_FLOAT32_C(   300.56),
        SIMDE_FLOAT32_C(   493.93), SIMDE_FLOAT32_C(  -612.97), SIMDE_FLOAT32_C(  -597.74), SIMDE_FLOAT32_C(   742.01) } },
    { { SIMDE_FLOAT32_C(    93.34), SIMDE_FLOAT32_C(  -866.30), SIMDE_FLOAT32_C(   722.47), SIMDE_FLOAT32_C(  -619.07),
        SIMDE_FLOAT32_C(   765.80), SIMDE_FLOAT32_C(  -278.78), SIMDE_FLOAT32_C(   -65.97), SIMDE_FLOAT32_C(   166.82),
        SIMDE_FLOAT32_C(  -733.46), SIMDE_FLOAT32_C(   774.05), SIMDE_FLOAT32_C(  -532.61), SIMDE_FLOAT32_C(  -227.39),
        SIMDE_FLOAT32_C(   387.03), SIMDE_FLOAT32_C(  -130.35), SIMDE_FLOAT32_C(  -485.39), SIMDE_FLOAT32_C(  -645.45) },
      { SIMDE_FLOAT32_C(   -74.20), SIMDE_FLOAT32_C(  -788.76), SIMDE_FLOAT32_C(  -390.34), SIMDE_FLOAT32_C(   397.02),
        SIMDE_FLOAT32_C(   556.21), SIMDE_FLOAT32_C(   755.24), SIMDE_FLOAT32_C(   542.94), SIMDE_FLOAT32_C(  -982.62),
        SIMDE_FLOAT32_C(  -765.42), SIMDE_FLOAT32_C(  -991.23), SIMDE_FLOAT32_C(   456.30), SIMDE_FLOAT32_C(   -54.29),
        SIMDE_FLOAT32_C(  -757.24), SIMDE_FLOAT32_C(    44.10), SIMDE_FLOAT32_C(  -832.27), SIMDE_FLOAT32_C(   336.11) },
      { SIMDE_FLOAT32_C(   -93.34), SIMDE_FLOAT32_C(   866.30), SIMDE_FLOAT32_C(  -722.47), SIMDE_FLOAT32_C(  -619.07),
        SIMDE_FLOAT32_C(   765.80), SIMDE_FLOAT32_C(  -278.78), SIMDE_FLOAT32_C(   -65.97), SIMDE_FLOAT32_C(  -166.82),
        SIMDE_FLOAT32_C(   733.46), SIMDE_FLOAT32_C(  -774.05), SIMDE_FLOAT32_C(  -532.61), SIMDE_FLOAT32_C(   227.39),
        SIMDE_FLOAT32_C(  -387.03), SIMDE_FLOAT32_C(  -130.35), SIMDE_FLOAT32_C(   485.39), SIMDE_FLOAT32_C(  -645.45) } },
    { { SIMDE_FLOAT32_C(   177.80), SIMDE_FLOAT32_C(   890.20), SIMDE_FLOAT32_C(   717.03), SIMDE_FLOAT32_C(   -56.40),
        SIMDE_FLOAT32_C(  -388.58), SIMDE_FLOAT32_C(  -348.94), SIMDE_FLOAT32_C(  -889.57), SIMDE_FLOAT32_C(  -122.04),
        SIMDE_FLOAT32_C(  -574.89), SIMDE_FLOAT32_C(  -422.18), SIMDE_FLOAT32_C(   650.57), SIMDE_FLOAT32_C(   812.14),
        SIMDE_FLOAT32_C(   447.47), SIMDE_FLOAT32_C(  -834.82), SIMDE_FLOAT32_C(  -833.31), SIMDE_FLOAT32_C(  -626.73) },
      { SIMDE_FLOAT32_C(  -623.58), SIMDE_FLOAT32_C(  -223.65), SIMDE_FLOAT32_C(   770.29), SIMDE_FLOAT32_C(   932.63),
        SIMDE_FLOAT32_C(  -468.42), SIMDE_FLOAT32_C(   313.23), SIMDE_FLOAT32_C(   950.00), SIMDE_FLOAT32_C(  -233.83),
        SIMDE_FLOAT32_C(   322.00), SIMDE_FLOAT32_C(   406.30), SIMDE_FLOAT32_C(   711.87), SIMDE_FLOAT32_C(   564.77),
        SIMDE_FLOAT32_C(  -549.60), SIMDE_FLOAT32_C(   879.61), SIMDE_FLOAT32_C(   -99.13), SIMDE_FLOAT32_C(   628.20) },
      { SIMDE_FLOAT32_C(  -177.80), SIMDE_FLOAT32_C(  -890.20), SIMDE_FLOAT32_C(   717.03), SIMDE_FLOAT32_C(   -56.40),
        SIMDE_FLOAT32_C(   388.58), SIMDE_FLOAT32_C(  -348.94), SIMDE_FLOAT32_C(  -889.57), SIMDE_FLOAT32_C(   122.04),
        SIMDE_FLOAT32_C(  -574.89), SIMDE_FLOAT32_C(  -422.18), SIMDE_FLOAT32_C(   650.57), SIMDE_FLOAT32_C(   812.14),
        SIMDE_FLOAT32_C(  -447.47), SIMDE_FLOAT32_C(  -834.82), SIMDE_FLOAT32_C(   833.31), SIMDE_FLOAT32_C(  -626.73) } },
    { { SIMDE_FLOAT32_C(   769.80), SIMDE_FLOAT32_C(  -382.09), SIMDE_FLOAT32_C(  -428.19), SIMDE_FLOAT32_C(  -618.78),
        SIMDE_FLOAT32_C(   268.96), SIMDE_FLOAT32_C(  -317.77), SIMDE_FLOAT32_C(   259.19), SIMDE_FLOAT32_C(   694.07),
        SIMDE_FLOAT32_C(   260.05), SIMDE_FLOAT32_C(   -90.25), SIMDE_FLOAT32_C(   506.21), SIMDE_FLOAT32_C(  -292.48),
        SIMDE_FLOAT32_C(    74.94), SIMDE_FLOAT32_C(   672.90), SIMDE_FLOAT32_C(    80.79), SIMDE_FLOAT32_C(   451.36) },
      { SIMDE_FLOAT32_C(  -550.76), SIMDE_FLOAT32_C(  -148.92), SIMDE_FLOAT32_C(   383.98), SIMDE_FLOAT32_C(   -19.17),
        SIMDE_FLOAT32_C(  -835.69), SIMDE_FLOAT32_C(   333.99), SIMDE_FLOAT32_C(   746.99), SIMDE_FLOAT32_C(   486.31),
        SIMDE_FLOAT32_C(  -259.72), SIMDE_FLOAT32_C(   458.87), SIMDE_FLOAT32_C(    51.08), SIMDE_FLOAT32_C(   190.69),
        SIMDE_FLOAT32_C(   338.47), SIMDE_FLOAT32_C(   951.96), SIMDE_FLOAT32_C(  -181.11), SIMDE_FLOAT32_C(   108.28) },
      { SIMDE_FLOAT32_C(  -769.80), SIMDE_FLOAT32_C(   382.09), SIMDE_FLOAT32_C(  -428.19), SIMDE_FLOAT32_C(   618.78),
        SIMDE_FLOAT32_C(  -268.96), SIMDE_FLOAT32_C(  -317.77), SIMDE_FLOAT32_C(   259.19), SIMDE_FLOAT32_C(   694.07),
        SIMDE_FLOAT32_C(  -260.05), SIMDE_FLOAT32_C(   -90.25), SIMDE_FLOAT32_C(   506.21), SIMDE_FLOAT32_C(  -292.48),
        SIMDE_FLOAT32_C(    74.94), SIMDE_FLOAT32_C(   672.90), SIMDE_FLOAT32_C(   -80.79), SIMDE_FLOAT32_C(   451.36) } },
    { { SIMDE_FLOAT32_C(  -430.14), SIMDE_FLOAT32_C(   390.70), SIMDE_FLOAT32_C(   489.50), SIMDE_FLOAT32_C(   838.83),
        SIMDE_FLOAT32_C(  -927.07), SIMDE_FLOAT32_C(  -251.31), SIMDE_FLOAT32_C(   532.90), SIMDE_FLOAT32_C(   332.98),
        SIMDE_FLOAT32_C(   658.44), SIMDE_FLOAT32_C(    39.11), SIMDE_FLOAT32_C(  -959.50), SIMDE_FLOAT32_C(  -266.62),
        SIMDE_FLOAT32_C(  -287.99), SIMDE_FLOAT32_C(   121.29), SIMDE_FLOAT32_C(  -815.27), SIMDE_FLOAT32_C(   161.25) },
      { SIMDE_FLOAT32_C(   972.37), SIMDE_FLOAT32_C(   568.72), SIMDE_FLOAT32_C(  -857.92), SIMDE_FLOAT32_C(  -863.32),
        SIMDE_FLOAT32_C(   -97.30), SIMDE_FLOAT32_C(   889.08), SIMDE_FLOAT32_C(   623.00), SIMDE_FLOAT32_C(   642.99),
        SIMDE_FLOAT32_C(   347.94), SIMDE_FLOAT32_C(  -325.92), SIMDE_FLOAT32_C(  -166.32), SIMDE_FLOAT32_C(  -313.58),
        SIMDE_FLOAT32_C(  -373.97), SIMDE_FLOAT32_C(   652.57), SIMDE_FLOAT32_C(   794.69), SIMDE_FLOAT32_C(   195.90) },
      { SIMDE_FLOAT32_C(  -430.14), SIMDE_FLOAT32_C(   390.70), SIMDE_FLOAT32_C(  -489.50), SIMDE_FLOAT32_C(  -838.83),
        SIMDE_FLOAT32_C(   927.07), SIMDE_FLOAT32_C(  -251.31), SIMDE_FLOAT32_C(   532.90), SIMDE_FLOAT32_C(   332.98),
        SIMDE_FLOAT32_C(   658.44), SIMDE_FLOAT32_C(   -39.11), SIMDE_FLOAT32_C(   959.50), SIMDE_FLOAT32_C(   266.62),
        SIMDE_FLOAT32_C(   287.99), SIMDE_FLOAT32_C(   121.29), SIMDE_FLOAT32_C(  -815.27), SIMDE_FLOAT32_C(   161.25) } },
    { { SIMDE_FLOAT32_C(    43.27), SIMDE_FLOAT32_C(   284.19), SIMDE_FLOAT32_C(    34.72), SIMDE_FLOAT32_C(   116.20),
        SIMDE_FLOAT32_C(  -967.12), SIMDE_FLOAT32_C(  -432.37), SIMDE_FLOAT32_C(  -550.81), SIMDE_FLOAT32_C(   691.32),
        SIMDE_FLOAT32_C(   606.74), SIMDE_FLOAT32_C(  -510.31), SIMDE_FLOAT32_C(  -575.30), SIMDE_FLOAT32_C(  -681.25),
        SIMDE_FLOAT32_C(   610.98), SIMDE_FLOAT32_C(  -390.57), SIMDE_FLOAT32_C(   480.00), SIMDE_FLOAT32_C(   583.36) },
      { SIMDE_FLOAT32_C(  -821.85), SIMDE_FLOAT32_C(   622.08), SIMDE_FLOAT32_C(   720.04), SIMDE_FLOAT32_C(    80.86),
        SIMDE_FLOAT32_C(   511.16), SIMDE_FLOAT32_C(   343.03), SIMDE_FLOAT32_C(  -276.16), SIMDE_FLOAT32_C(  -140.90),
        SIMDE_FLOAT32_C(  -982.89), SIMDE_FLOAT32_C(   557.52), SIMDE_FLOAT32_C(   545.52), SIMDE_FLOAT32_C(  -356.85),
        SIMDE_FLOAT32_C(   210.09), SIMDE_FLOAT32_C(   340.21), SIMDE_FLOAT32_C(   839.04), SIMDE_FLOAT32_C(  -746.64) },
      { SIMDE_FLOAT32_C(   -43.27), SIMDE_FLOAT32_C(   284.19), SIMDE_FLOAT32_C(    34.72), SIMDE_FLOAT32_C(   116.20),
        SIMDE_FLOAT32_C(  -967.12), SIMDE_FLOAT32_C(  -432.37), SIMDE_FLOAT32_C(   550.81), SIMDE_FLOAT32_C(  -691.32),
        SIMDE_FLOAT32_C(  -606.74), SIMDE_FLOAT32_C(  -510.31), SIMDE_FLOAT32_C(  -575.30), SIMDE_FLOAT32_C(   681.25),
        SIMDE_FLOAT32_C(   610.98), SIMDE_FLOAT32_C(  -390.57), SIMDE_FLOAT32_C(   480.00), SIMDE_FLOAT32_C(  -583.36) } },
    { { SIMDE_FLOAT32_C(  -375.59), SIMDE_FLOAT32_C(  -126.23), SIMDE_FLOAT32_C(   369.56), SIMDE_FLOAT32_C(  -342.71),
        SIMDE_FLOAT32_C(   441.39), SIMDE_FLOAT32_C(   818.74), SIMDE_FLOAT32_C(  -651.39), SIMDE_FLOAT32_C(    48.13),
        SIMDE_FLOAT32_C(  -691.57), SIMDE_FLOAT32_C(  -226.69), SIMDE_FLOAT32_C(   366.88), SIMDE_FLOAT32_C(   919.42),
        SIMDE_FLOAT32_C(   382.74), SIMDE_FLOAT32_C(  -153.11), SIMDE_FLOAT32_C(   502.77), SIMDE_FLOAT32_C(   560.89) },
      { SIMDE_FLOAT32_C(  -531.03), SIMDE_FLOAT32_C(   222.81), SIMDE_FLOAT32_C(  -358.25), SIMDE_FLOAT32_C(   980.13),
        SIMDE_FLOAT32_C(  -434.15), SIMDE_FLOAT32_C(   365.59), SIMDE_FLOAT32_C(  -160.76), SIMDE_FLOAT32_C(  -417.04),
        SIMDE_FLOAT32_C(   -76.89), SIMDE_FLOAT32_C(  -615.25), SIMDE_FLOAT32_C(   226.10), SIMDE_FLOAT32_C(  -866.80),
        SIMDE_FLOAT32_C(   724.97), SIMDE_FLOAT32_C(    65.15), SIMDE_FLOAT32_C(  -613.44), SIMDE_FLOAT32_C(  -650.63) },
      { SIMDE_FLOAT32_C(   375.59), SIMDE_FLOAT32_C(  -126.23), SIMDE_FLOAT32_C(  -369.56), SIMDE_FLOAT32_C(  -342.71),
        SIMDE_FLOAT32_C(  -441.39), SIMDE_FLOAT32_C(   818.74), SIMDE_FLOAT32_C(   651.39), SIMDE_FLOAT32_C(   -48.13),
        SIMDE_FLOAT32_C(   691.57), SIMDE_FLOAT32_C(   226.69), SIMDE_FLOAT32_C(   366.88), SIMDE_FLOAT32_C(  -919.42),
        SIMDE_FLOAT32_C(   382.74), SIMDE_FLOAT32_C(  -153.11), SIMDE_FLOAT32_C(  -502.77), SIMDE_FLOAT32_C(  -560.89) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_x_mm512_xorsign_ps(a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_x_mm512_xorsign_ps(a, b);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_xorsign_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   938.91), SIMDE_FLOAT64_C(   756.12), SIMDE_FLOAT64_C(     6.66), SIMDE_FLOAT64_C(   380.31),
        SIMDE_FLOAT64_C(   574.86), SIMDE_FLOAT64_C(   355.27), SIMDE_FLOAT64_C(  -571.56), SIMDE_FLOAT64_C(   883.30) },
      { SIMDE_FLOAT64_C(  -871.43), SIMDE_FLOAT64_C(   795.32), SIMDE_FLOAT64_C(   802.72), SIMDE_FLOAT64_C(   511.32),
        SIMDE_FLOAT64_C(  -357.79), SIMDE_FLOAT64_C(   305.49), SIMDE_FLOAT64_C(    72.21), SIMDE_FLOAT64_C(   111.18) },
      { SIMDE_FLOAT64_C(  -938.91), SIMDE_FLOAT64_C(   756.12), SIMDE_FLOAT64_C(     6.66), SIMDE_FLOAT64_C(   380.31),
        SIMDE_FLOAT64_C(  -574.86), SIMDE_FLOAT64_C(   355.27), SIMDE_FLOAT64_C(  -571.56), SIMDE_FLOAT64_C(   883.30) } },
    { { SIMDE_FLOAT64_C(  -471.70), SIMDE_FLOAT64_C(   713.96), SIMDE_FLOAT64_C(    91.31), SIMDE_FLOAT64_C(    94.15),
        SIMDE_FLOAT64_C(    79.55), SIMDE_FLOAT64_C(   930.55), SIMDE_FLOAT64_C(   677.11), SIMDE_FLOAT64_C(  -997.33) },
      { SIMDE_FLOAT64_C(  -684.70), SIMDE_FLOAT64_C(   -96.79), SIMDE_FLOAT64_C(  -864.13), SIMDE_FLOAT64_C(  -959.73),
        SIMDE_FLOAT64_C(   968.36), SIMDE_FLOAT64_C(  -477.57), SIMDE_FLOAT64_C(  -610.36), SIMDE_FLOAT64_C(   907.27) },
      { SIMDE_FLOAT64_C(   471.70), SIMDE_FLOAT64_C(  -713.96), SIMDE_FLOAT64_C(   -91.31), SIMDE_FLOAT64_C(   -94.15),
        SIMDE_FLOAT64_C(    79.55), SIMDE_FLOAT64_C(  -930.55), SIMDE_FLOAT64_C(  -677.11), SIMDE_FLOAT64_C(  -997.33) } },
    { { SIMDE_FLOAT64_C(  -721.46), SIMDE_FLOAT64_C(   396.30), SIMDE_FLOAT64_C(   287.57), SIMDE_FLOAT64_C(   853.41),
        SIMDE_FLOAT64_C(  -248.43), SIMDE_FLOAT64_C(   716.01), SIMDE_FLOAT64_C(   736.70), SIMDE_FLOAT64_C(  -119.85) },
      { SIMDE_FLOAT64_C(   511.33), SIMDE_FLOAT64_C(   539.42), SIMDE_FLOAT64_C(  -608.54), SIMDE_FLOAT64_C(  -846.46),
        SIMDE_FLOAT64_C(  -155.09), SIMDE_FLOAT64_C(   463.67), SIMDE_FLOAT64_C(   264.73), SIMDE_FLOAT64_C(   373.21) },
      { SIMDE_FLOAT64_C(  -721.46), SIMDE_FLOAT64_C(   396.30), SIMDE_FLOAT64_C(  -287.57), SIMDE_FLOAT64_C(  -853.41),
        SIMDE_FLOAT64_C(   248.43), SIMDE_FLOAT64_C(   716.01), SIMDE_FLOAT64_C(   736.70), SIMDE_FLOAT64_C(  -119.85) } },
    { { SIMDE_FLOAT64_C(   177.63), SIMDE_FLOAT64_C(  -643.96), SIMDE_FLOAT64_C(  -532.64), SIMDE_FLOAT64_C(  -742.82),
        SIMDE_FLOAT64_C(  -713.41), SIMDE_FLOAT64_C(  -855.54), SIMDE_FLOAT64_C(  -740.15), SIMDE_FLOAT64_C(  -398.11) },
      { SIMDE_FLOAT64_C(    47.67), SIMDE_FLOAT64_C(  -604.28), SIMDE_FLOAT64_C(  -357.84), SIMDE_FLOAT64_C(    16.03),
        SIMDE_FLOAT64_C(   -81.86), SIMDE_FLOAT64_C(    31.80), SIMDE_FLOAT64_C(   -76.70), SIMDE_FLOAT64_C(   196.69) },
      { SIMDE_FLOAT64_C(   177.63), SIMDE_FLOAT64_C(   643.96), SIMDE_FLOAT64_C(   532.64), SIMDE_FLOAT64_C(  -742.82),
        SIMDE_FLOAT64_C(   713.41), SIMDE_FLOAT64_C(  -855.54), SIMDE_FLOAT64_C(   740.15), SIMDE_FLOAT64_C(  -398.11) } },
    { { SIMDE_FLOAT64_C(  -571.89), SIMDE_FLOAT64_C(  -789.13), SIMDE_FLOAT64_C(    50.09), SIMDE_FLOAT64_C(   179.68),
        SIMDE_FLOAT64_C(   926.88), SIMDE_FLOAT64_C(  -213.20), SIMDE_FLOAT64_C(  -940.18), SIMDE_FLOAT64_C(   438.22) },
      { SIMDE_FLOAT64_C(  -673.78), SIMDE_FLOAT64_C(  -548.71), SIMDE_FLOAT64_C(   591.76), SIMDE_FLOAT64_C(   171.13),
        SIMDE_FLOAT64_C(   914.96), SIMDE_FLOAT64_C(  -143.51), SIMDE_FLOAT64_C(  -455.66), SIMDE_FLOAT64_C(    92.59) },
      { SIMDE_FLOAT64_C(   571.89), SIMDE_FLOAT64_C(   789.13), SIMDE_FLOAT64_C(    50.09), SIMDE_FLOAT64_C(   179.68),
        SIMDE_FLOAT64_C(   926.88), SIMDE_FLOAT64_C(   213.20), SIMDE_FLOAT64_C(   940.18), SIMDE_FLOAT64_C(   438.22) } },
    { { SIMDE_FLOAT64_C(   212.52), SIMDE_FLOAT64_C(    11.70), SIMDE_FLOAT64_C(   349.77), SIMDE_FLOAT64_C(   499.11),
        SIMDE_FLOAT64_C(   156.16), SIMDE_FLOAT64_C(   609.62), SIMDE_FLOAT64_C(  -899.00), SIMDE_FLOAT64_C(  -796.17) },
      { SIMDE_FLOAT64_C(  -994.66), SIMDE_FLOAT64_C(  -256.84), SIMDE_FLOAT64_C(   219.86), SIMDE_FLOAT64_C(   -76.52),
        SIMDE_FLOAT64_C(   774.97), SIMDE_FLOAT64_C(  -856.84), SIMDE_FLOAT64_C(  -879.83), SIMDE_FLOAT64_C(  -796.92) },
      { SIMDE_FLOAT64_C(  -212.52), SIMDE_FLOAT64_C(   -11.70), SIMDE_FLOAT64_C(   349.77), SIMDE_FLOAT64_C(  -499.11),
        SIMDE_FLOAT64_C(   156.16), SIMDE_FLOAT64_C(  -609.62), SIMDE_FLOAT64_C(   899.00), SIMDE_FLOAT64_C(   796.17) } },
    { { SIMDE_FLOAT64_C(  -645.97), SIMDE_FLOAT64_C(   170.26), SIMDE_FLOAT64_C(   382.75), SIMDE_FLOAT64_C(  -719.09),
        SIMDE_FLOAT64_C(   957.06), SIMDE_FLOAT64_C(   442.58), SIMDE_FLOAT64_C(   719.12), SIMDE_FLOAT64_C(  -716.72) },
      { SIMDE_FLOAT64_C(   893.87), SIMDE_FLOAT64_C(   310.88), SIMDE_FLOAT64_C(   454.40), SIMDE_FLOAT64_C(   808.82),
        SIMDE_FLOAT64_C(  -832.63), SIMDE_FLOAT64_C(   998.74), SIMDE_FLOAT64_C(   -98.58), SIMDE_FLOAT64_C(   379.89) },
      { SIMDE_FLOAT64_C(  -645.97), SIMDE_FLOAT64_C(   170.26), SIMDE_FLOAT64_C(   382.75), SIMDE_FLOAT64_C(  -719.09),
        SIMDE_FLOAT64_C(  -957.06), SIMDE_FLOAT64_C(   442.58), SIMDE_FLOAT64_C(  -719.12), SIMDE_FLOAT64_C(  -716.72) } },
    { { SIMDE_FLOAT64_C(    10.44), SIMDE_FLOAT64_C(  -748.81), SIMDE_FLOAT64_C(  -120.99), SIMDE_FLOAT64_C(  -833.40),
        SIMDE_FLOAT64_C(   860.81), SIMDE_FLOAT64_C(   -19.99), SIMDE_FLOAT64_C(  -629.57), SIMDE_FLOAT64_C(   866.15) },
      { SIMDE_FLOAT64_C(   723.17), SIMDE_FLOAT64_C(   590.29), SIMDE_FLOAT64_C(  -210.37), SIMDE_FLOAT64_C(   498.14),
        SIMDE_FLOAT64_C(   733.45), SIMDE_FLOAT64_C(   -90.20), SIMDE_FLOAT64_C(   701.22), SIMDE_FLOAT64_C(  -912.52) },
      { SIMDE_FLOAT64_C(    10.44), SIMDE_FLOAT64_C(  -748.81), SIMDE_FLOAT64_C(   120.99), SIMDE_FLOAT64_C(  -833.40),
        SIMDE_FLOAT64_C(   860.81), SIMDE_FLOAT64_C(    19.99), SIMDE_FLOAT64_C(  -629.57), SIMDE_FLOAT64_C(  -866.15) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_x_mm512_xorsign_pd(a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_x_mm512_xorsign_pd(a, b);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_xorsign_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_xorsign_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>