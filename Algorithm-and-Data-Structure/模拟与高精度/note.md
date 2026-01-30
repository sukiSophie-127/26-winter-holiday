### P4924

[我的代码](./P4924.cpp)

#### 最优解

```C++
#include<bits/stdc++.h>
using namespace std;
const int N=515;
int n,m,x,y,r,z,tmp,mmap[N][N],f[N][N];
//mmap是输入数组 f数组用于执行操作
void copy(){//把f数组复制到mmap数组，相当于memcpy
    for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                    mmap[i][j]=f[i][j];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {mmap[i][j]=++tmp;f[i][j]=mmap[i][j];}//原始矩阵
    for(int k=1;k<=m;k++){
        cin>>x>>y>>r>>z;
        if(!z){//顺时针z=0
            for(int i=-r;i<=r;i++){
                for(int j=-r;j<=r;j++){
                    f[x+j][y-i]=mmap[x+i][y+j];
                }
            }
            copy();
        }
        else{//逆时针
            for(int i=-r;i<=r;i++){
                for(int j=-r;j<=r;j++){
                    f[x-j][y+i]=mmap[x+i][y+j];
                }
            }
            copy();
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
                cout<<f[i][j]<<' ';
        cout<<endl;    
    }//输出最终矩阵
    return 0;
}
```

一般情况下的二维数组旋转90,-90,180,轴对称,中心对称的一般规律:

**坐标：** $(x, y)$，其中 $x$ 为行索引（Row），$y$ 为列索引（Col）。
**偏移量：** 相对旋转中心 $(x, y)$ 的偏移为 $dx$（行偏移）和 $dy$（列偏移）。
**数组属性：** 默认正方形数组，边长为 $n$（索引范围 $0$ 到 $n-1$）。

**顺时针 90°**
    关系：$(x+dx, y+dy) \to (x+dy, y-dx)$

**逆时针 90° (-90°)**
    关系：$(x+dx, y+dy) \to (x-dy, y+dx)$

**旋转 180°**
    关系：$(x+dx, y+dy) \to (x-dx, y-dy)$

**关于 row = x 对称（水平轴对称/上下翻转）**
    关系：$(x+dx, y) \to (x-dx, y)$

**关于 col = y 对称（垂直轴对称/左右翻转）**
    关系：$(x, y+dy) \to (x, y-dy)$

**关于主对角线对称（row = col，以左上角为 $x, y$ 原点）**
    关系：$(x+dx, y+dy) \to (x+dy, y+dx)$

**关于副对角线对称（row = -col 方向，以左上角为 $x, y$ 原点）**
    关系：$(x+dx, y+dy) \to (x+(n-1-dy), y+(n-1-dx))$


### P1328

#### 最优解(我的代码)
```C++
#include<cstdio>
#define MAXN 210
using namespace std;
//0 表示 剪刀，1 表示 石头，2 表示 布，3 表示 蜥蜴人，4 表示 斯波克
//每一次赢的人得 1 分，输的得 0 分；平局两人都得 0 分
int v[5][5]={0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,0};

int a[MAXN],b[MAXN];
int ascore=0,bscore=0;

int main(){
    int n,an,bn;
    scanf("%d%d%d",&n,&an,&bn);
    for (int i=0;i<an;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<bn;i++){
        scanf("%d",&b[i]);
    }

    for (int i=0;i<n;i++){
        ascore+=v[a[i%an]][b[i%bn]];
        bscore+=v[b[i%bn]][a[i%an]];
    }

    printf("%d %d",ascore,bscore);
    return 0;
}
```

### P1518

[我的代码](./P1518.cpp)

最优解有两种:
1. 我的代码中cnt的临界值取160000,因为10*10地图,2个运动物体,每个运动物体有100种可能位置和4种可能方向,故$(100\*4)^2=160000$种状态,暴力美学
2. 使用哈希映射(状态压缩),六个自由度且有各自取值范围, $Hash = d_c + 4 \cdot (y_c + 10 \cdot (x_c + 10 \cdot (d_f + 4 \cdot (y_f + 10 \cdot x_f))))$ 可以唯一确定每种状态(构成单射),结合visited数组

### P1067

[我的代码](./P1067.cpp)

#### 最优解
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a; cin >> n;
	for(int i=n; i>=0; i--){
		cin >> a;
		if(a){
			if(i<n&&a>0) cout << '+';
			if(abs(a)>1||i==0) cout << a;
			if(a==-1&&i) cout << '-';
			if(i>0) cout << 'x';
			if(i>1) cout << '^' << i;
		}
	}
	return 0;
}
```

最优解好强的思维逻辑

### P1098

[我的代码](./P1098.cpp)

#### 最优解

```C++
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int p1, p2, p3;
    string s;
    if (!(cin >> p1 >> p2 >> p3 >> s)) return 0;

    for (int i = 0; i < s.length(); ++i) {
        // 安全检查：只有当 i 在 (0, len-1) 之间时，才去评估减号两端的字符
        if (s[i] == '-' && i > 0 && i < s.length() - 1 && 
            s[i+1] > s[i-1] && // 此时访问 s[i-1] 是安全的
            ((isdigit(s[i-1]) && isdigit(s[i+1])) || (islower(s[i-1]) && islower(s[i+1])))) {
            
            for (int k = (p3 == 1 ? s[i-1] + 1 : s[i+1] - 1); 
                 (p3 == 1 ? k < s[i+1] : k > s[i-1]); 
                 k += (p3 == 1 ? 1 : -1)) {
                
                char out = (p1 == 3 ? '*' : (p1 == 2 ? toupper((char)k) : (char)k));
                for (int j = 0; j < p2; ++j) printf("%c", out);
            }
        } else {
            putchar(s[i]);
        }
    }
    return 0;
}
```

虽然我的if-else判断能跑通,但是什么时候我才能有最优解体现的强大的逻辑思维和整合能力?

### P1065

### P1591

[我的代码](./P1591.cpp)

#### 最优解

```C++
#include<iostream>
#include<cstring>
using namespace std;
int A[114514];
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,a,ws=1;
		cin>>n>>a;
		for(int i=1;i<=1145;i++) A[i]=0;
		A[1]=1;
		for(int i=2;i<=n;i++){
			int jw=0,j;
			for(j=1;j<=ws;j++){
				A[j]*=i;
				A[j]+=jw;
				jw=A[j]/10;
				A[j]%=10;
			}
			while(jw>0){
				A[j]=jw%10;
				jw/=10;
				j++;
			}
			ws=j-1;
		}
		long long s=0;
		for(int i=1;i<=ws;i++){
			if(A[i]==a) s++;
		}
		cout<<s<<endl;
	} 
	return 0;
}
```

[标准大整数类BigInt模板](./BigInt.cpp)

### P1249

#### 最优解(我的代码,非独立)
```C++
#include<cstdio>
#include<cstring>
#define MAXN 2000

