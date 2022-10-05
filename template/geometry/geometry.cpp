//向下取整floor 向上取整ceil 四舍五入round
//正弦定理：a/sinA = b/sinB = c/sinC = 2R (外接圆半径)
//余弦定理：a^2 = b^2 + c^2 - 2bc*cosA
//面积：S = 1/2 * ab * sinC
#include <bits/stdc++.h>

using namespace std;

#define qmax(x, y) (x = max(x, y))
#define qmin(x, y) (x = min(x, y))
#define mp(x, y) make_pair(x, y)

typedef pair<int, int> pii;
typedef long long ll;

const double pi = acos(-1.0);
const double inf = 1e100;
const double eps = 1e-8;

//判断符号
int sgn(double x) {return x < -eps ? -1 : x > eps; }

//比较大小
int dcmp(double x, double y) {
    return sgn(x - y);
}

struct Point {
    double x, y;
    Point(double X = 0, double Y = 0) {
        x = X, y = Y;
    }
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) {
    return Vector(A.x + B.x, A.y + B.y);
}

Vector operator - (Vector A, Vector B) {
    return Vector(A.x - B.x, A.y - B.y);
}

Vector operator * (Vector A, double p) {
    return Vector(A.x * p, A.y * p);
}

Vector operator * (double p, Vector A) {
    return Vector(A.x * p, A.y * p);
}

Vector operator / (Vector A, double p) {
    return Vector(A.x / p, A.y / p);
}

bool operator == (const Point& a, const Point& b){
    if(dcmp(a.x, b.x) == 0 && dcmp(a.y, b.y) == 0)
        return true;
    return false;
}

//数量积/点积/内积 a*b = |a||b|cos(t)
double operator * (Vector A, Vector B) {
    return A.x*B.x + A.y*B.y;
}

//向量积/外积/叉积
//向量A与B所张成的平行四边形的有向面积
//遵循右手定则，如果B在A的逆时针方向则为正
//顺时针方向则为负
//两向量共线则为0
double operator ^ (Vector A, Vector B) {
    return A.x*B.y - A.y*B.x;
}

//长度
double Length(Vector A) {
    return sqrt(A * A);
}

//计算两向量夹角
//返回值为弧度值
double Angle(Vector A, Vector B) {
    return acos((A*B) / Length(A) / Length(B));
}


//单位化向量
Vector Normal(Vector A) {
    double len = Length(A);
    A.x /= len;
    A.y /= len;
    return A;
}

//计算向量逆时针旋转rad弧度后的向量

Vector Rotate(Vector A, double rad) {
    return Normal(Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad)));
}

//计算两直线交点（平行会出bug）最好先算叉积判平行
Point Meetpoint(Point p, Vector v, Point q, Vector w) {
    Vector u = p - q;
    double t = (w^u) / (v^w);
    return p + t*v;
}

//计算点p到直线AB的距离
double Disline(Point p, Point A, Point B) {
    Vector v1 = B-A, v2 = p-A;
    return fabs((v1^v2) / Length(v1));
}//去掉绝对值，如果P在向量AB左边则为正

//计算点p到线段AB的距离
double Disseg(Point p, Point A, Point B){
    if(A == B)
        return Length(p-A);
    Vector v1 = B-A, v2 = p-A, v3 = p-B;
    if(sgn(v1*v2) < 0)
        return Length(v2);
    if(sgn(v1*v3) > 0)
        return Length(v3);
    return Disline(p, A, B);
}

//求点在直线上的投影点
Point Projection(Point p, Point A, Point B){
    Vector v = B-A;
    return A + v*((v*(p-A)) / (v*v));
}

//判断点是否在线段上
bool Onseg(Point p, Point A, Point B) {
    return sgn((A-p) ^ (B-p))==0 && sgn((A-p) * (B-p))<0;
}

//判断两线段是否相交：通过两次跨立实验
bool Checksegmeet(Point a1, Point a2, Point b1, Point b2){
    double c1 = (a2-a1)^(b1-a1), c2 = (a2-a1)^(b2-a1);
    double c3 = (b2-b1)^(a1-b1), c4 = (b2-b1)^(a2-b1);
    //if判断控制是否允许线段在端点处相交，根据需要添加
    if(!sgn(c1) || !sgn(c2) || !sgn(c3) || !sgn(c4)){
        bool f1 = Onseg(b1, a1, a2);
        bool f2 = Onseg(b2, a1, a2);
        bool f3 = Onseg(a1, b1, b2);
        bool f4 = Onseg(a2, b1, b2);
        bool f = (f1|f2|f3|f4);
        return f;
    }
    return (sgn(c1)*sgn(c2) < 0 && sgn(c3)*sgn(c4) < 0);
}

