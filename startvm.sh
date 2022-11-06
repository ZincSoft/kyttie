# qemu-system-x86_64 -display curses -kernel ./arch/x86/boot/bzImage -hda qemu-image.img -append root=/dev/sda single
# qemu-system-x86_64 -display curses -kernel ./arch/x86/boot/bzImage -drive file=qemu-image.img,format=raw,index=0,media=disk -append root=/dev/sda single
echo "Use 'shutdown -h now' for shutdown."
echo "Please place your KVM combatable, built Linux source tree in the 'linux_source_tree.ignore' directory."
echo "A raw QEMU image named 'qemu-image.img' should also be built there."
qemu-system-x86_64 \
    -display curses \
    -kernel ./linux_source_tree.ignore/arch/x86/boot/bzImage \
    -drive file=./linux_source_tree.ignore/qemu-image.img,format=raw,index=0,media=disk \
    -virtfs local,path="$PWD",mount_tag=host0,security_model=passthrough,id=host0 \
    -append "root=/dev/sda loglevel=4 vga=6" \
    -vga std \
    --enable-kvm

echo "Please proceed to the chamber lock."

