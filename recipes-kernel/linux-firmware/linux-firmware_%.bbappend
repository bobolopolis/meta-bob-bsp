inherit deploy

do_deploy() {
    install -d ${WORKDIR}/amd-ucode/kernel/x86/microcode
    cat ${S}/amd-ucode/microcode_amd.bin > ${WORKDIR}/amd-ucode/kernel/x86/microcode/AuthenticAMD.bin
    echo ${WORKDIR}/amd-ucode/kernel/x86/microcode/AuthenticAMD.bin | cpio -o -H newc -R0:0 > ${DEPLOYDIR}/amd-uc.img
}
addtask do_deploy after do_install before do_build
