#include <iostream>

using namespace std;

class FixedArray {
    
    protected:
        int _current_index;
        int _length;
        int* _values;

    public:

        FixedArray(int length){
            _current_index = 0;
            _values = new int[length];
            _length = length;
        }

        int get_length(){
            //what should i put here?
            return _length;
        }

       virtual void insert(int new_value, int index){
            if(index + 1 > get_length()){
                cout << "element overflow" << endl;
                return;
            }
            *(_values + index) = new_value;
        }

        void print_values(){
            for(int i = 0; i < get_length(); i++){
                cout << _values[i] << endl;
            }
            cout << _values[get_length() + 1];
        }

        ~FixedArray(){
            delete[] _values;
        }
};

class DynamicArray : public FixedArray{
    public:
        DynamicArray(int length) : FixedArray(length){
        }

        void insert(int new_value, int index) override{
            if (index + 1 > get_length()){
                int* new_block = new int[index + 1];
                
                for (int i = 0 ; i < get_length(); i++){
                    *(new_block + i) = *(_values + i);
                }
                _values = new_block;
                _length = index + 1;
            }
            *(_values + index) = new_value;
        }
};

int main(){

    // FixedArray* test_array = new FixedArray(3);
    // cout << test_array->get_length() << endl;
    // test_array->insert(5, 0);
    // test_array->insert(10, 1);
    // test_array->print_values();
    // delete test_array;

    DynamicArray* test_array = new DynamicArray(1);
    test_array->print_values();
    cout << endl;
    cout << endl;
    test_array->insert(5, 3);
    test_array->print_values();
    cout<<endl;
    test_array->insert(4,2);
    test_array->print_values();
    return 0;
}