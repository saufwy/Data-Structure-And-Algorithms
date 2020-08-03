#ifndef _UNION_FIND_TEST_HELERP_H_
#define _UNION_FIND_TEST_HELERP_H_
#include <cassert>
#include <ctime>

void test_uf1(int n){
    srand( time(NULL) );
    UnionFind uf = UnionFind(n);

    time_t start_time = clock();

    for( int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.union_elems(a,b);
    }
    for(int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.is_connected(a,b);
    }
    time_t end_time = clock();

    std::cout<<"UF1, "<<2*n<<" ops, "<<double(end_time-start_time)/CLOCKS_PER_SEC<<" s"<<std::endl;
}

#endif

