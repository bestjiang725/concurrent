#include<iostream>
#include<thread>

void td_1(std::string &str){
    std::cout<<str<<std::endl;
}

void tes1(){
    std::string hi="hello world";
    std::thread t1(td_1,hi);
    //主线程等待子线程
    t1.join();
}

//仿函数做参数
class td_2{
    public:
        void operator()(){
            std::cout<<" sdhgjksd"<<std::endl;
        }
};
void tes2(){
    std::string hi="Mr.jiang";
    int a=20;
    std::thread t2((td_2()));
    t2.join();
}

//lambda做参数
void tes3(){
    std::string hi="MR.jiang";
    std::thread t([](std::string &str){
        std::cout<<str<<std::endl;
    },hi);
    t.join();

}
int main(){
    tes1();
    tes2();
    tes3();

    return 0;
}