struct BigInt {
    int len;
    int a[MAXN];

    BigInt(){
        memset(a,0,sizeof(a));
    }

    BigInt(int n){
        memset(a,0,sizeof(a));
        if (n==0){
            len=1;
        }
        else {
            len=0;
            while (n>0){
                a[len++]=n%10;
                n=n/10;
            }
        }
    }

    void mul(int k){
        if (!k){
            memset(a,0,sizeof(a));
            len=1;
            return ;
        }

        for (int i=0;i<len;i++){
            a[i]=a[i]*k;
        }
        len=len+6;
        for (int i=0;i<len;i++){
            a[i+1]=a[i+1]+a[i]/10;
            a[i]=a[i]%10;
        }
        while (!a[len-1]){
            len--;
        }
    }

    void print(){
        for (int i=len-1;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n");
    }
};

int split[MAXN];
int cnt=0,sum=0,n;

int main(){
    scanf("%d",&n);
    if (n==3){
        printf("3\n3");
    }
    if (n==4){
        printf("4\n4");
    }
    if (n==5){
        printf("2 3\n6");
    }
    for (int i=2;i<n;i++){
        if (sum+i<n){
            split[cnt++]=i;
            sum+=i;
            continue;
        }
        else if (sum+i==n){
            split[cnt++]=i;
            sum+=i;
            break;
        }
        else {
            int res=n-sum;
            int pr=cnt;
            while (res>0){
                if (pr==0) pr+=cnt;
                split[--pr]++;
                res--;
            }
            break;
        }
    }
    BigInt ans=BigInt(1);
    for (int i=0;i<cnt;i++){
        ans.mul(split[i]);
    }
    for (int i=0;i<cnt;i++){
        printf("%d ",split[i]);
    }
    printf("\n");
    ans.print();
    return 0;
}
```

贪心策略:
1. 1一定不在最优序列中(将1加在序列中剩下的任意一个数上都会使结果变大)
2. 最优序列的任意相邻两数之差小于等于2(假设存在相邻两数$a_i$,$a_{i+1}$之差大于2,则替换成后$a_i+1$,$a_{i+1}-1$结果变大)
3. 从2开始连续增加直至再加下一个数会超过目标数(任意大于k+1的x拆成k和x-k会使结果变大(忽略可能的重复数字))
4. 从后往前,每次分配1,到头后从末尾继续开始地分配余数(为了满足前3条)

我更欣赏动态规划的做法,通过取对数转成0-1背包问题,详情见[题解](https://www.luogu.com.cn/article/77ri3zu9)


### P1045

[我的代码(有错误)](./P1045.cpp)

#### 最优解(AI改正我的代码的结果)

```C++
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

// 针对麦森数题目，只需保留最后500位
struct BigInt {
    int num[505];

    BigInt() {
        memset(num, 0, sizeof(num));
    }

    // 初始化高精度数为 n
    void assign(int n) {
        memset(num, 0, sizeof(num));
        num[0] = n;
        // 简单处理低位数，不需要复杂的循环
    }

    // 专门针对此题优化的乘法：res = this * other
    void mul(const BigInt& other) {
        int temp[505];
        memset(temp, 0, sizeof(temp));

        for (int i = 0; i < 500; i++) {
            for (int j = 0; j + i < 500; j++) {
                temp[i + j] += num[i] * other.num[j];
            }
        }

        // 进位处理
        for (int i = 0; i < 500; i++) {
            temp[i + 1] += temp[i] / 10;
            num[i] = temp[i] % 10;
        }
    }
};

BigInt res, base;

void fast_pow(int p) {
    res.num[0] = 1; // 初始化结果为1
    base.num[0] = 2; // 初始化底数为2

    while (p > 0) {
        if (p & 1) res.mul(base);
        base.mul(base);
        p >>= 1;
    }
}

int main() {
    int p;
    if (scanf("%d", &p) != 1) return 0;

    // 1. 输出位数：log10(2^p) = p * log10(2)
    printf("%d\n", (int)(p * log10(2)) + 1);

    // 2. 快速幂计算 2^p
    fast_pow(p);

    // 3. 计算 2^p - 1
    res.num[0] -= 1;

    // 4. 输出最后500位
    for (int i = 499; i >= 0; i--) {
        printf("%d", res.num[i]);
        if (i % 50 == 0) printf("\n");
    }

    return 0;
}
```

至此除了两道模拟题(P1065和P1786)还没做以外,模拟和高精度章节结束.

模拟可画状态机;高精度背模板;