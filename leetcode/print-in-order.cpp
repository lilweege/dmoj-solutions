class Foo {
    int nextFunc = 1;
    mutex mtx;
    condition_variable cv;
    
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);
        
        printFirst();
        nextFunc = 2;
        
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        
        cv.wait(lck, [this](){ return nextFunc == 2; });
        
        printSecond();
        nextFunc = 3;
        
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        
        cv.wait(lck, [this](){ return nextFunc == 3; });
        
        printThird();
        nextFunc = 4;
        
        cv.notify_all();
    }
};