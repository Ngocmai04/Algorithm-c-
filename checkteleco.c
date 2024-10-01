#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100000
typedef struct node1
{ // tinh tong so lan goi tu phonenumber
    char number[11];
    int tonggoi;
    int tongtime; // tong so tgian ma phonenumber da goi
} node1;
// bang bam
node1 *T[MAX];

typedef struct node
{
    char form_number[11];
    char to_number[11];
    char ngay[20];
    int gio1;
    int phut1;
    int giay1;
    int gio2;
    int phut2;
    int giay2;
} node;

int cnt = 0; // demsotongcuocgoi
int checkgoidi;
int checkgoiden;
int checktong = 1;

node *makeNode()
{
    char goidi[11], goiden[11], Ngay[20];
    int Gio1, Phut1, Giay1, Gio2, Phut2, Giay2;
    scanf("%s %s %s %d:%d:%d %d:%d:%d", goidi, goiden, Ngay, &Gio1, &Phut1, &Giay1, &Gio2, &Phut2, &Giay2);
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->form_number, goidi);
    strcpy(new->to_number, goiden);
    strcpy(new->ngay, Ngay);
    new->gio1 = Gio1;
    new->phut1 = Phut1;
    new->giay1 = Giay1;
    new->gio2 = Gio2;
    new->phut2 = Phut2;
    new->giay2 = Giay2;
    return new;
}
node1 *makeNode1(node*r)
{
    node1 *new = (node1 *)malloc(sizeof(node1));
    new->tonggoi = 1;
    new->tongtime = 0;
    strcpy(new->number,r->form_number);
    return new;
}
int checkNumber(char a[])
{
    int len = strlen(a);
    if (len == 10)
    {
        for (int i = 0; i < len; i++)
        {
            int x = a[i] - '0';
            if (x > 9)
                return -1;
        }
        return 1;
    }
    else
        return -1;
}
int H(const char a[])
{ // Convert string to number
    int hash = 0;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        hash = (hash * 256 + a[i]) % MAX;
    }
    return hash;
}

int ham(int hash, int probe)
{                                    // Hashing function
    return (hash + 9 * probe) % MAX; // ax+b
}
// hàm chen
void insert(const char a[], node1 *v)
{
    int index = H(a);
    int probe = 0;

    while (T[index] != NULL && probe < MAX)
    { // nó có gia trị rồi
        if (strcmp(T[index]->number, a) == 0)
        {
            T[index]->tonggoi++;
            T[index]->tongtime += v->tongtime;
            return;
        }

        probe++;
        index = ham(index, probe); // Calculate next position
    }

    T[index] = v; // Copy the string into the hash table
}

// ham tinh time
int tinhtime(node *r)
{
    int tongdi = r->gio1 * 3600 + r->phut1 * 60 + r->giay1;
    int tongden = r->gio2 * 3600 + r->phut2 * 60 + r->giay2;
    return tongden - tongdi;
}

int find(const char a[])
{
    int index = H(a);
    int probe = 0;

    while (T[index] != NULL && probe < MAX)
    {
        if (strcmp(T[index]->number, a) == 0)
            return index; // Element found

        probe++;
        index = ham(index, probe); // Calculate next position
    }

    return 0; // Element not found
}
void tongTime(char a[])
{
    int index = find(a);
    printf("%d\n", T[index]->tongtime);
}
void tongGoi(char a[])
{
    int index = find(a);
    printf("%d\n", T[index]->tonggoi);
}
int main()
{
    char a[20];
    while (1)
    {
        scanf("%s", a);
        if (strcmp(a, "#") == 0) //
            break;
        cnt++;
        node *r = makeNode();
        node1 *v = makeNode1(r);
        v->tongtime = tinhtime(r);
        checkgoidi = checkNumber(r->form_number);
        checkgoiden = checkNumber(r->to_number);
        if (checkgoidi==-1|| checkgoiden==-1) checktong=-1;
        insert(r->form_number,v);
    }
    while (1)
    {
        scanf("%s", a);
        if (strcmp(a, "#") == 0)
            break;
        else if (strcmp("?check_phone_number", a) == 0)
        {
            if (checktong==1)
            {
                printf("1\n");
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (strcmp("?number_total_calls", a) == 0)
        {
            printf("%d\n", cnt);
        }
        else if (strcmp("?count_time_calls_from", a)==0)
        {
            scanf("%s", a);
            tongTime(a);
        }
        else if (strcmp("?number_calls_from", a)==0)
        {
            scanf("%s", a);
            tongGoi(a);
        }
    }
}