//计算三角形的面积
double Triarea(Point A, Point B, Point C) {
    return fabs((B-A) ^ (C-A))/2;
}

//三角形面积海伦公式：abc分别为三边长度
double Triarea(double a, double b, double c) {
    double p = (a+b+c) / 2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

//求两向量的角平分线向量
Vector Angbis(Vector A, Vector B) {
    return Normal(Normal(A) + Normal(B));
}

//三角形四心：
//外心：三边中垂线交点，性质：到三个顶点距离相同
Point Outcenter(Point A, Point B, Point C) {
    Point P = (A + B) / 2;
    Vector V = Vector((B-A).y, -(B-A).x);
    Point Q = (A + C) / 2;
    Vector W = Vector((C-A).y, -(C-A).x);
    return Meetpoint(P, V, Q, W);
}

//内心：角平分线交点，到三边距离相等
Point Incenter(Point A, Point B, Point C) {
    Vector V = Angbis(B-A, C-A);
    Vector W = Angbis(A-B, C-B);
    return Meetpoint(A, V, B, W);
}

//垂心：三条高线的交点
Point Orthocenter(Point A, Point B, Point C) {
    Vector V = Vector((B-A).y, -(B-A).x);
    Vector W = Vector((C-A).y, -(C-A).x);
    return Meetpoint(C, V, B, W);
}

//重心：三条中线的交点
Point Gcenter(Point A, Point B, Point C) {
    return Point((A.x+B.x+C.x)/3, (A.y+B.y+C.y)/3);
}

Point STO;

//判断A点是否在向量BC左边，左边返回1
int inleft(Point A, Point B, Point C) {
    Vector X = C - B;
    Vector Y = A - B;
    return sgn(X ^ Y);
}

//在一二象限为0，三四象限为1，可以进行极角排序
int vecPos(Vector A) {
    if(sgn(A.y) == -1 || (sgn(A.y) == 0 && sgn(A.x) == -1))
        return 1;
    return 0;
}

//更细的判象限，x轴正向在1， y轴正向在2， x轴负向在3， y轴负向在4
//原点在 0
int getvecPos(Vector A) {
    if(A.x > 0 && A.y >= 0) return 1;
    if(A.x <= 0 && A.y > 0) return 2;
    if(A.x < 0 && A.y <= 0) return 3;
    if(A.x >= 0 && A.y < 0) return 4;
    return 0;
}

//以O点为参照点进行极角排序
bool Angcmp(Point A, Point B) {
    int a = vecPos(A), b = vecPos(B);
    if(a != b) return a < b;
    int tmp = inleft(B, STO, A);
    if(tmp == 0) return Length(A - STO) < Length(B - STO);
    return tmp==1;
}

void Angsort(Point *A, int n, Point O) {
    STO = O;
    sort(A+1, A+n+1, Angcmp);
}

//求凸包
void Convexhull(Point *A, int &n) {
    for(int i=2; i<=n; i++) {
        if(dcmp(A[i].x, A[1].x)==1) continue;
        if(dcmp(A[i].x, A[1].x)==0) {
            if(dcmp(A[i].y, A[1].y)==-1) swap(A[1], A[i]);
        }
        else
            swap(A[1], A[i]);
    }
    Angsort(A+1, n-1, A[1]);
    int t = 1;
    for(int i=2; i<=n; i++) {
        A[++t] = A[i];
        if(t<=2) continue;
        while(t>2 && inleft(A[t], A[t-2], A[t-1])<=0)
            A[t-1] = A[t], t--;
    }
    n = t;
}

//求凸多边形周长
double getC(Point *A, int n) {
    double Ans = 0;
    for(int i=2; i<=n; i++)
        Ans += Length(A[i] - A[i-1]);
    Ans += Length(A[1] - A[n]);
    return Ans;
}

//求多边形面积，点按照逆时针顺序给出
double getS(Point *A, int n) {
    double Ans = 0;
    Point O = Point(0, 0);
    for(int i=2; i<=n; i++)
        Ans += (A[i-1]-O) ^ (A[i]-O);
    Ans += (A[n]-O) ^ (A[1]-O);
    return Ans/2;
}

// “pick定理:在一个平面直角坐标系内,
// 以整点为顶点的简单多边形(任两边不交叉),
// 它内部整点数为a,它的边上(包括顶点)的整点数为b,
// 则它的面积S = a+b/2-1”
// a = S + 1 - b/2
// 求边上整点数的方法：gcd(a,b) a，b为边的x，y向量
// 求面积的方法：对于多边形的每一条边，将两个端点到原点向量的叉积累加起来
// 知道边上整点数和面积了，就可以用pick定理求多边形内整点数了

//Melkman算法: 求解简单多边形的凸包（可以是凹多边形）时间复杂度 O(n)

//判断点是否在凸多边形内部:是否始终在边的左边（逆时针枚举边）
int insideconvex(Point X, Point *A, int n) {
    for(int i=2; i<=n; i++) {
        int tmp = inleft(X, A[i-1], A[i]);
        if(tmp!=1) return tmp;
    }
    int tmp = inleft(X, A[n], A[1]);
    if(tmp!=1) return tmp;
    return 1;
}

//判断点是否在多边形内部：
/*
转角法的基本思想是看多边形相对于这个点转了多少度
如果是三百六十度，说明点在多边形内
如果是零度，说明点在多边形外
如果是一百八十度，说明点在多边形边界上
如果直接按照定义来算，则需要计算大量反三角函数，不仅速度慢，而且容易产生精度问题
我们采用winding number绕数来计算
*/

//判断点是否在多边形内，若点在多边形内返回1，在多边形外部返回-1，在多边形上返回0
int insidehull(Point p, Point *A, int n){
    int wn = 0;
    for(int i=1; i<=n; ++i){
        if(Onseg(p, A[i], A[i%n+1])) return 0;
        int k = sgn((A[i%n+1]-A[i]) ^ (p-A[i]));
        int d1 = sgn(A[i].y - p.y);
        int d2 = sgn(A[i%n+1].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) wn++;
        if(k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if(wn != 0)
        return 1;
    return -1;
}

//圆的定义
struct Circle {
    Point o;
    double r;
    Circle(Point O = Point(0, 0), double R = 0) {
        o = O, r = R;
    }
    Point point(double a){//通过圆心角a求坐标
        return Point(o.x + cos(a)*r, o.y + sin(a)*r);
    }
};

//求圆C与直线AB交点 -1代表相离，0代表相切，1代表相交
int Linecirclemeet(Circle C, Point A, Point B, Point &Ans1, Point &Ans2) {
    double dis = Disline(C.o, A, B); //圆心到直线距离
    if(dis > C.r) return -1;
    Point D = Projection(C.o, A, B); //圆心在直线上的投影
    if(dis == C.r) {
        Ans1 = D;
        return 0;
    }
    double h = Length(D - C.o); //圆心到直线的距离
    double l = sqrt(C.r*C.r - h*h); //弦长的一半
    Vector v = Normal(B - A);
    Ans1 = D + l*v;
    Ans2 = D - l*v;
    return 1;
}

//求两圆的交点
int Circlecirclemeet(Circle A, Circle B, Point &Ans1, Point &Ans2) {
    double d = Length(B.o - A.o);
    if(d > A.r + B.r) return -1;
    Vector v = Normal(B.o - A.o);
    if(d == A.r + B.r) {
        Ans1 = A.o + A.r*v;
        return 0;
    }
    double a = acos((d*d + A.r*A.r - B.r*B.r) / (2*A.r*B.r));//余弦定理
    Vector vx = Rotate(v, a);
    Ans1 = A.o + A.r*vx;
    Vector vy = Rotate(v, -a);
    Ans2 = A.o + A.r*vy;
    return 1;
}

//求点到圆的切线
int Cutline(Point A, Circle B, Vector &Ans1, Vector &Ans2) {
    double d = Length(B.o - A);
    if(d < B.r) return -1; //在圆内
    if(d == B.r) {
        Ans1 = Rotate(B.o - A, pi/2); //在圆上
        return 0;
    }
    double a = asin(B.r / d);
    Ans1 = Rotate(B.o - A, a); //在圆外
    Ans2 = Rotate(B.o - A, -a);
    return 1;
}

//求两圆相交的面积
double CirclemeetS(Circle A, Circle B){
    Point c1 = A.o, c2 = B.o;
    double r1 = A.r, r2 = B.r;
    double d = Length(c1 - c2);
    if(r1 + r2 < d + eps)
        return 0.0;
    if(d < fabs(r1 - r2) + eps){
        double r = min(r1, r2);
        return pi*r*r;
    }
    double x = (d*d + r1*r1 - r2*r2)/(2.0*d);
    double p = (r1 + r2 + d)/2.0;
    double t1 = acos(x/r1);
    double t2 = acos((d - x)/r2);
    double s1 = r1*r1*t1;
    double s2 = r2*r2*t2;
    double s3 = 2*sqrt(p*(p - r1)*(p - r2)*(p - d));
    return s1 + s2 - s3;
}

//一点一向量表示一条线
struct Line {
    Point p;
    Vector v;
    Line(Point P = Point(0, 0), Vector V = Vector(0, 0)) {
        p = P, v = V;
    }
};

bool operator != (Point A, Point B) {
    return dcmp(A.x, B.x)!=0 || dcmp(A.y, B.y)!=0;
}

bool operator != (Line A, Line B) {
    return A.p!=B.p || A.v!=B.v;
}

//给半平面排序，先按照极角，极角相同按照先左再右
bool cmp(Line a, Line b) {
    int t1 = vecPos(a.v);
    int t2 = vecPos(b.v);
    if(t1 != t2) return t1 < t2;
    double vc = a.v ^ b.v;
    if(sgn(vc) != 0) return sgn(vc) == 1;
    return inleft(a.p, b.p, b.p+b.v)==1;
}

//半平面交
void Halfplanemeet(int &n, Line *s, Point *t) {
    sort(s+1, s+n+1, cmp);
    int l = 1, r = 1;
    for(int i=2; i<=n; i++)
        if(s[i].v != s[i-1].v) {
            while(r-l>0 && inleft(t[r], s[i].p, s[i].p+s[i].v)!=1) r--;
            while(r-l>0 && inleft(t[l+1], s[i].p, s[i].p+s[i].v)!=1) l++;
            s[++r] = s[i];
            if(r-l>0) t[r] = Meetpoint(s[r-1].p, s[r-1].v, s[r].p, s[r].v);
        }
    while(r-l>0 && inleft(t[r], s[l].p, s[l].p+s[l].v)!=1) r--;
    if(r-l<=1) {
        n = 0;
        return;
    }
    t[l] = Meetpoint(s[l].p, s[l].v, s[r].p, s[r].v);
    for(int i=l; i<=r; i++)
        t[i-l+1] = t[i], s[i-l+1] = s[i];
    n = r-l+1;
}

//求凸包直径（距离最远的两个点的距离）使用旋转卡壳
double Convexdiameter(Point *A, int n) {
    int dz = 2;//记录对踵点
    double Ans = 0;
    for(int i=1; i<=n; i++) { //逆时针枚举每一条边，寻找其对踵点
        while(dcmp(Disline(A[dz], A[i], A[i%n+1]), Disline(A[dz%n+1], A[i], A[i%n+1])) == -1)
            dz = dz%n + 1;
        qmax(Ans, Length(A[dz] - A[i]));
        qmax(Ans, Length(A[dz] - A[i%n+1]));
    }
    return Ans;
}

//判断点A是否在圆B内,圆内返回1，上0，外-1
int Incircle(Point A, Circle B) {
    double d = Length(A - B.o);
    return dcmp(B.r, d);
}

//求n个点的最小圆覆盖
Circle Circlehull(Point *A, int n) {
    random_shuffle(A+1, A+n+1); //随机打乱序列，保证不被卡
    Circle O = Circle(Point(0, 0), 0);
    for(int i=1; i<=n; i++) {
        if(Incircle(A[i], O)>=0) continue;
        O = Circle(A[i], 0);
        for(int j=1; j<i; j++) {
            if(Incircle(A[j], O)>=0) continue;
            O = Circle((A[i]+A[j])/2, Length(A[i]-A[j])/2);
            for(int k=1; k<j; k++) {
                if(Incircle(A[k], O)>=0) continue;
                Point OC = Outcenter(A[i], A[j], A[k]); //三角形外心
                O = Circle(OC, Length(OC-A[i]));
            }
        }
    }
    return O;
}

int main() {
//	freopen("nh.in", "r", stdin);

    return 0;
}







