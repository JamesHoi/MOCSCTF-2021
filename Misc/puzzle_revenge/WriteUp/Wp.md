## 小透明 题解
<font color='red'>考点:png图像格式 栅栏密码</font><br/>
题目给出了out文件夹下100张图片和名为find.png的一张图片.
观察发现100张图片的透明度不尽相同,find.png中每个笑脸的颜色深度也不同.
推断图像的alpha维度可能存在映射关系,

通过对rgba分析,可知笑脸放置在正确位置时,alpha的值为255,随后将整张图的alpha通道修为255,可得完整拼图.
[![6Se78g.png](https://s3.ax1x.com/2021/02/26/6Se78g.png)](https://imgtu.com/i/6Se78g)
然后文字识别
[![6Se78g.png](https://ae01.alicdn.com/kf/U0aeca99775bd48409b4b4f1ca349259by.jpg)](https://imgtu.com/i/6Se78g)
加密用的是5个一组的栅栏密码,去[千千秀字工具](www.qqxiuzi.cn)多试几次解开<br>
#### 得到结果 ```MOCSCTF{Thanks_for_watching_my_face}```

### 拼图脚本(仅供参考):
```python
import cv2
import os

pics=os.listdir('out')
find=cv2.imread('find.png',cv2.IMREAD_UNCHANGED)
x=y=0
for i in range(1,101):
    v=find[y + 60][x + 90][3]
    for pic in pics:
        img=cv2.imread('out/'+pic,cv2.IMREAD_UNCHANGED)
        if img[60, 90, 3]+v==255:
            for ny in range(108):
                for nx in range(192):
                    if find[ny][nx][3]!= 1:
                        find[y + ny, x + nx]= img[ny][nx]
    if x<1920-192: x+=192
    if i%10==0: y+=108;x=0
find[:,:,3]=255
cv2.imwrite("out.png",find)
```