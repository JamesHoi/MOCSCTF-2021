# signIn

# 题目分析
exe后缀名是假的，放进exeinfope便知道并不是exe是elf64位，放进linux虚拟机运行会出现一个二维码
![image.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1614335362663-123fd68c-0b9b-43cc-82b5-a121fc12de6f.png#align=left&display=inline&height=74&margin=%5Bobject%20Object%5D&name=image.png&originHeight=107&originWidth=443&size=46743&status=done&style=none&width=306)
signIn.exe所生成的二维码
![qrcode.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1614337774116-9b10fbf4-58b7-48bd-bcd9-7305f3ffb55f.png#align=left&display=inline&height=204&margin=%5Bobject%20Object%5D&name=qrcode.png&originHeight=480&originWidth=480&size=23450&status=done&style=none&width=204)
二维码信息为：
已加密的flag(hex)： 
```python
encode =[0x1b7,0x1b5,0x1b9,0x1a9,0x1b9,0x1ae,0x1bc,0x181,0x1ad,0x1ca,0x196,0x199,0x1ca,0x197,0x19f,0x1a5,0x1d1,0x1b0,0x1ca,0x193,0x1b4,0x1a5,0x1d0,0x197,0x1ca,0x1b9,0x1a9,0x199,0x18e,0x19c,0x187]
```
關注facebook社團獲得xor cipher，通過cipher解密 即flag[i] = cipher^encode[i] [https://www.facebook.com/MOCSCTF](https://www.facebook.com/MOCSCTF)


# 解答
在facebook上找到cipher为0x1FA，根据二维码提示即得flag
```python
encode = [0x1b7,0x1b5,0x1b9,0x1a9,0x1b9,0x1ae,0x1bc,0x181,0x1ad,0x1ca,
          0x196,0x199,0x1ca,0x197,0x19f,0x1a5,0x1d1,0x1b0,0x1ca,0x193,
          0x1b4,0x1a5,0x1d0,0x197,0x1ca,0x1b9,0x1a9,0x199,0x18e,0x19c,0x187]
flag = []
cipher = 0x1FA

for i in range(len(encode)):
    flag.append(chr(cipher^encode[i]))
print("".join(flag))
# MOCSCTF{W0lc0me_+J0iN_*m0CSctf}
```



