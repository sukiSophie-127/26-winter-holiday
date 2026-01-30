### P2676

#### 最优解(我的代码)

```C++
#include<algorithm>
#include<cstdio>
#define MAXN 20010
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int n,k,h=0,cnt=0;
int cow[MAXN];

int main(){
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",&cow[i]);
    }
    sort(cow,cow+n,cmp);
    while (h<k){
        h+=cow[cnt++];
    }
    printf("%d",cnt);
    return 0;
}
```
### P1116

#### 最优解(我的代码)

```C++
#include<cstdio>
#define MAXN 1010
using namespace std;

int n,cnt=0;
int a[MAXN];

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<=n-2;i++){
        for (int j=i+1;j<n;j++){
            if (a[i]>a[j]) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
```
#### 命题证明：最小相邻交换次数等于初始逆序对个数

设序列为 $A$，其初始逆序对总数为 $I(A)$。

##### 1. 引理：相邻交换对逆序对数的影响
对于序列中任意两个相邻元素 $a_i, a_{i+1}$：
- 若交换前 $a_i > a_{i+1}$（即这是一对逆序对），交换后该对变为顺序，且不改变涉及序列中其他任何元素的相对位置关系。因此，逆序对总数 $I(A)$ **精确减少 1**。
- 同理，若交换前 $a_i < a_{i+1}$，交换后 $I(A)$ **精确增加 1**。

##### 2. 必要性证明（下界）
目标状态为升序序列，此时逆序对数 $I_{target} = 0$。
由于单次相邻交换操作对 $I(A)$ 的改变量 $\Delta I \in \{1, -1\}$，要使逆序对数从 $I_{init}$ 减少到 $0$，至少需要执行 $I_{init}$ 次交换操作。
即：$MinSteps \ge I_{init}$。

##### 3. 充分性证明（可行性）
只要序列 $A$ 不是升序的，根据**有序性判定依据**（若 $\forall i, a_i \le a_{i+1}$ 则序列有序），通过反证法可知：非有序序列中**必然存在**至少一个 $i$ 使得 $a_i > a_{i+1}$。
通过不断选取并交换这种“相邻逆序对”，每一步都能确保 $I(A)$ 严格递减 1。经过 $I_{init}$ 步后，$I(A)$ 必定减至 0，此时序列达到有序状态。
即：$MinSteps \le I_{init}$。

##### 结论
综合上述性质，$MinSteps = I_{init}$。证明完毕。


### P1152

[我的代码(有错误)](./P1152.cpp)

#### 最优解

```C++
#include<cstdio>
#include<algorithm>
#define MAXN 1010
using namespace std;

int n;
int a[MAXN];

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<n;i++){
        a[i-1]=abs(a[i]-a[i-1]);
    };
    sort(a,a+n-1);
    for (int i=0;i<n-1;i++){
        if (a[i]!=i+1){
            printf("Not jolly");
            return 0;
        }
    }
    printf("Jolly");
    return 0;
}
```

algorithm中定义的unique返回的是指向去重后数组最后一个元素的后一个位置的指针

### P1068

#### 最优解(我的代码)

```C++
#include<cstdio>
#include<algorithm>
#define MAXN 5010
using namespace std;

struct Stu {
    int k;
    int s;
};

bool cmp(Stu a,Stu b){
    if (a.s==b.s) return a.k<b.k;
    else return a.s>b.s;
}

Stu stu[MAXN];
int n,m;
int ans_s,ans;

int main(){
    scanf("%d %d",&n,&m);
    int line=m*3/2-1;
    for (int i=0;i<n;i++){
        scanf("%d %d",&stu[i].k,&stu[i].s);
    }
    sort(stu,stu+n,cmp);
    ans_s=stu[line].s;
    ans=line;
    while (stu[ans+1].s==stu[ans].s){
        ans++;
    }
    printf("%d %d\n",ans_s,ans+1);
    for (int i=0;i<=ans;i++){
        printf("%d %d\n",stu[i].k,stu[i].s);
    }
    return 0;
}
```

### P5143

#### 最优解(我的代码)

