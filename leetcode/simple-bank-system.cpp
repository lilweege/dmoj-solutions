// https://leetcode.com/problems/simple-bank-system

class Bank {
    vector<long long> accounts;
    int n;
    
public:
    Bank(vector<long long>& balance) 
        : accounts(balance), n(size(balance)) {
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!(1 <= account1 && account1 <= n))
            return false;
        if (!(1 <= account2 && account2 <= n))
            return false;
        if (accounts[account1-1] < money)
            return false;
        accounts[account2-1] += money;
        accounts[account1-1] -= money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!(1 <= account && account <= n))
            return false;
        accounts[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!(1 <= account && account <= n))
            return false;
        if (accounts[account-1] < money)
            return false;
        accounts[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */