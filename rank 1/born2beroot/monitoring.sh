#!/bin/bash
arch=$(uname -a)
pCPU=$(lscpu | awk '$1 == "CPU(s):" {printf $2}')
Threads=$(lscpu | grep "^Thread(s) per core:" | awk '{print $4}')
vCPU=$((Threads * pCPU))
useram=$(free -m | grep "Mem:" | awk '{printf $2}')
freeram=$(free -m | grep "Mem:" | awk '{printf $3}')
percram=$(free | grep "Mem:" | awk '{printf ("%.2f"), $3/$2*100}')
usedisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ud += $3} END {print ud}')
totaldisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{td += $2} END {print td}')
percdisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ud += $3} {td += $2} END {printf>
CPUl=$(top -bn1 | grep "^%Cpu(s)" | awk '{print $2 + $4}')
CPUl=$(printf "%.1f%%" $cpul)
lb=$(who -b | awk '$1 == "system" {printf $3 " " $4 " " $5}')
lvmt=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3}')
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')
cmds=$(journalctl _COMM=sudo -q | grep COMMAND | wc -l)
wall "  #Architecture: $arch
        #CPU physical: $pCPU
        #vCPU: $vCPU
        #Memory Usage: $useram/${freeram}MB ($percram%)
        #Disk Usage: $usedisk/${totaldisk}Gb ($percdisk%)
        #CPU load: $CPUl
        #Last boot: $lb
        #LVM use: $lvmu
        #Connexions TCP: $ctcp ESTABLISHED
        #User log: $ulog
        #Network: IP $ip ($mac)
        #Sudo: $cmds cmd"

