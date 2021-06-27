// Shortest Superstring Problem, 全探索
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

std::string get_superstring(std::string s1, std::string s2){
    std::string prefix = s1;
    int length = 0;
    
    for(int i=1; i<s1.length(); ++i){
        // s1の後方がs2の前方一致か判定
        std::string substring = s1.substr(s1.length() - i);
        if(s2.size() >= substring.size() && std::equal(std::begin(substring), std::end(substring), std::begin(s2))){
            length = i;
        }
    }
    return s1 + s2.substr(length);
}

int main(void){
    int n = 4;
    std::vector<std::string> S = {"abb", "bba", "bbc", "bbb"};
    std::vector<int> index;
    for(int i=0; i<n; ++i) index.push_back(i);

    do{
        // latex用に整形
        for(int i=0; i<n-1; ++i){
            std::cout << "\\bm{s_" << index.at(i)+1 << "} + ";
        }
        std::cout << "\\bm{s_" << index.at(n-1)+1 << "} &= ";

        std::string superstring = S.at(index.at(0));
        for(int i=1; i<n; ++i){
            superstring = get_superstring(superstring, S.at(index.at(i)));
        }
        
        std::cout << "\\bm{" << superstring << "} ";

        std::cout << "& (" << superstring.length() << "\\mbox{文字})\\\\" << std::endl;
    }while(std::next_permutation(index.begin(), index.end()));
}
