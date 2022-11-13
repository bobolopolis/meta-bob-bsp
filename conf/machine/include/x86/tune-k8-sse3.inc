# Settings for the GCC cpu-type k8-sse3.
#
# AMD K8 cores with x86-64 instruction set support. Supported
# extensions include:
#   3dnow, 3dnowext, mmx, sse, sse2, sse3
#

DEFAULTTUNE ?= "k8-sse3-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/x86/tune-core2.inc

# Extra tune features
TUNEVALID[k8-sse3] = "Enable k8-sse3 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'k8-sse3', ' -march=k8-sse3', '', d)}"

AVAILTUNES += "k8-sse3-64"
TUNE_FEATURES:tune-k8-sse3-64 = "${TUNE_FEATURES:tune-x86-64} k8-sse3"
BASE_LIB:tune-k8-sse3-64 = "lib64"
TUNE_PKGARCH:tune-k8-sse3-64 = "k8-sse3-64"
PACKAGE_EXTRA_ARCHS:tune-k8-sse3-64 = "${PACKAGE_EXTRA_ARCHS:tune-x86-64} k8-sse3-64"
QEMU_EXTRAOPTIONS_k8-sse3-64 = " -cpu phenom,check=false"
