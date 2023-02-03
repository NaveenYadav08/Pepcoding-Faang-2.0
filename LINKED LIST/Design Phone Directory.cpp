https://leetcode.ca/2016-12-13-379-Design-Phone-Directory/


class PhoneDirectory {
private:
    unordered_set<int> pool;
public:
    PhoneDirectory(int maxNumbers) {
        while (maxNumbers--) pool.insert(maxNumbers);
    }
    int get() {
        if (pool.empty()) return -1;
        int ans = *pool.begin();
        pool.erase(pool.begin());
        return ans;
    }
    bool check(int number) {
        return pool.find(number) != pool.end();
    }
    void release(int number) {
        if (check(number)) return;
        pool.insert(number);
    }
};
