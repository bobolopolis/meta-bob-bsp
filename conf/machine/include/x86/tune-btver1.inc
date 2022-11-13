# Settings for the GCC cpu-type btver1.
#
# AMD family 14h cores with x86-64 instruction set support. Supported
# extensions include:
#
#   mmx, sse, sse2, sse3, ssse3, sse4a, cx16, abm
#
# This tune is recommended for AMD Bobcat cores

DEFAULTTUNE ?= "btver1-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/x86/tune-core2.inc

# Extra tune features
TUNEVALID[btver1] = "Enable btver1 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'btver1', ' -march=btver1', '', d)}"

AVAILTUNES += "btver1-64"
TUNE_FEATURES:tune-btver1-64 = "${TUNE_FEATURES:tune-x86-64} btver1"
BASE_LIB:tune-btver1-64 = "lib64"
TUNE_PKGARCH:tune-btver1-64 = "btver1-64"
PACKAGE_EXTRA_ARCHS:tune-btver1-64 = "${PACKAGE_EXTRA_ARCHS:tune-x86-64} btver1-64"
QEMU_EXTRAOPTIONS_btver1-64 = " -cpu Opteron_G4,check=false"
