# ez_unpack

扔进Exeinfo PE，32位exe，Aspack壳
![image.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1612101439359-8754c8c6-f9a9-472c-9245-c1005151dcc5.png#align=left&display=inline&height=78&margin=%5Bobject%20Object%5D&name=image.png&originHeight=116&originWidth=449&size=55311&status=done&style=none&width=301)
压缩壳一般都会用到pushad指令，ESP定律即可脱壳，进去按一下F8
![image.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1614351643818-bed38d94-920c-40b6-95a7-0e6c154ef430.png#align=left&display=inline&height=225&margin=%5Bobject%20Object%5D&name=image.png&originHeight=449&originWidth=1376&size=158999&status=done&style=none&width=688)
右键ESP寄存器然后选择断点，即HW break [ESP]，然后按一下F9
![image.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1614351718600-6d6600fc-8031-45e7-985b-41a73bf6480e.png#align=left&display=inline&height=207&margin=%5Bobject%20Object%5D&name=image.png&originHeight=413&originWidth=1391&size=169347&status=done&style=none&width=695.5)
再F8几下进入壳内的exe函数，然后就找到了程序真正的OEP
![image.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1614351793015-84a50666-39e4-403b-b13b-baa021cb4674.png#align=left&display=inline&height=167&margin=%5Bobject%20Object%5D&name=image.png&originHeight=334&originWidth=1440&size=130396&status=done&style=none&width=720)
OEP
![image.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1614351818840-327c9998-05f7-43a4-a3e5-088e0d0e560e.png#align=left&display=inline&height=167&margin=%5Bobject%20Object%5D&name=image.png&originHeight=333&originWidth=874&size=67908&status=done&style=none&width=437)
选择 插件->OllyDump，自动选择了当前EIP作为OEP，啥都不用选直接按脱壳，保存为dump.exe
![image.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1612102019530-8d647ba0-52ed-4171-8361-09b384379f85.png#align=left&display=inline&height=153&margin=%5Bobject%20Object%5D&name=image.png&originHeight=285&originWidth=615&size=42091&status=done&style=none&width=331)
将脱好壳的程序放进ida，剩下的不细讲了，base64解码一下就是flag
![image.png](https://cdn.nlark.com/yuque/0/2021/png/2738284/1614351976655-3eb4636b-3d47-4d83-8984-69d3a91fe3f7.png#align=left&display=inline&height=199&margin=%5Bobject%20Object%5D&name=image.png&originHeight=397&originWidth=756&size=26486&status=done&style=none&width=378)
```python
import base64
flag = "TU9DU0NURntWZXJ5X0V6X1VucDBja19SMHZlcnNlX2hhKmhhfQ=="

print(base64.b64decode(flag))
# MOCSCTF{Very_Ez_Unp0ck_R0verse_ha*ha}
```


