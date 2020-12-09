struct BigNum {
    vector<int> value = { 0 };
    BigNum() {};
    BigNum(long long val) {
        *this = val;
    }
    void operator =(long long val) {
        value.clear();
        while (val) {
            value.push_back(val % 10);
            val /= 10;
        }
    }
    void operator += (int val) {
        int location = 0;
        while (val) {
            int to_add = val % 10;
            int location2 = location;
            if (location2 > value.size() - 1) {
                value.resize(location2 + 1);
            }
            while (value[location2] + to_add > 9) {
                value[location2] = (value[location2] + to_add) % 10;
                if (location2 + 1 > value.size() - 1) {
                    value.resize(location2 + 2);
                }
                location2++;
                to_add = 1;
            }
            value[location2] += to_add;
            val /= 10;
            location++;
        }
    }
    void operator +=(BigNum& b) {
        value.resize(max(b.value.size(), value.size()) + 1);
        for (int location = 0; location < b.value.size(); location++) {
            int to_add = b.value[location];
            int location2 = location;
            while (value[location2] + to_add > 9) {
                value[location2] = (value[location2] + to_add) % 10;
                location2++;
                to_add = 1;
            }
            value[location2] += to_add;
        }
        if (value[value.size() - 1] == 0) {
            value.pop_back();
        }
    }
    void operator *=(int a) {
        vector<int> result(value.size());
        for (int i = value.size() - 1; i >= 0; i--) {
            int res = value[i] * a;
            int location = i;
            while (res) {
                int to_add = res % 10;
                int location2 = location;
                if (location2 > result.size() - 1) {
                    result.resize(location2 + 1);
                }
                while (result[location2] + to_add > 9) {
                    result[location2] = (result[location2] + to_add) % 10;
                    if (location2 + 1 > result.size() - 1) {
                        result.resize(location2 + 2);
                    }
                    location2++;
                    to_add = 1;
                }
                result[location2] += to_add;
                res /= 10;
                location++;
            }
        }
        value = result;
    }
    bool operator >(BigNum& b) {
        if (value.size() > b.value.size()) {
            return true;
        }
        else if (value.size() == b.value.size()) {
            int loc = value.size() - 1;
            while (loc >= 0 and value[loc] == b.value[loc]) {
                loc--;
            }
            if (loc == -1) {
                return false;
            }
            else {
                return value[loc] > b.value[loc];
            }
        }
    }
    friend ostream& operator <<(ostream& stream, const BigNum& b) {
        for (int i = b.value.size() - 1; i >= 0; i--) {
            stream << b.value[i];
        }
        return stream;
    }
};