//
//  heap-tree.cpp
//  Algorithms
//
//  Created by Arman Malekzade on 1/30/17.
//  Copyright © 2017 Arman Malekzade. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX_SIZE 100
using namespace std;
class heap{
    int nodes[MAX_SIZE];
    int size;
public:
    heap(){
        size=0;
    }
    void insert_node(int value){
        nodes[size]=value;
        size++;
        cout<<"The new node with value "<<value<<" was inserted.\n";
        print_nodes();
        cout<<"Comparing "<<nodes[parent_index(size-1)]<<" and "<<nodes[size-1]<<" at indices "<<parent_index(size-1)<<" and "<<size-1<<"\n";
        if(nodes[parent_index(size-1)]<nodes[size-1]){
            cout<<"The new node's value is greater than its parent's.\nTrying to Swap "<<nodes[parent_index(size-1)]<<" and "<<nodes[size-1]<<"\n";
            int i=size-1;
            while(1){
                if(i!=size-1) cout<<"Comparing "<<nodes[parent_index(i)]<<" and "<<nodes[i]<<" at indices "<<parent_index(i)<<" and "<<i<<"\n";
                if(nodes[parent_index(i)]<nodes[i]){
                    if(i!=size-1) cout<<"The child node's value is greater than its parent's.\nTrying to Swap "<<nodes[parent_index(i)]<<" and "<<nodes[i]<<"\n";
                    swap_elements(parent_index(i), i);
                    print_nodes();
                    i=parent_index(i);
                }else{
                    break;
                }
                
            }
        }
    }
    int parent_index(int index){
        if(index==0) return 0;
        else if(index%2==1) return index/2;
        else return (index/2)-1;
    }
    int left_child_index(int index){
        return 2*index+1;
    }
    int right_child_index(int index){
        return 2*index+2;
    }
    int get_value(int index){
        return nodes[index];
    }
    int get_size(){
        return size;
    }
    void print_nodes(){
        cout<<"Printing Started...\n";
        for(int i=0;i<size;i++){
            cout<<nodes[i]<<"\n";
            
        }
        cout<<"Printing Finished...\n";
    }
    void swap_first_and_last_element(){
        swap_elements(0, size-1);
    }
    void delete_last_node(){
        nodes[size]=-1;
        size--;
    }
    int* get_nodes(){
        return nodes;
    }
private:
    void swap_elements(int i1,int i2){
        int temp=nodes[i1];
        nodes[i1]=nodes[i2];
        nodes[i2]=temp;
    }
};
heap build_max_heap_from_array(int* arr,int size){
    heap h=heap();
    for(int i=0;i<size;i++){
        int val=*(arr+i);
        h.insert_node(val);
    }
    return h;
}
vector<int> heapsort(heap h){
    vector<int> v={};
    int heap_initial_size=h.get_size();
    while(v.size()<heap_initial_size){
        v.push_back(h.get_value(0));
        h.swap_first_and_last_element();
        h.delete_last_node();
        h=build_max_heap_from_array(h.get_nodes(), h.get_size());
    }
    return v;
}
int main(){
    int arr[]={1,5,2,3,7,4};
    heap h=build_max_heap_from_array(arr, 6);
    h.print_nodes();
    vector<int> sorted=heapsort(h);
    cout<<"The array is completely sorted \n ---------------------\n";
    for(int i:sorted){
        cout<<i<<"\n";
    }
    return 0;
}
