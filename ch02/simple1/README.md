## Simple Kernel Module - 1
A simple kernel module to demonstrate loading and unloading kernel modules and obtaining values (`GOLDEN_RATIO_PRIME`) and calling functions (`long unsigned gcd (long unsigned a, long unsigned b)`) that are available inside the kernel.  
  
#### Loading the Kernel Module
`sudo insmod simple.ko`
#### Removing the Kernel Module
`sudo rmmod simple`
#### Viewing contents of the kernel log buffer
`dmesg`