```C++
#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAXN 50010
using namespace std;

struct Point {
    int x,y,z;
};

bool cmp(Point a,Point b){
    return a.z<b.z;
}

int n;
Point p[MAXN];
double ans=0;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
    }
    sort(p,p+n,cmp);
    for (int i=1;i<n;i++){
        ans+=sqrt(pow(p[i].x-p[i-1].x,2)+pow(p[i].y-p[i-1].y,2)+pow(p[i].z-p[i-1].z,2));
    }
    printf("%.3f",ans);
    return 0;
}
```

### P1104

#### 最优解(我的代码)

```C++
#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#define MAXN 110
using namespace std;

struct Stu {
    string name;
    int y,m,d,id;
};

bool cmp(Stu a,Stu b){
    if (a.y==b.y){
        if (a.m==b.m){
            if (a.d==b.d){
                return a.id>b.id;
            }
            else {
                return a.d<b.d;
            }
        }
        else {
            return a.m<b.m;
        }
    }
    else {
        return a.y<b.y;
    }
}

int n;
Stu stu[MAXN];

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>stu[i].name>>stu[i].y>>stu[i].m>>stu[i].d;
        stu[i].id=i;
    }
    sort(stu,stu+n,cmp);
    for (int i=0;i<n;i++){
        cout<<stu[i].name<<endl;
    }
    return 0;
}
```

### P1012

#### 最优解

```C++
#include<string>
#include<iostream>
#include<algorithm>
#define MAXN 30
using namespace std;

bool cmp(string a,string b){
    return a+b>b+a;
}

int n;
string num[MAXN];

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n,cmp);
    for (int i=0;i<n;i++){
        cout<<num[i];
    }
    return 0;
}
```

> 无法独立证明这个...

核心在于将字符串比较转化为代数数值比较。

1. 数学建模设字符串 $x$ 的数值为 $V_x$，长度为 $L_x$。字符串拼接 $a \oplus b$ 的数值可表示为：
$$V_{a \oplus b} = V_a \cdot 10^{L_b} + V_b$$
定义关系 $\succ$：$a \succ b \iff a \oplus b > b \oplus a$。

2. 变换判定准则将 $a \oplus b > b \oplus a$ 代数化：
$$V_a \cdot 10^{L_b} + V_b > V_b \cdot 10^{L_a} + V_a$$
$$V_a(10^{L_b} - 1) > V_b(10^{L_a} - 1)$$
由于长度 $L \ge 1$，则 $10^L - 1 > 0$，等式变形为：
$$\frac{V_a}{10^{L_a} - 1} > \frac{V_b}{10^{L_b} - 1}$$
令映射函数 $f(x) = \frac{V_x}{10^{L_x} - 1}$，则 $a \succ b \iff f(a) > f(b)$。

3. 性质证明由于 $f(x)$ 将字符串映射到了实数域，利用实数全序集的性质：
- 完全性：对于任意 $a, b$，实数 $f(a), f(b)$ 必有大小关系，故 $a, b$ 必可比。
- 反对称性：若 $f(a) > f(b)$ 且 $f(b) > f(a)$ 则冲突；若 $f(a) = f(b)$，则拼接顺序不影响结果。
- 传递性：若 $a \succ b$ 且 $b \succ c$，则 $f(a) > f(b)$ 且 $f(b) > f(c)$。由实数传递性得 $f(a) > f(c)$，即 $a \succ c$。

结论：该关系是全序关系，贪心排序有效。


快速排序

```C++
void quickSort(int a[],int l,int r){
    if (l==r){
        return;
    }
    int i=l,j=r,pivot=a[(l+r)/2];
    do {
        while (a[i]<pivot) i++;
        while (a[j]>pivot) j--;
        if (i<=j){
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }        
    }while (i<=j);
    if (i<r) quickSort(a,i,r);
    if (j>l) quickSort(a,l,j);
}
```

`algorithm`中:
- `sort(para1,para2,para3)`:para1是排序开始的地址,para2是排序结束的地址的后一位,相当与[para1,para2)区间,para3为排序方式,传入cmp布尔函数,cmp(a,b)返回true时按照a,b排序;返回false时按照b,a排序,默认升序排序.
- `unique(para1,para2)`:对[para1,para2)范围内去重后返回指向序列结尾元素的后一位位置的指针

