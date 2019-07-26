class Foo {
public:
    int sque = 0;
    
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        while(sque != 0) {}
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        sque = 1;
    }

    void second(function<void()> printSecond) {
        while(sque != 1) {}
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        sque = 2;
    }

    void third(function<void()> printThird) {
        while(sque !=2) {}
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};