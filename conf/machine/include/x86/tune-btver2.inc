# Settings for the GCC cpu-type btver2.
#
# AMD family 16h cores with x86-64 instruction set support. Supported
# extensions include:
#
#   mmx, sse, sse2, sse3, ssse3, sse4a, sse4.1, sse4.2, avx, aes, pclmul,
#   f16c, popcnt, abm, bmi, lzcnt, xsave, xsaveopt, movbe
#
# This tune is recommended for AMD Jaguar and Puma cores

DEFAULTTUNE ?= "btver2-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/x86/tune-core2.inc

# Extra tune features
TUNEVALID[btver2] = "Enable btver2 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'btver2', ' -march=btver2', '', d)}"

AVAILTUNES += "btver2-64"
TUNE_FEATURES:tune-btver2-64 = "${TUNE_FEATURES:tune-x86-64} btver2"
BASE_LIB:tune-btver2-64 = "lib64"
TUNE_PKGARCH:tune-btver2-64 = "btver2-64"
PACKAGE_EXTRA_ARCHS:tune-btver2-64 = "${PACKAGE_EXTRA_ARCHS:tune-x86-64} btver2-64"
QEMU_EXTRAOPTIONS_btver2-64 = " -cpu phenom,bmi1=on,sse4.1=on,movbe=on"
