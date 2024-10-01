#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

struct node1 {
    std::string number;
    int tonggoi;
    int tongtime;
};

std::unordered_map<std::string, node1*> T;

struct node {
    std::string form_number;
    std::string to_number;
    std::string ngay;
    int gio1;
    int phut1;
    int giay1;
    int gio2;
    int phut2;
    int giay2;
};

int cnt = 0;
int checkgoidi;
int checkgoiden;
int checktong = 1;

node* makeNode() {
    std::string goidi, goiden, Ngay;
    int Gio1, Phut1, Giay1, Gio2, Phut2, Giay2;
    std::cin >> goidi >> goiden >> Ngay >> Gio1 >> Phut1 >> Giay1 >> Gio2 >> Phut2 >> Giay2;
    node* newNode = new node();
    newNode->form_number = goidi;
    newNode->to_number = goiden;
    newNode->ngay = Ngay;
    newNode->gio1 = Gio1;
    newNode->phut1 = Phut1;
    newNode->giay1 = Giay1;
    newNode->gio2 = Gio2;
    newNode->phut2 = Phut2;
    newNode->giay2 = Giay2;
    return newNode;
}

node1* makeNode1(node* r) {
    node1* newNode = new node1();
    newNode->tonggoi = 1;
    newNode->tongtime = 0;
    newNode->number = r->form_number;
    return newNode;
}

int checkNumber(const std::string& a) {
    if (a.length() == 10) {
        for (char c : a) {
            if (c < '0' || c > '9') {
                return -1;
            }
        }
        return 1;
    } else {
        return -1;
    }
}

int H(const std::string& a) {
    int hash = 0;
    for (char c : a) {
        hash = (hash * 256 + c) % MAX;
    }
    return hash;
}

int ham(int hash, int probe) {
    return (hash + 9 * probe) % MAX;
}

void insert(const std::string& a, node1* v) {
    int index = H(a);
    int probe = 0;

    while (T.find(a) != T.end() && probe < MAX) {
        if (T[a]->number == a) {
            T[a]->tonggoi++;
            T[a]->tongtime += v->tongtime;
            return;
        }

        probe++;
        index = ham(index, probe);
    }

    T[a] = v;
}

int tinhtime(node* r) {
    int tongdi = r->gio1 * 3600 + r->phut1 * 60 + r->giay1;
    int tongden = r->gio2 * 3600 + r->phut2 * 60 + r->giay2;
    return tongden - tongdi;
}

int find(const std::string& a) {
    if (T.find(a) != T.end()) {
        return 1;
    }
    return 0;
}

void tongTime(const std::string& a) {
    if (find(a)) {
        std::cout << T[a]->tongtime << std::endl;
    }
}

void tongGoi(const std::string& a) {
    if (find(a)) {
        std::cout << T[a]->tonggoi << std::endl;
    }
}

int main() {
    std::string a;
    while (true) {
        std::cin >> a;
        if (a == "#") {
            break;
        }
        cnt++;
        node* r = makeNode();
        node1* v = makeNode1(r);
        v->tongtime = tinhtime(r);
        checkgoidi = checkNumber(r->form_number);
        checkgoiden = checkNumber(r->to_number);
        if (checkgoidi == -1 || checkgoiden == -1) {
            checktong = -1;
        }
        insert(r->form_number, v);
    }

    while (true) {
        std::cin >> a;
        if (a == "#") {
            break;
        } else if (a == "?check_phone_number") {
            if (checktong == 1) {
                std::cout << "1" << std::endl;
            } else {
                std::cout << "-1" << std::endl;
            }
        } else if (a == "?number_total_calls") {
            std::cout << cnt << std::endl;
        } else if (a == "?count_time_calls_from") {
            std::cin >> a;
            tongTime(a);
        } else if (a == "?number_calls_from") {
            std::cin >> a;
            tongGoi(a);
        }
    }

    return 0;
}

