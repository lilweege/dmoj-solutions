class FooBar {
    
    mutex mtx;
    condition_variable cv;
    
    int x;
    int n;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);

            cv.wait(lck, [this](){ return x % 2 == 0; });
            
        	printFoo();
            ++x;

            cv.notify_all();
        
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);

            cv.wait(lck, [this](){ return x % 2 == 1; });
            
        	printBar();
            ++x;

            cv.notify_all();
        }
    }
};