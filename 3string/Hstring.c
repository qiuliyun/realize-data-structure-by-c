#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//串的定义和基本操作（动态数组堆分配存储）
//用到的c语言库函数介绍：
//strcpy(1,2):将字符串2复制给1
//strlen(s):获取字符串长度
//puts(s):输出s
//strcat(1,2):把2连接到1后面
//strcmp(1,2)：字符串比较


typedef struct{
    char *ch;
    int length;
}Hsting;

//赋值操作，把串T赋值为chars
Hsting *StrAssign(char chars[]){
    Hsting *s = (Hsting *)malloc(sizeof(Hsting));
    s->ch = chars;     //赋值
    s->length = strlen(chars);
    return s;
}

//复制操作
Hsting *StrCopy(Hsting S){
    Hsting *T = (Hsting *)malloc(sizeof(Hsting));
    T->ch = S.ch;
    T->length = S.length;
    return T;
}

//判空操作,返回1为空
int StrEmpty(Hsting S){
    if(S.length == 0)
        return 1;
    else return 0;
}

//比较(a,b)操作,相同返回0，a>b返回1,a<b返回-1
int StrCompare(Hsting S1,Hsting S2){
    int x =strcmp(S1.ch,S2.ch);
    return x;
}

//求串长
int Strlen(Hsting S){
    return S.length;
}

//求子串,求从串S的【start】序号开始的长度为length的子串
Hsting *SubString(Hsting S,int start,int l){
    Hsting *L = (Hsting *)malloc(sizeof(Hsting));
    L->ch = (char *)malloc(sizeof(char)*l);
    if(S.length == 0)
        return NULL;
    for(int i = start,j = 0;i<S.length&&j<l;i++,j++){
        L->ch[j] = S.ch[i];
    }
    L->ch[l] = '\0';
    return L;
}

//串链接，链接a、b串并返回
Hsting *concat(Hsting A,Hsting B){
    Hsting *p = (Hsting *)malloc(sizeof(Hsting));
    int len = A.length + B.length;
    p->ch = (char *)malloc(sizeof(char)*len);
    printf("长度为：%d\n",strlen(p->ch));
    p->length = len;
    for(int i=0;i<A.length;i++){
        p->ch[i] = A.ch[i];
    }
    for(int j=A.length,i=0;i<B.length;i++,j++){
        p->ch[j] = B.ch[i];
    }
    p->ch[len] = '\0';
    printf("长度为：%d\n",strlen(p->ch));
    return p;
}

int main(){
    //赋值操作，把串T赋值为chars
    Hsting *StrAssign(char chars[]);
    //复制操作
    Hsting *StrCopy(Hsting S);
    //判空操作,返回1为空
    int StrEmpty(Hsting S);
    //比较(a,b)操作,相同返回0，a>b返回1,a<b返回-1
    int StrCompare(Hsting S1,Hsting S2);
    //求串长
    int Strlen(Hsting S);
    //求子串,求从串S的【start】序号开始的长度为length的子串
    Hsting *SubString(Hsting S,int start,int l);
    //串链接，链接a、b串并返回
    Hsting *concat(Hsting A,Hsting B);

    char c[] = "qiuliyun can success";
    Hsting *p,*q,*m;
    p = StrAssign(c);
    puts(p->ch);

    q = StrCopy(*p);
    puts(q->ch);

    // if(StrEmpty(*q) != 1)
    //     printf("串不为空\n");
    // else printf("串为空\n");

    // printf("比较一下两个串：%s,%s\n",p->ch,q->ch);
    // if(StrCompare(*p,*q) == 0)
    //     printf("两个串相同\n");
    // else printf("两个串不同\n");

    printf("串%s的长为：%d\n",p->ch,Strlen(*p));

    //printf("求串：%s 从第9位开始长为3位的子串为：%s\n",p->ch,SubString(*p,9,3)->ch);

    //m = concat(*p,*q);
    //printf("串%s和%s链接后为%s,长度是%d\n",p->ch,q->ch,m->ch,m->length);




    return 0;
}
