# include <iostream>
# include <unordered_map>

template<typename K, typename V>
void show_map(std::unordered_map<K, V> &map){
    for (auto &pair : map){
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    std::unordered_map<std::string, int> umap0;   // 空的 unordered_map

    // 使用列表初始化
    std::unordered_map<std::string, bool> umap1 = {{"boyfriend", true}, {"cat", false}};
    
    // 使用迭代器范围初始化
    std::unordered_map<std::string, bool> umap2(umap1.begin(), umap2.end());

    // 拷贝构造
    std::unordered_map<std::string, int> umap3 = {{"apple", 1}, {"banana", 2}};
    std::unordered_map<std::string, int> umap3_0(umap3);

    // 移动构造：移动构造接受一个右值引用，能够将数据从一个unordered_map 移动到另一个 unordered_map，而不必进行逐元素拷贝,
    std::unordered_map<std::string, int> umap3_1(std::move(umap3));
    // 注：移动完后 umap3 表现为一个空的 unordered_map，不在有值

    show_map(umap0);
    show_map(umap1);
    show_map(umap3);

    // 增
    umap0.insert({{"girlfriend", true}});
    umap1.insert(std::make_pair("dog", 2));
    umap3_0["orange"] = 1;         // []:是key而不是索引

    std::cout << "insert" << std::endl;
    show_map(umap0);
    show_map(umap1);
    show_map(umap3_0);

    // 删
    umap0.erase(umap0.begin());
    umap1.erase("dog");
    umap3_0.clear();

    std::cout << "erase" << std::endl;
    show_map(umap0);
    show_map(umap1);
    show_map(umap3_0);

    // 查
    std::cout << "find" << std::endl;
    std::cout << "cat" << umap1.at("cat") << std::endl;
    std::cout << "boyfirend" << umap1["cat"] << std::endl;
    std::cout << umap1.find("cat")->first << umap1.find("cat")->second << std::endl;

    return 0;
}