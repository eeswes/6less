# 6less
Temporarily disable IPv6 for your program.

## Install:
```
gcc -shared -fPIC -o lib6less.so lib6less.c -ldl
sudo install -Dm755 lib6less.so /usr/local/lib/lib6less.so
sudo install -Dm755 6less.sh /usr/local/bin/6less
```

## Examples:
```
$ ping -6 aliyun.com
PING aliyun.com (2401:b180:1:60::6) 56 data bytes
64 bytes from 2401:b180:1:60::6: icmp_seq=1 ttl=90 time=10.6 ms
64 bytes from 2401:b180:1:60::6: icmp_seq=2 ttl=90 time=10.8 ms
64 bytes from 2401:b180:1:60::6: icmp_seq=3 ttl=90 time=10.8 ms
^C
--- aliyun.com ping statistics ---
3 packets transmitted, 3 received, 0% packet loss, time 2003ms
rtt min/avg/max/mdev = 10.572/10.715/10.800/0.101 ms
$ 6less ping -6 aliyun.com
ping: aliyun.com: Address family for hostname not supported
```
