### P3392

#### 最优解(我的代码)

```C++
#include<cstdio>
#include<cstring>
#define MAXN 60
#define min(a,b) ((a<b)?(a):(b))
using namespace std;

int a[MAXN][3];
int n,m;
int ans=MAXN*MAXN+10;
int res=0;

int main(){
    memset(a,0,sizeof(a));
    scanf("%d %d",&n,&m);
    char tmp;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf(" %c",&tmp);
            if (tmp=='W') a[i][0]++;  //white is 0
            else if (tmp=='B') a[i][1]++;  //blue is 1
            else a[i][2]++;  //red is 2
        }
    }
    for (int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            res=0;
            for (int p=0;p<=i-1;p++){
                res+=a[p][1]+a[p][2];
            }
            for (int p=i;p<=j-1;p++){
                res+=a[p][0]+a[p][2];
            }
            for (int p=j;p<=n-1;p++){
                res+=a[p][0]+a[p][1];
            }
            ans=min(ans,res);
        }
    }
    printf("%d",ans);
    return 0;
}
```

因为n,m<=50所以可以暴力枚举


### P3654

#### 最优解(我的代码)

```C++
#include<cstdio>
#include<cstring>
#define MAXN 110
#define max(a,b) ((a>b)?(a):(b))
using namespace std;

int a[MAXN][MAXN];
int dx[2]={1,0};
int dy[2]={0,1};
int r,c,k;
int ans=0,other_ans=0;

int main(){
    memset(a,0,sizeof(a));
    scanf("%d %d %d",&r,&c,&k);
    char tmp;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            scanf(" %c",&tmp);
            if (tmp=='.'){
                a[i][j]=1;
                other_ans++;
            }
        }
    }
    if (k==1){
        printf("%d",other_ans);
        return 0;
    }
    //注释部分为O(n^3)复杂度,非注释部分为O(n^2)
    // for (int i=1;i<=r;i++){
    //     for (int j=1;j<=c;j++){
    //         if (a[i][j]){
    //             for (int p=0;p<2;p++){
    //                 int res=1;
    //                 while (a[i+dx[p]*res][j+dy[p]*res]){
    //                     res++;
    //                 }
    //                 if (res>=k) ans++;
    //             }
    //         }
    //     }
    // }
    for (int i=1;i<=r;i++){
        int res=0;
        for (int j=1;j<=c;j++){
            if (a[i][j]) res++;
            else {
                ans+=max(0,res-k+1);
                res=0;
            }
        }
        ans+=max(0,res-k+1);
    }
    for (int j=1;j<=c;j++){
        int res=0;
        for (int i=1;i<=r;i++){
            if (a[i][j]) res++;
            else {
                ans+=max(0,res-k+1);
                res=0;
            }
        }
        ans+=max(0,res-k+1);
    }
    printf("%d",ans);
    return 0;
}
```

### P1217

#### 最优解

```C++
#include <cstdio>
#include <stdbool.h>
#include <cmath>

bool is_prime(int n){
    if(n<2)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    int limit=(int)sqrt(n);
    for(int i=3;i<=limit;i+=2){
        if(n%i==0)return false;
    }
    return true;
}

void check_and_print(int num,int a,int b){
    if(num>=a&&num<=b&&is_prime(num)){
        printf("%d\n",num);
    }
}

int main(){
    int a,b;
    if(scanf("%d %d",&a,&b)!=2)return 0;
    for(int d1=1;d1<=9;d1++){
        check_and_print(d1,a,b);
    }
    check_and_print(11,a,b);
    if(b>=101){
        for(int d1=1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                int num=d1*100+d2*10+d1;
                check_and_print(num,a,b);
            }
        }
    }
    if(b>=10001){
        for(int d1=1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                for(int d3=0;d3<=9;d3++){
                    int num=d1*10000+d2*1000+d3*100+d2*10+d1;
                    check_and_print(num,a,b);
                }
            }
        }
    }
    if(b>=1000001){
        for(int d1=1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                for(int d3=0;d3<=9;d3++){
                    for(int d4=0;d4<=9;d4++){
                        int num=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
                        check_and_print(num,a,b);
                    }
                }
            }
        }
    }
    return 0;
}
```

先得到回文数再判断质数;
偶数都不是质数;
偶位的回文数不是质数(被11整除).

### P1149

#### 最优解(我的代码)

```C++
#include<cstdio>
#define MAXN 2000
using namespace std;

int digit[10]={6,2,5,5,4,5,6,3,7,6};

int f(int n){
    if (n==0) return digit[0];
    int res=0;
    while (n>0){
        res+=digit[n%10];
        n=n/10;
    }
    return res;
}

int n;
int num[MAXN];
int ans=0;

int main(){
    scanf("%d",&n);
    if (n<13){
        printf("0");
        return 0;
    }
    for (int i=0;i<MAXN;i++){
        num[i]=f(i);
    }
    for (int i=0;i<MAXN/2;i++){
        for (int j=0;j<MAXN/2;j++){
            if (num[i]+num[j]+num[i+j]==n-4){
                ans++;
                // printf("%d+%d=%d\n",i,j,i+j);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
```

有点理解暴力枚举的含义了,两种方式:寻找变量间关系(一一映射等)从而减少枚举变量的数量;寻找变量间关系(和一定等)从而减少枚举变量的范围.

### P3799

#### 最优解(我的代码,AI纠错后)

