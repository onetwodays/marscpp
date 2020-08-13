//
// Created by zh on 2020/7/9.
//

#ifndef ALGORITHM_SORT_DS_PRIORITYQUEUE_H
#define ALGORITHM_SORT_DS_PRIORITYQUEUE_H
#include <vector>
#include <functional>
template <class T,class Container= std::vector<T>,class Com=std::less<T>>
class ds_priorityqueue {
private:
    Container _con;
    Com _com;
public:
    ds_priorityqueue(){}

    template<class Iterator>
    ds_priorityqueue(Iterator first,Iterator last):_con(first,last){
        auto root = (size()-1-1)>>1;
        while (root){
            adjust_down(root);
            root--;
        }
    }
    const T& top() const{
        return _con.front();
    }
    void push(const T& data){
        _con.emplace_back(data);
        adjust_up(size()-1);

    }
    void pop(){
        if(empty()) return;
        std::swap(_con.front(),_con.back());
        _con.pop_back();
        adjust_down(0);
    }
    bool empty(){
        return _con.empty();
    }
    inline  std::size_t size(){
        return _con.size();
    }

private:
    void adjust_down(std::size_t parent){
        std::size_t left = left_child(parent);

        while (left<size()){
            std::size_t right = right_child(parent);
            if(right<size() && _com(_con[left],_con[right])){
                left = right;
            }
            if(_com(_con[parent],_con[left])){
                std::swap(_con[parent],_con[left]);
                parent = left ;
                left = left_child(parent);
            }else{
                return;
            }
        }
    }

    void adjust_up(std::size_t child){
        if(child>=size()){
            return; //数组的下标超出范围了
        }
        std::size_t par = parent(child);
        while (child){
            if(_com(_con[par],_con[child])){
                std::swap(_con[par],_con[child]);
                child = par;
                par= parent(child);

            }else{
                return;
            }
        }

    }
    inline std::size_t left_child(std::size_t  i){ return 2*i+1;}
    inline std::size_t right_child(std::size_t i){ return 2*i+2;}
    inline std::size_t parent(std::size_t      i){ return (i-1)/2;}


};


#endif //ALGORITHM_SORT_DS_PRIORITYQUEUE_H
