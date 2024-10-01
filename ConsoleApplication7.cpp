#include <iostream>
#include <iomanip>  
using namespace std;

class dhtvz {
private:
    int g1;
    int m1;
    int s1;

    void ntaim() {
        if (s1 >= 60) {
            m1 += s1 / 60;
            s1 %= 60;
        }
        if (m1 >= 60) {
            g1 += m1 / 60;
            m1 %= 60;
        }
        if (s1 < 0) {
            m1 -= (abs(s1) / 60 + 1);
            s1 = 60 - abs(s1) % 60;
        }
        if (m1 < 0) {
            g1 -= (abs(m1) / 60 + 1);
            m1 = 60 - abs(m1) % 60;
        }
        if (g1 < 0) {
            g1 = 0;
            m1 = 0;
            s1 = 0;
        }
    }

public:
    dhtvz() : g1(0), m1(0), s1(0) {}

    dhtvz(int h, int m, int s) : g1(h), m1(m), s1(s) {
        ntaim();
    }

    friend istream& operator>>(istream& in, dhtvz& t) {
        cout << "Введіть години: ";
        in >> t.g1;
        cout << "Введіть хвилини: ";
        in >> t.m1;
        cout << "Введіть секунди: ";
        in >> t.s1;
        t.ntaim();
        return in;
    }

    friend ostream& operator<<(ostream& out, const dhtvz& t) {
        out << setw(2) << setfill('0') << t.g1 << ":"
            << setw(2) << setfill('0') << t.m1 << ":"
            << setw(2) << setfill('0') << t.s1;
        return out;
    }

    dhtvz& operator++() {
        s1++;
        ntaim();
        return *this;
    }

    dhtvz operator++(int) {
        dhtvz temp = *this;
        ++(*this);
        return temp;
    }

    dhtvz operator-(const dhtvz& other) const {
        dhtvz result;
        result.g1 = g1 - other.g1;
        result.m1 = m1 - other.m1;
        result.s1 = s1 - other.s1;
        result.ntaim();
        return result;
    }

    bool operator==(const dhtvz& other) const {
        return (g1 == other.g1 && m1 == other.m1 && s1 == other.s1);
    }

    bool operator!=(const dhtvz& other) const {
        return !(*this == other);
    }

    bool operator>(const dhtvz& other) const {
        if (g1 > other.g1) return true;
        if (g1 == other.g1 && m1 > other.m1) return true;
        if (g1 == other.g1 && m1 == other.m1 && s1 > other.s1) return true;
        return false;
    }

    bool operator<(const dhtvz& other) const {
        return !(*this > other) && *this != other;
    }

    dhtvz& operator+=(const dhtvz& other) {
        g1 += other.g1;
        m1 += other.m1;
        s1 += other.s1;
        ntaim();
        return *this;
    }

    dhtvz& operator-=(const dhtvz& other) {
        g1 -= other.g1;
        m1 -= other.m1;
        s1 -= other.s1;
        ntaim();
        return *this;
    }

    void operator()() const {
        cout << "Час: " << *this << endl;
    }

    dhtvz& operator=(const dhtvz& other) {
        if (this != &other) {
            g1 = other.g1;
            m1 = other.m1;
            s1 = other.s1;
        }
        return *this;
    }
};


int main() {
    dhtvz t1(2, 45, 30);
    dhtvz t2;

    cout << "Введіть другий час:" << endl;
    cin >> t2;

    cout << "Перший час: " << t1 << endl;
    cout << "Другий час: " << t2 << endl;

    dhtvz t3 = t1 - t2;
    cout << "Різниця часу: " << t3 << endl;

    if (t1 == t2) {
        cout << "Часи рівні." << endl;
    }
    else {
        cout << "Часи не рівні." << endl;
    }

    ++t1;
    cout << "Перший час після інкременту: " << t1 << endl;

    t2++;
    cout << "Другий час після інкременту: " << t2 << endl;

    t1();

    return 0;
}
