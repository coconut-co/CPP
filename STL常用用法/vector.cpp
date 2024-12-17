# include<vector>
# include<iostream>

void show_vector(std::vector<int> &vec){
    for (int val : vec){
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void show_vector(std::vector<std::vector<int>> &vec){
    for (auto rows : vec){
        for (int x : rows){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    // 构造函数
    std::vector<int> v0();               // 空vector
    std::vector<int> v1({1, 1, 1, 1});   // 赋值初始化
    std::vector<int> v2(10);             // 10个元素，每个元素为0
    std::vector<int> v3(10, 5);          // 10个元素，每个元素为5
    std::vector<std::vector<int>> v4(3, std::vector<int>(4, 1));   // 创建3*4的矩阵,每个元素初始化为1
    std::vector<std::vector<int>> v5({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    show_vector(v1);
    show_vector(v2);
    show_vector(v3);
    show_vector(v4);

    // 增
    int x = 2;
    v1.push_back(x);
    show_vector(v1);
    
    v2.insert(v2.begin() + 1, 5);
    show_vector(v2);
    // v2.insert(v2.begin() + 15, 1); 插入的位置大于容器的容量，会发生段错误

    // 删
    v2.erase(v2.begin() + 0);
    show_vector(v2);

    v2.pop_back();     // 括号内没有参数，默认删除最后一个

    // 查
    std::cout << v2.at(0) << std::endl;
    std::cout << v2[0] << std::endl;
    for (auto row_it = v4.begin(); row_it < v4.end(); row_it++){
        for (auto col_it = row_it->begin(); col_it < row_it->end(); col_it++){
            std::cout << *col_it << " ";
        }
    }std::cout << std::endl;

    // 其他重要函数
    std::cout << "v2容量:" << v2.capacity() << std::endl;
    std::cout << "v2大小:" << v2.size() << std::endl;

}