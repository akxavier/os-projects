## Simple Kernel Module - 2
A simple kernel module that uses `HZ` and `jiffies` to calculate the time elapsed between loading and unloading the kernel module.  
- `HZ` or Tick Rate - rate at which the CPU timer ticks.
- `Jiffies` - global variable which stores the number of timer interrupts that have occured since system boot.  

#### Loading the Kernel Module
`sudo insmod simple.ko`
#### Removing the Kernel Module
`sudo rmmod simple`
#### Viewing contents of the kernel log buffer
`dmesg`