```C++
#include<cstdio>
#include<cstring>
#define MAXN 5010
#define MOD 1000000007
#define ll long long
using namespace std;

ll cnt[MAXN];
int res[MAXN];
int len=0;
int n;
ll ans=0;

ll c(int n){
    return n*(n-1)/2%MOD;
}

int main(){
    memset(cnt,0,sizeof(cnt));
    memset(res,0,sizeof(res));
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        cnt[tmp]++;
    }
    // for (int i=1;2*i<MAXN;i++){
    //     if (cnt[i]<2) continue;
    //     if (cnt[2*i]>=2){
    //         ans+=cnt[i]*(cnt[i]-1)*cnt[2*i]*(cnt[2*i]-1)/4;
    //         ans=ans%MOD;
    //     }
    // }
    for (int i=0;i<MAXN;i++){
        if (cnt[i]) res[len++]=i;
    }
    for (int i=len-1;i>=0;i--){
        if (cnt[res[i]]<2) continue;
        int l=0,r=i-1;
        while (l<=r){
            if (res[l]+res[r]==res[i]){
                if (l==r){
                    ans+=c(cnt[res[l]])*c(cnt[res[i]]);
                    ans=ans%MOD;
                    break;
                }
                else {
                    ans+=cnt[res[l]]*cnt[res[r]]*c(cnt[res[i]]);
                    ans=ans%MOD;
                    l++;
                    r--;
                }
            }
            else if (res[l]+res[r]>res[i]){
                r--;
            }
            else {
                l++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
```

注意审题,不要想当然地默认核心逻辑

### P2392

#### 最优解(我的代码,照抄AI)

```C++
#include<cstdio>
#include<cstring>
#define MAXN 70
#define max(a,b) ((a>b)?(a):(b))
using namespace std;

int a[4],val[MAXN],dp[2500],ans=0;

int main(){
    for (int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<4;i++){
        int sum=0;
        for (int j=0;j<a[i];j++){
            scanf("%d",&val[j]);
            sum+=val[j];
        }
        int target=sum/2;
        memset(dp,0,sizeof(dp));
        for (int j=0;j<a[i];j++){
            for (int k=target;k>=val[j];k--){
                dp[k]=max(dp[k],dp[k-val[j]]+val[j]);
            }
        }
        ans+=sum-dp[target];
    }
    printf("%d",ans);
    return 0;
}
```

还是没完全理解dp的处理过程,等到动态规划学完再来复习一下

### P2036

#### 最优解(我的代码,照抄AI)

```C++
#include<cstdio>
#include<algorithm>
#define INF 1e9
#define MAXN 10
using namespace std;

int n;
int s[MAXN],b[MAXN];
int total_s,total_b;
int ans=INF;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d",&s[i],&b[i]);
    }
    for (int i=1;i<(1<<n);i++){
        total_s=1;
        total_b=0;
        for (int j=0;j<n;j++){
            if ((i>>j)&1){
                total_s*=s[j];
                total_b+=b[j];
            }
        }
        ans=min(ans,abs(total_s-total_b));
    }
    printf("%d",ans);
    return 0;
}
```

所以套多重循环实在还是太难用了,即便我相处各种小巧思(赋无关值统一枚举变量数,积化和等)也还是败在小巧思上(多余位的无关值正好提供了一个不存在的结果1)

以后这类全部使用位运算

然后**dfs**也可以,代码如下:

```C++
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
long long s[15], b[15];
long long min_diff = 1e18; // 使用足够大的初始值

/**
 * @param index 当前处理到第几种食材
 * @param current_s 当前累积的酸度（乘积）
 * @param current_b 当前累积的苦度（总和）
 * @param count 记录选择了多少种食材，防止“一种都不选”
 */
void dfs(int index, long long current_s, long long current_b, int count) {
    if (index == n) {
        if (count > 0) {
            min_diff = min(min_diff, abs(current_s - current_b));
        }
        return;
    }

    // 选择 1：不选当前食材
    dfs(index + 1, current_s, current_b, count);

    // 选择 2：选择当前食材
    dfs(index + 1, current_s * s[index], current_b + b[index], count + 1);
}

int main() {
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }

    dfs(0, 1, 0, 0); // 初始酸度为1，苦度为0，计数为0

    cout << min_diff << endl;
    return 0;
}
```

### P1433

[我的代码(全排列暴力枚举,过6个测试点)](./P1433.cpp)

#### 最优解(dfs,剪枝,过10个测试点)

```C++
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

#define MAXN 20
#define INF 1e18 // 使用更大的 INF 避免精度问题
using namespace std;

struct Point {
    double x, y;
};

Point p[MAXN];
int n;
bool visited[MAXN];
double dist[MAXN][MAXN];
double ans = INF;

// 预计算欧几里得距离
double get_dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

/**
 * @brief DFS 模拟全排列枚举
 * @param curr 当前所在点的编号
 * @param count 已经走过的点数（不含起点）
 * @param current_dist 当前累计距离
 */
void dfs(int curr, int count, double current_dist) {
    // 【核心剪枝】如果当前距离已经大于等于已知最优解，直接返回
    if (current_dist >= ans) {
        return;
    }

    // 走完了所有点
    if (count == n) {
        ans = min(ans, current_dist);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, count + 1, current_dist + dist[curr][i]);
            visited[i] = false; // 回溯
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 加速 I/O
    cin.tie(0);

    if (!(cin >> n)) return 0;

    p[0].x = 0; p[0].y = 0; // 起点 (0,0)
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    // 预处理距离矩阵
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dist[i][j] = get_dist(p[i], p[j]);
        }
    }

    // 从起点 (0) 开始搜索
    dfs(0, 0, 0.0);

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}
```

如果不把dfs算作暴力枚举的话,那暴力枚举主要就是在找变量间关系(一一映射等)从而减少枚举变量的数量;寻找变量间关系(和一定等)从而减少枚举变量的范围.

位运算提供集合的各项操作.

`algorithm`定义的`next_permutation`函数:next_permutation(para1,para2,para3),[para1,para2)范围内按照para3定义的"大小关系"进行排列,无法排列时返回false,否则为true;para3默认为字典序