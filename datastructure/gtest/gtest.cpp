//
// Created by zh on 2020/6/22.
//
#include <gtest/gtest.h>
#include "ut_dict.h"
#include "ds_priorityqueue.h"
#include "cyclequeue.h"
#include <string>
//用户持仓的key
typedef struct dict_position_key {
    uint32_t        user_id;
    uint32_t        direct; // 0:持仓没有方向 1:做空方向的持仓 2:做多方向的持仓
} dict_position_key;

//用户持仓的value
typedef struct position_t {

    double          create_time;
    double          update_time;

    uint32_t        user_id;                  //此单属于哪个用户
    uint32_t         direct;                  // 3:持仓没有方向 1:做空方向的持仓 2:做多方向的持仓
    char            *market;                  //合约名称
} position_t;

static uint32_t dict_position_hash_func(const void* key){
    return dict_generic_hash_function(key,sizeof(dict_position_key));
}
static int dict_position_key_compare_func(const void* key1,const void* key2){
    const dict_position_key* obj1 = (dict_position_key*)key1;
    const dict_position_key* obj2 = (dict_position_key*)key2;
    if(obj1->user_id == obj2->user_id && obj1->direct == obj2->direct){
        return 0; //返回0 表示存在
    }
    return 1; //返回1 表示不存在
}
static void* dict_position_key_dup_func(const void* key){
    dict_position_key* obj = (dict_position_key*)malloc(sizeof(dict_position_key));
    memcpy(obj,key,sizeof(dict_position_key));
    return obj;
}

static void dict_position_key_free_func(void* key){
    free(key);
}

static void* positon_dup(const char* market){
    position_t* obj = (position_t*)(malloc(sizeof(position_t)));
    memset(obj,0,sizeof(position_t));
    obj->market = (char*)(malloc(strlen(market)));
    memcpy(obj->market,market,strlen(market));
    return obj;
}

static void position_free(position_t* position){
    if(position->market){
        free(position->market);
        position->market=NULL;
        free(position);
        position=NULL;
    }

}
static void* dict_position_value_dup_func(const void* market){
    return positon_dup((char*)market);
}
static void dict_position_value_free_func(void* value){
    position_free((position_t*)value);
}


TEST(DS,dict){

    dict_types dt;
    memset(&dt,0,sizeof(dt));
    dt.hash_function = dict_position_hash_func;
    dt.key_compare   = dict_position_key_compare_func;

    dt.key_dup = dict_position_key_dup_func;
    dt.key_destructor = dict_position_key_free_func;

    dt.val_dup = dict_position_value_dup_func;
    dt.val_destructor = dict_position_value_free_func;
    dict_t* dict=dict_create(&dt,1024);
    if(!dict){
        std::cout<< "创建的dict null"<<"\n";
    }

    //添加
    dict_position_key key={.user_id = 1,.direct=1};
    if(dict_add(dict,&key,(char*)"BTCUSDT")==NULL){
        std::cout << "add {1,1} error"<<"\n";

    }

    key={.user_id = 2,.direct=2};
    if(dict_add(dict,&key,(char*)"ETHUSDT")==NULL){
        std::cout << "add {2,2} error"<<"\n";
    }



    //迭代
    dict_iterator *it =dict_get_iterator(dict);
    dict_entry* entry=dict_next(it);

    while (entry){
        dict_position_key* key =(dict_position_key*) (it->entry->key);
        position_t * value     =(position_t *) (it->entry->val);
        std::cout<< key->direct<<" " << key->user_id<<" "<<  value->market <<"\n";
        entry = dict_next(it);
    }

    dict_delete(dict,&key);//删除

    dict_position_key temp={.user_id = 3,.direct=3};
    dict_replace(dict,&temp,(char*)"1234");
    dict_replace(dict,&temp,(char*)"12345"); //修改

    dict_entry* obj = dict_find(dict,&temp);
    if(obj){
        std::cout <<"find obj"<<"\n";
    }


    std::cout<<"\n";
    it=dict_get_iterator(dict);
    entry=dict_next(it);

    while (entry){
        dict_position_key* key =(dict_position_key*) (it->entry->key);
        position_t * value     =(position_t *) (it->entry->val);
        std::cout<< key->direct<<" " << key->user_id<<" "<<  value->market <<"\n";
        entry = dict_next(it);
    }

    dict_release(dict);

}
TEST(DS,priority_queue){
    std::vector<int > v{5,4,3,2,2,1,0,-1};
    ds_priorityqueue<int> pq(v.begin(),v.end());
    for(int i = 0;i<v.size();++i){
        std::cout << pq.top()<<" ";
        pq.pop();
    }
    std::cout<< "\n";
    struct StrCom{
        bool operator()(const std::string& left,const std::string& right){
            return !(left.length()>=right.size());
        }
    };

    ds_priorityqueue<std::string,std::vector<std::string>,StrCom> pq_str;
    pq_str.push("12");
    pq_str.push("12");
    pq_str.push("1234");
    pq_str.push("12345");
    for(int i =1;i<=4;++i){
        std::cout<<pq_str.top()<<" ";
        pq_str.pop();
    }
    std::cout<< "\n";
}
TEST(DS,cyclequeue){
    cyclequeue<int> cq(5);
    for (int i = 0; i < 10; ++i) {
        auto f = cq.push(i);
        if(!f){
            std::cout << i << "入队失败，队列满:"<<cq.length()<<"\n";
        }else{
            std::cout << i << "入队成功,当前元素个数："<<cq.length()<<"\n";
        }
    }

    for (int i = 0; i < 10; ++i) {
        auto f = cq.pop();
        if(f.first){
            std::cout  <<"第"<< i << "次("<< f.second << ")出队成功"<<"\n";
        }else{
            std::cout <<"第"<< i << "次，出队失败，队列空"<<"\n";
        }
    }


}