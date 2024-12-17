# include <iostream>
# include <map>

using namespace std;

template<typename K, typename V, typename fun>
void show_map(map<K, V, fun> &map){
    for (auto &kv : map){
        std::cout << kv.first << ": " << kv.second << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    std::map<std::string, int> map0;   // 空的 map

    std::map<std::string, int> map1 = {{"ten", 10}, {"two", 2}};
    std::map<std::string, int, std::less<string>> map2 = {{"one", 1}, {"two", 2}};
    std::map<std::string, int, std::greater<string>> map3 = {{"one", 1}, {"two", 2}};

    // 传入自定义的排序函数, map排序基于红黑树，所以传入l和r两个参数
    struct Compare{
        bool operator()(const string& l, const string& r) const {
            return l.length() > r.length();
        }
    };
    std::map<std::string, int, Compare> map{{"ten", 10}, {"to", 2}, {"eveven", 11}};

    show_map(map1);
    show_map(map2);
    show_map(map3);
    show_map(map);

    // 查
    std::cout << "lower:" << map1.lower_bound("two")->first << std::endl;   // 返回第一个大于等于key的元素
    std::cout << "upper:" << map1.upper_bound("two")->second << std::endl;  // 返回第一个大于key的元素

    return 0;
}