#include <iostream>

//omp parallel
void test01() {
#pragma omp parallel
    std::cout <<"Hello World" <<std::endl;
}

//omp parallel for
void test02() {
    //to find the biggest number
    int i,max=0;
#pragma omp parallel for
    for (i=0; i<10000; ++i) {
        if (i>max) max = i;
    }
    std::cout <<max <<std::endl;
}

//omp parallel for private()
void test03() {
    int i,max=0;
#pragma omp parallel for private(i)
    for (i=0; i<10000; ++i) {
        if (i>max) max = i;
    }
    std::cout <<max <<std::endl;
}

//omp parallel reduction(:)
void test04() {
    int i,max=0;
#pragma omp parallel for private(i) reduction(max:max)
    for (i=0; i<10000; ++i) {
        if (i>max) max = i;
    }
    std::cout <<max <<std::endl;
}

//omp parallel critical
void test05() {
    //calculate the sum of an array
    int sum=0;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
#pragma omp parallel for
    for(int i=0; i<10; ++i) {
        int temp = a[i];
#pragma omp critical
        {
            sum += temp;
        }
    }
    std::cout <<sum <<std::endl;
}

//omp parallel num_threads(n)
void test06() {
#pragma omp parallel num_threads(4)
    std::cout <<"Hello World!" <<std::endl;
}

//omp parallel sections
void test07() {
#pragma parallel num_threads(4) 
#pragma omp sections
    {
    #pragma omp section
        {
            std::cout <<"thread-0" <<std::endl;        
        }
    #pragma omp section
        {
            std::cout <<"thread-1" <<std::endl;        
        }
    #pragma omp section
        {
            std::cout <<"thread-2" <<std::endl;        
        }
    #pragma omp section
        {
            std::cout <<"thread-3" <<std::endl;        
        }
    }
}

//pragma omp single
void test08() {
#pragma omp parallel
    {
        #pragma omp single
            std::cout <<"print only once" <<std::endl;
        std::cout <<"hello world" <<std::endl;
    }
}

int main(int argc, char** argv) {
    test08();
    return 0;
}